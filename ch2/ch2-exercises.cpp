#include <cstdlib>
#include <string>
#include <iostream>

namespace TLAP {

// 3-1
struct Student
{
    int grade;
    int studentID;
    std::string name;
};

int compareStudentGrade(const void* s1, const void* s2) { 
    Student* student1 = (Student*)s1;
    Student* student2 = (Student*)s2;
    return student1->grade - student2->grade;
}

int compareStudentID(const void* s1, const void* s2) {
    Student* student1 = (Student*)s1;
    Student* student2 = (Student*)s2;
    return student1->studentID - student2->studentID;
}

int compareStudentName(const void* student1, const void* student2) {
    Student* s1 = (Student*)student1;
    Student* s2 = (Student*)student2;
    return s1->name.compare(s2->name);
}

void sortStudent(Student* students, size_t size, std::string sortBy) {
    if (sortBy == "grade") {
        std::qsort(students, size, sizeof(Student), compareStudentGrade);
    }
    else if (sortBy == "studentID") {
        std::qsort(students, size, sizeof(Student), compareStudentID);
    }
    else if (sortBy == "name") {
        std::qsort(students, size, sizeof(Student), compareStudentName);
    }
}

} // namespace TLAP

int main() {
    std::string columns[3] = {"grade", "studentID", "name"};
    TLAP::Student students[2] =
    {
        {100, 1, "Tyler"},
        {99, 2, "Carolyn"}
    };

    std::cout << "Printing original student array.\n";
    for (auto student : students) {
        std::cout << student.name << ", " 
                << student.studentID << ", "
                << student.grade << "\n";
    }

    for (auto column : columns) {
        std::cout << "\nPrinting student array sorted by " << column << ".\n";
        sortStudent(students, 2, column);
        for (auto student : students) {
            std::cout << student.name << ", "
                    << student.studentID << ", "
                    << student.grade << "\n";
        }
    }
}