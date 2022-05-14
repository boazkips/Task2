
#include "Circle.h"
#include "Figure2D.h"
#include <math.h>


using namespace std;


Circle::Circle(const char *name, Point &pt, double R) : Figure2D(2 * R, 2 * R, pt.getX(), pt.getY()) {
    this->setName(name);
    this->R = R;
}

void Circle::setRadius(double newR) {
    this->R = newR;
}

double Circle::getRadius() const {
    return this->R;
}

double Circle::Area() const {
    return 3.1415926535897931 * pow(this->R, 2);
}

double Circle::Perimeter() const {
    return 2 * 3.1415926535897931 * this->R;
}

bool Circle::isInside(Figure2D *pt) {
    Point centre("", this->getX(), this->getY());
    double distance = pow(centre.getX() - pt->getX(), 2) + pow(centre.getY() - pt->getY(), 2);

    return distance <= pow(this->R, 2);
}

void Circle::Resize(double newl, double neww) {
    Figure2D::Resize(newl, neww);
    this->R = newl / 2;
}

void Circle::Scale(double kx, double ky) {
    Figure2D::Scale(kx, ky);
    this->R = this->getLength() / 2;
}

ostream &operator<<(ostream &cout, Circle &c) {
    Point centre("", c.getX(), c.getY());
    cout << "Circle " << c.getName() << " with center " << centre;
    cout << " and radius " << c.getRadius();

    return cout;
}

void Circle::Print() const {
    Point centre("", this->getX(), this->getY());
    cout << "Circle " << this->getName() << " with center " << centre;
    cout << " and radius " << this->getRadius() << endl;
}