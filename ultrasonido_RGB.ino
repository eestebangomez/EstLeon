//En este caso cuando el senser ultrasonico detecta que una persona se acerca mas
//hace que el led suba su intencidad.
#define pTrrig 4
#define pEcho 3

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
 delay(400);
}
void color(int r, int g, int b){
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}

void color_distancia(){
  color(distancia+110, distancia+110, distancia+110);
}
