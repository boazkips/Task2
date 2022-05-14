#include "Figure2D.h"
#include <iostream>


using namespace std;


Figure2D::Figure2D(double l, double h, double x, double y) {
    this->x = x;
    this->y = y;
    this->length = l;
    this->height = h;
}

Figure2D::Figure2D(Figure2D &fig) {
    this->length = fig.length;
    this->height = fig.height;
    this->x = fig.x;
    this->y = fig.y;
}

Figure2D::Figure2D() {
    this->length = 0;
    this->height = 0;
    this->x = 0;
    this->y = 0;
}

Figure2D::~Figure2D() {
    delete name;
}

const Figure2D &Figure2D::operator=(Figure2D &fig) {
    this->length = fig.length;
    this->height = fig.height;
    this->x = fig.x;
    this->y = fig.y;

    return *this;
}

void Figure2D::setName(const char *new_name) {
    // Figuring new name size:
    int new_name_size = 0;
    while (new_name[new_name_size] != '\0') {
        new_name_size++;
    }
    // Allocating string:
    char *name = new char[new_name_size + 1];
    // Assigning each letter one by one:
    for (int i = 0; i < new_name_size; i++) {
        name[i] = new_name[i];
    }
    // Adding end-of-string character:
    name[new_name_size] = '\0';
    this->name = name;
}

double Figure2D::getX() const { return this->x; }

double Figure2D::getY() const { return this->y; }

double Figure2D::getLength() const { return this->length; }

double Figure2D::getHeight() const { return this->height; }

const char *Figure2D::getName() const { return this->name; }

void Figure2D::Shift(double dx, double dy) {
    this->x += dx;
    this->y += dy;
}

void Figure2D::MoveTo(double newX, double newY) {
    this->x = newX;
    this->y = newY;
}

void Figure2D::Resize(double newL, double newH) {
    this->length = newL;
    this->height = newH;
}

void Figure2D::Scale(double kx, double ky) {
    this->length *= kx;
    this->height *= ky;
}


bool Figure2D::isInside(Figure2D *P) {

    if ((P->getX() > this->getX()) && (P->getX() < (this->getX() + this->getLength()))) {
        if ((P->getY() > this->getY()) && (P->getY() < (this->getY() + this->getHeight()))) {
            return true;
        }
    }

    return false;
}

ostream &operator<<(ostream &cout, Figure2D &fig) {
    cout << fig.getName() << ": ";
    cout << "x = " << fig.getX();
    cout << ", y = " << fig.getY();
    cout << ", length = " << fig.getLength();
    cout << ", height = " << fig.getHeight();

    return cout;
}

void Figure2D::Print() const {
    cout << this->getName() << ": ";
    cout << "x = " << this->getX();
    cout << ", y = " <<  this->getY();
    cout << ", length = " << this->getLength();
    cout << ", height = " << this->getHeight() << endl;
}