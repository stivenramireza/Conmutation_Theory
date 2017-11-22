//#include "DHT.h"

#define ledRegar 22
#define ledAire 23
#define ledEnce 24
#define temperature A0
#define humedad A1
//#define DHTPIN 2
//#define DHTTYPE DHT11

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
  pinMode(ledRegar, OUTPUT);
  pinMode(ledAire, OUTPUT);
  pinMode(ledEnce, OUTPUT);
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
       automatizar();
     }else if(comando == 'M'){
       manual();
     }else if(comando == 'R'){
       regar();
     }else if(comando == 'V'){
       ventilar();
     }
     
  }
}

void automatizar() {
  /**
  if (h >= 40.00) {
    encender();
  }
  else {
    digitalWrite(ledEnce, 0);
  }
  */

  if (t >= 32) {
    if (t >= 36) {
      ventilar();
    }
    else {
      digitalWrite(ledAire, 0);
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

void regar() {
  if (cantR != 2) {
    digitalWrite(ledRegar, 1);
    delay(3000);
    digitalWrite(ledRegar, 0);
    rego = true;
  }
  else {
    rego = false;
  }
}

void ventilar() {
  digitalWrite(ledAire, 1);
}

void encender() {
  digitalWrite(ledEnce, 1);
}
