// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int redPin = 10;
int greenPin = 6;
int bluePin = 5;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  setColor(sonar.convert_cm(sonar.ping_median()));
}

void setColor(int dist) {
  int red = 0;
  int green = 0;
  int blue = 0;
  
      Serial.println(dist);
  
    if(dist < 25) {
       red = 255;
       green = dist * 10;
    }
    else if(dist < 50) {
      dist = 50 - dist;
      red = dist * 10;
      green = 255;
    }
    else if(dist < 75) {
      dist = 75 - dist;
      green = 255;
      blue = 255 - dist * 10;
    }
    else if(dist < 100) {
      dist = 100 - dist;
      green = dist * 10;
      blue = 255;
    }
    else {
      blue = 255;
    }
  
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
