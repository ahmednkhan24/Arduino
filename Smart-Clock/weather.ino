

#define ROW_1 2
#define ROW_2 3
#define ROW_3 4
#define ROW_4 5
#define ROW_5 6
#define ROW_6 7
#define ROW_7 8
#define ROW_8 9

#define COL_1 10
#define COL_2 11
#define COL_3 12
#define COL_4 13
#define COL_5 A0
#define COL_6 A1
#define COL_7 A2
#define COL_8 A3

const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};

// The display buffer
// It's prefilled with a smiling face (1 = ON, 0 = OFF)
byte TODOS[] = {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
byte EX[] = {B00000000,B00010000,B00010000,B00010000,B00010000,B00000000,B00010000,B00000000};
byte A[] = {B00000000,B00011000,B00100100,B00100100,B00111100,B00100100,B00100100,B00000000};
byte B[] = {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
byte C[] = {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
byte D[] = {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
byte E[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00111100,B00000000};
byte F[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
byte G[] = {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
byte H[] = {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
byte I[] = {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
byte J[] = {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
byte K[] = {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
byte L[] = {B00000000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100,B00000000};
byte M[] = {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
byte N[] = {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
byte O[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
byte P[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
byte Q[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
byte R[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
byte S[] = {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
byte T[] = {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
byte U[] = {B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000};
byte V[] = {B00000000,B00100010,B00100010,B00100010,B00010100,B00010100,B00001000,B00000000};
byte W[] = {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
byte X[] = {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
byte Y[] = {B00000000,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00000000};
byte Z[] = {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};
byte ZERO[] = {B00000000,B00111100,B00100100,B00100100,B00100100,B00100100,B00111100,B00000000};
byte ONE[] = {B00000000,B00001000,B00001000,B00001000,B00001000,B00001000,B00001000,B00000000};
byte TWO[] = {B00000000,B00111100,B00000100,B00000100,B00111100,B00100000,B00100000,B00111100};
byte THREE[] = {B00000000,B00111100,B00000100,B00000100,B00011100,B00000100,B00000100,B00111100};
byte FOUR[] = {B00000000,B00100100,B00100100,B00111100,B00000100,B00000100,B00000100,B00000000};
byte FIVE[] = {B00000000,B00111100,B00100000,B00100000,B00111100,B00000100,B00000100,B00111100};
byte SIX[] = {B00000000,B00111100,B00100000,B00100000,B00111100,B00100100,B00100100,B00111100};
byte SEVEN[] = {B00000000,B00111100,B00000100,B00000100,B00000100,B00000100,B00000100,B00000000};
byte EIGHT[] = {B00000000,B00111100,B00100100,B00100100,B00111100,B00100100,B00100100,B00111100};
byte NINE[] = {B00000000,B00111100,B00100100,B00100100,B00111100,B00000100,B00000100,B00000000};
byte SUN[] = {B10010001,B01010010,B00111100,B11100111,B00100100,B00111100,B01010010,B10010001};
byte CLOUD[] = {B00000000,B00011000,B00100100,B01000010,B10000001,B10000001,B11111111,B00000000};
byte RAIN[] = {B00011000,B00100100,B01000010,B10000001,B11111111,B10101010,B01010101,B10101010};
byte SNOW[] = {B10011001,B01111110,B01011010,B11111111,B01011010,B01011010,B01111110,B10011001};
byte BLANK[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};

float timeCount = 0;
int temp1 = 0;
int condition = 0;
int check = 0;

void setup() {
    // Open serial port
    Serial.begin(9600);
    
    // Set all used pins to OUTPUT
    // This is very important! If the pins are set to input
    // the display will be very dim.
    for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);

    Serial.println("Please enter the temparature followed by 1 (if it is sunny), 2(if it is cloudy), 3(if it is raining) or 4(if it is snowy): ");
}

void loop() {

  while(Serial.available() > 0)
  {
    temp1 = Serial.parseInt();
    condition = Serial.parseInt();

    Serial.println(temp1);
    Serial.println(condition);
    check = 1;
  }
  // This could be rewritten to not use a delay, which would make it appear brighter
delay(5);
timeCount += 1;

if((temp1 < 0 || temp1 > 99 || condition < 1 || condition > 4) && check == 1)
{
    if(timeCount < 50)
    {
      drawScreen(E);
    }
    else if(timeCount < 100)
    {
      drawScreen(R);
    }
    else if(timeCount < 150)
    {
      drawScreen(R);
    }
    else if(timeCount < 200)
    {
      drawScreen(O);
    }
    else if(timeCount < 250)
    {
      drawScreen(R);
    }
    else
    {
      timeCount = 0;
    }
}
else
{
  if(check == 1)
  {
    if(timeCount < 80)
    {
        if(temp1 < 10)
        {
          drawScreen(ZERO);
        }
        else if(temp1 > 9 && temp1 < 20)
        {
          drawScreen(ONE);
        }
        else if(temp1 > 19 && temp1 < 30)
        {
          drawScreen(TWO);
        }
        else if(temp1 > 29 && temp1 < 40)
        {
          drawScreen(THREE);
        }
        else if(temp1 > 39 && temp1 < 50)
        {
          drawScreen(FOUR);
        }
        else if(temp1 > 49 && temp1 < 60)
        {
          drawScreen(FIVE);
        }
        else if(temp1 > 59 && temp1 < 70)
        {
          drawScreen(SIX);
        }
        else if(temp1 > 69 && temp1 < 80)
        {
          drawScreen(SEVEN);
        }
        else if(temp1 > 79 && temp1 < 90)
        {
          drawScreen(EIGHT);
        }
        else if(temp1 > 89 && temp1 < 100)
        {
          drawScreen(NINE);
        }
    }
    else if(timeCount < 90)
    {
      drawScreen(BLANK);
    }
    else if(timeCount < 160)
    {
      if((temp1 % 10) == 0)
      {
        drawScreen(ZERO);
      }
      else if((temp1 % 10) == 1)
      {
        drawScreen(ONE);
      }
      else if((temp1 % 10) == 2)
      {
        drawScreen(TWO);
      }
      else if((temp1 % 10) == 3)
      {
        drawScreen(THREE);
      }
      else if((temp1 % 10) == 4)
      {
        drawScreen(FOUR);
      }
      else if((temp1 % 10) == 5)
      {
        drawScreen(FIVE);
      }
      else if((temp1 % 10) == 6)
      {
        drawScreen(SIX);
      }
      else if((temp1 % 10) == 7)
      {
        drawScreen(SEVEN);
      }
      else if((temp1 % 10) == 8)
      {
        drawScreen(EIGHT);
      }
      else if((temp1 % 10) == 9)
      {
        drawScreen(NINE);
      }
    }
    else if(timeCount < 170)
    {
      drawScreen(BLANK);
    }
    else if(timeCount < 190)
    {
      drawScreen(D);
    }
    else if(timeCount < 195)
    {
      drawScreen(BLANK);
    }
    else if(timeCount < 220)
    {
      drawScreen(E);
    }
    else if(timeCount < 225)
    {
      drawScreen(BLANK);
    }
    else if(timeCount < 250)
    {
      drawScreen(G);
    }
    else if(timeCount < 255)
    {
      drawScreen(BLANK);
    }
    else if(timeCount < 280)
    {
      drawScreen(R);
    }
    else if(timeCount < 285)
    {
      drawScreen(BLANK);
    }
    else if(timeCount < 310)
    {
      drawScreen(E);
    }
    else if(timeCount < 315)
    {
      drawScreen(BLANK);
    }
    else if(timeCount < 340)
    {
      drawScreen(E);
    }
    else if(timeCount < 345)
    {
      drawScreen(BLANK);
    }
    else if(timeCount < 360)
    {
      drawScreen(S);
    }
    else if(timeCount < 365)
    {
      drawScreen(BLANK);
    }
    else if(timeCount < 700)
    {
      if(condition == 1)
      {
        drawScreen(SUN);
      }
      else if(condition == 2)
      {
        drawScreen(CLOUD);
      }
      else if(condition == 3)
      {
        drawScreen(RAIN);
      }
      else if(condition == 4)
      {
        drawScreen(SNOW);
      }
    }
    else if(timeCount < 730)
    {
      if(condition == 1)
      {
        drawScreen(B);
      }
      else if(condition == 2)
      {
        drawScreen(S);
      }
      else if(condition == 3)
      {
        drawScreen(S);
      }
      else
      {
        drawScreen(B);
      }
    }
    else if(timeCount < 760)
    {
      if(condition == 1)
      {
        drawScreen(E);
      }
      else if(condition == 2)
      {
        drawScreen(M);
      }
      else if(condition == 3)
      {
        drawScreen(T);
      }
      else
      {
        drawScreen(E);
      }
    }
    else if(timeCount < 790)
    {
      if(condition == 1)
      {
        drawScreen(H);
      }
      else if(condition == 2)
      {
        drawScreen(I);
      }
      else if(condition == 3)
      {
        drawScreen(A);
      }
      else
      {
        drawScreen(W);
      }
    }
    else if(timeCount < 820)
    {
      if(condition == 1)
      {
        drawScreen(A);
      }
      else if(condition == 2)
      {
        drawScreen(L);
      }
      else if(condition == 3)
      {
        drawScreen(Y);
      }
      else
      {
        drawScreen(A);
      }
    }
    else if(timeCount < 850)
    {
      if(condition == 1)
      {
        drawScreen(P);
      }
      else if(condition == 2)
      {
        drawScreen(E);
      }
      else if(condition == 3)
      {
        drawScreen(D);
      }
      else
      {
        drawScreen(R);
      }
    }
    else if(timeCount < 880)
    {
      if(condition == 1)
      {
        drawScreen(P);
      }
      else if(condition == 2)
      {
        drawScreen(EX);
      }
      else if(condition == 3)
      {
        drawScreen(R);
      }
      else
      {
        drawScreen(M);
      }
    }
    else if(timeCount < 910)
    {
      if(condition == 1)
      {
        drawScreen(Y);
      }
      else if(condition == 2)
      {
        drawScreen(EX);
      }
      else if(condition == 3)
      {
        drawScreen(Y);
      }
      else
      {
        drawScreen(EX);
      }
    }
    else
    {
      timeCount = 0;
    }
  }
}

}
 void  drawScreen(byte buffer2[]){
     
    
   // Turn on each row in series
    for (byte i = 0; i < 8; i++) {
        setColumns(buffer2[i]); // Set columns for this specific row
        
        digitalWrite(rows[i], HIGH);
        delay(2); // Set this to 50 or 100 if you want to see the multiplexing effect!
        digitalWrite(rows[i], LOW);
        
    }
}


void setColumns(byte b) {
    digitalWrite(COL_1, (~b >> 0) & 0x01); // Get the 1st bit: 10000000
    digitalWrite(COL_2, (~b >> 1) & 0x01); // Get the 2nd bit: 01000000
    digitalWrite(COL_3, (~b >> 2) & 0x01); // Get the 3rd bit: 00100000
    digitalWrite(COL_4, (~b >> 3) & 0x01); // Get the 4th bit: 00010000
    digitalWrite(COL_5, (~b >> 4) & 0x01); // Get the 5th bit: 00001000
    digitalWrite(COL_6, (~b >> 5) & 0x01); // Get the 6th bit: 00000100
    digitalWrite(COL_7, (~b >> 6) & 0x01); // Get the 7th bit: 00000010
    digitalWrite(COL_8, (~b >> 7) & 0x01); // Get the 8th bit: 00000001
    
}
