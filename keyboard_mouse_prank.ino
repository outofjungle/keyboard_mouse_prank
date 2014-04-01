
const int pin2 = 2;
const int pin3 = 3;

int pin2_old_state = HIGH;
int pin3_old_state = HIGH;

int times;
void setup() {
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  int pin2_state = digitalRead(pin2);
  int pin3_state = digitalRead(pin3);

  times = 1 + rand() % 5;

  if ((pin2_state != pin2_old_state) && (pin2_state == HIGH)) {
    move_mouse(times);
    delay(30);
  }
  
  if ((pin3_state != pin3_old_state) && (pin3_state == HIGH)) {
    send_cmd_tab(times);
  }
  
  pin2_old_state = pin2_state; 
  pin3_old_state = pin3_state;
}


void move_mouse(int times) {
  for(int i=0; i < times; i++) {  
    int r = 10 + rand() % 20;
    float t = (float) ( rand() % 6 );
    
    float dir = (rand() % 1) ? -1.0 : 1.0;
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
