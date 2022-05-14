#ifndef TASK2_SQUARE_H
#define TASK2_SQUARE_H


#include "Rectangle.h"
#include "Point.h"


class Square : public Rectangle {
    friend ostream &operator<<(ostream &, Square &);

public:
    Square(const char *, Point &, Point &);

    Square(const char *, Point &, double);

    Square(Square &);

    Square();

    virtual double Area() const;

    virtual double Perimeter() const;

    Square &operator=(Square &);

    virtual void Print() const;

    virtual bool isInside(Figure2D *);

    virtual void Scale(double, double);

    virtual void Resize(double, double);
};


#endif //TASK2_SQUARE_H
