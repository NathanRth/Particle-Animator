#include "vector.h"

#include <fstream>
#include <array>
#include <cmath>
#include <iostream>

using namespace std;

// ./wave [name]
int main(int argc, char *argv[])
{

    if(argc != 2)
    {
        return EXIT_FAILURE;
    }

    float time_step = 0.1;
	int nb_frames = 150;
	const int nb_points = 100;

    ofstream outfile;

    array<Vector, nb_points> points;
    for(int i = 0; i < 10; i++)
    {
        for(int  j = 0; j < 10; j++)
        {
            points[i*10+j] = Vector(static_cast<float>(i),0,static_cast<float>(j));
        }
    }

    outfile.open(argv[1], ios::out);

    outfile << "#PV==" << endl;
    outfile << 0.1 << endl;
    outfile << nb_points << endl;
    outfile << nb_frames << endl;

    for(int lgn=0; lgn<10; lgn++)
		outfile << "oLine " << 10*lgn << ":" << 10*(lgn+1)-1 << endl;
	outfile << "====" << endl;

    float amplitude = 0.1;
    float speed = 0.5;

    for(int i = 0; i < nb_frames ; i++)
    {
        for(int j = 0; j < nb_points; j++)
        {
            points[j].y = sin( static_cast<float>(i+(j%10)) * speed) * amplitude;
            outfile << points[j] << endl;
        }
    }

    outfile.close();

	return 0;
    
}