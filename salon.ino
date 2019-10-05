#define pTrrig 4
#define pEcho 3
#define pBuzzer 6

int duracion, distancia, contador = 0;

int red = 11;
int green = 10;
int blue = 9;

void setup() {
  Serial.begin(9600);
  pinMode(pEcho, INPUT);
  pinMode (pTrrig, OUTPUT);
  analogWrite(red,255);
  analogWrite(green,255);
  analogWrite(blue,255);
  pinMode(pBuzzer, OUTPUT);
}

void loop() {
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
     //Serial.print(distancia);
     //Serial.println("cm");
     
  }
  if(distancia <=50){
      analogWrite(red,0);
      analogWrite(green,0);
      analogWrite(blue,0);
      delay(3000);
      analogWrite(red,255);
      analogWrite(green,255);
      analogWrite(blue,255);
  }
}
