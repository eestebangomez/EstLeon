//Punto #1 y #2
#define pBuzzer 6
const int ledpin = A1;
const int ldrpin = A0;


int sensor =0;
int red = 11;
int green = 10;
int blue = 9;

void setup() {
Serial.begin(9600);
pinMode(ledpin,OUTPUT);
pinMode(ldrpin,INPUT);
  pinMode(pBuzzer, OUTPUT);
}
void loop() {
  sensor = analogRead(ldrpin);
  
  if(sensor < 300){
    digitalWrite(ledpin, HIGH);
    Serial.print(sensor);
    Serial.println("LDR is oscuro, LED prendido");
    color(0, 0, 0);
    analogWrite(pBuzzer, 150);
  }else{
    digitalWrite(ledpin, LOW);
    Serial.print(sensor);
    Serial.println("------------------------------");
    color(255, 255, 255);
    analogWrite(pBuzzer, 0);
  }
}

void color(int r, int g, int b){
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}
