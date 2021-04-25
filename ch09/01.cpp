#include <iostream>
#include <cassert>

class IntArray
{
private:
    int *m_intPtr{nullptr};
    int m_length{0};

public:
    IntArray(int length)
    {
        assert(length > 0);

        m_length = length;
        m_intPtr = new int[length]{};
    }

    IntArray(const IntArray &a)
    {
        m_intPtr = new int[a.m_length];
        m_length = a.m_length;

        for(int i = 0; i < a.m_length; i++)
            m_intPtr[i] = a.m_intPtr[i];
    }

    ~IntArray()
    {
        delete [] m_intPtr;
    }

    int& operator[](const int index)
    {
        assert(index >= 0);
        assert(index < m_length);

        return m_intPtr[index];
    }

    IntArray& operator=(const IntArray &a)
    {
        if(this == &a)
            return *this;

        delete [] m_intPtr;

        m_length = a.m_length;

        m_intPtr = new int[m_length];

        for(int i = 0; i < a.m_length; i++)
            m_intPtr[i] = a.m_intPtr[i];
        
        return *this;
    }

    friend std::ostream& operator<<(std::ostream &out, const IntArray &a);
};

std::ostream& operator<<(std::ostream &out, const IntArray &a)
{
    for(int i = 0; i < a.m_length; i++)
        out << a.m_intPtr[i] << " ";

    return out;
}

IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main()
{
    IntArray a{ fillArray() };
    std::cout << a << '\n';

    auto &ref{ a };
    a = ref;
    std::cout << a << '\n';

    IntArray b(1);
    b = a;
    std::cout << b << '\n';

    return 0;
}