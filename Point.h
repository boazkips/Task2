#ifndef TASK2_POINT_H
#define TASK2_POINT_H


#include "Figure2D.h"


class Point : public Figure2D {
    friend ostream &operator<<(ostream &, Point &);

public:
    Point(const char *, double, double);

    Point();

    Point(Point const &);

    virtual double Area() const { return 0; };

    virtual double Perimeter() const { return 0; };

    void Resize(double, double) {};

    virtual void Print() const;

    virtual bool isInside(Figure2D *);
};


#endif //TASK2_POINT_H
