#include "constants.h"
#include <iostream>

double getHeight();
double calculateCurrentHeight(int t, double h);

int main(){

    double h{getHeight()};
    int t = 0;


    do{
        std::cout << "At " << t << "s, the ball is at height: " << calculateCurrentHeight(t, h) << "m\n";
        t++;
    }while(calculateCurrentHeight(t, h) >= 0);

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