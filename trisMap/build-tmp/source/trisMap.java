import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class trisMap extends PApplet {


int backgroundShade = 30;
int trisWide = 30;
int trisHeight = 26;

boolean oddOrEven = true;
int counter = 0;

ArrayList<Tri> tris;



public void setup(){
  int offset = trisWide/2;
    
    for (int j = 0; j < height; j += trisHeight){
        
        if (counter % 2 ==0){
            offset = 0;
        } else {
            offset = trisWide/2;
        }
        
        for (int i = 0 + offset ; i < width; i += trisWide){
            
            Tri tempTri = new Tri(i,j, i-trisWide/2, j+trisHeight, i+trisWide/2, j+trisHeight);
            tris.add(tempTri);

        }
        
        for (int k = trisWide + offset; k < width; k += trisWide){
            
            Tri tempTri2 = new Tri(k+trisWide/2, j+trisHeight, k, j, k+trisWide, j);
            tris.add(tempTri2);
            
            
        }
        
        counter++;
    }

  
}
class Tri{
  
	ArrayList<PVector> points;
    boolean isDrawn;
    boolean isShaded;
    float threshold = .3f;

    Tri(int x1, int y1, int x2, int y2, int x3, int y3){

    	points.add(new PVector(x1,y1));
    points.add(new PVector(x2,y2));
    points.add(new PVector(x3,y3));
    
    isDrawn = true;
    isShaded = false;
    }

  
  
  
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "trisMap" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
