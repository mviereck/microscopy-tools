/*
  Code to control stepper motor with driver Pololu A4988
  https://www.watterott.com/de/Pololu-A4988-Schrittmotortreiber
*/

#define DIR  2
#define STEP 3
#define ENABLE 9
#define SLEEP 4
#define MS1 8
#define MS2 7
#define MS3 6

#define LED 13

#define D_IN 1
#define D_OUT 0

String  inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

char    befehl;
char    inputArray[200];
char    parameterArray[200] ;
long    parameter=0;

int     enablemode=1;            // 1=Motor aus, 0=Motor Dauerspannung
int     stepcount=1;
int     stepdelay=1600;

long    akt_pos=0;
long    mem_pos=0;

int     richtung=0;
int     richtung_alt=0;
long    richtung_leerraum=5;     // Anzahl wirkungsloser fullsteps bei Richtungswechsel, bis Zahnrad wieder greift


void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(SLEEP, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(MS3, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(SLEEP, HIGH);  // HIGH = wach
  digitalWrite(ENABLE, HIGH); // HIGH = Motor aus
  digitalWrite(DIR, LOW);
  digitalWrite(STEP, LOW);
  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, HIGH);
  digitalWrite(MS3, HIGH);
  digitalWrite(LED, LOW);
  
  set_stepmode(1);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    //Serial.println(inputString);
    parse();
    docommand();
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}

void parse(void) {
  //Serial.println("# parse");
  inputString.toCharArray(inputArray, 200);
  befehl = inputArray[0];                    // erstes Zeichen ist der Befehl
  if (inputArray[1] = ',') {                 // möglicher Parameter ist durch Komma , getrennt
    int i = 2;
    while (inputArray[i] != '\n') {          // nach Komma bis Zeilenende Parameter als string auslesen
      parameterArray[i-2] = inputArray[i];
      i++; 
    }
    parameterArray[i-2] = 0;
    parameter=atol(parameterArray);
  }
  //Serial.print("# befehl: ");
  //Serial.println(befehl);
  //Serial.println(parameter);
}

void docommand(void) {
  switch (befehl) {
  case 'c':  // check whether Arduino responds
    Serial.print("Device:       ok\n");
    break;
  case '1':  // enable -> Motor dauerhaft unter Strom setzen
    enablemode = 0;
    set_ENABLE(enablemode);
    break;  
  case '2': // disable -> Motor ausschalten, nur bei Bedarf anschalten
    enablemode = 1;
    set_ENABLE(enablemode);
    break;
  case 'i':	//fin
    lauf(D_IN,stepcount);
    Serial.print("Position:     ");
    Serial.print(akt_pos);
    Serial.print("\n");
    break;
  case 'o':	//fout
    lauf(D_OUT,stepcount);
    Serial.print("Position:     ");
    Serial.print(akt_pos);
    Serial.print("\n");
    break;
  case 'z':	//fz zero
    akt_pos = 0;
    Serial.print("ok\n");
    break;
  case 'g':	//fg get
    Serial.print(akt_pos);
    Serial.print("\n");
    break;
  case 'w':	//fw width
    stepcount=parameter;
    Serial.print("Schrittweite: ");
    Serial.print(stepcount);
    Serial.print("\n");
    break;
  default:
    break;
  }
}

void set_ENABLE(int mode) {
  // Funktion: Motor an/ausschalten
  // i  mode         0 = enable, 1 = disable
  // g  enablemode   global setting: 0 = always enable, 1 = enable only if in use

  switch (enablemode) {   // check global setting if motor should be shut off
  case 1:  // global shut off?
    switch (mode) {
    case 0:    // 0 = enable
      digitalWrite(ENABLE, LOW);
      digitalWrite(LED, HIGH);
      delay(10);  // Zeit lassen zum Anschalten
      break;
    case 1:    // 1 = disable
      delay(10);  // Zeit lassen vor dem Ausschalten
      digitalWrite(ENABLE, HIGH);
      digitalWrite(LED, LOW);
      break;     
    }
    break;
  case 0: // global: don't shut off, always enable
    digitalWrite(ENABLE, LOW);
    digitalWrite(LED, HIGH);
    break;
  } 
}

void lauf(int richtung, long schritte) {
  // i  richtung             0 oder 1 (LOW/HIGH)
  // i  schritte             Anzahl Schritte
  // g  stepdelay            Wartezeit in µs zwischen zwei Schritten. Mindestens 100 für 1/16, 1000 für 1/1

  long delta=1 ;
  
  digitalWrite(DIR, richtung);                // Drehrichtung setzen
  if (richtung != richtung_alt) {
    delay(100);
    richtung_alt = richtung;
  }
  delay(10);

  if (richtung == D_OUT) delta = -1;
  if (richtung == D_IN)  delta = 1;

  set_ENABLE(0);                              // Motor an

  for (long r = 0L; r < schritte; r++) {
    digitalWrite(STEP, HIGH);
    digitalWrite(STEP, LOW);
    akt_pos += delta;
    delayMicroseconds(stepdelay);    // Drehgeschwindigkeit mäßigen
  }

  set_ENABLE(1);                             // Motor ggf. aus
}

void set_stepmode(int stepmode) {
  // Stepmodus setzen 1/2/4/8/16
  // derzeit nicht in Gebrauch, fullsteps only
  // ig    stepmode
  switch (stepmode) {
  case 1:
    digitalWrite(MS1, LOW);
    digitalWrite(MS2, LOW);
    digitalWrite(MS3, LOW);
    break;
  case 2:
    digitalWrite(MS1, HIGH);
    digitalWrite(MS2, LOW);
    digitalWrite(MS3, LOW);
    break;
  case 4:
    digitalWrite(MS1, LOW);
    digitalWrite(MS2, HIGH);
    digitalWrite(MS3, LOW);
    break;
  case 8:
    digitalWrite(MS1, HIGH);
    digitalWrite(MS2, HIGH);
    digitalWrite(MS3, LOW);
    break;
  case 16:
    digitalWrite(MS1, HIGH);
    digitalWrite(MS2, HIGH);
    digitalWrite(MS3, HIGH);
    break;
  }
} 

