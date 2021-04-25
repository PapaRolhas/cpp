#include <iostream>
#include <cstdint>
#include <cmath>
#include <limits>

class FixedPoint2
{
private:
    std::int_least16_t  m_base{};
    std::int_least8_t  m_decimal{};

public:
    FixedPoint2()
    {
        m_base = 0;
        m_decimal = 0;
    }

    FixedPoint2(const double d)
    {
        m_base = static_cast<std::int_least16_t>(d);
        double decimal = d - m_base;
        m_decimal = std::round(decimal * 100);
    }

    FixedPoint2(const std::int_least16_t &dec, const std::int_least8_t &frac) : m_base{dec}, m_decimal{frac}
    {
        if (m_base < 0 || m_decimal < 0)
        {
            if (m_base > 0)
                m_base = -m_base;
            if (m_decimal > 0)
                m_decimal = -m_decimal;
        }
    }

    friend std::ostream& operator<<(std::ostream &out, const FixedPoint2 &fp);
    friend std::istream& operator>>(std::istream &in, FixedPoint2 &fp);
    friend bool operator==(const FixedPoint2 &fp1, const FixedPoint2 &fp2);

    operator double() const
    {
        return m_base + static_cast<double>(m_decimal) / 100.0;
    }

    FixedPoint2 operator-() const
    {
        return FixedPoint2{-m_base, -m_decimal};
    }
};

std::ostream& operator<<(std::ostream &out, const FixedPoint2 &fp)
{
    out << static_cast<double>(fp);
    return out;
}

std::istream& operator>>(std::istream &in, FixedPoint2 &fp)
{
    double d{};
    in >> d;
    fp = FixedPoint2(d);

    return in;
}

FixedPoint2 operator+(const FixedPoint2 &fp1, const FixedPoint2 &fp2)
{
    return FixedPoint2{static_cast<double>(fp1) + static_cast<double>(fp2)};
}

bool operator==(const FixedPoint2 &fp1, const FixedPoint2 &fp2)
{
    return (fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal);
}

int main()
{
    void testAddition(void);

    testAddition();

    FixedPoint2 a{ -0.48 };
    std::cout << a << '\n';

    std::cout << -a << '\n';

    std::cout << "Enter a number: "; // enter 5.678
    std::cin >> a;

    std::cout << "You entered: " << a << '\n';

    return 0;
}

void testAddition()
{
    std::cout << std::boolalpha;
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}