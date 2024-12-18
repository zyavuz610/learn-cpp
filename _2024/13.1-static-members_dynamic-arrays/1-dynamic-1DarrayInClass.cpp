#include <iostream>
using namespace std;

// Class definition for managing grades
class GradeManager {
private:
    double* grades; // Dynamic array for grades
    int size;       // Number of grades

public:
    // Constructor
    GradeManager(int numberOfGrades) {
        size = numberOfGrades;
        grades = new double[size];
    }

    // Destructor
    ~GradeManager() {
        delete[] grades;
    }

    // Input grades from the user
    void inputGrades() {
        double total = 0;
        for (int i = 0; i < size; i++) {
            cout << "Enter grade " << i + 1 << ": ";
            cin >> grades[i];
            total += grades[i];
        }
        cout << "Average grade: " << total / size << endl;
    }
};

// Class definition for dynamic integer array
class DynamicArray {
private:
    int* array;
    int size;

public:
    // Constructor
    DynamicArray(int arraySize) {
        size = arraySize;
        array = new int[size];
    }

    // Destructor
    ~DynamicArray() {
        delete[] array;
    }

    // Add value to the array at a specific index
    void addValue(int index, int value) {
        if (index >= 0 && index < size) {
            array[index] = value;
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    // Print the array
    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << i << ": " << array[i] << endl;
        }
    }
};

int main() {
    // Dynamic integer array example
    int arraySize = 5;
    DynamicArray dynamicArray(arraySize);
    dynamicArray.addValue(3, 23);
    dynamicArray.addValue(0, 35); // Set array[0] = 35
    dynamicArray.printArray();

    cout << "-------------------------------------" << endl;
    DynamicArray* dynamicArrayPtr = new DynamicArray(3);
    dynamicArrayPtr->addValue(0, 10);
    dynamicArrayPtr->addValue(1, 20);
    dynamicArrayPtr->addValue(2, 30);
    dynamicArrayPtr->printArray();

    cout << "-------------------------------------" << endl;

    // Grade manager example
    int numberOfGrades;
    cout << "Enter the number of grades: ";
    cin >> numberOfGrades;

    GradeManager gradeManager(numberOfGrades);
    gradeManager.inputGrades();

    return 0;
}
