#include "DHT.h"
#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
  //Serial.println("DHTxx test!");
  dht.begin();
}

void loop() 
{
  delay(2000);
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

//  Serial.print("Humidity: ");
  Serial.println(h);
  //Serial.println(" %");
  //Serial.print("Temperature: ");
  Serial.println(t);
  //Serial.print(" *C   ");
 // Serial.println(f);
  //Serial.println(" *F");
}
