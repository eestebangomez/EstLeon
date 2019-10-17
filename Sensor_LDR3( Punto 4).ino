//Punto #4
#define pBuzzer 6
const int ldrpin = A0;


int sensor =0;
/*int red = 11;
int green = 10;
int blue = 9;*/

int led1 = 11;
int led2 = 10;
int led3 = 9;

void setup() {
Serial.begin(9600);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(ldrpin,INPUT);
  pinMode(pBuzzer, OUTPUT);
}
void loop() {
  sensor = analogRead(ldrpin);
  
  if(sensor < 400 && sensor > 330){
    Serial.print(sensor);
    Serial.println("------------------------------");
    //color(0, 255, 255);
    digitalWrite(led1, HIGH);
  }else if(sensor < 330 && sensor > 260){
    Serial.print(sensor);
    Serial.println("------------------------------");
    //color(0, 0, 255);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }else if(sensor < 260 && sensor > 190){
    Serial.print(sensor);
    Serial.println("------------------------------");
    //color(0, 0, 0);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }else if (sensor > 400){
    Serial.print(sensor);
    Serial.println("------------------------------");
    //color(255, 255, 255);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  delay(100);
}

/*void color(int r, int g, int b){
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}*/
