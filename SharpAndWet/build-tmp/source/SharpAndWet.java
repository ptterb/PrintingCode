import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.pdf.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class SharpAndWet extends PApplet {




// Set these variables to the print size you want (in inches)
// The resulting PDF will be this aspect ratio
float print_width = 23;
float print_height = 17;

// This will help make the sketch window bigger
float make_bigger = 40;




public void setup() {
	size(round(print_width * make_bigger), round(print_height * make_bigger));
	background(255);
	fill(0,0,0, 200);
	noStroke();

	// Manual plotting
	//points.add(new PVector(width/2, height/2));

	drawTeardrop(.001f, 1);
	drawTeardrop(.4f, 2);

	
}

public void draw() {

	// Testing manaul plotting
	//drawManualPlot();
	
}

public void keyPressed(){

	switch (key) {

		
		case 'n' :
		beginRecord(PDF, "Sharp_and_Wet.pdf");
		background(255);
		fill(0,0,0, 200);
		//generateNewSharpShape();
		drawTeardrop(.001f, 1);
		drawTeardrop(.4f, 2);
		endRecord();
		break;	

		case 'c':
		background(255);
		break;

	}
}


// Create Sharp shape by picking random radii n steps around a center vertex
public void generateNewSharpShape(){

	float maxRadius = 200;
	float minRadius = 100;
	int steps = 10;

	pushMatrix();

	translate(width/4, height/2);
	
	beginShape();
	for (int i = 0; i < steps; ++i) {
		float randNum = random(minRadius, maxRadius);
		
		float vertX = cos(radians(i * 360 / steps)) * randNum;
		float vertY = sin(radians(i * 360 / steps)) * randNum;
		vertex(vertX, vertY);
	}
	endShape();

	popMatrix();

}

// Draw teardrop curve (quartic piriform) from the equation:
// y^2 = x^n(1-x)  solved for y as:
// y = sqrt(x^n(1-x))
public void drawTeardrop(float step, int pos){

	pushMatrix();
	int resizeScale = 300;

	if (pos == 1){
		translate(width/4, height/2 - resizeScale / 2);
	} else if (pos == 2){
		translate(width/2 + width/4, height/2 - resizeScale / 2);	
	}

	rotate(radians(90));

	  int n = 3;
	 
	  beginShape();
	  for (float x = -1; x < 1; x = x + step) {
	  	float y = sqrt(pow(x,n) * (1-x));

	  	if (!Float.isNaN(y)){
	  		println(x + " " +y);
		  	vertex(x * resizeScale, y * resizeScale);	
	  	}
	  	
	  }
	  // For negative y values
	  for (float x = 1; x > -1; x = x - step) {
	  	float y = sqrt(pow(x,n) * (1-x));
	  	
	  	if (!Float.isNaN(y)){
	  		println(x + " " +y);
		  	vertex(x * resizeScale, -y * resizeScale);	
	  	}
	  }
	  endShape();

	  popMatrix();
}

public void drawTeardropSharp(){

	pushMatrix();
	int resizeScale = 300;

	
	rotate(radians(90));

	  int n = 3;
	  float step = .4f;

	  beginShape();
	  for (float x = -1; x < 1; x = x + step) {
	  	float y = sqrt(pow(x,n) * (1-x));

	  	if (!Float.isNaN(y)){
	  		println(x + " " +y);
		  	vertex(x * resizeScale, y * resizeScale);	
	  	}
	  	
	  }
	  // For negative y values
	  for (float x = 1; x > -1; x = x - step) {
	  	float y = sqrt(pow(x,n) * (1-x));
	  	
	  	if (!Float.isNaN(y)){
	  		println(x + " " +y);
		  	vertex(x * resizeScale, -y * resizeScale);	
	  	}
	  }
	  endShape();

	  popMatrix();
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "SharpAndWet" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
