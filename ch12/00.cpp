#include <iostream>
#include <vector>

class Point
{
private:
    int m_x{ 0 };
    int m_y{ 0 };
    int m_z{ 0 };

public:
    Point(int x, int y, int z)
        : m_x{x}, m_y{y}, m_z{z}
    {

    }

    friend std::ostream& operator<<(std::ostream &out, const Point &p)
    {
        out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';
        return out;
    }
};

class Shape
{
private:

public:
    virtual std::ostream& print(std::ostream &out) const = 0;

    friend std::ostream& operator<<(std::ostream &out, Shape &shape)
    {
        return shape.print(out);
    }

    ~Shape()
    {
    }
};

class Circle : public Shape
{
private:
    Point m_center;
    int m_radius{};

public:
    Circle(const Point &center, const int &radius)
        : m_center{center}, m_radius{radius}
    {
    }

    virtual std::ostream& print(std::ostream &out) const
    {
        out << "Circle(" << m_center << ", radius " << m_radius << ")";
        return out;
    }

    int getRadius()
    {
        return m_radius;
    }
};

class Triangle : public Shape
{
private:
    Point m_point1;
    Point m_point2;
    Point m_point3;

public:
    Triangle(const Point &p1, const Point &p2, const Point &p3)
        : m_point1{p1}, m_point2{p2}, m_point3{p3}
    {
    }

    virtual std::ostream& print(std::ostream &out) const
    {
        out << "Triangle(" << m_point1 << ", " << m_point2 << ", " << m_point3 << ")";
        return out;
    }
};

int main()
{
    int getLargestRadius(std::vector<Shape*> &v);

    std::vector<Shape*> v{
        new Circle{Point{1, 2, 3}, 7},
        new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
        new Circle{Point{4, 5, 6}, 3}
    };

    for(auto shape : v)
        std::cout << (*shape) << "\n";
    std::cout << "\n";

    std::cout << "The largest radius is: " << getLargestRadius(v) << "\n";

    return 0;
}

int getLargestRadius(std::vector<Shape*> &v)
{
    int max{};

    for(auto shape : v)
    {
        Circle *c = dynamic_cast<Circle*>(shape);
        if(c)
        {
            if((*c).getRadius() > max)
                max = (*c).getRadius();
        }
    }

    return max;
}