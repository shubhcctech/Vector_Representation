#pragma once
#include "VectorOperations.h"

class Plane
{
public:
    Plane();
    Plane(VectorOperations &, Point3D &);
    ~Plane();

    VectorOperations getNormal() const;
    Point3D getPointOnPlane() const;


private:
    VectorOperations mNormal;
    Point3D mPointOnPlane;
};
