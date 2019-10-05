#define pTrrig 4
#define pEcho 3
#define pBuzzer 6

const int ledpin = A1;
const int ldrpin = A0;

int duracion, distancia, sensor;

int red = 11;
int green = 10;
int blue = 9;

void setup() {
  Serial.begin(9600);
  pinMode(pEcho, INPUT);
  pinMode(pTrrig, OUTPUT);
  
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
  pinMode(pBuzzer, OUTPUT);
  pinMode(ledpin,OUTPUT);
  pinMode(ldrpin,INPUT);
}

void loop() {
  //ldr();
  digitalWrite(pTrrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pTrrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pTrrig, LOW);

  duracion = pulseIn(pEcho, HIGH);
  distancia = (duracion/2)/29;

  if(distancia >= 500 || distancia <= 0){
    Serial.println("-------");
  }else{
    Serial.print(distancia);
    Serial.println("cm");
     
  }
 color_distancia();
}
/*
void ldr(){
    sensor = analogRead(ldrpin);

  if(sensor < 200){
    digitalWrite(ledpin, HIGH);
    Serial.print(sensor);
    Serial.println("LDR is oscuro, LED prendido");
    color(0, 0, 0);
  }else{
    digitalWrite(ledpin, LOW);
    Serial.print(sensor);
    Serial.println("------------------------------");
    color(255, 255, 255);
  }
}*/

void color(int r, int g, int b){
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}

void color_distancia(){
  if(distancia <=20 && distancia >=1){
    color(0, 255, 255);
    Serial.println("Alarma");
    analogWrite(pBuzzer, 150);
  }else if(distancia <=40 && distancia >=1){
    
    color(255, 0, 255);
    analogWrite(pBuzzer, 150);
    delay(300);
    
    color(255, 255, 0);
    analogWrite(pBuzzer, 0);
    delay(300);
    
    
  }else if(distancia <=50 && distancia >=1){
    analogWrite(pBuzzer, 0);
    color(0, 255, 0);
    Serial.println("Alarma");
  }
}
