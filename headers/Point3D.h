#ifndef POINT3D_H
#define POINT3D_H

class Point3D {
public:
    // Constructors
    Point3D();
    Point3D(double x, double y, double z);

    // Getter
    double getX() const;
    double getY() const;
    double getZ() const;

private:
    double x;
    double y;
    double z;
};

#endif // POINT3D_H
