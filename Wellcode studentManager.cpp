#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int score;

    Student(string n, int s) {
        name = n;
        score = s;
    }
};

void addStudent(vector<Student>& students){
    string name;
    int score;
    cout<< "Enter student name :";
    getline(cin, name);
    cout << "Enter student score (0-100): ";
    cin >> score;
    cin.ignore();
    while (score < 0 || score > 100) {
    cout << "Invalid score. Enter 0 to 100: ";
    cin >> score;
    cin.ignore();
}
    students.push_back(Student(name, score));
}

void displayStudents(const vector<Student>& students) {
    cout << "\nList of Students:\n";
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Score: " << student.score << endl;
    }
}
double averageScore(const vector<Student>& students) {
    if (students.empty()) {
        return 0.0;
    }       
    double total = 0;
    for (const auto& student : students) {
        total += student.score;
    }
    return total / students.size();

}
string topStudent(const vector<Student>& students){
    if (students.empty()){
        return "There is no student registered";    
    }int maxscore = students[0].score;
    string topStudentName = students[0].name;
    for (const auto& student : students) {
        if (student.score > maxscore) {
            maxscore = student.score;
            topStudentName = student.name;
        }
    }       
    return topStudentName;
}
void saveStudents(const vector<Student>& students){
    ofstream file("students.txt");
    if (!file.is_open()) return;
    for (const auto& student : students) {
         
            file << student.name << " " << student.score << endl;
        
    }
    file.close();
}

void loadStudents(vector<Student>& students) {
    ifstream file("students.txt");
    if (file.is_open()) {
        string name;
        int score;
        while (file >> name >> score) {
            students.push_back(Student(name, score));
        }
        file.close();
    }
}
bool deleteStudent(vector<Student>& students, const string& name) {
    for( int  i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            students.erase(students.begin() + i);
            return true;
        }

    }
        return false;
}
bool updateStudent(vector<Student>& students, const string& name, int newScore) {
    for (auto& student : students) {
        if (student.name == name) {
            student.score = newScore;
            return true;
        }
    }
    return false;
}
void showRanking(vector<Student> students){
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score;
    });
    cout << "\nStudent Rankings:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << i + 1 << ". Name: " << students[i].name << ", Score: " << students[i].score << endl;
    }



}
int main() {
    vector<Student> students;
   
loadStudents(students);
    int choice;
    
    do {
        cout << "\n1. Add student\n2. Show all students\n3. Statistics\n4. Delete Student\n5. Update Student\n6. Exit\n";
        cout << "Enter your choice (1-6): ";
cin >> choice;
if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    choice = 0;          // triggers "Invalid choice"
} else {
    cin.ignore();        // normal leftover newline
}

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                cout << " 1 Average Score: " << averageScore(students) << endl;
                cout << " 2 Top Student: " << topStudent(students) << endl;
                showRanking(students);
                break;
            case 4:
                {
                    string name;
                    cout << "Enter the name of the student to delete: ";
                    
                    getline(cin, name);
                    if (deleteStudent(students, name)) {
                        cout << "Student deleted successfully." << endl;
                    } else {
                        cout << "Student not found." << endl;
                    }
                }
                break;
            case 5:
                {
                    string name;
                    int newScore;
                    cout << "Enter the name of the student to update: ";
              
                    getline(cin, name);
                    cout << "Enter the new score: ";
                    cin >> newScore;
                    cin.ignore();
                    if (newScore < 0 || newScore > 100) {
                        cout << "Invalid score. Please enter a score between 0 and 100." << endl;
                        break;
                    }
                    if (updateStudent(students, name, newScore)) {
                        cout << "Student updated successfully." << endl;
                    } else {
                        cout << "Student not found." << endl;
                    }
                }
                break;
            case 6:
                saveStudents(students);
                cout << "Goodbye " << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 6);

    return 0;
}
