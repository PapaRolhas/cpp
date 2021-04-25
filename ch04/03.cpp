#include "constants.h"
#include <iostream>

int main(){

    std::cout << "Enter the radius of the circumference: ";
    double r{};
    std::cin  >> r;

    std::cout << "The area of the circumference is: " << constants::pi*r*r;

    return 0;
}