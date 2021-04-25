#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <cmath>

// #define DEBUG

int getIntNumber(){
    while(true){
        int num{};
        std::cin  >> num;
        
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else{
            std::cin.ignore(32767, '\n');
            return num;
        }
    }
}

int getRandNumber(){
    return (rand()%3 + 2);
}

void guessGame(std::vector<int> &arr);

int main(){
    srand(time(NULL));

    std::cout << "Start where? ";
    int start{getIntNumber()};
    std::cout << "How many? ";
    int amountOfNumbers{getIntNumber()};

    int randInt{getRandNumber()};

    std::vector<int> arr{};
    arr.resize(amountOfNumbers);

    for(int i=0; i<amountOfNumbers; i++){
        arr.at(i) = (start+i)*(start+i) * randInt;
#ifdef DEBUG
        std::cout << arr.at(i) << "\n";
#endif
    }
    std::cout << "I generated " << amountOfNumbers << " square numbers. Do you know each number is after multiplying it by " << randInt << "?\n";

    guessGame(arr);

    return 0;
}

void guessGame(std::vector<int> &arr){
    int guess{};

    while(true){
#ifdef DEBUG
    for(auto el : arr){
        std::cout << el << "  ";
    }
    std::cout << "\n\n";
#endif
        guess = getIntNumber();
        
        auto found{std::find(arr.begin(), arr.end(), guess)};

        if(found == arr.end()){
            auto closestGuess{std::min_element(arr.begin(), arr.end(), [guess](int a, int b){
                return std::abs(a-guess) < std::abs(b-guess); 
            })};

            if(std::abs(closestGuess[0]-guess) <= 4){
                std::cout << guess << " is wrong. Try " << closestGuess[0] << " next time.\n";
                return;
            }
            else{
                std::cout << guess << " is wrong.\n";
                return;
            }
        }
        else{
            arr.erase(found);
            std::cout << "Nice! " << arr.size() << " numbers left.\n";
            
            if(arr.size() == 0){
                std::cout << "Nice! You found all numbers, good job!\n";
                return;
            }
        }
    }
}