#include <iostream>
#include <stdexcept>
#include <string>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:

    Fraction(int n, int d) : m_numerator{n}, m_denominator{d}
    {
        if(d == 0)
            throw std::runtime_error("Invalid denominator");
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f)
    {
        out << f.m_numerator << "/" << f.m_denominator << "\n";
        return out;
    }
};

int main()
{
    std::cout << "Enter numerator: ";
    int n{};
    std::cin  >> n;

    std::cout << "Enter denominator: ";
    int d{};
    std::cin  >> d;

    try
    {
        Fraction fraction{n, d};
        std::cout << fraction;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    return 0;
}