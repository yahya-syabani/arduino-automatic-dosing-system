//Library
  #include <AFMotor.h>
  #include <Ezo_i2c_util.h>
  #include <Ezo_i2c.h>
  #include <Wire.h>
  Ezo_board PH = Ezo_board(99, "PH");
  Ezo_board EC = Ezo_board(100, "EC");
//Pin Declaration
  //Pompa Dosing
    AF_DCMotor pompa_air(1);  
    AF_DCMotor pompa_A(2);
    AF_DCMotor pompa_B(3);
  //Pompa Distribusi
    int pompa_1000 = 22;
    int pompa_1500 = 24;
    int pompa_2000 = 26;
  //Water Level Sensor {Biru - Ground, Cokelat - VCC, Kuning/Orange - Output (digital input)}
    #define water_level_sensor1000 46   
    #define water_level_sensor1500 50
    #define water_level_sensor2000 52
    int watersensor1000;
    int watersensor1500;
    int watersensor2000;
//Set point durasi pompa bekerja
  unsigned long waktu_pompa_air_1000 = 216000; // 6535000 - (19000+6300000) (Waktu air) - ((Waktu Nutrisi AB + Waktu Pembacaan))
  unsigned long waktu_pompa_AB_1000 = 19000;
  unsigned long waktu_pompa_air_1500 = 9714000; // 16158000 - (144000+6300000)  
  unsigned long waktu_pompa_AB_1500 = 144000;
  unsigned long waktu_pompa_air_2000 = 19149000; // 25740000 - (291000+6300000)
  unsigned long waktu_pompa_AB_2000 = 291000;
  unsigned long waktu_distribusi_1000 = 39300;
  unsigned long waktu_distribusi_1500 = 100000;
  unsigned long waktu_distribusi_2000 = 163860;
  unsigned long waktu_baca = 300000; // Dapat diganti sesuai dengan waktu yang diperlukan
  unsigned long waktu_baca_1500 = 300000;
  unsigned long waktu_baca_2000 = 300000;
  
void Dosing_1000() {
  Serial.println("Dosing 1000 PPM Bekerja");
  pompa_air.run(BACKWARD);
  pompa_A.run(BACKWARD);
  pompa_B.run(BACKWARD);
  delay(waktu_pompa_AB_1000);
  pompa_A.run(RELEASE);
  pompa_B.run(RELEASE);

  baca();
  
  delay(waktu_pompa_air_1000);
  pompa_air.run(RELEASE);
  
  //Dapat diberi sistem pengadukan pada space disini
  
  Serial.println("Mengalirkan nutrisi ke bak 1000 PPM");
  digitalWrite(pompa_1000,LOW);
  delay(waktu_distribusi_1000);
  digitalWrite(pompa_1000,HIGH);
}

void Dosing_1500() {
  Serial.println("Dosing 1500 PPM Bekerja");
  pompa_air.run(BACKWARD);
  pompa_A.run(BACKWARD);
  pompa_B.run(BACKWARD);
  delay(waktu_pompa_AB_1500);
  pompa_A.run(RELEASE);
  pompa_B.run(RELEASE);

  baca1500();
  
  delay(waktu_pompa_air_1500);
  pompa_air.run(RELEASE);
  
  //Dapat diberi sistem pengadukan pada space disini
  
  Serial.println("Mengalirkan nutrisi ke bak 1500 PPM");
  digitalWrite(pompa_1500,LOW);
  delay(waktu_distribusi_1500);
  digitalWrite(pompa_1500,HIGH);
}

void Dosing_2000() {
  Serial.println("Dosing 2000 PPM Bekerja");
  pompa_air.run(BACKWARD);
  pompa_A.run(BACKWARD);
  pompa_B.run(BACKWARD);
  delay(waktu_pompa_AB_2000);
  pompa_A.run(RELEASE);
  pompa_B.run(RELEASE);

  baca2000();
  
  delay(waktu_pompa_air_2000);
  pompa_air.run(RELEASE);
  
  //Dapat diberi sistem pengadukan pada space disini
  
  Serial.println("Mengalirkan nutrisi ke bak 1000 PPM");
  digitalWrite(pompa_2000,LOW);
  delay(waktu_distribusi_2000);
  digitalWrite(pompa_2000,HIGH);
}

void baca() {
  Serial.println("Pembacaan Konsentrasi PH dan EC Larutan Dosing");
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();
    
  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();
    
  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();
    
  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();
    
  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC); 
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();
    
  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();
}

void baca1500() {
  Serial.println("Pembacaan Konsentrasi PH dan EC Larutan Dosing");
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

    delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_1500);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();
}

void baca2000() {
  Serial.println("Pembacaan Konsentrasi PH dan EC Larutan Dosing");
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();
  
  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();
  
  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();
  
  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();
  
  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();

  delay(waktu_baca_2000);
  PH.send_read_cmd();
  EC.send_read_cmd();
  receive_and_print_reading(PH);
  Serial.print("  ");
  receive_and_print_reading(EC);
  Serial.println();
}

void setup() {
  pinMode(water_level_sensor1000,INPUT_PULLUP);
  pinMode(water_level_sensor1500,INPUT_PULLUP);
  pinMode(water_level_sensor2000,INPUT_PULLUP);
  pinMode(pompa_1000,OUTPUT);
  pinMode(pompa_1500,OUTPUT);
  pinMode(pompa_2000,OUTPUT);
  pompa_air.setSpeed(255);
  pompa_A.setSpeed(255);
  pompa_B.setSpeed(255);
  digitalWrite(pompa_1000,HIGH);
  digitalWrite(pompa_1500,HIGH);
  digitalWrite(pompa_2000,HIGH);
  pompa_air.run(RELEASE);
  pompa_A.run(RELEASE);
  pompa_B.run(RELEASE);
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
    watersensor1000=digitalRead(water_level_sensor1000);
    watersensor1500=digitalRead(water_level_sensor1500);
    watersensor2000=digitalRead(water_level_sensor2000);
    if (watersensor1000==HIGH) {
        Serial.println("Stok Nutrisi 1000 PPM Tersedia");
        delay(1000);
        if (watersensor1500==LOW) {
            Serial.println("Stok Nutrisi 1500 PPM Tersedia");
            delay(1000);
            if (watersensor2000==LOW) {
                Serial.println("Stok Nutrisi 2000 PPM Tersedia");
                delay(1000);
            }
            else {
               Serial.println("Stok Nutrisi 2000 PPM Berkurang");
               Dosing_2000();
            }
        }
        else {
            Serial.println("Stok Nutrisi 1500 PPM Berkurang");
            Dosing_1500();
        }
    }  
    else {
        Serial.println("Stok Nutrisi 1000 PPM Berkurang");
        Dosing_1000();}
}
