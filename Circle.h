#ifndef TASK2_CIRCLE_H
#define TASK2_CIRCLE_H


#include "Figure2D.h"
#include "Point.h"


using namespace std;


class Circle : public Figure2D {
    friend ostream &operator<<(ostream &, Circle &);

public:
    Circle(const char *, Point &, double);

    void setRadius(double);

    double getRadius() const;

    virtual double Area() const;

    virtual double Perimeter() const;

    virtual void Print() const;

    virtual bool isInside(Figure2D *);

    virtual void Resize(double, double);

    virtual void Scale(double, double);

private:
    double R;
};


#endif //TASK2_CIRCLE_H
