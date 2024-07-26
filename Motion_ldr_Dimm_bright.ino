const int ldrPin = D5;      // LDR sensor pin (analog pin)
const int motionPin = D4;   // Motion sensor pin
const int ledPin = D0;      // LED pin (PWM supported pin)

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(motionPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read LDR sensor
  int ldrValue = analogRead(ldrPin);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Read motion sensor
  int motionReading = digitalRead(motionPin);

  // Check conditions for LED control
  if (ldrValue > 300) {
    // LDR value is low, it's dark
    Serial.println("DARKNESS DETECTED :)");
    Serial.println("LED Brighten");

    // Adjust LED brightness based on motion
    if (motionReading == HIGH) {
      // Motion detected, brighten the LED
      Serial.println("Motion: HIGH");
      analogWrite(ledPin, 1023); // Set LED brightness to full
    } else {
      // No motion detected, dim the LED
      Serial.println("Motion: LOW");
      analogWrite(ledPin, 50); // Set LED brightness to a low value
    }
  } else {
    // LDR value is high, it's bright
    Serial.println("BRIGHTNESS DETECTED :)");
    Serial.println("LED OFF");
    analogWrite(ledPin, 0); // Set LED brightness to 0 (off)
  }

  // Add a delay to avoid rapid reading
  delay(500);
}
