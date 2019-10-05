#define pEcho 3
#define pTrrig 4

long duracion, distancia, contador;

void setup() {
  Serial.begin(9600);
  pinMode(pEcho, INPUT);
  pinMode(pTrrig, OUTPUT);
  pinMode(13, 1);
}

void loop() {
  digitalWrite(pTrrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pTrrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pTrrig, LOW);

  duracion = pulseIn(pEcho, HIGH);
  distancia = (duracion/2)/29;
  delay(1000);

  if(distancia >= 500 || distancia <= 0){
    Serial.println("-------");
  }else{
     //Serial.print(distancia);
     //Serial.println("cm");
  }
  if(distancia <=30 && distancia >=1){
    contador ++;
  }
  Serial.print("Cantidad de personas \t");
  Serial.println(contador);
  
}
