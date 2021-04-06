#include <TFT_eSPI.h> 
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI(); 

byte arr[10][5][3]=   
        {
            {
            {1,1,1}, //0
            {1,0,1},
            {1,0,1},
            {1,0,1},
            {1,1,1}
           
            },
              {
            {0,1,0}, //1
            {0,1,0},
            {0,1,0},
            {0,1,0},
            {0,1,0}
           
            },
              {
            {1,1,1}, //2
            {0,0,1},
            {1,1,1},
            {1,0,0},
            {1,1,1}
           
            },
            {
            {1,1,1}, //3
            {0,0,1},
            {1,1,1},
            {0,0,1},
            {1,1,1}
           
            },
            {
            {1,0,1}, //4
            {1,0,1},
            {1,1,1},
            {0,0,1},
            {0,0,1}
           
            },
            {
            {1,1,1}, //5
            {1,0,0},
            {1,1,1},
            {0,0,1},
            {1,1,1}
           
            },
            {
            {1,1,1}, //6
            {1,0,0},
            {1,1,1},
            {1,0,1},
            {1,1,1}
           
            },
            {
            {1,1,1}, //7
            {0,0,1},
            {0,0,1},
            {0,0,1},
            {0,0,1}
           
            },
            {
            {1,1,1}, //8
            {1,0,1},
            {1,1,1},
            {1,0,1},
            {1,1,1}
           
            },
              {
            {1,1,1}, //9
            {1,0,1},
            {1,1,1},
            {0,0,1},
            {1,1,1}
           
            }     
        };

const int pwmFreq = 5000;
const int pwmResolution = 8;
const int pwmLedChannelTFT = 0;


       
void setup(void) {
  Serial.begin(9600);
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  
  ledcSetup(pwmLedChannelTFT, pwmFreq, pwmResolution);
  ledcAttachPin(TFT_BL, pwmLedChannelTFT);
  ledcWrite(pwmLedChannelTFT, 53  );
  
}


short colors[2]={TFT_BLACK,TFT_GREEN};  //first colour is color of background , second is color of digit


int sizee=20;   //size of each box
byte space=8 ; // space between boxes
int fromTop=14;  //positon x
int fromLeft=10;  //position y
int Round=0;
 
 short number=0;
 int digits=0;

void loop() {


String n=String(number);

 
 for(int z=0;z<n.length();z++)
 for(int i=0;i<5;i++)
 for(int j=0;j<3;j++)
   {
    String c=n.substring(z, z+1);
    int b=c.toInt();
    tft.fillRoundRect((z*(sizee*4))+fromLeft+(j*sizee)+(j*space),fromTop+(i*sizee)+(i*space),sizee,sizee,Round,colors[arr[b][i][j]]);
    //delay(20);
   }

 

 delay(400);
 number++;
 
 if(number==100)
 number=0;


}
