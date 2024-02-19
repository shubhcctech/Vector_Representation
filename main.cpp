#include <iostream>
#include <vector>
#include <string>
#include "./headers/VectorOperations.h"
#include "./headers/Writer.h"
#include "./headers/Matrix.h"
#include "./headers/Plane.h"

int main()
{
    int choice;
    double xCoordinate1;
    double xCoordinate2;
    double yCoordinate1;
    double yCoordinate2;
    double zCoordinate1;
    double zCoordinate2;
    bool exitLoop = false;

    while (!exitLoop)
    {
        std::cout << "1. Check if two vectors are equal" << std::endl
                  << "2. Find magnitude of vector" << std::endl
                  << "3. Find normalized vector" << std::endl
                  << "4. Set new Vector-Length" << std::endl
                  << "5. Add Scalar Value to Vector" << std::endl
                  << "6. Subtract scalar value from vector" << std::endl
                  << "7. Multiply Vector by Scalar Value" << std::endl
                  << "8. Divide Vector by vector1 Scalar Value" << std::endl
                  << "9. Add two Vectors" << std::endl
                  << "10. Dot-Product of two Vectors" << std::endl
                  << "11. Cross-Product of two Vectors" << std::endl
                  << "12. Find Direction Cosines of vector1 Vector" << std::endl
                  << "13. Multiply Vector with Matrix" << std::endl
                  << "14. Find Distance between two Vectors" << std::endl
                  << "15. Find Distance between Vector and Plane" << std::endl
                  << "16. Find Angle between two Vectors" << std::endl
                  << "17. Find Angle between Vector and Plane" << std::endl
                  << "18. Find Projection on Vector" << std::endl
                  << "19. Find Projection on Plane " << std::endl
                  << "20. Angle between Vector and Axis" << std::endl
                  << "21. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        // Check whether the vectors are equal.
        case 1:
        {
            std::cout << "Enter value for x, y and z" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;

            std::cout << "Enter value for x, y and z" << std::endl;
            std::cin >> xCoordinate2 >> yCoordinate2 >> zCoordinate2;

            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);
            GeomVectors vector2(xCoordinate2, yCoordinate2, zCoordinate2);
            GeomVectors equalCheck;
            bool check = equalCheck.vectorEqualCheck(vector1 , vector2);

            if (check)
            {
                std::cout << "Two vectors are equal." << std::endl;
            }
            else
            {
                std::cout << "Two vectors are not equal." << std::endl;
            }
            break;
        }
       // Magnitude of vector.
        case 2:
        {
            std::cout << "Enter value for x, y and z" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);
            std::cout << "Magnitude of two vector is " << vector1.magnitude() << std::endl;
            break;
        }
        
        //Normalised Vector
        case 3:
        {
            std::cout << "Enter value for x, y and z" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);
            std::vector<GeomVectors> vectors;
            vectors.push_back(vector1);
            GeomVectors result = vector1.normalizedVector();
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
            break;
        }
        
        // Vector new length formation.
        case 4:
        {
            int newLength;
            std::cout << "Enter points of vector " << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);
            std::vector<GeomVectors> vectors;
            vectors.push_back(vector1);

            std::cout << "Enter new length " << std::endl;
            std::cin >> newLength;
            GeomVectors result = vector1.setVectorLength(newLength);

            vectors.push_back(result);
            Writer writer;
            std::string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
            break;
        }
        // Add scaler value to vector.
        case 5:
        {
            int scalarValue;
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);
            std::cout << "Enter integer value" << std::endl;
            std::cin >> scalarValue;
            GeomVectors result = vector1.addScalar(scalarValue);
            std::vector<GeomVectors> vectors;
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
            break;
        }
        
        // Subtract Scaler value
        case 6:
        {
            int scalarValue;
            std::cout << "Enter x, y and z value for vector" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);

            std::cout << "Enter integer value" << std::endl;
            std::cin >> scalarValue;

            GeomVectors result = vector1.subtractScalar(scalarValue);
            std::vector<GeomVectors> vectors;
            vectors.push_back(vector1);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
            break;
        }
        //Multiply by scaler value
        case 7:
        {
            int scalarValue;
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);

            std::cout << "Enter integer value" << std::endl;
            std::cin >> scalarValue;

            GeomVectors result = vector1.multiplyScalar(scalarValue);
            std::vector<GeomVectors> vectors;
            vectors.push_back(vector1);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
            break;
        }
        
        // Divide vector by scaler value
        case 8:
        {
            int scalarValue;
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);

            std::cout << "Enter integer value" << std::endl;
            std::cin >> scalarValue;

            GeomVectors result = vector1.divideScalar(scalarValue);
            std::vector<GeomVectors> vectors;
            vectors.push_back(vector1);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
             break;
        }
       
        // Add two vectors
        case 9:
        {
            std::cout << "Enter x, y and z value for vector" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);

            std::cout << "Enter x, y and z value for vector" << std::endl;
            std::cin >> xCoordinate2 >> yCoordinate2 >> zCoordinate2;
            GeomVectors vector2(xCoordinate2, yCoordinate2, zCoordinate2);

            GeomVectors result = vector1 + vector2;
            std::vector<GeomVectors> vectors;
            vectors.push_back(vector1);
            vectors.push_back(vector2);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
            break;
        }
        
        // Dot product of two vectors
        case 10:
        {
            std::cout << "Enter x, y and z value for vector" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);

            std::cout << "Enter x, y and z value for vector" << std::endl;
            std::cin >> xCoordinate2 >> yCoordinate2 >> zCoordinate2;
            GeomVectors vector2(xCoordinate2, yCoordinate2, zCoordinate2);

            double result = vector1.dotProduct(vector2);
            std::vector<GeomVectors> vectors;
            vectors.push_back(vector1);
            vectors.push_back(vector2);
            std::cout << "dot product is " << result << std::endl;
            Writer writer;
            std::string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
            break;
        }
        
        // Cross product of two vectors
        case 11:
        {
            std::cout << "Enter x, y and z value for vector" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);

            std::cout << "Enter x, y and z value for vector" << std::endl;
            std::cin >> xCoordinate2 >> yCoordinate2 >> zCoordinate2;
            GeomVectors vector2(xCoordinate2, yCoordinate2, zCoordinate2);

            GeomVectors result = vector1.crossProduct(vector2);
            std::vector<GeomVectors> vectors;
            vectors.push_back(vector1);
            vectors.push_back(vector2);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
            break;
        }
        
        // Direction cosine of a vector
        case 12:
        {
            std::cout << "Enter x, y and z value for vector" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);
            vector1.directionCosines();
            std::vector<GeomVectors> vectors;
            vectors.push_back(vector1);
            break;
        }
        
        // Multiply vector with matrix
        case 13:
        {
            std::cout << "Enter x, y and z value for vector" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);

            double s, vector2, c, d, e, f, g, h, i;
            std::cout << "Enter the elements of the 3 x 3 matrix: ";
            std::cin >> s >> vector2 >> c >> d >> e >> f >> g >> h >> i;
            Matrix matrix(s, vector2, c, d, e, f, g, h, i);

            GeomVectors result = vector1.multiplyMatrix(matrix);
            std::vector<GeomVectors> vectors;
            vectors.push_back(vector1);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
            break;
        }
        
        // Find distance between two vectors
        case 14:
        {
            std::cout << "Enter x, y and z value for vector" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);

            std::cout << "Enter x,y and zvalue for vector" << std::endl;
            std::cin >> xCoordinate2 >> yCoordinate2 >> zCoordinate2;
            GeomVectors vector2(xCoordinate2, yCoordinate2, zCoordinate2);

            double result = vector1.distanceBetweenVectors(vector2);
            std::cout << "Distance between two vectors is " << result << std::endl;
            break;
        }
        
        // Find distance between vector and plane
        case 15:
        {
            double x2;
            double y2;
            double z2;
            std::cout << "Enter x, y and z value for vector" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);

            std::cout << "Enter x,y and z value for normal" << std::endl;
            std::cin >> xCoordinate2 >> yCoordinate2 >> zCoordinate2;
            GeomVectors normal(xCoordinate2, yCoordinate2, zCoordinate2);

            std::cout << "Enter 3 coordinates for point" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Point3D point(x2, y2, z2);

            Plane plane(normal, point);
            double result = vector1.distanceBetweenVectorAndPlane(plane);
            std::cout << "Distance between vector and plane is " << result << std::endl;
            break;
        }
        
        // Find angle between two vectors
        case 16:
        {

            std::cout << "Enter x, yand z value for vector" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);

            std::cout << "Enter x,y and z value for normal" << std::endl;
            std::cin >> xCoordinate2 >> yCoordinate2 >> zCoordinate2;
            GeomVectors vector2(xCoordinate2, yCoordinate2, zCoordinate2);

            double result = vector1.angleBetweenVectors(vector2);
            std::cout << "Angle between two vectors is " << result << std::endl;
            break;
        }
        
        // Find angle between vector and plane
        case 17:
        {
            double x2;
            double y2;
            double z2;
            std::cout << "Enter x, y and z value for vector" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);

            std::cout << "Enter x,y and z value for normal" << std::endl;
            std::cin >> xCoordinate2 >> yCoordinate2 >> zCoordinate2;
            GeomVectors normal(xCoordinate2, yCoordinate2, zCoordinate2);

            std::cout << "Enter 3 coordinates for point" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Point3D point(x2, y2, z2);

            Plane plane(normal, point);
            double result = vector1.angleBetweenVectorAndPlane(plane);
            std::cout << "angle between vector and plane is " << result << std::endl;
            break;
        }
        
        // Find projection on vector
        case 18:
        {
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);

            std::cout << "Enter x,y and z value for normal" << std::endl;
            std::cin >> xCoordinate2 >> yCoordinate2 >> zCoordinate2;
            GeomVectors vector2(xCoordinate2, yCoordinate2, zCoordinate2);

            GeomVectors result = vector1.projectionOnVector(vector2);
            std::vector<GeomVectors> vectors;
            vectors.push_back(vector1);
            vectors.push_back(vector2);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
            break;
        }

        // Find projection on plane
        case 19:
        {
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);

            std::cout << "Enter x,y and z value for normal" << std::endl;
            std::cin >> xCoordinate2 >> yCoordinate2 >> zCoordinate2;
            GeomVectors normal(xCoordinate2, yCoordinate2, zCoordinate2);

            GeomVectors result = vector1.projectVectorOnPlane(vector1, normal);
            std::vector<GeomVectors> vectors;
            vectors.push_back(vector1);
            vectors.push_back(normal);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
            break;
        }

        //Angle between vector and axis.
        case 20:{
            std::cout << "Enter x, y and z value for vector" << std::endl;
            std::cin >> xCoordinate1 >> yCoordinate1 >> zCoordinate1;
            GeomVectors vector1(xCoordinate1, yCoordinate1, zCoordinate1);
            cout<<"Select axis: "<<endl;
            cout<<"X"<<endl<<"Y"<<endl<<"Z"<<endl;
            char ch;
            cin>>ch;
            if(ch=='x'||ch=='X'){
                cout<<vector1.angleWithXaxis()<<" "<<"degree";
            }
            else if(ch=='y'||ch=='Y'){
                cout<<vector1.angleWithYaxis()<<" "<<"degree";
            }
             else if(ch=='z'||ch=='Z'){
                cout<<vector1.angleWithZaxis()<<" "<<"degree";
            }
            else{
                cout<<"Enter correct Axis";
            }
            break;

        }

        // Exit Loop
        case 21: 
            exitLoop = true;
            break;


        // Default for incorrect option selection
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    return 0;
}
