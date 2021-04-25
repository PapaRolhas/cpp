#include <iostream>

#define NUMBER 7

int factorial(int n);

int main(){

    for(int i=0; i<NUMBER; i++){
        std::cout << "Factorial #" << i << ": " << factorial(i) << "\n";
    }

    return 0;
}

int factorial(int n){
    if(n == 0)
        return 1;
    else{
        return n * factorial(n-1);
    }
}