int txPin =  10;    // LoRa tx connected to digital pin 10
int rxPin =  11;    // LoRa rx connected to digital pin 11
int rstPin =  12;    // LoRa reset connected to digital pin 12
int ledPin =  13;    // LED connected to digital pin 13

int gasSensorPin = 0; //gas sensor connected to analog 0
 
// The setup() method runs once, when the sketch starts



 
void setup()   {                
  pinMode(ledPin, OUTPUT);
  pinMode(txPin, OUTPUT);
  pinMode(rxPin, INPUT);
  pinMode(rstPin, OUTPUT);
  
  Serial.begin(9600);
}
 
// the loop() method runs over and over again,
// as long as the Arduino has power
 
void loop()                    
{
  //digitalWrite(ledPin, HIGH);   // set the LED on
  //delay(1000);                  // wait for a second
  //digitalWrite(ledPin, LOW);    // set the LED off
  //delay(1000);                  // wait for a second

  int gasValue = analogRead(gasSensorPin);

  float vol;
  vol=(float)gasValue/1024*216;
  Serial.print("The gas density is ");
  Serial.println(vol);
  delay(100);
}
