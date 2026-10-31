#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Student
{
public:
    string name;
    int score;

    Student(string n, int s);
};

Student::Student(string n, int s)
{
    name = n;

    score = s;
}
Student findTopStudent(const vector<Student> &students)
{
    if (students.empty())
    {
        return Student("", 0);
    }

    Student highestStudent = students[0];
    for (const Student &student : students)
    {
        if (student.score > highestStudent.score)
        {
            highestStudent = student;
        }
    }
    return highestStudent;
}
int binarySearch(const vector<int> &target, int key)
{
    int low = 0;
    int high = static_cast<int>(target.size()) - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (target[mid] == key)
        {
            return mid;
        }
        if (target[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}
void saveStudents(const vector<Student> &students)
{
    ofstream file("students.txt");
    for (const Student &s : students)
    {
        file << s.name << " " << s.score << endl;
    }
}
vector<Student> loadStudents()
{
    vector<Student> students;
    ifstream file("students.txt");
    string name;
    int score;

    while (file >> name >> score)
    {
        students.push_back(Student(name, score));
    }
    return students;
}
// To find the highest score when they are more than one
vector<Student> findTopStudents(const vector<Student> &students)
{
    if (students.empty())
    {
        return {};
    }
    int highestScore = students[0].score;
    for (const Student &student : students)
    {
        if (student.score > highestScore)
        {
            highestScore = student.score;
        }
    }

    vector<Student> topStudents;
    for (const Student &student : students)
    {
        if (student.score == highestScore)
        {
            topStudents.push_back(student);
        }
    }
    return topStudents;
}
int main()
{

    vector<Student> students;
    Student s1("Abebe", 85);
    Student s2("Mimi", 92);
    Student s3("Dawit", 76);
    Student s4("Sara", 92);
    students.push_back(s1);
    students.push_back(s2);
    students.push_back(s3);

    students.push_back(s4);

    saveStudents(students); // the vector is full now, so save it

    vector<Student> topStudents = findTopStudents(students);

    if (topStudents.empty())
    {
        cout << "No students found." << endl;
    }
    else
    {
        cout << "Highest score: " << topStudents[0].score << endl;
        cout << "Top students:" << endl;
        for (const Student &student : topStudents)
        {
            cout << student.name << " - " << student.score << endl;
        }
    }
    vector<int> v = {2, 5, 8, 12, 16, 23, 38};

    cout << binarySearch(v, 23) << endl;
    cout << binarySearch(v, 2) << endl;
    cout << binarySearch(v, 38) << endl;
    cout << binarySearch(v, 7) << endl;
    ifstream("students.txt");

    return 0;
}
