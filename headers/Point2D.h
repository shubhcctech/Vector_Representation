#ifndef POINT2D_H
#define POINT2D_H

class Point2D {
public:
    // Constructors
    Point2D();
    Point2D(double x, double y);

    // Getter
    double getX() const;
    double getY() const;

private:
    double x;
    double y;
};

#endif // POINT2D_H
