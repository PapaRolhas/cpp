#include <iostream>

#define NUMBER 93427

int sumOfEachInt(int n);

int main(){

    std::cout << "The sum of each individual number of #" << NUMBER << " is: " << sumOfEachInt(NUMBER) << "\n";

    return 0;
}

int sumOfEachInt(int n){
    if(n == 0)
        return 0;
    else{
        int r = n%10;
        n = n/10;
        return r + sumOfEachInt(n);
    }
}