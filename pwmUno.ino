#define ledPin 9  //กำหนด pin pwm สำหรับควบคุม led

void setup() {
  // initialize the serial communication:
  Serial.begin(115200);
  // initialize the ledPin as an output:
  pinMode(ledPin, OUTPUT);

  Serial.println("Input brightness value between 0-100%...");
}

void loop() {
  // check if data has been sent from the computer:
  while (Serial.available()) {
    String brightness;
    int pwmVal;
    // read the most recent byte (which will be from 0 to 255):
    brightness = Serial.readString();

    Serial.println("Set brightness level to " + brightness);

    // pwmVal = map(brightness.toInt(), 0, 100, 0, 255);

    pwmVal = (brightness.toInt() * 255) / 100;

    //Serial.println(pwmVal);

    // set the brightness of the LED:
    analogWrite(ledPin, pwmVal);
  }
}
