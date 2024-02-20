#pragma once
#include "VectorOperations.h"

class Plane
{
public:
    Plane();
    Plane(GeomVectors &, Point3D &);
    ~Plane();

    GeomVectors normal() const;
    Point3D pointOnPlane() const;


private:
    GeomVectors mNormal;
    Point3D mPointOnPlane;
};
