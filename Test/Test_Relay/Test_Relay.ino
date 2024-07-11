int RelayPin = 22;
int RelayPin1 = 24;
int RelayPin2 = 26;

void setup() {
  // Set RelayPin as an output pin
  pinMode(RelayPin, OUTPUT);
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
}

void loop() {
  digitalWrite(RelayPin, HIGH);
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
//  digitalWrite(RelayPin, LOW);
//  digitalWrite(RelayPin1, LOW);
//  digitalWrite(RelayPin2, LOW);
}
