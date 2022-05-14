#ifndef TASK2_RECTANGLE_H
#define TASK2_RECTANGLE_H


#include "Figure2D.h"
#include "Point.h"


class Rectangle : public Figure2D {
    friend ostream &operator<<(ostream &, Rectangle &);

public:
    Rectangle(const char *, const Point &, const Point &);

    Rectangle();

    virtual double Area() const;

    virtual double Perimeter() const;

    Point getP1() const { return this->P1; };

    Point getP2() const { return this->P2; };

    virtual void Print() const;

private:
    Point P1, P2;
};


#endif //TASK2_RECTANGLE_H
