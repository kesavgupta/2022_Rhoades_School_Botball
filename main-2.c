#include <kipr/wombat.h>

int main()
{
    int STAGE = 1;
    int ss = 0;
    // servo steps
    int sp = 1900;
    //servo poststion
    int rc = 0;
    // range count
    //set to starting pos
    enable_servos();
    set_servo_position(0,1900);
    set_servo_position(1,1100);
    set_servo_position(2,801);
    msleep(150);
    disable_servos();
    //stop at ring


    motor(2,30);
    motor(3,30);
    msleep(1000);

    motor(2,0);
    motor(3,0);
    msleep(400);
    STAGE = 2;



    if(STAGE==2)
    {

        // move forward
        motor(2,30);
        motor(3,30);
        msleep(1000);


        STAGE = 3;
    }
    // turn
    while(STAGE == 3)
    {

        motor(2,30);  
        motor(3,-30);
        msleep(2700);
        motor(2,0);  //
        motor(3,0);
        msleep(100);
        motor(2,40);
        motor(3,40);
        msleep(200);
        STAGE = 4;

    }

    // forward

    if(STAGE == 4) //
    {
        motor(2,40);
        motor(3,40);
        msleep(9000);
        // revrse + line up
        motor(2,-40);
        motor(3,-40);
        msleep(2500);
        motor(2,40);
        motor(3,-40);
        msleep(3000);
        motor(2,-40);
        motor(3,-40);
        msleep(2700);
        STAGE = 5;
    }
    while(STAGE == 5)
    {
        enable_servos();
        set_servo_position(1,1450);
        set_servo_position(2,520);
        msleep(150);
        disable_servos();
        STAGE = 6;
    }
    // finding range stage
    while(STAGE == 6)
    {
        if(49>=rc || rc >=0)
        {
            motor(2,-10);
            motor(3,-10);
            if(analog(0)>1500)
            {
                motor(2,-10);
                motor(3,-10);
                msleep(200);
                STAGE = 7;
            }
            else
            {
                rc = rc + 1;
                msleep(30);
            }
        }
        if(rc>= 50)
        {
            motor(2,10);
            motor(3,10);
            if(analog(0)>1500)
            {
                motor(2,10);
                motor(3,10);
                msleep(300);
                STAGE = 7;
            }
            else
            {
                rc = rc - 1;
                msleep(5);
            }
        }
    }
    if(STAGE == 7)
    {
        motor(2,0);
        motor(3,0);
        msleep(10);
        enable_servos();
        set_servo_position(1,1600);
        set_servo_position(2,601);
        msleep(1150);
        while(ss < 41)
        {
            ss = ss + 1;
            sp = sp - 20;
            set_servo_position(0,sp);
            msleep(20);
        }
        set_servo_position(0,1097);
        msleep(550);
        set_servo_position(1,1005);
        set_servo_position(2,1103);
        msleep(150);
        disable_servos();
         set_servo_position(0,1300);
        msleep(550);
    }



    printf("Hello World\n");
    return 0;
}
