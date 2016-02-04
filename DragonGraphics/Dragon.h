// Kyle Graham
// Dragon Class 
#ifndef DRAGON_H
#define DRAGON_H

#include "Turtle.h"
#include <iostream>
#include <math.h>
using namespace std;

class Dragon : Turtle {
public:
  Dragon( float initX=0.0, float initY=0.0, float initAngle=0.0 )
	  :Turtle( initX, initY, initAngle){};
  void leftCurve( int l, float d );  //draw a level-l left curve with dist d
  void rightCurve( int l, float d ); //draw a level-l right curve with dist d
};
#endif

