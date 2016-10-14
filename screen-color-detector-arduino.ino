int led[3] = {11, 9, 10};
int brightness[3] = {0, 85, 170};
int fadeAmount[3] = {1, 1, 1};

void setup() {
  Serial.begin(115200);
  
  for (int i = 0; i < 3; ++i) {
    pinMode(led[i], OUTPUT);
    analogWrite(led[i], 0);
  }
}

void loop() {
  if (Serial.available() >= 3) {
    byte color[3];
    Serial.readBytes(color, 3);
    digitalWrite(12, HIGH);
    for (int i = 0; i < 3; ++i) {
      analogWrite(led[i], color[i]);
    }
  }
}
