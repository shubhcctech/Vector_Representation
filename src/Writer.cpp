#include <fstream>
#include <stdexcept>
#include <iostream>
#include "../headers/Writer.h"
using namespace std;

void Writer::write(std::string &filePath,std::vector<GeomVectors> &vectors)
{
    std::ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing."<<std::endl;
    }

    // Write vector points to the txt file
    for (const GeomVectors &vector : vectors)
    {
        // Write each vector point
        outFile<<0.0<<" "<<0.0<<" "<<0.0<<endl;
        outFile <<vector.X() << " " << vector.Z() << " " << vector.Z() << endl;
        
    }
    cout<<"Data written successfully...."<<endl;
    outFile.close();
}
