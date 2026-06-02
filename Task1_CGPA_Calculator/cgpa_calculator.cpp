#include <iostream>
#include <vector>
using namespace std;

struct Course {
    string name;
    float grade;
    int credits;
};

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    vector<Course> courses(n);

    float totalCredits = 0;
    float totalPoints = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << " name: ";
        cin >> courses[i].name;

        cout << "Grade (0-10): ";
        cin >> courses[i].grade;

        cout << "Credits: ";
        cin >> courses[i].credits;

        totalCredits += courses[i].credits;
        totalPoints += courses[i].grade * courses[i].credits;
    }

    cout << "\n----- RESULT -----\n";
    for (auto &c : courses) {
        cout << c.name << " | Grade: " << c.grade << " | Credits: " << c.credits << endl;
    }

    float cgpa = totalPoints / totalCredits;
    cout << "\nCGPA: " << cgpa << endl;

    return 0;
}