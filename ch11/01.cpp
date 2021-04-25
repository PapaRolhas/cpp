#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

class Creature
{
protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};

public:
    Creature() = default;

    Creature(const std::string &name, const char &symbol, 
            const int &health, const int &damage, const int &gold) 
            : m_name{name}, m_symbol{symbol}, m_health{health}, m_damage{damage}, m_gold{gold}
    {
    }

    std::string getName()
    {
        return m_name;
    }

    char getSymbol()
    {
        return m_symbol;
    }

    int getHealth()
    {
        return m_health;
    }

    int getDamage()
    {
        return m_damage;
    }

    int getGold()
    {
        return m_gold;
    }

    void reduceHealth(int damage)
    {
        m_health -= damage;
    }

    bool isDead()
    {
        return m_health <= 0;
    }

    void addGold(int gold)
    {
        m_gold += gold;
    }
};

class Player : public Creature
{
private:
    int m_level{};

public:

    Player(const std::string &name) : Creature{name, '@', 10, 1, 0}, m_level{1}
    {
        welcome();
    }

    void welcome()
    {
        std::cout << "Welcome " << getName() << "\n";
        std::cout << "You have " << getHealth() << " health and are carrying " << getGold() << " gold.\n";
    }

    void levelUp()
    {
        m_level += 1;
        m_damage += 1;
    }

    int getLevel()
    {
        return m_level;
    }

    bool hasWon()
    {
        return m_level >= 20;
    }
};

class Monster : public Creature
{
public:
    enum class Type
    {
        DRAGON,
        ORC,
        SLIME,

        MAX_TYPES
    };

    Monster(const Type &type) : Creature{getDefaultCreature(type)}
    {
    }

    static const Creature& getDefaultCreature(Type type)
    {
        static std::array<Creature, static_cast<std::size_t>(Type::MAX_TYPES)> monsterData{
            { { "dragon", 'D', 20, 4, 100 },
            { "orc", 'o', 4, 2, 25 },
            { "slime", 's', 1, 1, 10 } }
        };

        return monsterData.at(static_cast<std::size_t>(type));
    }

    static Monster getRandomMonster()
    {
        static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };
        int randNum = 0 + static_cast<int>(((static_cast<int>(Type::MAX_TYPES) - 1) - 0 + 1) * (std::rand() * fraction));

        return Monster{ static_cast<Type>(randNum) };
    }
};

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand(); // get rid of first result

    void fightMonster(Player &player);
    char getAction(void);
    int  getRandomNumber(int min, int max);

    std::cout << "Enter a name: ";
    std::string name{};
    std::cin  >> name;

    Player player{name};

    while(!player.isDead() && !player.hasWon())
        fightMonster(player);

    if(player.isDead())
    {
        std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you.\n";
    }

    return 0;
}

void fightMonster(Player &player)
{
    char getAction(void);
    int getRandomNumber(int min, int max);
    char a{};

    Monster m{ Monster::getRandomMonster() };
    std::cout << "You have encontered a " << m.getName() << " (" << m.getSymbol() << ")" << ".\n";

    do
    {
        a = getAction();
        if(a == 'r')
        {
            /*  If is 0 then player does not escapes the monster */
            if(getRandomNumber(0,1) == 0)
            {
                player.reduceHealth(m.getDamage());
                std::cout << "You failed to flee.\n";
                std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
            }
            else
            {
                std::cout << "You successfully fled\n";
                break;
            }
        }
        else if(a == 'f')
        {
            m.reduceHealth(player.getDamage());
            std::cout << "You hit the " << m.getName() << " for " << player.getDamage() << " damage.\n";
            if(m.isDead())
            {
                std::cout << "You killed the " << m.getName() << ".\n";
                player.levelUp();
                std::cout << "You are now level " << player.getLevel() << ".\n";
                player.addGold(m.getGold());
                std::cout << "You found " << m.getGold() << " gold.\n";
                break;
            }

            player.reduceHealth(m.getDamage());
            std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
            if(player.isDead())
                break;
        }
    } while (!m.isDead());
}

char getAction()
{
    char a{};

    do
    {
        std::cout << "(R)un or (F)ight: ";
        std::cin >> a;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
        {
            std::cin.ignore(32767, '\n');
        }
    } while ( a != 'r' && a != 'f');
    
    return a;
}

int getRandomNumber(int min, int max)
{
    static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}