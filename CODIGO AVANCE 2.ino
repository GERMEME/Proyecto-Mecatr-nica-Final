const byte pinEjex = A0;
const byte pinEjey = A1;
const byte pinB = 1;
const byte M1 = 2;
const byte M2 = 5;
const byte M3 = 8;
const byte M4 = 9;
const byte M5 = 6;
const byte M6 = 7;
const int deadZone = 50; // Rango de tolerancia centrado en el valor medio (512).

//Potenciómetro

float valorPot;
int vel;

//Sensor ultrasonido

int trig = 6;
int echo = 7;
int tiempo;
int distancia;
int distmin = 6;
int dismax = 90;

//Joystick

int ejeX;
int ejeY;
bool estadoB;

void setup()  {
  pinMode(pinEjex, INPUT);
  pinMode(pinEjey, INPUT);
  pinMode(echo, INPUT);
  pinMode(pinB, INPUT_PULLUP);
  
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(trig, OUTPUT);
  
  Serial.begin(9600);
}

void loop()  {
  ejeX = analogRead(pinEjex);
  ejeY = analogRead(pinEjey);
  estadoB = digitalRead(pinB);
  
  // Motor DC 1 Eje x
  
  if (ejeX > 491 && ejeX < 531){
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
  }
  if(ejeX > 531){
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
  }
  if(ejeX < 491 ) {
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
  }
  
  //Velocidad Motor 1
  
  int potValue = analogRead(pinEjex);
  int motorSpeed = map(valorPot, 0, 1023, 0, 255);
  
  analogWrite(M2, motorSpeed);
  delay(10);
  
  //Motor DC 2 Eje y
  
  if (ejeY > 491 && ejeY < 531){
    digitalWrite(M4, LOW);
    digitalWrite(M3, LOW);
  }
  if(ejeY > 531){
    digitalWrite(M4, HIGH);
    digitalWrite(M3, LOW);
  }
  if(ejeY < 491) {
    digitalWrite(M4, LOW);
    digitalWrite(M3, HIGH);
  }
  
  //Velocidad Motor 2
  
  int valorPot = analogRead(pinEjey);
  int vel = map(valorPot, 0, 1023, 0, 255);
  
  analogWrite(M3, vel);
  delay(10);
  
  //Sensor ultrasonido
  
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo/58.2 ; //distancia en cm
  
  //Funcionamiento sensor
  
  if (distancia > 40 or distancia <10) {
    analogWrite(M2, 0);   // Detiene el motor
  } else {
    analogWrite(M1, 255); // Velocidad máxima del motor (ajusta según sea necesario)
  }
  
  
  delay(100);  // Pequeño retraso para estabilidad
  
  
  
  
  Serial.print(ejeX);
  Serial.print("   ");
  Serial.print(ejeY);
  Serial.print("   ");
  Serial.println(estadoB);
  Serial.println(distancia);
    
}


  
  