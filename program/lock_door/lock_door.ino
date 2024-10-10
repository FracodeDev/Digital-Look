#include <Keypad.h>
#include <LiquidCrystal.h>
const int rs = 9, en = 8, d4 = 13, d5 = 12, d6 = 11, d7 = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','a'},
  {'4','5','6','b'},
  {'7','8','9','c'},
  {'*','0','#','d'}};
byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {7, 6, 5, 4}; 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char pass[6] = {'1','2','3','4','5'};
unsigned char password =0;
int t;
int x=0;
int q=0;
char p[6];
int wrong=0;

void setup() {
  pinMode(A0, OUTPUT); //LED GREEN
  pinMode(A1, OUTPUT); //LED YELLOW
  pinMode(A2, OUTPUT); //LED RED
  pinMode(4, OUTPUT); //relay
  digitalWrite(A0, 0);
  digitalWrite(A1, 0);
  digitalWrite(A2, 0);
  digitalWrite(4, 0);
lcd.begin(20,4);
lcd.clear();
lcd.setCursor(6,0);
lcd.print("Welcome");
lcd.setCursor(1,1);
lcd.print("to the Digital lock");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Plase Enter password");

}
void loop() {

char key = keypad.getKey();
   if (key != NO_KEY){
    lcd.setCursor(0,0);
    lcd.print("Plase Enter password");
    lcd.setCursor(x+7, 1);
    lcd.print('*');
    t++;
    x++;
    p[q] = key;
    q++;
    change();
    if (t>=5){
      lcd.clear();
      check();
      timer();
    }}
    
}
void check()
{
  if (p[0]==pass[0]&&p[1]==pass[1]&&p[2]==pass[2]&&p[3]==pass[3]&&p[4]==pass[4]){
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Password is correct");
      lcd.setCursor(1, 1);
      lcd.print("Opening the door...");
      digitalWrite(A0, 1);
      delay(1000);
      digitalWrite(A0, 0);
      lcd.clear();
      t=0;
      x=0;
      q=0;
      wrong=0;
      lcd.setCursor(0,0);
      lcd.print("Plase Enter password");
     }
     else {
      lcd.clear();
      lcd.setCursor(7, 0);
      lcd.print("Erorr");
      lcd.setCursor(1, 1);
      lcd.print("Password is wrong");
      digitalWrite(A2, 1);
      delay(1000);
      digitalWrite(A2, 0);
      lcd.clear();
      t=0;
      x=0;
      q=0;
      wrong++;
      lcd.setCursor(0,0);
      lcd.print("Plase Enter password");
    }
  }
void check_oldpassword()
{
  char key = keypad.getKey();
  t=0;
  x=0;
  q=0;
  wrong=0;
  int as=0;
  while (as == 0){
    if (q==5)
    {
        t=0;
        x=0;
        q=0;
        
    }
    char key = keypad.getKey();
    if (key != NO_KEY){
        lcd.setCursor(x+7, 1);
        lcd.print('*');
        t++;
        x++;
        p[q] = key;
        lcd.setCursor(q, 2);
        lcd.print(p[q]);
        lcd.setCursor(1, 3);
        q++;
        if (t>=5){
  if (p[0]==pass[0]&&p[1]==pass[1]&&p[2]==pass[2]&&p[3]==pass[3]&&p[4]==pass[4]){
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Enter new password");

      int m=0;
      q=0;
      t=0;
      x=0;
      int sa=0;
      while (sa == 0){
      char key = keypad.getKey();
      if (key != NO_KEY){
        lcd.setCursor(0, 2);
        lcd.print(m);
        lcd.setCursor(x+7, 1);
        lcd.print('*');
        
        pass[q] = key;
        m++;
        q++;
        x++;
        //lcd.setCursor(x+7, 3);
        //lcd.print(pass[q]);
        if (m>=5){
          lcd.clear();
          lcd.setCursor(1, 0);
          lcd.print("Password changed");
          digitalWrite(A1, 1);
          delay(1000);
          digitalWrite(A1, 0);
          m=0;
          q=0;
          t=0;
          x=0;
          sa=1;
          as=1;
          lcd.setCursor(0,0);
          lcd.print("Plase Enter password");
        }
      }
      }
  }
  
     else {
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Password is wrong");
      lcd.setCursor(3, 1);
      lcd.print("back to main");
      digitalWrite(A2, 1);
      delay(1000);
      digitalWrite(A2, 0);
      lcd.clear();
      t=0;
      x=0;
      q=0;
      as=1;
      lcd.setCursor(0,0);
      lcd.print("Plase Enter password");
    }
    }
    }
    }
  
}
void change ()
{
  if (p[0]=='#'&&p[1]=='#'){
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Changing password");
      lcd.setCursor(2, 1);
      lcd.print("Yes(#)");
      lcd.setCursor(11, 1);
      lcd.print("No(*)");
        if (p[2]=='#'){
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Enter old password");
        check_oldpassword();
      
        }
        else if(p[2]=='*'){
          t=0;
          x=0;
          q=0;
          wrong=0;
          lcd.clear();
          lcd.setCursor(3, 0);
          lcd.print("back to main");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Plase Enter password");
        }
        }
      }
void timer()
{
  if (wrong==2) 
  {
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("warning");
    digitalWrite(A2, 1);
    delay(1000);
    lcd.setCursor(1, 0);
    lcd.print("You Enter password");
    lcd.setCursor(4, 1);
    lcd.print("wrong 2 time");
    delay(2000);
    digitalWrite(A2, 0);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Plase Enter password");
    t=0;
    x=0;
    q=0;
  }
  if (wrong==3)
  {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("You Enter password");
    lcd.setCursor(4, 1);
    lcd.print("wrong 3 time");
    digitalWrite(A2, 1);
    delay(1000);
    digitalWrite(A2, 0);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("keypad is lock");
    for (int timer=59;timer>=0;timer--)
    {
      digitalWrite(A1, 1);
      lcd.setCursor(7, 1);
      lcd.print("0:");
      lcd.setCursor(9, 1);
      lcd.print(timer);
      delay(1000);
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("keypad is lock");
    }
    digitalWrite(A1, 0);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Plase Enter password");
    wrong=0;
    t=0;
    x=0;
    q=0;
  }
}
