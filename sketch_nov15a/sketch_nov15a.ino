#include <Adafruit_MCP23017.h>
#define MAX 4294967295
Adafruit_MCP23017 mcp;
unsigned long dur1=0;
unsigned long dur2=0;
unsigned long dur3=0;
unsigned long dur4=0;
unsigned long dur=0;
int inches=0;
void setup() {
  // put your setup code here, to run once:
  mcp.begin();
  mcp.pinMode(8, OUTPUT);
  mcp.pinMode(9, OUTPUT);
  mcp.pinMode(6,OUTPUT);
  mcp.pinMode(7,OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  Serial.begin(9600);
}

void loop() {
  mcp.digitalWrite(8, LOW);
  mcp.digitalWrite(9, LOW);
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  dur1 = pulseIn(13, HIGH);
  if(dur1==0){dur1=MAX;}
  delay(1);
  mcp.digitalWrite(8, LOW);
  mcp.digitalWrite(9, HIGH);
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  dur2 = pulseIn(13, HIGH);
  if(dur2==0){dur1=MAX;}
  delay(1);
  mcp.digitalWrite(8, HIGH);
  mcp.digitalWrite(9, LOW); 
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  dur3 = pulseIn(13, HIGH);
  if(dur3==0){dur1=MAX;}
  delay(1);
  mcp.digitalWrite(8, HIGH);
  mcp.digitalWrite(9, HIGH);
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  dur4 = pulseIn(13, HIGH);
  if(dur4==0){dur1=MAX;}
  delay(1);
  dur = min(min(dur1,dur2),min(dur3,dur4));
  inches = dur / 74 /2;
  if(inches<=6){
    mcp.digitalWrite(7,HIGH);
    mcp.digitalWrite(6,LOW);
  }
  else{
    mcp.digitalWrite(7,LOW);
    mcp.digitalWrite(6,HIGH);
  }
}
