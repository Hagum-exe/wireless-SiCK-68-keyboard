#include <Keypad.h>
#include <BleKeyboard.h>


const byte ROWS = 5; //four rows
const byte COLS = 15; //three columns
char keys[ROWS][COLS] = {
  {'E', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'B', '`'},
  {'T', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 'H', 'D'},  //H=SLASH
  {'C', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', 'L', ' ',  'N', 'M'},
  {'S', ' ', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 'S', 'U', 'R'},
  {'O', 'W', 'A', ' ', ' ', ' ', 'P', ' ', ' ', 'V', 'Y', 'F', '<', '!', '>'}   //V-PREVIOUS, Y-prntscreen
};
byte rowPins[ROWS] = {13, 12, 14, 27, 26}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {25 ,33, 32, 15, 2, 0, 4, 16, 17, 5, 18, 19, 21, 22, 23}; //connect to the column pinouts of the keypad

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

BleKeyboard bleKeyboard("SICK68-HAGUM", "Blough", 69);

//unsigned long loopCount;
//unsigned long startTime;
//String msg;


void setup() {
    
    Serial.begin(9600);
    bleKeyboard.begin();
    
}


  

void loop() {
   
   if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            
               if (kpd.key[i].kstate==1){

                switch(kpd.key[i].kchar){

                  case'E':
                    bleKeyboard.press(KEY_ESC);
                    break;


                  case'B':
                    bleKeyboard.press(KEY_BACKSPACE);
                    break;
                  
                  case'T':
                    bleKeyboard.press(KEY_TAB);
                    break;
                  
                  case'H':
                    bleKeyboard.press(92);
                    break;

                  case'D':
                    
                    bleKeyboard.press(KEY_DELETE);
                    break;

                  case'C':
                    bleKeyboard.press(KEY_CAPS_LOCK);
                    break;

                  case'L':
                    bleKeyboard.press(39);
                    break;

                  case'N':
                    bleKeyboard.press(KEY_RETURN);
                    break;

                  //case'F':
                    //bleKeyboard.press(KEY_LEFT_GUI);
                    //bleKeyboard.press(32);
                    //bleKeyboard.print("act");
                    //bleKeyboard.press(KEY_RETURN);
                    //bleKeyboard.release(KEY_LEFT_GUI);
                    //bleKeyboard.release(32);
                    //bleKeyboard.release(KEY_RETURN);
                    //break;

                  case'M':
                    bleKeyboard.press(KEY_LEFT_GUI);
                    bleKeyboard.press(',');
                    bleKeyboard.release(KEY_LEFT_GUI);
                    bleKeyboard.release(',');
                    break;
                    
    

                  
                  case'S':
                    bleKeyboard.press(KEY_RIGHT_SHIFT);
                    break;

                  case'U':
                    bleKeyboard.press(KEY_UP_ARROW);
                    break;

                  case'R':
                    bleKeyboard.press(KEY_END);
                    break;

                  case'O':
                    bleKeyboard.press(KEY_LEFT_GUI);
                    break;

                  case'W':
                     bleKeyboard.press(KEY_LEFT_GUI);
                     bleKeyboard.press(32);
                     bleKeyboard.release(KEY_LEFT_GUI);
                     bleKeyboard.release(32);
                     break;

                  case'A':
                    bleKeyboard.press(KEY_LEFT_ALT);
                    break;

                  case'P':
                    bleKeyboard.press(32);
                    break;

                  case'V':
                    bleKeyboard.press(KEY_LEFT_GUI);
                    bleKeyboard.press('z');
                     bleKeyboard.release(KEY_LEFT_GUI);
                    bleKeyboard.release('z');
                    break;

                  case'Y':
                    bleKeyboard.press(KEY_LEFT_GUI);
                    bleKeyboard.press(KEY_LEFT_SHIFT);
                    bleKeyboard.press('4');
                    bleKeyboard.release(KEY_LEFT_GUI);
                    bleKeyboard.release(KEY_LEFT_SHIFT);
                    bleKeyboard.release('4');
                    break;

                  case'F':
                    bleKeyboard.press(KEY_LEFT_GUI);
                    bleKeyboard.press(KEY_LEFT_SHIFT);
                    bleKeyboard.press('z');
                    bleKeyboard.release(KEY_LEFT_GUI);
                    bleKeyboard.release(KEY_LEFT_SHIFT);
                    bleKeyboard.release('z');
                    break;

                  case'<':
                    bleKeyboard.press(KEY_LEFT_ARROW);
                    break;

                  case'!':
                    bleKeyboard.press(KEY_DOWN_ARROW);
                    break;

                  case'>':
                    bleKeyboard.press(KEY_RIGHT_ARROW);
                    break;

                  default:
                    bleKeyboard.press(kpd.key[i].kchar);
                    break;

                    
                  
                  
                  }
                }

                  
                
                
                
               else if (kpd.key[i].kstate==0){
                 switch(kpd.key[i].kchar){

                  case'E':
                    bleKeyboard.release(KEY_ESC);
                    break;


                  case'B':
                    bleKeyboard.release(KEY_BACKSPACE);
                    break;

                  case'T':
                    bleKeyboard.release(KEY_TAB);
                    break;

                  case'H':
                    bleKeyboard.release(92);
                    break;

                   case'D':
                    
                    bleKeyboard.release(KEY_DELETE);
                    break;

                  case'C':
                    bleKeyboard.release(KEY_CAPS_LOCK);
                    break;

                  case'L':
                    bleKeyboard.release(39);
                    break;

                  case'N':
                    bleKeyboard.release(KEY_RETURN);
                    break;

                  //case'F':
                    //bleKeyboard.release(KEY_LEFT_GUI);
                    //bleKeyboard.release(32);
                    //bleKeyboard.write("activity monitor");
                    //bleKeyboard.release(KEY_RETURN);
                    //break;

                  case'S':
                    bleKeyboard.release(KEY_RIGHT_SHIFT);
                    break;

                  case'U':
                    bleKeyboard.release(KEY_UP_ARROW);
                    break;

                  case'R':
                    bleKeyboard.release(KEY_END);
                    break;

                  case'O':
                    bleKeyboard.release(KEY_LEFT_GUI);
                    break;

                  

                  case'A':
                    bleKeyboard.release(KEY_LEFT_ALT);
                    break;

                  case'P':
                    bleKeyboard.release(32);
                    break;


                  case'<':
                    bleKeyboard.release(KEY_LEFT_ARROW);
                    break;

                  case'!':
                    bleKeyboard.release(KEY_DOWN_ARROW);
                    break;

                  case'>':
                    bleKeyboard.release(KEY_RIGHT_ARROW);
                    break;



                  
                  default:
                    bleKeyboard.release(kpd.key[i].kchar);
                    break;

                    
                  
                  
                  }
                }
                        

                    
                
                
                }
                
                }
                
                }
