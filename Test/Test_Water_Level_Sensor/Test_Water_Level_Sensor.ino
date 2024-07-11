#define water_level_sensor1000 46
#define water_level_sensor1500 50
#define water_level_sensor2000 52
int watersensor1000;
int watersensor1500;
int watersensor2000;

void Baca() {
  watersensor1000=digitalRead(water_level_sensor1000);
  watersensor1500=digitalRead(water_level_sensor1500);
  watersensor2000=digitalRead(water_level_sensor2000);
  if (watersensor1000==HIGH) {
      Serial.println("48 1000 Water level is detected");
      delay(1000);
  }
  
  else { 
      Serial.println("48 1000 No water"); 
      delay(1000); 
  }
  
  delay(1000);
  if (watersensor1500==LOW) {
      Serial.println("50 1500 Water level is detected");
      delay(1000);
  }
  
  else { 
      Serial.println("50 1500 No water"); 
      delay(1000); 
  }

  delay(1000);
  if (watersensor2000==LOW) {
      Serial.println("52 2000 Water level is detected");
      delay(1000);
  }
  
  else { 
      Serial.println("52 2000 No water"); 
      delay(1000); 
  }
}

void setup() {
  Serial.begin(9600); 
  pinMode(water_level_sensor1000,INPUT_PULLUP);
  pinMode(water_level_sensor1500,INPUT_PULLUP);
  pinMode(water_level_sensor2000,INPUT_PULLUP);
}

void loop() {
  Baca();
}
