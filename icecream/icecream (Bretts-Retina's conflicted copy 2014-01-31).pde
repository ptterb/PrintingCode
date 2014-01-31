/*  Properties
_________________________________________________________________ */

import processing.pdf.*;

// Set these variables to the print size you want (in inches)
// The resulting PDF will be this aspect ratio
float print_width = 17;
float print_height = 23;

// This will help make the sketch window bigger
float make_bigger = 40;


int scoopSize = 25;
int scoopOffset = 8;
int coneOffsetX = 20;
int coneOffsetY = 55;

/*  Setup
_________________________________________________________________ */

void setup()
{
  size(round(print_width * make_bigger), round(print_height * make_bigger));

  beginRecord(PDF, "grab.pdf"); 
  background(255);

  
  // Start Ice Cream code
  
  
  strokeWeight(3);
  ellipse(width/2+scoopOffset,height/2,scoopSize,scoopSize);   // Scoop 2
  ellipse(width/2,height/2 - scoopOffset - 5,scoopSize,scoopSize);   // Scoop 3
  ellipse(width/2-scoopOffset,height/2,scoopSize,scoopSize);   // Scoop 1
  
  triangle(width/2-coneOffsetX, height/2 + 5,width/2+coneOffsetX, height/2 + 5, width/2, height/2 + coneOffsetY); 
  
  
  
  
  // End Ice Cream code
  
  
  endRecord();
}
