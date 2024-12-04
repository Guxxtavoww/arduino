#define LED 2

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char command = (char)Serial.read();

    Serial.print("Recebido: ");
    Serial.println(command);

    if (command == 'L') {
      digitalWrite(LED, HIGH); 
    } else if (command == 'D') {
      digitalWrite(LED, LOW);
    } else {
      Serial.write("Comando desconhecido");
    }
  }
}

