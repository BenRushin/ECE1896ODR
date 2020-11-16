#include <Adafruit_MCP23017.h>
Adafruit_MCP23017 mcp;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
  mcp.begin();
  mcp.pinMode(5, OUTPUT);
  mcp.pinMode(4, OUTPUT);
  mcp.pinMode(1, OUTPUT);
  mcp.pinMode(0, OUTPUT);
  mcp.pinMode(6, OUTPUT);
  mcp.pinMode(7, OUTPUT);
  mcp.pinMode(3, OUTPUT);
  mcp.pinMode(2, OUTPUT);
}

void loop() {
  mcp.digitalWrite(7, HIGH);
  mcp.digitalWrite(6, LOW);
  mcp.digitalWrite(5, HIGH);
  mcp.digitalWrite(4, LOW);
  mcp.digitalWrite(3, HIGH);
  mcp.digitalWrite(2, LOW);
  mcp.digitalWrite(1, HIGH);
  mcp.digitalWrite(0, LOW);
  delay(100);
  digitalWrite(9, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  digitalWrite(6, LOW);
  digitalWrite(11, LOW);
  digitalWrite(5, LOW);
  delay(10);
  mcp.digitalWrite(6, HIGH);
  mcp.digitalWrite(7, LOW);
  mcp.digitalWrite(4, HIGH);
  mcp.digitalWrite(5, LOW);
  mcp.digitalWrite(2, HIGH);
  mcp.digitalWrite(3, LOW);
  mcp.digitalWrite(0, HIGH);
  mcp.digitalWrite(1, LOW);
  delay(100);
  digitalWrite(9, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  digitalWrite(6, LOW);
  digitalWrite(11, LOW);
  digitalWrite(5, LOW);
  delay(10);
}
