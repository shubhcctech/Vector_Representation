#include <iostream>
#include <cmath>
#include "..\headers\VectorOperations.h"
#include "..\headers\Plane.h"

GeomVectors::GeomVectors() : Point3D() {}
GeomVectors::GeomVectors(double x, double y, double z) : Point3D(x, y, z) {}

GeomVectors ::GeomVectors::~GeomVectors() {}

bool GeomVectors ::operator==(const GeomVectors &other) const
{
    return ((other.X() == this->X()) && (other.Y() == this->Y()) && (other.Z() == this->Z()));
}
double GeomVectors::dotProduct(const GeomVectors &other) const
{
    return (this->X() * other.X()) + (this->Y() * other.Y()) + (this->Z() * other.Z());
}

GeomVectors GeomVectors::crossProduct(const GeomVectors &other) const
{
    double newX = (this->Y() * other.Z()) - (this->Z() * other.Y());
    double newY = (this->Z() * other.X()) - (this->X() * other.Z());
    double newZ = (this->X() * other.Y()) - (this->Y() * other.X());
    return GeomVectors(newX, newY, newZ);
}

double GeomVectors::magnitude() const
{
    return sqrt(this->X() * this->X() + this->Y() * this->Y() + this->Z() * this->Z());
}

GeomVectors GeomVectors::normalizedVector() const
{
    double mag = magnitude();
    return GeomVectors(this->X() / mag, this->Y() / mag, this->Z() / mag);
}

GeomVectors GeomVectors::operator+(const GeomVectors &other) const
{
    return GeomVectors(this->X() + other.X(), this->Y() + other.Y(), this->Z() + other.Z());
}

GeomVectors GeomVectors::operator-(const GeomVectors &other) const
{
    return GeomVectors(this->X() - other.X(), this->Y() - other.Y(), this->Z() - other.Z());
}

GeomVectors GeomVectors::operator*(const GeomVectors &other) const
{
    return GeomVectors(this->X() * other.X(), this->Y() * other.Y(), this->Z() * other.Z());
}

GeomVectors GeomVectors::operator/(const GeomVectors &other) const
{
    return GeomVectors(this->X() / other.X(), this->Y() / other.Y(), this->Z() / other.Z());
}

GeomVectors GeomVectors::setVectorLength(double newLength) const
{
    return this->normalizedVector().multiplyScalar(newLength);
}

GeomVectors GeomVectors::addScalar(double scalar) const
{
    return GeomVectors(this->X() + scalar, this->Y() + scalar, this->Z() + scalar);
}

GeomVectors GeomVectors::subtractScalar(double scalar) const
{
    return GeomVectors(this->X() - scalar, this->Y() - scalar, this->Z() - scalar);
}

GeomVectors GeomVectors::multiplyScalar(double scalar) const
{
    return GeomVectors(this->X() * scalar, this->Y() * scalar, this->Z() * scalar);
}

GeomVectors GeomVectors::divideScalar(double scalar) const
{
    return GeomVectors(this->X() / scalar, this->Y() / scalar, this->Z() / scalar);
}

double GeomVectors::distanceBetweenVectors(const GeomVectors &other) const
{
    double dx = this->mX - other.X();
    double dy = this->mY - other.Y();
    double dz = this->mZ - other.Z();
    return sqrt(dx * dx + dy * dy + dz * dz);
}

double GeomVectors::distanceBetweenVectorAndPlane(const Plane &plane) const
{
    double dX = X() - plane.pointOnPlane().X();
    double dY = Y() - plane.pointOnPlane().Y();
    double dZ = Z() - plane.pointOnPlane().Z();
    double dotProduct = dX * plane.normal().X() + dY * plane.normal().Y() + dZ * plane.normal().Z();
    double distance = std::abs(dotProduct) / plane.normal().magnitude();
    return distance;
}

double GeomVectors ::angleBetweenVectors(const GeomVectors &other) const
{
    double dotProductResult = this->dotProduct(other);
    double magnitudeResult = magnitude() * other.magnitude();
    double angleradians = acos(dotProductResult / magnitudeResult);
    return angleradians * (180.0 / M_PI);
}

double GeomVectors::angleBetweenVectorAndPlane(const Plane &plane) const
{
    // dot product (vector and plane's normal)
    double dotProductResult = dotProduct(plane.normal());
    // getMagnitude of vector and plane's normal
    double vectorMagnitude = magnitude();
    double normalMagnitude = plane.normal().magnitude();

    double angleRadians = std::acos(dotProductResult / (vectorMagnitude * normalMagnitude));
    // converting radians to degrees
    return angleRadians * (180.0 / M_PI);
}

void GeomVectors ::directionCosines() const
{
    double magnitudeResult = magnitude();
    double alpha;
    double beta;
    double gamma;
    // Ensure the getMagnitude is not zero to avoid division by zero
    if (magnitudeResult != 0.0)
    {
        alpha = std::acos(this->X() / magnitude()) * (180.0 / M_PI);
        beta = std::acos(this->Y() / magnitude()) * (180.0 / M_PI);
        gamma = std::acos(this->Z() / magnitude()) * (180.0 / M_PI);
    }
    else
    {
        // Handle the case when the getMagnitude is zero
        alpha = beta = gamma = 0.0;
    }
}

GeomVectors GeomVectors::multiplyMatrix(const Matrix &matrix) const
{
    double resultX = X() * matrix.getElement(0, 0) + Y() * matrix.getElement(1, 0) + Z() * matrix.getElement(2, 0);
    double resultY = X() * matrix.getElement(0, 1) + Y() * matrix.getElement(1, 1) + Z() * matrix.getElement(2, 1);
    double resultZ = X() * matrix.getElement(0, 2) + Y() * matrix.getElement(1, 2) + Z() * matrix.getElement(2, 2);
    return GeomVectors(resultX, resultY, resultZ);
}

GeomVectors GeomVectors::projectionOnVector(const GeomVectors &otherVector) const
{
    double dotProductResult = dotProduct(otherVector);
    double denominator = otherVector.dotProduct(otherVector);

    if (std::abs(denominator) == 0)
    {
        return GeomVectors();
    }

    double scalarValue = dotProductResult / denominator;
    return otherVector.multiplyScalar(scalarValue);
}

GeomVectors GeomVectors::projectVectorOnPlane(const GeomVectors &vector, const GeomVectors &planeNormal) const
{
    GeomVectors projection = vector.projectionOnVector(planeNormal);
    GeomVectors result = vector - projection;
    return result;
}

double GeomVectors::angleBetweenVector(const GeomVectors& other){
    double res = (this->dotProduct(other))/(this->magnitude()*other.magnitude());
    return acos(res)*180/M_PI;
}
 
 
double GeomVectors::angleWithXaxis(){
    GeomVectors axis(1,0,0);
    return this->angleBetweenVector(axis);
}
double GeomVectors::angleWithYaxis(){
    GeomVectors axis(0,1,0);
    return this->angleBetweenVector(axis);
}
double GeomVectors::angleWithZaxis(){
    GeomVectors axis(0,0,1);
    return this->angleBetweenVector(axis);
}

bool GeomVectors::vectorEqualCheck(const GeomVectors& vector1 , const GeomVectors& vector2){
    bool checkValue =( vector1==vector2);
    return checkValue;
}
