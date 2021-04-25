#include <iostream>

void swap(int &a, int &b);

int main(){

    int a{15};
    int b{0};

    std::cout << "a: " << a << "\nb: " << b << "\n\n";

    swap(a, b);

    std::cout << "After swapping.\n";
    std::cout << "a: " << a << "\nb: " << b << "\n\n";

    return 0;
}

void swap(int &a, int &b){
    int tmp{};
    tmp = a;
    a = b;
    b = tmp;   
}