import processing.pdf.*;


int backgroundShade = 30;
int trisWide = 30;
int trisHeight = 26;

boolean oddOrEven = true;
int counter = 0;

ArrayList<Tri> tris;

boolean record;

void setup(){
  size(800,600);
  noFill();
  stroke(255);
  
  tris = new ArrayList<Tri>();
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

void draw(){
  
  if (record) {
    // Note that #### will be replaced with the frame number. Fancy!
    beginRecord(PDF, "frame-####.pdf"); 
  }
  
  
  background(30);
  for (int i = 0; i < tris.size(); i++){
      if (tris.get(i).getIsDrawn() == true){
          tris.get(i).draw();  
      }
       
    }
    
  if (record) {
    endRecord();
  record = false;
  }
}

void mousePressed(){
  if (mouseButton == LEFT){
    
    for (int i = 0; i < tris.size(); i++){
        if (tris.get(i).pointInTri(new PVector(mouseX, mouseY))){
           tris.get(i).toggleDrawn(); 
        }
    }
  } else if (mouseButton == RIGHT){
    for (int i = 0; i < tris.size(); i++){
        if (tris.get(i).pointInTri(new PVector(mouseX, mouseY))){
           tris.get(i).toggleShaded(); 
        }
    }
  }
}

void keyPressed(){
   record = true; 
}
