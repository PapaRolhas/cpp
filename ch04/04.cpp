#include <iostream>

double enterNumber_double();
void   doMath(double d1, double d2);
bool   isOperand(char c);

int main(){

    double d1{enterNumber_double()};
    double d2{enterNumber_double()};

    doMath(d1, d2);

    return 0;
}

double enterNumber_double(){
    std::cout << "Enter a double: ";
    double d{};
    std::cin  >> d;
    return d; 
}

void doMath(double d1, double d2){
    std::cout << "Enter one of the following: +, -, * or / : ";
    char c{};
    std::cin  >> c;

    if(isOperand(c)){
        if(c == '+')
            std::cout << d1 << " " << c << " " << d2 << " = " << d1 + d2;
        if(c == '-')
            std::cout << d1 << " " << c << " " << d2 << " = " << d1 - d2;
        if(c == '*')
            std::cout << d1 << " " << c << " " << d2 << " = " << d1 * d2;
        if(c == '/')
            std::cout << d1 << " " << c << " " << d2 << " = " << d1 / d2;
    }
}

bool isOperand(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}