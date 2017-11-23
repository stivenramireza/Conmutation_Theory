// @author: Jose Miguel Alzate Acevedo
// @author: Stiven Ramirez Arango
// @version: 1.0
// @date: 23/11/2017

#define temperature A0
#define humedad A1
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

float t;
float posicion;
float h;
float posicion2;
bool rego;
bool ventilo;

void setup() {
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
}
void loop() {
  if(Serial.available()>0){
    char comando = Serial.read();
    if(comando == 'R'){
       Serial.print('R');
       regar();
    }else if(comando == 'A'){
       Serial.print('A');
       automatizar();
    }else if(comando == 'M'){
       Serial.print('M');
       manual();
    }else if(comando == 'V'){
       Serial.print('V');
       ventilar();
    }else if(comando == 'E'){
       Serial.print('E');
       encender();
    }else if(comando == 'P'){
       Serial.print('P');
       apagar();
    }else if(comando == 'T'){
      Serial.print('T');
      posicion = analogRead(temperature);
      t = map(posicion,0,1023,0,100);
      Serial.println((int)t);
     }else if(comando == 'H'){
      Serial.print('H');
      posicion2 = analogRead(humedad);
      h = map(posicion2,0,1023,0,100);
      Serial.println((int)h);
     }
  }
}


void automatizar() {
  if (h >= 40 && (t >= 32 && t <=36)) {
    encender();
    apagar();
    regar();
    
  }else if(h >= 40 && t >= 36){
    encender();
    apagar();
    ventilar();
  }else {
    if (t >= 32) {
      if (t >= 36) {
        ventilar();
      }else {
        apagar();
        regar();
      }
    apagar();
  }
}
}

void manual() {
  if(rego == false){
    regar();
  }else{
    apagar();
  }
  if(ventilo == false){
    ventilar();
  }else{
    apagar();
  }
}

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
  rego = true;
}

void ventilar() {
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
  delay(500);
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
  delay(500);
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
