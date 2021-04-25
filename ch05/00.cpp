#include "constants.h"
#include <iostream>

double getHeight();
double calculateCurrentHeight(int t, double h);

int main(){

    double h{getHeight()};
    int t = 0;


    while(true){
        std::cout << "At " << t << "s, the ball is at height: " << calculateCurrentHeight(t, h) << "m\n";
        if(calculateCurrentHeight(t, h) <= 0){
            std::cout << "Ball has reached the ground at t=" << t << "s\n";
            break;
        }
        t++;
    }

    return 0;
}

double getHeight(){
    std::cout << "Enter the height of the tower in meters: ";
    double h{};
    std::cin  >> h;
    return h;
}

double calculateCurrentHeight(int t, double h){
    return h - constants::gravity * t * t / 2;
}