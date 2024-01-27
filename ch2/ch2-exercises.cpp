#include <cstdlib>
#include <string>
#include <iostream>

namespace TLAP {

// 3-1, 3-8
struct Student
{
    int grade;
    int studentID;
    std::string name;
};

struct Quartiles
{
    int quartile25th;
    int quartile50th;
    int quartile75th;
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

void sortStudents(Student students[], size_t size, std::string sortBy) {
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

Quartiles calculateStudentGradeQuartiles(Student students[], size_t size) {
    sortStudents(students, size, "grade");

    return Quartiles {
        students[(size / 4)].grade,
        students[size / 2].grade,
        students[size * 3 / 4].grade
    };
}

} // namespace TLAP

int main() {
    const int ARRAY_SIZE = 10;
    std::string columns[] = {"grade", "studentID", "name"};
    TLAP::Student students[ARRAY_SIZE] =
    {
        {99, 1, "Hank"},
        {100, 2, "Beth"},
        {78, 3, "Trevor"},
        {72, 4, "Sydney"},
        {82, 5, "Frank"},
        {69, 6, "Veronica"},
        {77, 7, "Felix"},
        {95, 8, "Silvia"},
        {44, 9, "Nathan"},
        {58, 10, "Jan"}
    };

    std::cout << "Printing original student array.\n";
    for (auto student : students) {
        std::cout << student.name << ", " 
                << student.studentID << ", "
                << student.grade << "\n";
    }

    for (auto column : columns) {
        std::cout << "\nPrinting student array sorted by " << column << ".\n";
        sortStudents(students, ARRAY_SIZE, column);
        for (auto student : students) {
            std::cout << student.name << ", "
                    << student.studentID << ", "
                    << student.grade << "\n";
        }
    }

    TLAP::Quartiles quartiles = calculateStudentGradeQuartiles(students, ARRAY_SIZE);
    std::cout << "\nQuartiles:\n25th Percentile: " << quartiles.quartile25th
                << "\n50th Percentile: " << quartiles.quartile50th
                << "\n75th Percentile: " << quartiles.quartile75th
                << "\n";
}