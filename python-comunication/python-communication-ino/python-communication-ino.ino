#define LED 2

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'L') {
      digitalWrite(LED, HIGH); 
      Serial.println("LED Ligado"); // Send a command to Python     
    } else if (command == 'D') {
      digitalWrite(LED, LOW);
      Serial.println("LED Desligado"); // Send a command to Python
    } else {
      Serial.println("Comando desconhecido");
    }
  }
}

