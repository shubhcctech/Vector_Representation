#include "../headers/Point2D.h"

Point2D::Point2D() : x(0), y(0) {}

Point2D::Point2D(double x, double y) : x(x), y(y) {}

double Point2D::getX() const {
    return x;
}

double Point2D::getY() const {
    return y;
}
