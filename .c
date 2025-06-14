#define RELAY_1 2
#define RELAY_2 3
#define PIR_SENSOR 4
#define TEMP_SENSOR A0

void setup() {
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(PIR_SENSOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(PIR_SENSOR);
  int temp = analogRead(TEMP_SENSOR);
  
  // Example: Turn on fan if temperature is high
  if (temp > 600) {
    digitalWrite(RELAY_1, HIGH);  // Fan ON
  } else {
    digitalWrite(RELAY_1, LOW);   // Fan OFF
  }

  // Motion-based light control
  if (motion == HIGH) {
    digitalWrite(RELAY_2, HIGH);  // Light ON
  } else {
    digitalWrite(RELAY_2, LOW);   // Light OFF
  }

  delay(1000);
}
