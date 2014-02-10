import processing.pdf.*;


// Set these variables to the print size you want (in inches)
// The resulting PDF will be this aspect ratio
float print_width = 23;
float print_height = 17;

// This will help make the sketch window bigger
float make_bigger = 40;




void setup() {
	size(round(print_width * make_bigger), round(print_height * make_bigger));
	background(255);
	fill(0,0,0, 200);
	noStroke();

	drawTeardrop(.001, 1);
	drawTeardrop(.4, 2);

	
}

void draw() {
	
}

void keyPressed(){

	switch (key) {

		
		case 'n' :
		beginRecord(PDF, "Sharp_and_Wet.pdf");

		background(255);
		fill(0,0,0, 200);

		drawTeardrop(.001, 1);
		drawTeardrop(.4, 2);
		
		endRecord();
		break;	

		case 'c':
		background(255);
		break;

	}
}


// Draw teardrop curve (quartic piriform) from the equation:
// y^2 = x^n(1-x)  solved for y as:
// y = sqrt(x^n(1-x))
//
// Change the steps to make the curve sharper or smoother
void drawTeardrop(float step, int pos){

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


// This was my first attempt at 'Sharp'. I liked the other way above, using the same algorithm MUCH better.
// Create Sharp shape by picking random radii n steps around a center vertex

// void generateNewSharpShape(){

// 	float maxRadius = 200;
// 	float minRadius = 100;
// 	int steps = 10;

// 	pushMatrix();

// 	translate(width/4, height/2);
	
// 	beginShape();
// 	for (int i = 0; i < steps; ++i) {
// 		float randNum = random(minRadius, maxRadius);
		
// 		float vertX = cos(radians(i * 360 / steps)) * randNum;
// 		float vertY = sin(radians(i * 360 / steps)) * randNum;
// 		vertex(vertX, vertY);
// 	}
// 	endShape();

// 	popMatrix();

// }