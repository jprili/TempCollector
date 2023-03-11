#include <Arduino.h>
#include <dht.h>

#define DHT_PIN      2
#define BAUD_RATE 9600

dht sensor;
int status = 1; // placeholder status
bool runOnce = 1;

void setup() {
  // serial setup
  Serial.begin(BAUD_RATE);
  Serial.print("Serial started with ");
  Serial.println(BAUD_RATE);

  // initial status check for DHT11
  int status = sensor.read11(DHT_PIN);
  if (status == DHTLIB_OK) {
    Serial.println("[INFO] Connection OK.\n"
                    "Moving to loop.");
  } else {
    Serial.print("[WARN] Connection Status ");
    Serial.print(status);
    Serial.println(". Please check sensor connection.");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (status == DHTLIB_OK) {
    if (runOnce) {
      Serial.println("Humidity (%), \t Temperature: (degC)");
    }
    runOnce = 0;
    
    // collect humidity and temperature
    // round to 1 digit
    Serial.print(sensor.humidity, 1);
    Serial.print(", \t");
    Serial.print(sensor.temperature, 1);
    Serial.println(" ");
  } else {
    delay(10000);
  }

  status = sensor.read11(DHT_PIN);
}