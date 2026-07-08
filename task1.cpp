#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    float totalCredits = 0, totalGradePoints = 0;

    cout << "Enter the number of courses: ";
    cin >> n;

    vector<float> grade(n), credit(n);

    // Input grades and credit hours
    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Grade Point (0 - 10): ";
        cin >> grade[i];

        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

    // Calculate Semester GPA
    float semesterGPA = totalGradePoints / totalCredits;

    // Input previous CGPA details
    float previousCGPA;
    float previousCredits;

    cout << "\nEnter Previous CGPA (Enter 0 if first semester): ";
    cin >> previousCGPA;

    cout << "Enter Total Previous Credits: ";
    cin >> previousCredits;

    float overallCGPA;

    if (previousCredits == 0) {
        overallCGPA = semesterGPA;
    } else {
        overallCGPA = ((previousCGPA * previousCredits) + totalGradePoints) /
                      (previousCredits + totalCredits);
    }

    // Display Results
    cout << "\n----------- Course Details -----------\n";
    cout << left << setw(10) << "Course"
         << setw(15) << "Grade"
         << setw(15) << "Credits" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << i + 1
             << setw(15) << grade[i]
             << setw(15) << credit[i] << endl;
    }

    cout << "\nTotal Credits      : " << totalCredits;
    cout << "\nTotal Grade Points : " << totalGradePoints;
    cout << "\nSemester GPA       : " << fixed << setprecision(2) << semesterGPA;
    cout << "\nOverall CGPA       : " << fixed << setprecision(2) << overallCGPA << endl;

    return 0;
}