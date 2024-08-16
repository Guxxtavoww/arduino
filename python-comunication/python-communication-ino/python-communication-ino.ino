#define LED 2

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'L') {
      digitalWrite(LED, HIGH);      
    } else if (command == 'D') {
      digitalWrite(LED, LOW);
    } else {
      Serial.println("Comando desconhecido");
    }
  }
}

