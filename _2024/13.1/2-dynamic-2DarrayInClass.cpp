#include <iostream>
using namespace std;

// Class to manage a 2D dynamic array
class Dynamic2DArray {
private:
    int** array;
    int rows;
    int cols;

public:
    // Constructor
    Dynamic2DArray(int rowCount, int colCount) {
        rows = rowCount;
        cols = colCount;
        array = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            array[i] = new int[cols];
        }
    }

    // Destructor
    ~Dynamic2DArray() {
        for (int i = 0; i < rows; ++i) {
            delete[] array[i];
        }
        delete[] array;
    }

    // Accessor
    void setValue(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            array[row][col] = value;
        }
    }

    int getValue(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return array[row][col];
        }
        return 0; // Default return value
    }
};

// Class to manage student grades and calculate averages
class GradeManager {
private:
    double** grades;
    double* studentAverages;
    double* projectAverages;
    int studentCount;
    int projectCount;

public:
    // Constructor
    GradeManager(int numberOfStudents, int numberOfProjects) {
        studentCount = numberOfStudents;
        projectCount = numberOfProjects;

        grades = new double*[studentCount];
        for (int i = 0; i < studentCount; i++) {
            grades[i] = new double[projectCount];
        }

        studentAverages = new double[studentCount]();
        projectAverages = new double[projectCount]();
    }

    // Destructor
    ~GradeManager() {
        for (int i = 0; i < studentCount; i++) {
            delete[] grades[i];
        }
        delete[] grades;
        delete[] studentAverages;
        delete[] projectAverages;
    }

    // Input grades
    void inputGrades() {
        for (int i = 0; i < studentCount; i++) {
            cout << "Student " << i + 1 << ":" << endl;
            for (int j = 0; j < projectCount; j++) {
                cout << "Enter grade for project " << j + 1 << ": ";
                cin >> grades[i][j];
            }
        }
    }

    // Calculate averages
    void calculateAverages() {
        for (int i = 0; i < studentCount; i++) {
            double studentTotal = 0;
            for (int j = 0; j < projectCount; j++) {
                studentTotal += grades[i][j];
                projectAverages[j] += grades[i][j];
            }
            studentAverages[i] = studentTotal / projectCount;
        }

        for (int j = 0; j < projectCount; j++) {
            projectAverages[j] /= studentCount;
        }
    }

    // Display averages
    void displayAverages() {
        cout << "Student Averages:" << endl;
        for (int i = 0; i < studentCount; i++) {
            cout << "Student " << i + 1 << ": " << studentAverages[i] << endl;
        }

        cout << "Project Averages:" << endl;
        for (int j = 0; j < projectCount; j++) {
            cout << "Project " << j + 1 << ": " << projectAverages[j] << endl;
        }
    }
};

int main() {
    // Example for 2D dynamic array
    int rowCount = 5, colCount = 3;
    Dynamic2DArray dynamicArray(rowCount, colCount);

    // Set some values
    dynamicArray.setValue(0, 0, 10);
    dynamicArray.setValue(1, 2, 20);
    cout << "Value at (0, 0): " << dynamicArray.getValue(0, 0) << endl;
    cout << "Value at (1, 2): " << dynamicArray.getValue(1, 2) << endl;

    cout << "-------------------------------------" << endl;

    // Example for grade management
    int studentCount, projectCount;
    cout << "Enter the number of students: ";
    cin >> studentCount;
    cout << "Enter the number of projects: ";
    cin >> projectCount;

    GradeManager gradeManager(studentCount, projectCount);
    gradeManager.inputGrades();
    gradeManager.calculateAverages();
    gradeManager.displayAverages();

    return 0;
}
