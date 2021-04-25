#include <iostream>
#include <cstdint>

class Average
{
private:
    std::int_least32_t m_total{};
    std::int_least8_t  m_numbers{};
    double avg{};

public:
    Average() = default;

    Average(Average &avg)
    {
        m_total = avg.m_total;
        m_numbers = avg.m_numbers;
    }

    Average& operator+=(const int n);
    friend std::ostream& operator<<(std::ostream &out, const Average &avg);
};

Average& Average::operator+=(const int n)
{
    m_total += n;
    m_numbers++;
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Average &avg)
{
    out << static_cast<double>(avg.m_total) / avg.m_numbers;
    return out;
}

int main()
{
    Average avg{};

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10; // 2 calls chained together
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{ avg };
    std::cout << copy << '\n';

    return 0;
}