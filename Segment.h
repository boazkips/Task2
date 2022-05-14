#ifndef TASK2_SEGMENT_H
#define TASK2_SEGMENT_H


#include "Figure2D.h"
#include "Point.h"
#include <math.h>


class Segment : public Figure2D {
public:
    Segment(const char *, Point &, Point &, bool = true);

    virtual double Area() const { return 0; };

    virtual double Perimeter() const;

    virtual void Print() const;

    virtual bool isInside(Figure2D *P);

private:
    Point p1, p2;
    double eqcoeff[2];
};


#endif //TASK2_SEGMENT_H
