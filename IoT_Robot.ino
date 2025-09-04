#include <WiFi.h>
#include <PubSubClient.h>

// Wi-Fi credentials
const char* ssid = "YourSSID";
const char* password = "YourPassword";

// MQTT broker details
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic_status = "robot/status";
const char* mqtt_topic_command = "robot/command";

// IR and ultrasonic pins
const int leftIR = 2;
const int rightIR = 3;
const int trigPin = 4;
const int echoPin = 5;

// Motor pins
const int motorLeftFwd = 6;
const int motorLeftBwd = 7;
const int motorRightFwd = 8;
const int motorRightBwd = 9;

// Obstacle threshold
const int obstacleThreshold = 15;

// Wi-Fi and MQTT clients
WiFiClient espClient;
PubSubClient client(espClient);

// Function to read ultrasonic distance
long readUltrasonicDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

// Motor control functions
void moveForward() {
  digitalWrite(mo
