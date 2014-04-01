class Tri{
  
   	ArrayList<PVector> points;
    boolean isDrawn;
    boolean isShaded;
    float threshold = .3f;

    Tri(int x1, int y1, int x2, int y2, int x3, int y3){
      
      points = new ArrayList<PVector>();
  
      points.add(new PVector(x1,y1));
      points.add(new PVector(x2,y2));
      points.add(new PVector(x3,y3));
      
      isDrawn = true;
      isShaded = false;
    }
    
    void draw(){
      if (isShaded){
        fill(70);
       noStroke(); 
      }
     triangle(points.get(0).x, points.get(0).y, points.get(1).x, points.get(1).y, points.get(2).x, points.get(2).y);
     
     noFill();
     stroke(255);
    }
    
    
    boolean pointInTri(PVector point){
     
      int sideLength = (int) points.get(0).dist(points.get(1));
      boolean isPointIn = false;
      
      if (point.dist(points.get(0)) < sideLength && point.dist(points.get(1)) < sideLength && point.dist(points.get(2)) < sideLength){
          
          isPointIn =true;
      } else {
          isPointIn = false;
      }

      return isPointIn; 
      
    }
    
    boolean getIsDrawn(){
      return isDrawn;
    }
    
    void setIsDrawn(boolean value) {
      isDrawn = value;
    }
    
    void toggleDrawn(){
       isDrawn = !isDrawn;
    }
    boolean getIsShaded(){
      return isShaded;
    }
    void setIsShaded(boolean value){
      isShaded = value;
    }
    void toggleShaded(){
       isShaded = !isShaded; 
    }
}
    

  
  
  

