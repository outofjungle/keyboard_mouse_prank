#include <Keyboard.h>
#include <Mouse.h>

#define MIN_DELAY 30
#define MAX_DELAY 60

int times;
int counter;
int choice;

void setup() {
  Keyboard.begin();
  Mouse.begin();
  randomSeed(analogRead(0));
  counter = MIN_DELAY;
}

void loop() {
  if ( counter <= 0 ) {
    times = random(3, 7);
    
    choice = random(2);    
    if (choice) {
      move_mouse(times);
    } else {
      send_cmd_tab(times);
    }
    counter = random(MIN_DELAY, MAX_DELAY);
  }
  else {
    counter--;
    delay(1000);
  }  
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
