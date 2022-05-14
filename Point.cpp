#include "Point.h"
#include "Figure2D.h"


using namespace std;


Point::Point(const char *name, double x, double y) : Figure2D(0, 0, x, y) {
    this->setName(name);
}

Point::Point() : Figure2D() {}

Point::Point(const Point &pt) : Figure2D(0, 0, pt.getX(), pt.getY()) {
    this->setName(pt.getName());
}

bool Point::isInside(Figure2D *P) {
    if (P->getX() == this->getX() && P->getY() == this->getY())
        return true;

    return false;
}

ostream &operator<<(ostream &cout, Point &pt) {
    cout << "(" << pt.getX() << ", " << pt.getY() << ")";

    return cout;
}

void Point::Print() const {
    cout << "(" <<  this->getX() << ", " << this->getY() << ")" << endl;
}