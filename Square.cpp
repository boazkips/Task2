#include "Square.h"
#include "Rectangle.h"


using namespace std;


Square::Square(const char *name, Point &p1, Point &p2) : Rectangle(name, p1, p2) {}

Square::Square(const char *name, Point &pt, double len) : Rectangle(name, pt,
                                                                    Point(name, pt.getX() + len, pt.getY() + len)) {}

Square::Square() : Rectangle() {}

Square::Square(Square &sq) : Rectangle(sq.getName(), sq.getP1(), sq.getP2()) {}

double Square::Area() const {
    return pow(this->getLength(), 2);
}

double Square::Perimeter() const {
    return 4 * this->getLength();
}

Square &Square::operator=(Square &sq) {
    this->setName(sq.getName());
    this->Figure2D::operator=(sq);

    return *this;
}

bool Square::isInside(Figure2D *P) {
    if (P->getX() > this->getX() && P->getX() < this->getX() + this->getLength()) {
        if (P->getY() > this->getY() && P->getY() < this->getY() + this->getLength())
            return true;
    }

    return false;
}

void Square::Scale(double a, double b) {
    double k = max(a, b);
    this->Figure2D::Scale(k, k);
}

void Square::Resize(double a, double b) {
    double n = max(a, b);
    this->Figure2D::Resize(n, n);
}

ostream &operator<<(ostream &cout, Square &sq) {
    Point centre("", sq.getX() + sq.getLength() / 2, sq.getY() + sq.getLength() / 2);
    cout << "Square " << sq.getName() << " with centre " << centre << " and side " << sq.getLength();

    return cout;
}

void Square::Print() const {
    Point centre("", this->getX() + this->getLength() / 2, this->getY() + this->getLength() / 2);
    cout << "Square " << this->getName() << " with centre " << centre << " and side " << this->getLength() << endl;
}