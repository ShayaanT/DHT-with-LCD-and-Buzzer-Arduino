//Shayaan Tanvir
//11 - 10 - 2020
//dht sensor connected to an led and a buzzer

#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_Sensor.h>







int speakerPin = 11;
int length = 1;
#define DHTPIN 10
#define DHTTYPE DHT11
#define LED_TOO_COLD A0
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");

  dht.begin();
}

void loop() {
  pinMode(speakerPin, OUTPUT);
  pinMode (A0 , OUTPUT);
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);


  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  if (t < 26) {
    Serial.println("Too cold!");
    digitalWrite(A0, HIGH);
    delay (2000);
    digitalWrite(A0, LOW);
  }
  if (26 < t < 27) {
    Serial.println("Perfect temperature!");
    delay (2000);
  }
  if (t > 27) {
    Serial.println("Too hot!");
    digitalWrite(speakerPin, HIGH);
    delay (2000);
    digitalWrite(speakerPin, LOW);
  }

}
