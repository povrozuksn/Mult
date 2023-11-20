#include "TXLib.h"

void drawSkyDay()
{
    //Небо
    txSetColor (RGB(106, 230, 230));
    txSetFillColor (RGB(106, 230, 230));
    txRectangle (0, 0, 800, 600);
}

void drawSkyNight()
{
    //Небо
    txSetColor (RGB ( 0, 0, 0));
    txSetFillColor (RGB ( 0, 0, 0));
    txRectangle (0, 0, 800, 600);
}

void drawLand()
{
    //Земля
    txSetColor (TX_GREEN);
    txSetFillColor (TX_GREEN);
    txRectangle (0, 420, 800, 600);
}

void drawSun(int x, int y, float razm)
{
    //Солнце
    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txCircle (x, y, 50*razm);
}

void drawHouse(int x, float razm, int xDver, int yDver, COLORREF colorWin)
{
    //Дом x= 300
    txSetColor (TX_RED, 3);
    txSetFillColor (RGB(150, 100, 60));
    txRectangle (x,300*razm,x+250*razm,500*razm);   //Стена
    txSetFillColor (RGB(200, 200, 10));
    POINT krysha[3] = {{x, 300*razm}, {x+125*razm, 200*razm}, {x+250*razm, 300*razm}};//Крыша
    txPolygon (krysha, 3);
    txSetFillColor (colorWin);
    txRectangle (x+30*razm,360*razm,x+100*razm,420*razm);    //Окно
    txSetFillColor (TX_YELLOW);
    txRectangle (x+140*razm,360*razm,x+200*razm,480*razm);    //Проем
    txSetFillColor (RGB(75, 75, 37));
    POINT dver[4] = {{x-300+xDver, yDver}, {x+200*razm, 360*razm}, {x+200*razm, 480*razm}, {x-300+xDver*razm, yDver+120*razm}};
    txPolygon (dver, 4);//Дверь
}

void drawBike(int x, double a)
{
    //Самокат
    int x1, y1, x2, y2, x3, y3;

    txSetColor (RGB ( 0, 0, 0), 5);
    txSetFillColor (TX_GREEN);
    txCircle (x, 530, 20);         //колесо заднее
    txCircle (x+100, 530, 20);     //колесо переднее

    x1=x+20*cos((a)*3.14/180);
    y1=530+20*sin((a)*3.14/180);
    x2=x+20*cos((a+120)*3.14/180);
    y2=530+20*sin((a+120)*3.14/180);
    x3=x+20*cos((a+240)*3.14/180);
    y3=530+20*sin((a+240)*3.14/180);

    txLine(x,530,x1,y1);
    txLine(x,530,x2,y2);
    txLine(x,530,x3,y3);

    txLine(x+100,530,x1+100,y1);
    txLine(x+100,530,x2+100,y2);
    txLine(x+100,530,x3+100,y3);

    txLine(x+20, 530, x+80, 530);
    txLine(x+70, 470, x+90, 510);
    txLine(x+50, 470, x+80, 470);
}

void drawCloud(int x)
{
    //Облако
    txSetColor (TX_BLUE, 3);
    txSetFillColor (TX_BLUE);
    txEllipse (x+400-400, 50, x+540-400, 130);
    txEllipse (x+500-400, 40, x+640-400, 140);
    txEllipse (x+600-400, 60, x+750-400, 140);
}

void drawTree(int x)
{
    //Дерево
    txSetColor (TX_BROWN, 3);
    txSetFillColor (TX_BROWN);
    txRectangle (x+650-650,360,x+670-650,440);
    txSetColor (RGB(104, 253, 108), 3);
    txSetFillColor (RGB(104, 253, 108));
    txEllipse (x+640-650, 260, x+680-650, 400);
}

void drawForest()
{
    for(int x = 50; x<=750; x+=50)
    {
        drawTree(x);
    }

}

void drawFlyer(HDC flyer, int x)
{
    txTransparentBlt (txDC(), x, 20, 200, 76, flyer, 0, 0, TX_WHITE);
}

void drawMan(int x, int y, int xRightNoga, int xLeftNoga, float razm, COLORREF Color)
{
    txSetColor (Color, 3);
    txSetFillColor (Color);
    txCircle (x, y-30*razm, 20*razm);       //голова
    txLine(x, y-10*razm, x,                    y+50*razm);    //тело
    txLine(x, y,         x-20*razm,            y+30*razm);    //правая рука
    txLine(x, y,         x+20*razm,            y+30*razm);    //левая рука
    txLine(x, y+50*razm, x-20*razm+xRightNoga, y+80*razm);    //правая нога
    txLine(x, y+50*razm, x+20*razm+xLeftNoga,  y+80*razm);    //левая нога
}

