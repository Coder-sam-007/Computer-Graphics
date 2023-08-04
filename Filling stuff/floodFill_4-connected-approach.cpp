#include <graphics.h>

void floodFill4(int x, int y, int fillColor, int oldColor)
{
  if (getpixel(x, y) == oldColor)
  {
    // Set the pixel to the new color
    putpixel(x, y, fillColor);

    // Recursive call to fill the adjacent pixels
    floodFill4(x + 1, y, fillColor, oldColor); // Right
    floodFill4(x - 1, y, fillColor, oldColor); // Left
    floodFill4(x, y + 1, fillColor, oldColor); // Down
    floodFill4(x, y - 1, fillColor, oldColor); // Up
  }
}

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  // Draw your shape or outline here
  // For example, to draw a rectangle
  rectangle(100, 100, 300, 200);

  // Coordinates of the starting point inside the shape
  int start_x = 150;
  int start_y = 150;

  // Color to be filled (GREEN in this case)
  int fillColor = CYAN;

  // Get the color of the starting point
  int oldColor = getpixel(start_x, start_y);

  // Perform flood fill starting from the specified point
  floodFill4(start_x, start_y, fillColor, oldColor);

  delay(5000); // Show the result for 5 seconds
  closegraph();
  return 0;
}
