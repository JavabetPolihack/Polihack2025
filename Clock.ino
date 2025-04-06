#include "SevSeg.h"
SevSeg sevseg; //Initiate a seven segment controller object
int time=0;
int task=7;


void setup() {
    byte numDigits = 4;  
    byte digitPins[] = {2, 3, 4, 5};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
    bool resistorsOnSegments = 0; 
    // variable above indicates that 4 resistors were placed on the digit pins.
    // set variable to 1 if you want to use 8 resistors on the segment pins.
    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    Serial.begin(9600);
    sevseg.setBrightness(90);
}

int get_time(int time)
{
    int hour=time/60;
    int minute=time%60;
    int rez=0;
    int uh=hour/10;
    int lh=hour%10;
    int um=minute/10;
    int lm=minute%10;
    rez=rez*10+uh;
    rez=rez*10+lh;
    rez=rez*10+um;
    rez=rez*10+lm;
    return rez;
}

void loop() {
    if(time!=0)
    {
        for(int i=1; i<=8; i++)
        {
            sevseg.setNumber(get_time(time), 2);
            sevseg.refreshDisplay();
            delay(1);
        }
        time=time-1;
    }
    Serial.println(time);
    if(time==0)
    {
        if(task==7)
        {
            time=900;
            task--;
        }
        if(task==6)
        {
            time=150;
            task--;
        }
        else if(task==5)
        {
            time=900;
            task--;
        }
        else if(task==4)
        {
            time=150;
            task--;
        }
        else if(task==3)
        {
            time=900;
            task--;
        }
        else if(task==2)
        {
            time=150;
            task--;
        }
        else if(task==1)
        {
            time=900;
            task--;
        }
        else
        {
            for(int i=1; i<=2500; i++)
            {
                sevseg.setNumber(get_time(0),2);
                sevseg.refreshDisplay();
            }
            delay(250);
            time=0;
            int sensorValue = analogRead(A1);
            float voltage=sensorValue * (5.0 / 1023.0);
            if(voltage>3)
            {
                time=900;
                task=6;
            }
        }
    }
}
