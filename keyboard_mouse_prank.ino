
const byte pin2 = 2;
const byte pin3 = 3;

int pin2_old_state = HIGH;
int pin3_old_state = HIGH;

int times;
int counter;
int choice;

void setup() {
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  int pin2_state = digitalRead(pin2);
  int pin3_state = digitalRead(pin3);

  times = random(1, 6);

  if ((pin2_state != pin2_old_state) && (pin2_state == HIGH)) {
    move_mouse(times);
    delay(30);
  }
  else if ((pin3_state != pin3_old_state) && (pin3_state == HIGH)) {
    send_cmd_tab(times);
  }
  else if ( counter <= 0 ) {
    choice = random(2);
    
    if (choice) {
      move_mouse(times);
    } else {
      send_cmd_tab(times);
    }
    counter = random(3, 6);
  }
  else {
    counter--;
    delay(1000);
  }  
  
  pin2_old_state = pin2_state; 
  pin3_old_state = pin3_state;
}


void move_mouse(int times) {
  for(int i=0; i < times; i++) {  
    int r = random(10, 20);
    float t = (float) random(6);
    
    float dir = random(2) ? -1.0 : 1.0;
    for(int itr = 0; itr < 30; itr++) {
      t = t + (dir * 0.1);
      
      int move_x = r * cos(t);
      int move_y = r * sin(t);
      
      Mouse.move(move_x, move_y, 0);
      delay(2);
    }
  }
}

void send_cmd_tab(int times) {
  Keyboard.press(KEY_LEFT_GUI);
  delay(30);
  for(int i=0; i < times; i++) {
    Keyboard.press(KEY_TAB);
    delay(30);
    Keyboard.release(KEY_TAB);
    delay(30);
  }
  Keyboard.release(KEY_LEFT_GUI);
  delay(30);
}
