#include <iostream>

int main(){

    char char1_a{'a'};
    char char2_a = 97;

    std::cout << "Char 1: " << char1_a << "\nChar 2: " << char2_a << "\n"; 

    char a{'a'};
    std::cout << a << "\n";
    std::cout << "Convert ASCII char to its integer value: " << static_cast<int>(a) << "\n";

    return 0;
}