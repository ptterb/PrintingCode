/*  Properties
 _________________________________________________________________ */

import processing.pdf.*;


// Set these variables to the print size you want (in inches)
// The resulting PDF will be this aspect ratio
float print_width = 17;
float print_height = 23;

// This will help make the sketch window bigger
float make_bigger = 40;

Cone cone = new Cone();
int spacer = 100;
int spacerX = 80;
int spacerY = 50;

boolean blackOnWhite = false;   // invert colors
Pattern pattern;      // enum to extend for more patterns if desired

/*  Setup
 _________________________________________________________________ */

void setup()
{
  size(round(print_width * make_bigger), round(print_height * make_bigger));

  beginRecord(PDF, "grab.pdf"); 

  if (blackOnWhite) {
    background(255);
    stroke(0);
  } 
  else {
    background(0);
    stroke(255);
    fill(0);
  }

  pattern = Pattern.INVERT;

  switch (pattern) {
  case INVERT:        // Draw with alternating inverted cones
    drawInvert(); 
    break;
  case NO_INVERT:     // Cones all in one direction and more spaced out
    drawNoInvert(); 
    break;
  }


  endRecord();
}

void drawNoInvert() {
  for (int i = 0; i < 2000; i += spacer) {
    for (int j = -500; j < 1000; j += spacer) {
      pushMatrix();
      rotate(PI/3.8);
      translate(-width/2 + i, -height/2 + j);
      cone.drawCone(false);
      popMatrix();
    }
  }
}

void drawInvert() {
  for (int y = -500; y < height; y += spacerY) {
    for (int x = 0; x < width * 2; x += spacerX) {
      pushMatrix();
      rotate(PI/3.8);
      if (y % (spacerY * 2) == 0) {

        translate(-width/2 + x + spacerX / 2, -height/2 + y);
        cone.drawCone(true);
      } 
      else {
        translate(-width/2 + x, -height/2 + y);
        cone.drawCone(false);
      }
      popMatrix();
    }
  }
}

