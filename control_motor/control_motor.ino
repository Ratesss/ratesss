#include <Servo.h>
Servo myservo; 
const int led = 13;
const long interval = 1000;

int reg [10]= {0,0,0,0,0,0,0,0,0,0};
int promig;
int pos = 0;
int suma;
float vu;





void setup() {
  pinMode(led, OUTPUT);
  myservo.attach(9);
  Serial.begin(115200);
}

void loop() {
  int v;
  v = analogRead(A0);
  //v = 540;
  reg [pos]=v;
  pos = (pos + 1)%10;
  promig= ordrepromig(); 
  myservo.write(promig);
  //print(v,promig);
  
  Serial.print(v);
  Serial.print(' ');
  Serial.println(promig);
  delayMicroseconds(1);
  //toggleLed(led);
}


//rutina per fer l'ordre
//rutina per calcular promig

int ordrepromig(){
  int i;
  float prom;
  suma = 0;
  for (i = 0; i < 10; i++){
    suma = suma + reg[i];
  }
  prom = suma/10;
  prom = prom*180/1024;
  return (int)prom;
}

int toggleLed (){
  digitalWrite (led, HIGH);
  delayMicroseconds(10);
  digitalWrite(led, LOW);
}
