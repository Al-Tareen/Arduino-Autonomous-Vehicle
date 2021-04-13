int IN1 = 3;
int IN2 = 4;
int IN3 = 5;
int IN4 = 6;

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

// defines variables
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance > 20) {
    Forward(10);
  }
  else {
    Stop(1000);
    Backward(1000);
    Left(1000);
    Stop(1000);
  }

}

void Forward(int time) {
  //Motor 1
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Motor 2
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(time);
}

void Backward(int time) {
  //Motor 1
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //Motor 2
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(time);
}

void Left(int time) {
  //Motor 1
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Motor 2
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(time);
}

void Stop(int time) {
  //Motor 1
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  //Motor 2
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(time);
}
