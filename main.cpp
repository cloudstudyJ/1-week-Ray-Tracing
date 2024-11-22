#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;

#include "objects/sphere.hpp"

int main() {
    ofstream writer("./output.ppm");

    if (writer) {
        cout << "Write Image" << endl;

        unsigned int imgW = 512;
        unsigned int imgH = 512;

        // Render here
        Sphere sphere;

        writer << "P3 " << imgW << ' ' << imgH << endl;
        writer << 255 << endl;
    }

    return 0;
}