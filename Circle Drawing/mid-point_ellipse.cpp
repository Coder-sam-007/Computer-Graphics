#include <graphics.h>

void drawEllipseMidpoint(int centerX, int centerY, int rx, int ry)
{
  int x = 0;
  int y = ry;
  int rxSq = rx * rx;
  int rySq = ry * ry;
  int tworxSq = 2 * rxSq;
  int tworySq = 2 * rySq;
  int p;
  int px = 0;
  int py = tworxSq * y;

  // Region 1
  p = rySq - rxSq * ry + 0.25 * rxSq;
  while (px < py)
  {
    putpixel(centerX + x, centerY + y, WHITE);
    putpixel(centerX - x, centerY + y, WHITE);
    putpixel(centerX + x, centerY - y, WHITE);
    putpixel(centerX - x, centerY - y, WHITE);

    x++;
    px += tworySq;

    if (p < 0)
      p += rySq + px;

    else
    {
      y--;
      py -= tworxSq;
      p += rySq + px - py;
    }
  }

  // Region 2
  p = rySq * (x + 0.5) * (x + 0.5) + rxSq * (y - 1) * (y - 1) - rxSq * rySq;
  while (y >= 0)
  {
    putpixel(centerX + x, centerY + y, WHITE);
    putpixel(centerX - x, centerY + y, WHITE);
    putpixel(centerX + x, centerY - y, WHITE);
    putpixel(centerX - x, centerY - y, WHITE);

    y--;
    py -= tworxSq;
    if (p > 0)
      p += rxSq - py;

    else
    {
      x++;
      px += tworySq;
      p += rxSq - py + px;
    }
  }
}

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  int centerX = 200;
  int centerY = 200;
  int rx = 150; // Horizontal radius
  int ry = 100; // Vertical radius

  drawEllipseMidpoint(centerX, centerY, rx, ry);

  delay(5000);
  closegraph();
  return 0;
}
