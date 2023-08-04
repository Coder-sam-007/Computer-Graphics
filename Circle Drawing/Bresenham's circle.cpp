#include <graphics.h>

void DrawBresenhamCircle(int xc, int yc, int radius)
{
  int x = 0;
  int y = radius;
  int d = 3 - 2 * radius;

  while (x <= y)
  {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc + y, yc + x, RED);
    putpixel(xc - x, yc + y, RED);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + x, yc - y, GREEN);
    putpixel(xc + y, yc - x, GREEN);
    putpixel(xc - x, yc - y, CYAN);
    putpixel(xc - y, yc - x, CYAN);

    if (d <= 0)
      d = d + 4 * x + 6;
    else
    {
      d = d + 4 * (x - y) + 10;
      y--;
    }
    x++;
  }
}

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  int xc = 200, yc = 200;
  int radius = 100;

  DrawBresenhamCircle(xc, yc, radius);

  delay(5000);
  closegraph();
  return 0;
}
