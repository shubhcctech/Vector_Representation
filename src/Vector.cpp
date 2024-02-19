#include <iostream>
#include <cmath>
#include "..\headers\VectorOperations.h"
#include "..\headers\Plane.h"

VectorOperations::VectorOperations() : Point3D() {}
VectorOperations::VectorOperations(double x, double y, double z) : Point3D(x, y, z) {}

VectorOperations ::VectorOperations::~VectorOperations() {}

bool VectorOperations ::operator==(const VectorOperations &other) const
{
    return ((other.X() == this->X()) && (other.Y() == this->Y()) && (other.Z() == this->Z()));
}
double VectorOperations::getDotProduct(const VectorOperations &other) const
{
    return (this->X() * other.X()) + (this->Y() * other.Y()) + (this->Z() * other.Z());
}

VectorOperations VectorOperations::getCrossProduct(const VectorOperations &other) const
{
    double newX = (this->Y() * other.Z()) - (this->Z() * other.Y());
    double newY = (this->Z() * other.X()) - (this->X() * other.Z());
    double newZ = (this->X() * other.Y()) - (this->Y() * other.X());
    return VectorOperations(newX, newY, newZ);
}

double VectorOperations::getMagnitude() const
{
    return sqrt(this->X() * this->X() + this->Y() * this->Y() + this->Z() * this->Z());
}

VectorOperations VectorOperations::getNormalized() const
{
    double mag = getMagnitude();
    return VectorOperations(this->X() / mag, this->Y() / mag, this->Z() / mag);
}

VectorOperations VectorOperations::operator+(const VectorOperations &other) const
{
    return VectorOperations(this->X() + other.X(), this->Y() + other.Y(), this->Z() + other.Z());
}

VectorOperations VectorOperations::operator-(const VectorOperations &other) const
{
    return VectorOperations(this->X() - other.X(), this->Y() - other.Y(), this->Z() - other.Z());
}

VectorOperations VectorOperations::operator*(const VectorOperations &other) const
{
    return VectorOperations(this->X() * other.X(), this->Y() * other.Y(), this->Z() * other.Z());
}

VectorOperations VectorOperations::operator/(const VectorOperations &other) const
{
    return VectorOperations(this->X() / other.X(), this->Y() / other.Y(), this->Z() / other.Z());
}

VectorOperations VectorOperations::setVectorLength(double newLength) const
{
    return this->getNormalized().multiplyScalar(newLength);
}

VectorOperations VectorOperations::addScalar(double scalar) const
{
    return VectorOperations(this->X() + scalar, this->Y() + scalar, this->Z() + scalar);
}

VectorOperations VectorOperations::subtractScalar(double scalar) const
{
    return VectorOperations(this->X() - scalar, this->Y() - scalar, this->Z() - scalar);
}

VectorOperations VectorOperations::multiplyScalar(double scalar) const
{
    return VectorOperations(this->X() * scalar, this->Y() * scalar, this->Z() * scalar);
}

VectorOperations VectorOperations::divideScalar(double scalar) const
{
    return VectorOperations(this->X() / scalar, this->Y() / scalar, this->Z() / scalar);
}

double VectorOperations::getDistanceBetweenVectors(const VectorOperations &other) const
{
    double dx = this->mX - other.X();
    double dy = this->mY - other.Y();
    double dz = this->mZ - other.Z();
    return sqrt(dx * dx + dy * dy + dz * dz);
}

double VectorOperations::getDistanceBetweenVectorAndPlane(const Plane &plane) const
{
    double dX = X() - plane.getPointOnPlane().X();
    double dY = Y() - plane.getPointOnPlane().Y();
    double dZ = Z() - plane.getPointOnPlane().Z();
    double getDotProduct = dX * plane.getNormal().X() + dY * plane.getNormal().Y() + dZ * plane.getNormal().Z();
    double distance = std::abs(getDotProduct) / plane.getNormal().getMagnitude();
    return distance;
}

double VectorOperations ::getAngleBetweenVectors(const VectorOperations &other) const
{
    double dotProductResult = this->getDotProduct(other);
    double magnitudeResult = getMagnitude() * other.getMagnitude();
    double angleradians = acos(dotProductResult / magnitudeResult);
    return angleradians * (180.0 / M_PI);
}

double VectorOperations::getAngleBetweenVectorAndPlane(const Plane &plane) const
{
    // dot product (vector and plane's normal)
    double dotProductResult = getDotProduct(plane.getNormal());
    // getMagnitude of vector and plane's normal
    double vectorMagnitude = getMagnitude();
    double normalMagnitude = plane.getNormal().getMagnitude();

    double angleRadians = std::acos(dotProductResult / (vectorMagnitude * normalMagnitude));
    // converting radians to degrees
    return angleRadians * (180.0 / M_PI);
}

void VectorOperations ::directionCosines() const
{
    double magnitudeResult = getMagnitude();
    double alpha;
    double beta;
    double gamma;
    // Ensure the getMagnitude is not zero to avoid division by zero
    if (magnitudeResult != 0.0)
    {
        alpha = std::acos(this->X() / getMagnitude()) * (180.0 / M_PI);
        beta = std::acos(this->Y() / getMagnitude()) * (180.0 / M_PI);
        gamma = std::acos(this->Z() / getMagnitude()) * (180.0 / M_PI);
    }
    else
    {
        // Handle the case when the getMagnitude is zero
        alpha = beta = gamma = 0.0;
    }
}

VectorOperations VectorOperations::multiplyMatrix(const Matrix &matrix) const
{
    double resultX = X() * matrix.getElement(0, 0) + Y() * matrix.getElement(1, 0) + Z() * matrix.getElement(2, 0);
    double resultY = X() * matrix.getElement(0, 1) + Y() * matrix.getElement(1, 1) + Z() * matrix.getElement(2, 1);
    double resultZ = X() * matrix.getElement(0, 2) + Y() * matrix.getElement(1, 2) + Z() * matrix.getElement(2, 2);
    return VectorOperations(resultX, resultY, resultZ);
}

VectorOperations VectorOperations::projectionOnVector(const VectorOperations &otherVector) const
{
    double dotProductResult = getDotProduct(otherVector);
    double denominator = otherVector.getDotProduct(otherVector);

    if (std::abs(denominator) == 0)
    {
        return VectorOperations();
    }

    double scalarValue = dotProductResult / denominator;
    return otherVector.multiplyScalar(scalarValue);
}

VectorOperations VectorOperations::projectVectorOnPlane(const VectorOperations &vector, const VectorOperations &planeNormal) const
{
    VectorOperations projection = vector.projectionOnVector(planeNormal);
    VectorOperations result = vector - projection;
    return result;
}

double VectorOperations::angleBetweenVector(const VectorOperations& other){
    double res = (this->getDotProduct(other))/(this->getMagnitude()*other.getMagnitude());
    return acos(res)*180/M_PI;
}
 
 
double VectorOperations::angleWithXaxis(){
    VectorOperations axis(1,0,0);
    return this->angleBetweenVector(axis);
}
double VectorOperations::angleWithYaxis(){
    VectorOperations axis(0,1,0);
    return this->angleBetweenVector(axis);
}
double VectorOperations::angleWithZaxis(){
    VectorOperations axis(0,0,1);
    return this->angleBetweenVector(axis);
}
