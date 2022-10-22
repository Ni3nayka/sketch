PImage img;
int pointSize = 5;
void setup() {
  size(800, 500);
  background(255);
  img = loadImage("pic4.jpg");
}

void draw() {
  for (int i = 0; i < 2000; i++)
  {
    int x = int(random(img.width));
    int y = int(random(img.height));

    int loc = x + y * img.width;

    loadPixels();
    float r = red(img.pixels[loc]);
    float b = blue(img.pixels[loc]);
    float g = green(img.pixels[loc]);
    fill(r, g, b, 100);
    noStroke();
    ellipse(x, y, pointSize, pointSize);
  }
}
