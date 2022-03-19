#include <kipr/wombat.h>
void SERVO_RIGHT();
void SERVO_LEFT();
void WIPES();
void DECAPITATERUP();
void DECAPITATERDOWN();
int main()
{
    create_connect();
    DECAPITATERUP();
    msleep(1000);
    create_drive_direct(-100,-100);
    msleep(10);
    DECAPITATERDOWN();
    create_drive_direct(100,100);
    msleep(10);
    //  create_drive_direct(100,-100);
   // msleep(10);
    DECAPITATERUP();
    msleep(1000);
   // create_drive_direct(-100,-100);
   // msleep(10);
    create_disconnect();
        return 0;
}
void SERVO_RIGHT()
{
    int stepper=0;
     enable_servos();
    while (stepper<1453)
    {
       
        set_servo_position(0,stepper);
        stepper=stepper+10;
        msleep(20);
    }
     disable_servos();
}
void SERVO_LEFT()
{
    int stepper=1453;
      enable_servos();
    while (stepper>296)
    {
        enable_servos();
        set_servo_position(0,stepper);
        stepper=stepper-10;
        msleep(20);
        
    }
    disable_servos();
}
void WINDSHEILDWIPPERYAY()
{
    int winddd=0;
    while (winddd<2)
    {
        SERVO_LEFT();
        SERVO_RIGHT();
        winddd=winddd+1;
    }
}
void DECAPITATERDOWN()
{
int steper=1694;
    enable_servos();
    while(steper<2046)
    {
        set_servo_position(1,steper);
        steper=steper+50;
        msleep(100);
    }
        disable_servos();                   
}
void DECAPITATERUP()
{
int steper=2046;
    enable_servos();
    while(steper>1694)
    {
        set_servo_position(1,steper);
        steper=steper-50;
        msleep(100);
    }
        disable_servos();                   
}
void WIPES()
{  
    SERVO_RIGHT();
   SERVO_LEFT();
}
    
    