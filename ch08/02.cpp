#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Monster{
public:
    enum Type{
        DRAGON,
        GOBLIN,
        OGRE,
        ORC,
        SKELETON,
        TROLL,
        VAMPIRE,
        ZOMBIE,
        MAX_MONSTER_TYPES
    };

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};

public:
    Monster(Type monster, std::string name, std::string roar, int hitPoints) : 
        m_type{monster}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints} {
    }

    friend std::string getTypeString(Monster::Type &type);

    void print(){
        std::cout << m_name << " the " << getTypeString(m_type) << " has " << m_hitPoints <<
            " hit points and says " << m_roar << "\n";
    }

    std::string getTypeString(Monster::Type &type){
        switch(type){
            case Monster::Type::DRAGON:
                return "Dragon";
            case Monster::Type::GOBLIN:
                return "Goblin";
            case Monster::Type::OGRE:
                return "Ogre";
            case Monster::Type::ORC:
                return "Orc";
            case Monster::Type::SKELETON:
                return "Skeleton";
            case Monster::Type::TROLL:
                return "Troll";
            case Monster::Type::VAMPIRE:
                return "Vampire";
            case Monster::Type::ZOMBIE:
                return "Zombie";
            default:
                return "Error";
    };
}

};

class MonsterGenerator{
private:

public:
    static Monster generateMonster(){
        
        static std::string s_names[6] = {"Butcher", "King Leoric", "Lazarus", "Diablo", "Andariel", "Duriel"};
        static std::string s_roars[6] = {"*Fresh meat!*", "*muahaha*", "*Get ready to die!*", "*pesants*", "*Die*", "*You are dead already*"};

        Monster::Type type{static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::MAX_MONSTER_TYPES)-1))};
        int hitPoints{getRandomNumber(1, 100)};
        std::string name = s_names[getRandomNumber(0, 5)];
        std::string roar = s_roars[getRandomNumber(0, 5)];

        return Monster{type, name, roar, hitPoints};
    }

    static int getRandomNumber(int min, int max){
        static constexpr double fraction{1.0 / (static_cast<double>(RAND_MAX) + 1.0)};
        return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
    }
};

int main(){
    std::srand(std::time(0));
    std::rand();

    Monster skeleton{Monster::Type::SKELETON, "Bones", "*rattle*", 4};
    skeleton.print();

    Monster m{MonsterGenerator::generateMonster()};
    m.print();

    return 0;
}


