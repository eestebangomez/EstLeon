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
    Serial.print(distancia);
    Serial.println("cm");
  }
  color_distancia();  
}

void color_distancia(){
    while(distancia <=20 && contador < 5){
      analogWrite(red,0);
      analogWrite(green,255);
      analogWrite(blue,255);
      Serial.println("Alarma");
      analogWrite(pBuzzer, 150);
      delay(300);
      analogWrite(red,255);
      analogWrite(green,255);
      analogWrite(blue,0);
      Serial.println("Alarma");
      analogWrite(pBuzzer, 0);
      delay(300);
      contador ++;
  }
}
