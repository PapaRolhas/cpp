#include <iostream>
#include <string>
#include <array>
#include <algorithm>

struct Student{
    std::string name{};
    int grade{};
};

bool maxGrade(Student a, Student b){
    return a.grade < b.grade;
}

int main(){

    const std::array<Student, 8> arr{
    {   { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 },
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } }
    };

    auto result = std::max_element(arr.begin(), arr.end(), maxGrade);

    std::cout << (*result).name << " is the best student with a grade of: " << (*result).grade << "\n";

    return 0;
}