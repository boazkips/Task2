#include "Segment.h"


using namespace std;


Segment::Segment(const char *name, Point &p1, Point &p2, bool flag) : Figure2D(abs(p2.getX() - p1.getX()),
                                                                               abs(p2.getY() - p1.getY()), p1.getX(),
                                                                               p2.getY()), p1(p1), p2(p2) {
    this->setName(name);

    // Calculating equation
    if (p1.getX() == p2.getX()) {
        this->eqcoeff[1] = NULL;
        this->eqcoeff[0] = p1.getY();
    } else {
        this->eqcoeff[1] = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
        this->eqcoeff[0] = p2.getY() - this->eqcoeff[1] * p2.getX();
    }
}

double Segment::Perimeter() const {
    double dx = this->getLength();
    double dy = this->getHeight();

    return sqrt(pow(dx, 2) + pow(dy, 2));
}

bool Segment::isInside(Figure2D *pt) {
    double projY = this->eqcoeff[0];
    if (this->eqcoeff[1] != NULL) {
        projY += this->eqcoeff[1] * pt->getX();
    }

    return projY == pt->getY();
}

ostream &operator<<(ostream &cout, Segment &seg) {
    cout << seg.getName() << ": Point(" << seg.getX() << ", " << seg.getY() + seg.getHeight() << ")";
    cout << "-";
    cout << "Point(" << seg.getX() + seg.getLength() << ", " << seg.getY() << ")";

    return cout;
}

void Segment::Print() const {
    cout << this->getName() << ": Point(" << this->getX() << ", " << this->getY() + this->getHeight() << ")";
    cout << "-";
    cout << "Point(" << this->getX() + this->getLength() << ", " << this->getY() << ")" << endl;
}