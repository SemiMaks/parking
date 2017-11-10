//
// обработка нажатий кнопок
// устранение дребезга контактов
//


const int button_1 = 2;    
const int light_1 = 13;      


int lightState = HIGH;         
int buttonState;            
int lastButtonState = LOW;   

unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;   

void setup() {
  pinMode(button_1, INPUT);
  pinMode(light_1, OUTPUT);

  
  digitalWrite(light_1, lightState);
}

void loop() {
 
  int reading = digitalRead(button_1);


  if (reading != lastButtonState) {
    
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    
    if (reading != buttonState) {
      buttonState = reading;
      
      if (buttonState == HIGH) {
        lightState = !lightState;
      }
    }
  }

  digitalWrite(light_1, lightState);
  lastButtonState = reading;
}

