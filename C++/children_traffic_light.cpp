/* Marcel Scherer
* arduino code for manage a children traffic light
*/

#include <Arduino.h>

#define STATE_TIMER_MAX    20
#define STATE_TIMER_MIN     2

#define TRANSISTOR_PIN_RED    11
#define TRANSISTOR_PIN_YELLOW 12
#define TRANSISTOR_PIN_GREEN  13
#define TRAFFIC_LIGHT_TIMER   A2  /* Pin A2 */

typedef enum{
  state_green          = 1,
  state_yellow_to_red     ,
  state_red               ,
  state_yellow_to_green   
}traffic_light_state_t;

traffic_light_state_t traffic_light_state = state_red;

void setup() {
  Serial.begin(9600);
  traffic_light_state = state_red;
  pinMode(TRANSISTOR_PIN_GREEN,  OUTPUT);        /* configure pin for GREEN LED's */
  pinMode(TRANSISTOR_PIN_YELLOW, OUTPUT);        /* configure pin for YELLOW LED's */
  pinMode(TRANSISTOR_PIN_RED,    OUTPUT);        /* configure pin for RED LED's */
  pinMode(TRAFFIC_LIGHT_TIMER,   INPUT);         /* configure pin for read resistant for timer */
}

void loop() {

  uint32_t timer = max((analogRead(TRAFFIC_LIGHT_TIMER) * STATE_TIMER_MAX) / 1023 , STATE_TIMER_MIN);
  Serial.print("timer: ");
  Serial.println(timer);

  switch (traffic_light_state)
  {
  case state_green:
    Serial.println("green");
    digitalWrite(TRANSISTOR_PIN_RED,   HIGH);
    digitalWrite(TRANSISTOR_PIN_YELLOW,HIGH);
    digitalWrite(TRANSISTOR_PIN_GREEN, LOW);
    delay(timer*1000);
    traffic_light_state = state_yellow_to_red;
    break;

  case state_yellow_to_red:
    Serial.println("yellow to red");
    digitalWrite(TRANSISTOR_PIN_RED,   HIGH);
    digitalWrite(TRANSISTOR_PIN_YELLOW,LOW);
    digitalWrite(TRANSISTOR_PIN_GREEN, HIGH);
    delay(2000);
    traffic_light_state = state_red;
    break;
  
  case state_red:
    Serial.println("red");
    digitalWrite(TRANSISTOR_PIN_RED,   LOW);
    digitalWrite(TRANSISTOR_PIN_YELLOW,HIGH);
    digitalWrite(TRANSISTOR_PIN_GREEN, HIGH);
    delay(timer*1000);
    traffic_light_state = state_yellow_to_green;
    break;
    break;

  case state_yellow_to_green:
    Serial.println("yellow to green");
    digitalWrite(TRANSISTOR_PIN_RED,   LOW);
    digitalWrite(TRANSISTOR_PIN_YELLOW,LOW);
    digitalWrite(TRANSISTOR_PIN_GREEN, HIGH);
    delay(2000);
    traffic_light_state = state_green;
    break;

  default:
    traffic_light_state = state_red;
    break;
  }
}