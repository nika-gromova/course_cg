#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "rgbcolor.h"

const double PI = 3.1415926535897932384;
const double TWO_PI = 6.2831853071795864769;

const RGBColor BLACK(0.0);
const RGBColor WHITE(1.0);
const RGBColor RED(1.0, 0.0, 0.0);


#define SPHERE 0
#define BOX 1
#define PYRAMID 2
#define CONE 3
#define CYLINDER 4
#define TORI 5
#define OBJECTS_TOTAL 6

#define GLASS 0
#define METAL 1
#define MIRROR 2
#define IVORY 3
#define PLASTIC 4
#define RUBBER 5



#endif // CONSTANTS_H
