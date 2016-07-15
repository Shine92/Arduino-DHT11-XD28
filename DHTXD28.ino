#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE 11
#define SENSORPIN A0
#define SENSORDELAY 5000

DHT dht (DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  Serial.println("DHT11 & XD28 test!");  
}

void loop() {
sensorValue();
}
void sensorValue(){
  delay(SENSORDELAY);
  int soilValue = 0;
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  soilValue = analogRead(SENSORPIN); //土壤濕度感測模組
  soilValue = map(soilValue,250,1023,100,0); //將數值轉換為0%~100%表示
   
    if(isnan(h) || isnan(t)){
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
      Serial.print("Humidity: ");  /*環境濕度*/
      Serial.print(h);
      Serial.print(" %\t");
      Serial.print("Temperature: ");  /*環境溫度*/
      Serial.print(t);
      Serial.print(" *C\t");
      Serial.print("Soil: ");  /*土壤濕度*/
      Serial.print(soilValue);
      Serial.println(" % ");
}

