class Cone {
  
  int scoopSize = 25;
  int scoopOffset = 8;
  int coneOffsetX = 19;
  int coneOffsetY = 55;
  
  void drawCone(boolean invert){
    int[][] scoopPositions = { { width / 2 + scoopOffset, height / 2, scoopSize},
                             { width / 2, height / 2 - scoopOffset - 5},
                             { width / 2 - scoopOffset, height/2} };
                                                     
    strokeWeight(3);
    pushMatrix();
    translate(width / 2, height / 2);
    
    if (invert) {
      rotate(PI);
    }
    
   translate(-width / 2, -height / 2);
    
    for (int i = 0; i < 3; i ++){
      ellipse(scoopPositions[i][0], scoopPositions[i][1], scoopSize, scoopSize);
    }
    triangle(width/2-coneOffsetX, height/2 + 5,width/2+coneOffsetX, height/2 + 5, width/2, height/2 + coneOffsetY); 
    
    popMatrix();
  }
  
 
  
}
