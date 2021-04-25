#include <iostream>

int readNumber();
bool isPrime(int num);

int main(){

    int num{readNumber()};

    if(isPrime(num))
        std::cout << num << " is prime!\n";
    else
        std::cout << num << " is not prime!\n";

    return 0;
}

int readNumber(){
    std::cout << "Enter an integer: ";
    int num{};
    std::cin  >> num;
    return num;
}

bool isPrime(int num){
    for(int i=2; i<num/2+1; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}