#define LED 2

bool is_led_on = false;

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, is_led_on ? HIGH : LOW);

  if (Serial.available() > 0) {
    char command = (char)Serial.read();

    if (command == 'L') {
      digitalWrite(LED, HIGH);
      is_led_on = true;
    } else if (command == 'D') {
      digitalWrite(LED, LOW);
      is_led_on = false;
    }

    Serial.print(is_led_on ? "ON" : "OFF");
  }
}

