//#include "DHT.h"

//#define ledRegar 22
//#define ledAire 23
//#define ledEnce 24
#define temperature A0
#define humedad A1
//#define DHTPIN 2
//#define DHTTYPE DHT11
#define led22 22
#define led23 23
#define led24 24
#define led25 25
#define led26 26
#define led27 27
#define led28 28
#define led29 29
#define led30 30
#define led31 31
#define led32 32
#define led33 33
#define led34 34
#define led35 35
#define led36 36
#define led37 37

int iRegar;
int iEncender;
int iAire;

float t;
float posicion;
float h;
float posicion2;
//float h;
int cantR = 1;
bool rego;
bool automatico;

//DHT dht(DHTPIN, DHTTYPE);

void setup() {
  /**
  pinMode(ledRegar, OUTPUT);
  pinMode(ledAire, OUTPUT);
  pinMode(ledEnce, OUTPUT);
  */
  pinMode(led22, OUTPUT);
  pinMode(led23, OUTPUT);
  pinMode(led24, OUTPUT);
  pinMode(led25, OUTPUT);
  pinMode(led26, OUTPUT);
  pinMode(led27, OUTPUT);
  pinMode(led28, OUTPUT);
  pinMode(led29, OUTPUT);
  pinMode(led30, OUTPUT);
  pinMode(led31, OUTPUT);
  pinMode(led32, OUTPUT);
  pinMode(led33, OUTPUT);
  pinMode(led34, OUTPUT);
  pinMode(led35, OUTPUT);
  pinMode(led36, OUTPUT);
  pinMode(led37, OUTPUT);
  pinMode(temperature, INPUT);
  pinMode(humedad, INPUT);  

  Serial.begin(9600);
  //dht.begin();
}
void loop() {
  //t = dht.readTemperature();
  //h = dht.readHumidity();
  if(Serial.available()>0){
    char comando = Serial.read();
    if(comando == 'R'){
       Serial.print('R');
       regar();
    }else if(comando == 'A'){
       Serial.print('A');
       automatizar();
    }
    /**
    if(comando == 'T'){
      Serial.print('T');
      posicion = analogRead(temperature);
      t = map(posicion,0,1023,0,100);
      Serial.println((int)t);
     }else if(comando == 'H'){
      Serial.print('H');
      posicion2 = analogRead(humedad);
      h = map(posicion2,0,1023,0,100);
      Serial.println((int)h);
     }else if(comando == 'A'){
       Serial.print('A');
       automatizar();
     }else if(comando == 'M'){
       Serial.print('M');
       manual();
     }else if(comando == 'R'){
       Serial.print('R');
       regar();
     }else if(comando == 'V'){
       Serial.print('V');
       ventilar();
     }else if(comando == 'E'){
       Serial.print('E');
       encender();
     }
     */
     
  }
}


void automatizar() {
  if (h >= 40) {
    encender();
  }else {
    apagar();
  }
  
  if (t >= 32) {
    if (t >= 36) {
      ventilar();
    }
    else {
      apagar();
    }
    regar();
  }

  if (cantR == 4) {
    cantR = 1;
  }
  else {
    cantR += 1;
  }

  if (rego == false) {
    delay(5000);
  }
  else {
    delay(2000);
  }
}

/**
void manual() {
  if (iEncender == 1) {
    regar();
    cantR = 1;
  }
  else {
    digitalWrite(ledEnce, 0);
  }

  if (iAire == 1) {
    ventilar();
  }
  else {
    digitalWrite(ledEnce, 0);
  }

  if (iRegar == 1) {
    regar();
  }
  else {
    digitalWrite(ledRegar, 0);
  }
}
*/

