#include <iostream>
#include <string>

void printCharByChar(const char* string);

int main(){

    char const *str = "Hello, world!";

    printCharByChar(str);

    return 0;
}

void printCharByChar(const char* string){
    for(int i=0; ; i++){
        if(*(string+i) == '\0')
            return;
        std::cout << *(string+i);
    }
}