#include <iostream>
#include <random>
#include <ctime>

#define MAX_RAND 100
#define MIN_RAND 1

int main()
{
    bool keepPlaying();
    bool play(int number, int tries);
    int  getIntValueBetween(int min, int max);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    int number{rand()};
    int tries{7};

    do{
        std::cout << "Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.\n";
        number = getIntValueBetween(MIN_RAND, MAX_RAND);
        tries = 7;
        
        if(play(number, tries))
            std::cout << "Correct! You win\n";
        else
            std::cout << "Sorry, you lose. The correct number was " << number << "\n";
        
    }while(keepPlaying());

    return 0;
}

bool play(int number, int tries){
    int guessIteration{};
    int guess{};

    while(tries > 0){
        std::cout << "Guess #" << guessIteration << ": ";
        std::cin  >> guess;

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else{
            std::cin.ignore(32767, '\n');
            if(guess > number)
                std::cout << "Your guess is to high!\n";
            else if(guess < number)
                std::cout << "Your guess is to low!\n";
            else{
                return true;
            }

            tries--;
            guessIteration++;
        }
    }

    return false;
}

int getIntValueBetween(int min, int max){
    return (int) (min + ((float) rand()/RAND_MAX * (max-min)));
}

bool keepPlaying(){
    char c{};
    do{
        std::cout << "Would you like to keep playing ? (y/n)\t";
        std::cin  >> c;

        switch(c){
            case 'y':
                return true;
            case 'n':
                std::cout << "Thank you for playing.\n";
                return false;
        }

    }while(c != 'y' && c != 'n');
    
    std::cout << "Something went wrong!\n";
    return false;
}