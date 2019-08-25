    #define LED 11
     
    void setup() {
      Serial.begin(115200);
      Serial.println("MiCS-5524 demo!");
     
      pinMode(LED, OUTPUT);
    }
     
    void loop() {
      int reading = analogRead(A0);
      Serial.println(reading);
     
      analogWrite(LED, reading);
      delay(10);
    }
