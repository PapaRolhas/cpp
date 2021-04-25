#include <iostream>

int getNumber(void);
char getOperation(void);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int (*getArithmeticFunction(char op))(int, int);

int main(){

    int val1{getNumber()};
    int val2{getNumber()};

    char op{getOperation()};

    using arithmeticFcn = int (*)(int,int);
    int (*pFcn)(int, int){};
    
    pFcn = getArithmeticFunction(op);

    std::cout << val1 << " " << op << " " << val2 << " = " << pFcn(val1, val2);

    return 0;
}

int getNumber(){
    std::cout << "Enter a number: ";
    int n{};
    std::cin  >> n;

    return n;
}

char getOperation(){
    do{
        std::cout << "Enter an operation (+, -, *, /): ";
        char op{};
        std::cin  >> op;

        switch(op){
            case '+':
                return '+';
            case '-':
                return '-';
            case '*':
                return '*';
            case '/':
                return '/';
            default:
                std::cout << "Wrong operation!\n";
                break;
        }
    }while(true);
}

int sum(int a, int b){
    return a+b;
}

int subtract(int a, int b){
    return a-b;
}

int multiply(int a, int b){
    return a*b;
}

int divide(int a, int b){
    return a/b;
}

int (*getArithmeticFunction(char op))(int, int){
    switch(op){
        case '+':
            return &sum;
        case '-':
            return &subtract;
        case '*':
            return &multiply;
        case '/':
            return &divide;
        default:
            std::cout << "? Applying sum";
            return &sum;
    }
}