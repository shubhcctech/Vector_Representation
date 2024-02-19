#include "../headers/Point3D.h"

Point3D::Point3D() : mX(0), mY(0), mZ(0) {}

Point3D::Point3D(double x, double y, double z) : mX(x), mY(y), mZ(z) {}

Point3D::~Point3D() {}

double Point3D::X() const
{
    return this->mX;
}

double Point3D::Y() const
{
    return this->mY;
}

double Point3D::Z() const
{
    return this->mZ;
}

void Point3D::setX(double x)
{
    this->mX = x;
}
void Point3D::setY(double y)
{
    this->mY = y;
}

void Point3D::setZ(double z)
{
    this->mZ = z;
}

bool Point3D::operator<(const Point3D &other) const
{
    if (this->mX < other.mX) return true;
    if (this->mX > other.mX) return false;
    if (this->mY < other.mY) return true;
    if (this->mY > other.mY) return false;
    return this->mZ < other.mZ;
}

bool Point3D::operator==(const Point3D &other) const
{
    return (this->mX == other.mX) && (this->mY == other.mY) && (this->mZ == other.mZ);
}