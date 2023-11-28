const int inputPin = 2;
const int outputPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
}

void loop() {
  // Lee el estado del pulsador y envía la información a la PC
  if (digitalRead(inputPin) == HIGH) {
    Serial.println("INPUT_2_HIGH");
  } else {
    Serial.println("INPUT_2_LOW");
  }

  // Lee la información de la PC y controla el estado del LED
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n').trim();
    if (command.equals("TOGGLE_OUTPUT_3")) {
      digitalWrite(outputPin, !digitalRead(outputPin));
    }
    if (command.equals("CHECK_INPUT_2")) {
      Serial.println(digitalRead(inputPin) == HIGH ? "HIGH" : "LOW");
    }
    if (command.equals("CHECK_OUTPUT_3")) {
      Serial.println(digitalRead(outputPin) == HIGH ? "HIGH" : "LOW");
    }
  }
}
