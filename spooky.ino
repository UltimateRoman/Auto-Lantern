#define trig D5
#define echo D3
#define alrt D1
#define ldr A0
#define leds D2

long duration;
int distance;

void setup(){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(alrt, OUTPUT);
  pinMode(leds, OUTPUT);
  pinMode(D4, OUTPUT);
  digitalWrite(D4, HIGH);
  Serial.begin(9600);
}

void loop(){
  int ldr_val = analogRead(ldr);
  if(ldr_val<=500)
  {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance= duration*0.034/2;
    if(distance<50)
    {
      alert_user();
      delay(10000);
      for(int i=0;i<16;++i)
      {
       Serial.println("");
      }
    } 
  }
  delay(500);
}

void alert_user(){
  Serial.println("Triggered");
  delay(1000);
  digitalWrite(alrt, HIGH);
  digitalWrite(leds, HIGH);
  delay(5500);
  digitalWrite(alrt, LOW);
  digitalWrite(leds, LOW);
  for(int i=0;i<2;++i)
  {
    digitalWrite(alrt, HIGH);
    digitalWrite(leds, HIGH);
    delay(400);
    digitalWrite(alrt, LOW);
    digitalWrite(leds, LOW);
    delay(300);
  }
  for(int i=0;i<4;++i)
  {
    digitalWrite(alrt, HIGH);
    digitalWrite(leds, HIGH);
    delay(200);
    digitalWrite(alrt, LOW);
    digitalWrite(leds, LOW);
    delay(300);
  }
  for(int i=0;i<2;++i)
  {
    digitalWrite(alrt, HIGH);
    digitalWrite(leds, HIGH);
    delay(400);
    digitalWrite(alrt, LOW);
    digitalWrite(leds, LOW);
    delay(300);
  }
  digitalWrite(alrt, HIGH);
  digitalWrite(leds, HIGH);
  delay(600);
  digitalWrite(alrt, LOW);
  digitalWrite(leds, LOW);
  delay(200);
  for(int i=0;i<4;++i)
  {
    digitalWrite(alrt, HIGH);
    digitalWrite(leds, HIGH);
    delay(150);
    digitalWrite(alrt, LOW);
    digitalWrite(leds, LOW);
    delay(150);
  }
  digitalWrite(alrt, HIGH);
  digitalWrite(leds, HIGH);
  delay(500);
  digitalWrite(alrt, LOW);
  digitalWrite(leds, LOW);
}