void regar() {
  digitalWrite(led22, 1);
  delay(500);
  digitalWrite(led23, 1);
  delay(500);
  digitalWrite(led24, 1);
  delay(500);
  digitalWrite(led25, 1);
  delay(500);
  digitalWrite(led26, 1);
  delay(500);
  digitalWrite(led27, 1);
  delay(500);
  digitalWrite(led28, 1);
  delay(500);
  digitalWrite(led29, 1);
  delay(500);
  digitalWrite(led30, 1);
  delay(500);
  digitalWrite(led31, 1);
  delay(500);
  digitalWrite(led32, 1);
  delay(500);
  digitalWrite(led33, 1);
  delay(500);
  digitalWrite(led34, 1);
  delay(500);
  digitalWrite(led35, 1);
  delay(500);
  digitalWrite(led36, 1);
  delay(500);
  digitalWrite(led37, 1);
  delay(500);
  digitalWrite(led22, 0);
  delay(500);
  digitalWrite(led23, 0);
  delay(500);
  digitalWrite(led24, 0);
  delay(500);
  digitalWrite(led25, 0);
  delay(500);
  digitalWrite(led26, 0);
  delay(500);
  digitalWrite(led27, 0);
  delay(500);
  digitalWrite(led28, 0);
  delay(500);
  digitalWrite(led29, 0);
  delay(500);
  digitalWrite(led30, 0);
  delay(500);
  digitalWrite(led31, 0);
  delay(500);
  digitalWrite(led32, 0);
  delay(500);
  digitalWrite(led33, 0);
  delay(500);
  digitalWrite(led34, 0);
  delay(500);
  digitalWrite(led35, 0);
  delay(500);
  digitalWrite(led36, 0);
  delay(500);
  digitalWrite(led37, 0);
  /**
  if (cantR != 2) {
    digitalWrite(ledRegar, 1);
    delay(3000);
    digitalWrite(ledRegar, 0);
    rego = true;
  }
  else {
    rego = false;
  }
 */ 
}

void ventilar() {
  for(int i = 0; i < 4; ++i){
  digitalWrite(led22, 1);
  digitalWrite(led23, 1);
  digitalWrite(led24, 1);
  digitalWrite(led25, 1);
  digitalWrite(led26, 1);
  digitalWrite(led27, 1);
  digitalWrite(led28, 1);
  digitalWrite(led29, 1);
  digitalWrite(led30, 0);
  digitalWrite(led31, 0);
  digitalWrite(led32, 0);
  digitalWrite(led33, 0);
  digitalWrite(led34, 0);
  digitalWrite(led35, 0);
  digitalWrite(led36, 0);
  digitalWrite(led37, 0);
  delay(500);
  digitalWrite(led22, 0);
  digitalWrite(led23, 0);
  digitalWrite(led24, 0);
  digitalWrite(led25, 0);
  digitalWrite(led26, 0);
  digitalWrite(led27, 0);
  digitalWrite(led28, 0);
  digitalWrite(led29, 0);
  digitalWrite(led30, 1);
  digitalWrite(led31, 1);
  digitalWrite(led32, 1);
  digitalWrite(led33, 1);
  digitalWrite(led34, 1);
  digitalWrite(led35, 1);
  digitalWrite(led36, 1);
  digitalWrite(led37, 1);
  }
}



void encender() {
  digitalWrite(led22, 1);
  digitalWrite(led23, 1);
  digitalWrite(led24, 1);
  digitalWrite(led25, 1);
  digitalWrite(led26, 1);
  digitalWrite(led27, 1);
  digitalWrite(led28, 1);
  digitalWrite(led29, 1);
  digitalWrite(led30, 1);
  digitalWrite(led31, 1);
  digitalWrite(led32, 1);
  digitalWrite(led33, 1);
  digitalWrite(led34, 1);
  digitalWrite(led35, 1);
  digitalWrite(led36, 1);
  digitalWrite(led37, 1);
}

void apagar() {
  digitalWrite(led22, 0);
  digitalWrite(led23, 0);
  digitalWrite(led24, 0);
  digitalWrite(led25, 0);
  digitalWrite(led26, 0);
  digitalWrite(led27, 0);
  digitalWrite(led28, 0);
  digitalWrite(led29, 0);
  digitalWrite(led30, 0);
  digitalWrite(led31, 0);
  digitalWrite(led32, 0);
  digitalWrite(led33, 0);
  digitalWrite(led34, 0);
  digitalWrite(led35, 0);
  digitalWrite(led36, 0);
  digitalWrite(led37, 0);
}
