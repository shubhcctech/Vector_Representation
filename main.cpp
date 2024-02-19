#include <iostream>
#include "headers/Vector.h"
#include "headers/Point3D.h"
#include "headers/Point2D.h"

using namespace std;

int main() {
    // std::vector<double> elems1 = {1.0, 2.0, 3.0};
    // std::vector<double> elems2 = {4.0, 5.0, 6.0};
    double xCoordinate;
    double yCoordinate;
    double zCoordinate;
    cout<<"Enter points  for Vector 1"<<endl;
    cout<<"Enter X coordinate"<<endl;
    cin>>xCoordinate;
    cout<<"Enter Y coordinate"<<endl;
    cin>>yCoordinate;
    cout<<"Enter Z coordinate"<<endl;
    cin>>zCoordinate;
    Point3D point1(xCoordinate,yCoordinate,zCoordinate);

    cout<<"Enter points  for Vector 2"<<endl;
    cout<<"Enter X coordinate"<<endl;
    cin>>xCoordinate;
    cout<<"Enter Y coordinate"<<endl;
    cin>>yCoordinate;
    cout<<"Enter Z coordinate"<<endl;
    cin>>zCoordinate;
    Point3D point2(xCoordinate,yCoordinate,zCoordinate);



    


    
    int choice;
    cout << "Enter your choice:" << endl;
    cout << "1. Dot Product" << endl;
    cout << "2. Cross Product" << endl;
    cout << "3. Vector Magnitude" << endl;
    cout << "4. Vector Normalized" << endl;
    cout << "5. Is Equal" << endl;
    cout << "6. Add Scalar" << endl;
    cout << "7. Vector Scalar Multiplication" << endl;
    cout << "8. Angle Between Vectors" << endl;
    cout << "9. Distance Between Vectors" << endl;
    cout << "10. Subtract Scalar" << endl;
    cout << "11. Vector Scalar Division" << endl;
    cout << "12. Angle Between Plane and Vector" << endl;
    cout << "13. Direction Cosines" << endl;
    cin>>choice;

    switch(choice){
        case(1): {
            double dotProduct = vec1.dot(vec2);
            std::cout << "Dot Product of Vector 1 and Vector 2: " << dotProduct << std::endl;
            break;

        }
        case(2):{
            Vector crossProduct = vec1.cross(vec2);
            std::cout << "Cross Product of Vector 1 and Vector 2: ";
            for (double elem : crossProduct.getElements()) {
            std::cout << elem << " ";
            }
            std::cout << std::endl;
            break;
        }
        case(3):{

        }
         case(4):{
            
        }
         case(5):{
            
        }
         case(6):{
            
        }
         case(7):{
            Vector scalarMultiplication = vec1 * 2.0;
            Vector scalarMultiplication1 = vec2 * 2.0;
            std::cout << "Scalar Multiplication of Vector 1: ";
            for (double elem : scalarMultiplication.getElements()) {
            std::cout << elem << " ";
            }
            std::cout << "Scalar Multiplication of Vector 2: ";
            for (double elem : scalarMultiplication1.getElements()) {
            std::cout << elem << " ";
            }

            break;

            

            
        }
         case(8):{
            
        }
    }
    // Create vectors
  

    // Perform vector operations
    // Vector addition = vec1 + vec2;
    // Vector subtraction = vec1 - vec2;
    
    
    
    // // double magnitudeVec1 = vec1.magnitude();
    // // Vector normalizedVec1 = vec1.normalized();

    // // Print results
    // std::cout << "Vector 1: ";
    // for (double elem : vec1.getElements()) {
    //     std::cout << elem << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "Vector 2: ";
    // for (double elem : vec2.getElements()) {
    //     std::cout << elem << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "Vector Addition: ";
    // for (double elem : addition.getElements()) {
    //     std::cout << elem << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "Vector Subtraction: ";
    // for (double elem : subtraction.getElements()) {
    //     std::cout << elem << " ";
    // }
    // std::cout << std::endl;

    
    // std::cout << std::endl;

    

    

    // // std::cout << "Magnitude of Vector 1: " << magnitudeVec1 << std::endl;

    // // std::cout << "Normalized Vector 1: ";
    // // for (double elem : normalizedVec1.getElements()) {
    // //     std::cout << elem << " ";
    // // }
    // // std::cout << std::endl;

    return 0;
}
