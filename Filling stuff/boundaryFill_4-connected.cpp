#include <graphics.h>

void boundaryFill4(int x, int y, int fill_color, int boundary_color)
{
  if (getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color)
  {
    putpixel(x, y, fill_color);

    boundaryFill4(x + 1, y, fill_color, boundary_color);
    boundaryFill4(x - 1, y, fill_color, boundary_color);
    boundaryFill4(x, y + 1, fill_color, boundary_color);
    boundaryFill4(x, y - 1, fill_color, boundary_color);
  }
}

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  int centerX = 200;
  int centerY = 200;
  int radius = 100;

  // Draw the boundary of the circle
  setcolor(WHITE);
  circle(centerX, centerY, radius);

  // Fill the circle with a color using boundary fill algorithm
  boundaryFill4(centerX, centerY, CYAN, WHITE);

  delay(5000);
  closegraph();
  return 0;
}
