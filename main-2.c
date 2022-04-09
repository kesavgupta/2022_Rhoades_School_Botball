#include <kipr/wombat.h>

int main()
{
    int COUNTER=0;

    create_connect();
    while(analog(0)<3400) 
    {create_drive_direct(100,100);} //drive until robot sees black tape
    create_drive_direct(500,500);
    msleep(200);
    while(analog(0)<3400)
    {create_drive_direct(100,0);} //pivot CW WHILE right sensorsees black tape
    while(analog(1)<3400)
    {create_drive_direct(100,0);}//pivot clockwise until left sensor sees black tape
    while(COUNTER<1000)
    {
        if(analog(1)>3400)
        {
            create_drive_direct(20,100);
        }
        else
        {
            create_drive_direct(100,20);
        }
        COUNTER=COUNTER +1;
    }
    COUNTER=0;
     while(COUNTER<7000)
    {
        if(analog(0)>3400)
        {
            create_drive_direct(100,20);
        }
        else
        {
            create_drive_direct(20,100);
        }
        COUNTER=COUNTER +1;
    }
 
    /*create_drive_direct(50,-50); //spin CW for some amt of time
    msleep(100);*/
    

    /* create_drive_direct(0,-100);
        msleep(2800);
        create_drive_direct(-500,-500);
        msleep(3400);
        create_drive_direct(-100,-100);
        msleep(2000);
    //1Pivot conterclockwise to avoid seeing black tape for _ time//
    //2Pivot CCW while analog(0)<4000
    //2aDrive straightfor short amt of time//
    //3Drive forward while analog(0)<4000*/
    
    create_stop();
    create_disconnect();

    return(0);
}
