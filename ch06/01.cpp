#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct students_t{
    std::string name{};
    int grade{};
};

void enterStudentsList(std::vector<students_t> &list);
void showStudentsList(const std::vector<students_t> &list);

bool compareStudents(students_t s1, students_t s2);

int main(){

    std::vector<students_t> studentsList{0};

    std::cout << "How many students do you want to enter? ";
    int length{};
    std::cin  >> length;

    studentsList.resize(length);

    enterStudentsList(studentsList);

    std::sort(studentsList.begin(), studentsList.end(), compareStudents);

    showStudentsList(studentsList);

    return 0;
}

void enterStudentsList(std::vector<students_t> &list){
    for(int i=0; i<list.size(); i++){
        std::cin >> list.at(i).name;
        std::cin >> list.at(i).grade;
    }
}

void showStudentsList(const std::vector<students_t> &list){
    std::cout << "\n\n";
    for(students_t student : list){
        std::cout << student.name << " got a grade of " << student.grade << "\n";
    }
}

bool compareStudents(students_t s1, students_t s2){
    if(s1.grade > s2.grade)
        return true;
    else
        return false;
}