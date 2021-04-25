#include <iostream>
#include <array>

enum class playerBag{
    HEALTH_POTIONS,
    TORCHES,
    ARROWS
};


int countTotalItems(std::array<int, 3> bag);

int main(){

    std::array<int, 3> bag = {2, 5, 10};

    std::cout << "Player's bag has " << bag[static_cast<int>(playerBag::TORCHES)] << " torches.\n";
    std::cout << "Player's bag has " << countTotalItems(bag) << " items.\n";

    return 0;
}

int countTotalItems(std::array<int, 3> bag){
    int sum{};
    for(int i: bag){
        sum = sum + i;
    }

    return sum;
}