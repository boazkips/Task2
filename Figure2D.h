#ifndef TASK2_FIGURE2D_H
#define TASK2_FIGURE2D_H


#include <iostream>
#include <math.h>

using std::ostream;

class Figure2D {
    friend ostream &operator<<(ostream &, Figure2D &);

private:
    double x, y, length, height;
    const char *name = nullptr;
public:
    
    Figure2D(double l, double h, double x = 0, double y = 0);

    Figure2D(Figure2D &f);

    Figure2D();

    virtual ~Figure2D();

    const Figure2D &operator=(Figure2D &);

    void setName(const char *);

    double getX() const;

    double getY() const;

    double getLength() const;

    double getHeight() const;

    const char *getName() const;

    virtual double Area() const = 0;

    virtual double Perimeter() const = 0;

    void Shift(double, double);

    void MoveTo(double, double);

    void Resize(double, double);

    void Scale(double, double);

    bool isInside(Figure2D *);

    virtual void Print() const;
};


#endif //TASK2_FIGURE2D_H
