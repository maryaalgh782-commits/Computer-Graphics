#include <graphics.h> 
#include <conio.h> 
#include <math.h> 
#include <dos.h> 
void drawLineDDA(int ax, int ay, int bx, int by, int color) { 
    double dx = bx - ax; 
    double dy = by - ay; 
    double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy); 
    double xInc = dx / steps; 
    double yInc = dy / steps; 
    double x = ax, y = ay; 
 
    for (int i = 0; i <= steps; i++) { 
        putpixel((int)(x + 0.5), (int)(y + 0.5), color); 
        x += xInc; 
        y += yInc; 
    } 
} 
 
void drawCircleMidpoint(int xCenter, int yCenter, int radius, int color) { 
    int x = 0; 
    int y = radius; 
    int f = 1 - radius; 
 
    while (x <= y) { 
        putpixel(xCenter + x, yCenter + y, color); 
        putpixel(xCenter - x, yCenter + y, color); 
        putpixel(xCenter + x, yCenter - y, color); 
        putpixel(xCenter - x, yCenter - y, color); 
        putpixel(xCenter + y, yCenter + x, color); 
        putpixel(xCenter - y, yCenter + x, color); 
        putpixel(xCenter + y, yCenter - x, color); 
        putpixel(xCenter - y, yCenter - x, color); 
        x++; 
        if (f < 0) { 
            f += 2 * x + 1; 
        } else { 
            y--; 
            f += 2 * (x - y) + 1; 
        } 
    } 
} 
 
void drawObjects() { 
    setcolor(YELLOW); 
    drawCircleMidpoint(520, 80, 40, YELLOW); 
    setfillstyle(SOLID_FILL, YELLOW); 
    floodfill(520, 80, YELLOW); 
 
    setfillstyle(SOLID_FILL, WHITE); 
    setcolor(WHITE); 
    fillellipse(150, 100, 40, 20); 
    fillellipse(180, 90, 50, 30); 
    fillellipse(210, 100, 40, 20); 
 
    fillellipse(400, 110, 35, 18); 
    fillellipse(430, 100, 45, 25); 
    fillellipse(460, 110, 35, 18); 
} 
 
void drawShip(int x, int y) { 
    int body[] = { 
        x - 90, y + 25, 
        x + 90, y + 25, 
        x + 60, y + 65, 
        x - 60, y + 65, 
        x - 90, y + 25 
    }; 
 
    setcolor(BROWN); 
    setfillstyle(SOLID_FILL, BROWN); 
    fillpoly(5, body); 
 
    setcolor(DARKGRAY); 
    drawLineDDA(x - 90, y + 25, x + 90, y + 25, DARKGRAY); 
    drawLineDDA(x + 90, y + 25, x + 60, y + 65, DARKGRAY); 
    drawLineDDA(x + 60, y + 65, x - 60, y + 65, DARKGRAY); 
    drawLineDDA(x - 60, y + 65, x - 90, y + 25, DARKGRAY); 
 
    setcolor(WHITE); 
    drawLineDDA(x, y + 25, x, y - 60, WHITE); 
 
    int leftSail[] = { 
        x, y - 55, 
        x, y + 20, 
        x - 70, y + 20, 
        x, y - 55 
    }; 
    setfillstyle(SOLID_FILL, WHITE); 
    fillpoly(4, leftSail); 
 
    int rightSail[] = { 
        x + 5, y - 50, 
        x + 5, y + 20, 
        x + 80, y + 20, 
        x + 5, y - 50 
    }; 
    setfillstyle(SOLID_FILL, LIGHTGRAY); 
    fillpoly(4, rightSail); 
 
    setcolor(YELLOW); 
    setfillstyle(SOLID_FILL, YELLOW); 
    fillellipse(x - 35, y + 43, 7, 7); 
    fillellipse(x, y + 43, 7, 7); 
    fillellipse(x + 35, y + 43, 7, 7); 
} 
 
int main() { 
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 
    int shipX = 0; 
 
    while (!kbhit()) { 
        cleardevice(); 
 
        setbkcolor(11); 
        setcolor(WHITE); 
        rectangle(0, 220, 640, 360); 
        setfillstyle(SOLID_FILL, 6); 
        floodfill(10, 300, WHITE); 
 
        setcolor(BLUE); 
        rectangle(0, 360, 640, 480); 
        setfillstyle(SOLID_FILL, BLUE); 
        floodfill(10, 400, BLUE); 
 
        setcolor(WHITE); 
        line(0, 360, 640, 360); 
 
        for (int x = 20; x < 620; x += 80) { 
            line(x, 400, x + 20, 390); 
            line(x + 20, 390, x + 40, 400); 
            line(x + 40, 400, x + 60, 390); 
            line(x + 60, 390, x + 80, 400); 
        } 
 
        drawObjects(); 
        drawShip(shipX, 375); 
 
        shipX += 5; 
        if (shipX > 740) shipX = -100; 
 
        delay(50); 
    } 
 
    closegraph(); 
    return 0; 
}