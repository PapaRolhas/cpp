#include <iostream>
#include <string>

template <class T1, class T2>
class Pair
{
protected:
    T1 m_x;
    T2 m_y;

public:
    Pair(const T1& x, const T2& y) : m_x{x}, m_y{y} 
    {
    }

    const T1& first() const
    {
        return m_x;
    }

    const T2& second() const
    {
        return m_y;
    }
};

template <class T>
class StringValuePair : public Pair<std::string, T>
{
private:
public:
    StringValuePair(const std::string& str, const T& val) : Pair<std::string, T>(str, val)
    {
    }

    void print()
    {
        std::cout << "Pair: " << (*this).first() << ' ' << this->second() << '\n';
    }
};

int main()
{
    StringValuePair<int> svp("Hello", 5);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    svp.print();

    return 0;
}