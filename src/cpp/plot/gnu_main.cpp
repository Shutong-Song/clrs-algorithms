#include <vector>
#include <cmath>
#include <boost/tuple/tuple.hpp>
#include "gnuplot-iostream.h"

//how to run this: use c++17
//install step1: sudo apt-get install libboost-all-dev
//install step2: add gnuplot-iostream.h file to the same folder as the main plot file 
//g++ -std=c++17 gnu_main.cpp -o main -lboost_iostreams -lboost_system -lboost_filesystem


//gnuplot on terminal:
//install: sudo apt-get install gnuplot
//run: $gnuplot
//then: plot exp(-x**2 / 2)

int main() {
    Gnuplot gp;
    std::vector<boost::tuple<double, double, double, double> > pts_A;
    std::vector<double> pts_B_x;
    std::vector<double> pts_B_y;
    std::vector<double> pts_B_dx;
    std::vector<double> pts_B_dy;
    for(double alpha=0; alpha<1; alpha+=1.0/24.0) {
        double theta = alpha*2.0*3.14159;
        pts_A.push_back(boost::make_tuple(
             cos(theta),
             sin(theta),
            -cos(theta)*0.1,
            -sin(theta)*0.1
        ));

        pts_B_x .push_back( cos(theta)*0.8);
        pts_B_y .push_back( sin(theta)*0.8);
        pts_B_dx.push_back( sin(theta)*0.1);
        pts_B_dy.push_back(-cos(theta)*0.1);
    }
    gp << "set xrange [-2:2]\nset yrange [-2:2]\n";
    gp << "plot '-' with vectors title 'pts_A', '-' with vectors title 'pts_B'\n";
    gp.send1d(pts_A);
    gp.send1d(boost::make_tuple(pts_B_x, pts_B_y, pts_B_dx, pts_B_dy));


    //Gnuplot gp;
    //std::vector<int> x = {1, 2, 3, 4, 5};
    //gp << "plot '-' with points\n";
    //gp.send1d(x);
    //gp.send(x);
    //std::vector<double> y_pts;
    //for(int i=0; i<1000; i++) {
    //    double y = (i/500.0-1) * (i/500.0-1);
    //    y_pts.push_back(y);
    //}

    //gp << "plot '-' with lines, sin(x/200) with lines\n";
    //gp.send(y_pts);


    //Gnuplot plot;
    //plot("set border 4095");
    //plot("splot \"C:/\\Users/\\lRaulMN/\\Desktop/\\Datafile.dat\" with lines");

} // very simple tool right???