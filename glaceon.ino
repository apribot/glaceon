const int RED = 9;
const int GREEN = 10;
const int BLUE = 11;
const int WHITE1 = 5;
const int WHITE2 = 6;
const int maxWhite = 200;

int r = 0; /* red led value is temporally 255 and it will be the first led to light up */
int b = 0; /* blue led value is temporally 0 */
int g = 0; /* green led value is temporally 0 */
int w1 = 0;
int w2 = 0;
int lvl1;
int lvl2;

void setup() {/* no setup */
  setRGB(20,50,200);

  lvl1 = random(0, maxWhite);
  lvl2 = random(0, maxWhite);
}

void loop() {
  if(w1 < lvl1) {
    w1++;  
  }
  if(w1 > lvl1) {
    w1--;  
  }
  if(w2 < lvl2) {
    w2++;  
  }
  if(w2 > lvl2) {
    w2--;  
  }

  if(w1 == lvl1) {
    lvl1 = random(0,maxWhite);
  }
  if(w2 == lvl2) {
    lvl2 = random(0,maxWhite);
  }

  setWhite(WHITE1, w1);
  setWhite(WHITE2, w2);
  delay(5);  
}

void tempSetRGB(int rx, int gx, int bx) {
  analogWrite(RED, rx);
  analogWrite(GREEN, gx);
  analogWrite(BLUE, bx);
}

void setRGB() {
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
}

void setRGB(int rx, int gx, int bx) {
    r = rx;
    g = gx;
    b = bx;
    analogWrite(RED, r);
    analogWrite(GREEN, g);
    analogWrite(BLUE, b);
}

void tempSetWhite(int led, int wx) {
  analogWrite(led, wx);
}

void setWhite() {
  analogWrite(WHITE1, w1);
  analogWrite(WHITE2, w2);
}

void setWhite(int led, int wx) {
  if (led == WHITE1) {
    w1 = wx;
    analogWrite(led, w1);
  } else if (led == WHITE2) {
    w2 = wx;
    analogWrite(led, w2);    
  }
}
