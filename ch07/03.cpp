#include <iostream>

#define NUMBER 0

void printDEC2BIN(int n);

int main(){

    printDEC2BIN(NUMBER);

    return 0;
}

void printDEC2BIN(int n){
    if(n == 1)
        std::cout << 1;
    else if(n == 0)
        std::cout << 0;
    else{
        printDEC2BIN(n/2);
        std::cout << n%2;
    }
}