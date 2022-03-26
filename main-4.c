#include <kipr/wombat.h>
void SERVO_RIGHT();
void SERVO_LEFT();
void BABYWIPES();
void DECAPITATERUP();
void DECAPITATERDOWN();
void LINESTOP();
int BLACK = 3400;
// line up with black line
int SWITCH = 0;
int POM = 5;
int main()
{
    create_connect();
    DECAPITATERUP();
    msleep(300);
    // bring up DECAPITATER
    LINESTOP();
    // localing to black line
    DECAPITATERDOWN();
    msleep(100);
    // bringing down decapitaer
    create_drive_direct(100,100);
    msleep(1200);
    // to line up backwards before spin palm 3
    create_stop();
    msleep(50);
    // helps to keep stable
    create_drive_direct(50,-50);
    msleep(1200);
    // spin for palm 3
    create_stop();
    msleep(200);
    // helps to keep stable
    DECAPITATERUP();
    // raise for palm 3
    // to stop when hits both lines
    while(analog(0) < BLACK || analog(1) < BLACK)
    {
        create_drive_direct(-40,-50);
    }
    create_stop();
    msleep(200);
    // helps to keep stable

    // driver forward for red palm 3
    create_drive_direct(-100,-100);
    msleep(700);
    create_stop();
    msleep(200);
    // helps to keep stable
    DECAPITATERDOWN();
    // back up for palm 4
    create_drive_direct(100,100);
    msleep(1500);
    //spin for line up
    create_drive_direct(-50,50);
    msleep(1200);
    // line up for horozontal line up
    LINESTOP();
    // go forward for line following
    create_drive_direct(-50,-50);
    msleep(3000);
    // turn for prep line follow
    while(analog(0)<BLACK)
    {
        create_drive_direct(50,-50);
    }
    create_stop();
    msleep(200);
    // for stable
    // bring up for pom 5
    DECAPITATERUP();
    msleep(200);
    // to pass first black line
    create_drive_direct(-50,-50);
    msleep(1500);
    // line follow until second black line
    while(POM == 5)
    {
        if(analog(0) > BLACK)
        {
            create_drive_direct(-50,-30);
            msleep(50);

        }
        else
        {
            create_drive_direct(-30,-50);
            msleep(50);

        }

        if(analog(1) > BLACK)
        {
            // for stable
            create_stop();
            msleep(200);
            POM = 6;
        }
    }
    // to pass second black line and get pom 5
    create_drive_direct(-50,-50);
    msleep(1400);
    //servo left for pom 6
    create_stop();
    msleep(200);
    SERVO_LEFT();
    msleep(100);
    while(POM == 6)
    {
        if(analog(1) > BLACK)
        {
            create_drive_direct(-30,-50);
            SWITCH = SWITCH + 1;
            msleep(50);
        }
        else
        {
            create_drive_direct(-50,-30);
            SWITCH = SWITCH + 1;
            msleep(50);
        }
        if(SWITCH == 5)
        {
            create_stop();
            msleep(6000);
        }
        if(analog(0) > BLACK)
        {
            // for stable
            create_stop();
            msleep(200);
            POM = 6;
        }
    }
    create_disconnect();
    return 0;
}
void LINESTOP()
{
    while(analog(0) < BLACK || analog(1) < BLACK)
    {
        if(analog(0) > BLACK && analog(1) < BLACK)
        {
            create_drive_direct(50,100);

        }
        if(analog(0) < BLACK && analog(1) > BLACK)
        {
            create_drive_direct(50,-50);
        }
        else
        {
            create_drive_direct(-50,-50);
        }
    }
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
void DECAPITATERDOWN()
{
    int steper=1694;
    enable_servos();
    while(steper<2046)
    {
        set_servo_position(0,1305);
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
        set_servo_position(0,1305);
        set_servo_position(1,steper);
        steper=steper-50;
        msleep(100);
    }
    disable_servos();                   
}
void BABYWIPES()
{  
    SERVO_RIGHT();
    SERVO_LEFT();
}

