#define LED 2

const int delay_value = 500;
int blink_amount = 0;
bool printed = false;

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
}

void loop() {
  if (blink_amount != 10) {
    delay(delay_value);

    digitalWrite(LED, HIGH);
    blink_amount++;

    delay(delay_value);

    digitalWrite(LED, LOW);
  }

  if (!printed && blink_amount == 10) {
    Serial.print("Piscou 10 vezes");
    printed = true;
  }
}