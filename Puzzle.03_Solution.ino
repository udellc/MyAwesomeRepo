#include <Adafruit_CircuitPlayground.h>

bool slideSwitch;
bool leftButtonPressed;
bool rightButtonPressed;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  slideSwitch = CircuitPlayground.slideSwitch();
  leftButtonPressed = CircuitPlayground.leftButton();
  rightButtonPressed = CircuitPlayground.rightButton();
  
  Serial.print("Left Button: ");
  if (leftButtonPressed) {
    Serial.print("DOWN");
  } else {
    Serial.print("  UP");
  }
  Serial.print("   Right Button: ");
  if (rightButtonPressed) {
    Serial.print("DOWN");
  } else {
    Serial.print("  UP");    
  }
  Serial.print("Slide Switch: ");
  if (slideSwitch) {
    Serial.print("+");
  } else {
    Serial.print("-");
  }
  Serial.println();

  if(slideSwitch)
  {
    if (leftButtonPressed && rightButtonPressed)
    {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else
    {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
  else
  {
    if (leftButtonPressed || rightButtonPressed)
    {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else
    {
      digitalWrite(LED_BUILTIN, LOW);
    }
  } 
  // delay(1000);
}
