#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void DDA(int type, int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0;
    int dy = y1 - y0;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xin = dx / float(steps);
    float yin = dy / float(steps);

    float x = x0;
    float y = y0;
    for (int i = 0; i <= steps; i++)
    {
        putpixel(x, y, 14);
        if (type == 1)
        {
            putpixel(x + 35, y, 14);
            putpixel(x + 70, y, 14);
            delay(10);
        }
        else
            delay(5);
        x += xin;
        y += yin;
    }
}

void drawArrows(int side, int num)
{
    int h = 55, t = 1;
    int x, y, x2, y2, lx, ly, rx, ry;
    if (side == 1)
    {
        x = 245;
        y = num*100 - 30;
    }
    else
    {
        t = -1;
        x = 795;
        y = num*100 - 30 + h;
    }

    x2 = x;
    y2 = y + (t * h);
    lx = x2 - 10;
    rx = x2 + 10;
    ly = y2 - (t * 10);
    ry = ly;

    DDA(1, x, y, x2, y2);
    setcolor(14);
    line(lx, ly, x2, y2);
    line(rx, ry, x2, y2);
    line(lx + 35, ly, x2 + 35, y2);
    line(rx + 35, ry, x2 + 35, y2);
    delay(300);
    setcolor(0);
    line(x, y, x2, y2);
    line(x + 35, y, x2 + 35, y2);
    line(lx, ly, x2, y2);
    line(rx, ry, x2, y2);
    line(lx + 35, ly, x2 + 35, y2);
    line(rx + 35, ry, x2 + 35, y2);
    line(lx + 70, ly, x2 + 70, y2);
    line(rx + 70, ry, x2 + 70, y2);
}

void datarect(int side, int color)
{
    int x_init = 210, y_init = 30;
    int ylen = 40;
    int rectx1, rectx2;
    setcolor(WHITE);
    if (side == 2)
    {
        x_init = 760;
    }

    rectx1 = x_init + ylen + 15;
    rectx2 = rectx1 + 80 + color * 6;

    y_init = 30 + 100 * (color - 1);
    rectangle(x_init, y_init, x_init + ylen, y_init + ylen);
    rectangle(rectx1, y_init, rectx2, y_init + ylen);
    
    if(color == 6)
    {
        rectangle(rectx2 + 10, y_init, rectx2 + 10 + ylen, y_init + ylen);
        outtextxy(rectx2 + 18, y_init + 10, "T6");
    }
    
    string s = "H" + to_string(color);
    char* s1 = &s[0];
    outtextxy(x_init + 10, y_init + 10, s1);
    s = "D" + to_string(color);
    outtextxy(rectx1 + 38, y_init + 10, s1);
}
void drawArrowHori(int flag)
{
    if (flag == 0) return;

    int x1 = 400, x2 = 550, y = 650;
    int subx1 = x2 - 10;

    for (int i = 0; i < 3; i++)
    {
        setcolor(14);
        DDA(2, x1, y, x2, y);
        line(subx1, y - 10, x2, y);
        line(subx1, y + 10, x2, y);
        delay(300);
        if (i == 2)
            break;
        setcolor(0);
        line(x1, y, x2, y);
        line(subx1, y - 10, x2, y);
        line(subx1, y + 10, x2, y);
    }
}
int main()
{

    initwindow(1500, 1500);
    int h = 60, w = 150;
    int c, side = 1, flag = 1;
    settextstyle(3, 0, 2);
    outtextxy(60, 5, (char*)"SENDER");
    outtextxy(600, 5, (char*)"RECIEVER");
    setcolor(WHITE);
    settextstyle(3, 0, 1);
    char* s[7] ={"Application","Presentation","Session","Transport",
                    "Network","Data Link","Physical"};
    //SENDER SIDE
    for(int i=0;i<7;i++)
    {
        rectangle(50, 25+100*i, 150, 75+100*i);
        outtextxy(53, 37+100*i, s[i]);
    }

    //RECIEVER SIDE
    for(int i=0;i<7;i++)
    {
        rectangle(600, 25+100*i, 700, 75+100*i);
        outtextxy(603, 37+100*i, s[i]);
    }

    //TRANSMISSION MODE
    for (int i = 1; i < 15; i++){
        if (i > 7){
            c = 15 - i;
            side = 2;
        }
        else
            c = i;

        datarect(side, c);
        delay(100);
        if (c == 7){
            drawArrowHori(flag--);
            continue;
        }

        drawArrows(side, c);
    }
    getch();
    closegraph();
}
