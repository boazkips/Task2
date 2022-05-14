#include "Rectangle.h"
#include "Figure2D.h"
#include "Point.h"


using namespace std;


Rectangle::Rectangle(const char *name, const Point &p1, const Point &p2) : Figure2D(abs(p2.getX() - p1.getX()),
                                                                        abs(p2.getY() - p1.getY()),
                                                                        min(p1.getX(), p2.getX()),
                                                                        min(p1.getY(), p2.getY())), P1(p1), P2(p2) {
    this->setName(name);
}

Rectangle::Rectangle() : Figure2D() {}

double Rectangle::Area() const {
    return this->getHeight() * this->getLength();
}

double Rectangle::Perimeter() const {
    return 2 * this->getHeight() + 2 * this->getLength();
}

ostream &operator<<(ostream &cout, Rectangle &rect) {
    Point begin("", rect.getX(),  rect.getY()), end("", rect.getX() + rect.getLength(),  rect.getY() + rect.getHeight());
    cout << rect.getName() << " Point" << begin << "-Point" << end;

    return cout;
}

void Rectangle::Print() const {
    Point begin("", this->getX(),  this->getY()), end("", this->getX() + this->getLength(),  this->getY() + this->getHeight());
    cout << this->getName() << " Point" << begin << "-Point" << end << endl;
}
