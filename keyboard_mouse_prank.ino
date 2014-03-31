
const int up_button = 2;     
const int down_button = 3;        

int range = 5;
int response_delay = 10;

void setup() {
  pinMode(up_button, INPUT);
  pinMode(down_button, INPUT);
  Mouse.begin();
}

void loop() {
  int up_state = digitalRead(up_button);
  int down_state = digitalRead(down_button);

  int  distance = (up_state - down_state)*range;

  if (distance != 0) {
    Mouse.move(0, distance, 0);
  }

  delay(response_delay);
}
