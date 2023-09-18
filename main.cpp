#include "TXLib.h"

int main()
{
    txCreateWindow (800, 600);

    //Небо
    txSetColor (TX_LIGHTBLUE);
    txSetFillColor (TX_LIGHTBLUE);
    txRectangle (0, 0, 800, 600);

    //Земля
    txSetColor (TX_GREEN);
    txSetFillColor (TX_GREEN);
    txRectangle (0, 420, 800, 600);

    //Солнце
    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txCircle (150, 100, 50);

    //Дом
    txSetColor (TX_BROWN, 5);
    txSetFillColor (TX_BROWN);
    txRectangle (300,300,550,500);   //Стена
    txSetColor (TX_YELLOW, 5);
    txSetFillColor (TX_YELLOW);
    POINT krysha[3] = {{300, 300}, {425, 200}, {550, 300}};//Крыша
    txPolygon (krysha, 3);
    txSetColor (TX_YELLOW, 5);
    txSetFillColor (TX_YELLOW);
    txRectangle (330,360,400,420);    //Окно
    txSetColor (TX_YELLOW, 5);
    txSetFillColor (TX_YELLOW);
    txRectangle (440,360,500,480);    //Дверь

    //Самокат
    txSetColor (TX_BLACK, 5);
    txSetFillColor (TX_GREEN);
    txCircle (100, 530, 20);
    txCircle (200, 530, 20);
    txLine(120, 530, 180, 530);
    txLine(170, 470, 190, 510);
    txLine(150, 470, 180, 470);

    //Облако
    txSetColor (TX_BLUE, 3);
    txSetFillColor (TX_BLUE);
    txEllipse (400, 50, 540, 130);
    txEllipse (500, 40, 640, 140);
    txEllipse (600, 60, 750, 140);

    //Дерево
    txSetColor (TX_BROWN, 3);
    txSetFillColor (TX_BROWN);
    txRectangle (650,360,670,440);
    txSetColor (TX_GREEN, 3);
    txSetFillColor (TX_GREEN);
    txEllipse (640, 260, 680, 400);

txTextCursor (false);
return 0;
}

