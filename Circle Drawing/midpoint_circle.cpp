#include <graphics.h>

void drawCircleMidpoint(int Cx, int Cy, int radius)
{
  int x = 0;
  int y = radius;
  int p = 1 - radius;

  while (x <= y)
  {
    putpixel(Cx + x, Cy + y, RED);
    putpixel(Cx + y, Cy + x, YELLOW);
    putpixel(Cx - x, Cy + y, GREEN);
    putpixel(Cx - y, Cy + x, BLUE);
    putpixel(Cx + x, Cy - y, WHITE);
    putpixel(Cx + y, Cy - x, WHITE);
    putpixel(Cx - x, Cy - y, WHITE);
    putpixel(Cx - y, Cy - x, WHITE);

    if (p < 0)
      p += 2 * x + 3;
    else
    {
      p += 2 * (x - y) + 5;
      y--;
    }
    x++;
  }
}

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  int Cx = 200;
  int Cy = 200;
  int radius = 100;

  drawCircleMidpoint(Cx, Cy, radius);

  delay(5000);
  closegraph();
  return 0;
}
