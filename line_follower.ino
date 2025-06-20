#define LS 6  // Left sensor
#define MS 5  // Middle sensor
#define RS 4  // Right sensor

#define LM1 12
#define LM2 13
#define enL 11

#define RM1 9
#define RM2 8
#define enR 10

void setup() {
  Serial.begin(9600);

  pinMode(LS, INPUT);
  pinMode(MS, INPUT);
  pinMode(RS, INPUT);

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(enL, OUTPUT);

  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(enR, OUTPUT);
}

void loop() {
  int ls = digitalRead(LS);
  int ms = digitalRead(MS);
  int rs = digitalRead(RS);

  Serial.print("LS: "); Serial.println(ls);
  Serial.print("MS: "); Serial.println(ms);
  Serial.print("RS: "); Serial.println(rs);

  // All sensors off line
  if (ls == LOW && ms == LOW && rs == LOW) {
    stop();
    Serial.println("Stop");
  }

  // Line is slightly to the left
  else if (ls == LOW && rs == HIGH) {
    TurnLeft();
    Serial.println("TurnLeft");
  }

  // Line is slightly to the right
  else if (ls == HIGH && rs == LOW) {
    TurnRight();
    Serial.println("TurnRight");
  }

  // Line is centered
  else if (ls == HIGH && ms == LOW && rs == HIGH) {
    MoveForward();
    Serial.println("MoveForward");
  }

  delay(100); // small delay for stability
}

void stop() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  analogWrite(enL, 0);

  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
  analogWrite(enR, 0);
}

void TurnLeft() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(enL, 50);

  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(enR, 255);
}

void TurnRight() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(enL, 255);

  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(enR, 50);
}

void MoveForward() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(enL, 255);

  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(enR, 255);
}
