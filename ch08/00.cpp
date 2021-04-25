#include <iostream>
#include <cmath>

class Point2d{
private:
    double m_x{0.0};
    double m_y{0.0};

public:
    Point2d(double x = 0.0, double y = 0.0){
        m_x = x;
        m_y = y;
    }

    void print() const {
        std::cout << "Point(" << m_x << ", " << m_y << ")\n";
    }

    double distanceTo(const Point2d &p){
        double x{ m_x - p.m_x };
        double y{ m_y - p.m_y };
        return std::sqrt( x * x + y * y );
    }

    friend double distanceFrom(const Point2d &p1, const Point2d &p2);
};

double distanceFrom(const Point2d &p1, const Point2d &p2){
    double x{ p1.m_x - p2.m_x };
    double y{ p1.m_y - p2.m_y };
    return std::sqrt( x * x + y * y );
}

int main(){

    Point2d first{};
    Point2d second{3.0, 4.0};

    first.print();
    second.print();

    std::cout << "Distance between points: " << first.distanceTo(second) << "\n";
    std::cout << "Distance between points: " << distanceFrom(first, second) << "\n";

    return 0;
}