void drawDialog(int x, int y, const char* text, COLORREF Color)
{

    txSetColor(TX_WHITE);
    txSetFillColor(Color);
    txSelectFont ("Comic Sans MS", 20);
    txEllipse (x, y, x+100, y+50);
    txCircle(x+75, y+45, 10);
    txCircle(x+85, y+50, 5);
    txDrawText (x, y, x+100, y+50, text);


}

void drawTitle(int y, float razm, const char* text)
{
    txSetColor(TX_WHITE);
    txSetFillColor(TX_BLACK);
    txSelectFont("Comic Sans MS", razm);
    txDrawText(0, y, 800, y+100, text);
}

int main()
{
    txCreateWindow (800, 600);

    HDC flyerRight  = txLoadImage ("самолетRight.bmp");
    HDC flyerLeft  = txLoadImage ("самолетLeft.bmp");
    int xFlyer = 0;
    int xSun = 150;
    int ySun = 100;
    float razmSun = 1;
    int xHouse = 300;
    float razmHouse = 1;
    int xDver = 440;
    int yDver = 360;
    float razmMan = 0.5;
    int xCloud = 400;
    int xBike = 100;
    double aBike = 0;
    int xMan = 460;
    int yMan = 430;
    int xManRightNoga = 0;
    int xManLeftNoga = 0;
    int yTitle = 650;
    float razmTitle = 10;

    while(yTitle > 250)
    {
        txBegin();
        //txRectangle (0, 0, 800, 600);
        drawTitle(yTitle, razmTitle, "НОЧНАЯ ПРОГУЛКА");
        yTitle -= 2;
        txEnd();
        txSleep(10);
    }
    while(razmTitle < 80)
    {
        txBegin();
        txRectangle (0, 0, 800, 600);
        drawTitle(yTitle, razmTitle, "НОЧНАЯ ПРОГУЛКА");
        razmTitle += 1;
        txEnd();
        txSleep(10);
    }
    while(razmTitle > 10)
    {
        txBegin();
        txRectangle (0, 0, 800, 600);
        drawTitle(yTitle, razmTitle, "НОЧНАЯ ПРОГУЛКА");
        razmTitle -= 1;
        txEnd();
        txSleep(10);
    }
    while(yTitle > -50)
    {
        txBegin();
        //txRectangle (0, 0, 800, 600);
        drawTitle(yTitle, razmTitle, "НОЧНАЯ ПРОГУЛКА");
        yTitle -= 2;
        txEnd();
        txSleep(10);
    }

    //Солнце заходит
    while(xSun<950)
    {
        txBegin();
        drawSkyDay();
        drawSun(xSun, ySun, razmSun);
        drawLand();
        drawForest();
        drawHouse(xHouse, 1, xDver, yDver, RGB(100, 100, 100));
        drawBike(xBike, aBike);
        drawCloud(xCloud);
        drawFlyer(flyerRight, xFlyer);


        xSun += 5;
        ySun += 2;
        xFlyer += 5;
        txEnd();
        txSleep(10);
    }

    //Наступает ночь
    while(xDver<500)
    {
        txBegin();
        drawSkyNight();
        drawLand();
        drawSun(xSun, ySun, razmSun);
        drawForest();
        drawHouse(xHouse, 1, xDver, yDver, TX_YELLOW);
        drawBike(xBike, aBike);
        drawCloud(xCloud);

        xCloud -= 5;
        xFlyer -= 5;
        xDver += 1;
        yDver += 1;
        txEnd();
        txSleep(10);
    }

    while(razmMan<1)
    {
        txBegin();
        drawSkyNight();
        drawSun(xSun, ySun, razmSun);
        drawLand();
        drawForest();
        drawHouse(xHouse, razmHouse, xDver, yDver, TX_YELLOW);
        drawBike(xBike, aBike);
        drawCloud(xCloud);
        drawMan(xMan, yMan, xManRightNoga, xManLeftNoga, razmMan, RGB(222, 186, 100));

        razmMan += 0.005;
        txEnd();
        txSleep(10);
    }

    while(xMan>400)
    {
        txBegin();
        drawSkyNight();
        drawSun(xSun, ySun, razmSun);
        drawLand();
        drawForest();
        drawHouse(xHouse, razmHouse, xDver, yDver, TX_YELLOW);
        drawBike(xBike, aBike);
        drawCloud(xCloud);
        drawMan(xMan, yMan, random(30), random(20), razmMan, RGB(222, 186, 100));

        drawDialog(xMan-100, yMan-100,"Привет", RGB(222, 186, 100));

        xMan -= 2;
        txEnd();
        txSleep(10);
    }

    while(xDver>440)
    {
        txBegin();
        drawSkyNight();
        drawSun(xSun, ySun, razmSun);
        drawLand();
        drawForest();
        drawHouse(xHouse, razmHouse, xDver, yDver, TX_YELLOW);
        drawBike(xBike, aBike);
        drawCloud(xCloud);
        drawMan(xMan, yMan, random(30), random(20), razmMan, RGB(222, 186, 100));
        drawDialog(xMan-100, yMan-100,"Я иду", RGB(222, 186, 100));

        xDver -= 1;
        yDver -= 1;
        xMan -= 2;
        txEnd();
        txSleep(10);
    }

    while(xMan>150)
    {
        txBegin();
        drawSkyNight();
        drawSun(xSun, ySun, razmSun);
        drawLand();
        drawForest();
        drawHouse(xHouse, razmHouse, xDver, yDver, TX_YELLOW);
        drawBike(xBike, aBike);
        drawCloud(xCloud);
        drawMan(xMan, yMan, random(30), random(20), razmMan, RGB(222, 186, 100));
        drawDialog(xMan-100, yMan-100,"Я пришел", RGB(222, 186, 100));

        xMan -= 2;
        txEnd();
        txSleep(10);
    }

    while(yMan<460)
    {
        txBegin();
        drawSkyNight();
        drawSun(xSun, ySun, razmSun);
        drawLand();
        drawForest();
        drawHouse(xHouse, razmHouse, xDver, yDver, TX_YELLOW);
        drawBike(xBike, aBike);
        drawCloud(xCloud);
        drawMan(xMan, yMan, xManRightNoga, xManLeftNoga, razmMan, RGB(222, 186, 100));

        yMan += 5;
        txEnd();
        txSleep(10);
    }

    while(xBike<1000)
    {
        txBegin();
        drawSkyNight();
        drawLand();
        drawSun(xSun, ySun, razmSun);
        drawForest();
        drawHouse(xHouse, 1, xDver, yDver, TX_YELLOW);
        drawBike(xBike, aBike);
        drawCloud(xCloud);
        drawMan(xMan, yMan, random(30), random(20), razmMan, RGB(222, 186, 100));

        xBike += 5;
        xMan = xBike + 50;
        aBike=aBike+5;
        txEnd();
        txSleep(10);
    }

    xBike = -300;
    while(xBike<500)
    {
        txBegin();
        drawSkyNight();
        drawLand();
        drawForest();
        drawBike(xBike, aBike);
        drawMan(xMan, yMan, random(30), random(20), razmMan, RGB(222, 186, 100));
        drawDialog(xMan-100, yMan-100,"УРААА!!!", RGB(222, 186, 100));

        drawMan(700, yMan, 0, 0, razmMan, RGB(40, 128, 156));

        xBike += 5;
        xMan = xBike + 50;
        aBike=aBike+5;
        txEnd();
        txSleep(10);
    }

    drawSkyNight();
    drawLand();
    drawForest();
    drawBike(xBike, aBike);
    drawMan(xMan, yMan, 0, 0, razmMan, RGB(222, 186, 100));
    drawMan(700, yMan, 0, 0, razmMan, RGB(40, 128, 156));
        txSleep(2000);

    drawSkyNight();
    drawLand();
    drawForest();
    drawBike(xBike, aBike);
    drawMan(xMan, yMan, 0, 0, razmMan, RGB(222, 186, 100));
    drawMan(700, yMan, 0, 0, razmMan, RGB(40, 128, 156));
    drawDialog(xMan-100, yMan-100,"Привет!!!", RGB(222, 186, 100));
        txSleep(2000);

    drawSkyNight();
    drawLand();
    drawForest();
    drawBike(xBike, aBike);
    drawMan(xMan, yMan, 0, 0, razmMan, RGB(222, 186, 100));
    drawMan(700, yMan, 0, 0, razmMan, RGB(40, 128, 156));
        txSleep(2000);

    drawSkyNight();
    drawLand();
    drawForest();
    drawBike(xBike, aBike);
    drawMan(xMan, yMan, 0, 0, razmMan, RGB(222, 186, 100));
    drawMan(700, yMan, 0, 0, razmMan, RGB(40, 128, 156));
    drawDialog(600, yMan-100,"УРААА!!!", RGB(40, 128, 156));
        txSleep(2000);

    yTitle = 650;
    while(yTitle > -500)
    {
        txBegin();
        txRectangle (0, 0, 800, 600);
        drawTitle(yTitle,    20, "Автор  - ");
        drawTitle(yTitle+50, 20, "Сценарий  - ");
        drawTitle(yTitle+100, 20, "Режисер  - ");
        drawTitle(yTitle+150, 20, "Жудожник-постановщик  - ");
        yTitle -= 2;
        txEnd();
        txSleep(10);
    }

    txDeleteDC (flyerRight);
    txDeleteDC (flyerLeft);

txTextCursor (false);
return 0;
}

