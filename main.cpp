#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    vector<vector<int>> grades(3, vector<int>(3, 0));
    bool recorded = false;
    int choice = 0;

    do {
        cout << "\n1) Record Grades (3x3)" << endl;
        cout << "2) One Student's Total & Average Grades" << endl;
        cout << "3) Display All (Table + Per-Student Stats)" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    cout << "Enter grade for Student " << i + 1
                         << ", Subject " << j + 1 << ": ";
                    cin >> grades[i][j];
                }
            }
            recorded = true;
        }
        else if (choice == 2) {
            if (!recorded) {
                cout << "Please record grades first (Option 1).\n";
                continue;
            }

            int studentIndex;
            cout << "Enter student number (1-3): ";
            cin >> studentIndex;

            if (studentIndex < 1 || studentIndex > 3) {
                cout << "Invalid student number.\n";
                continue;
            }

            int s = studentIndex - 1;
            int total = 0;
            for (int j = 0; j < 3; ++j) {
                total += grades[s][j];
            }
            double average = total / 3.0;

            cout << "Student " << studentIndex
                 << " Total: " << total
                 << ", Average: " << fixed << setprecision(2) << average << endl;
        }
        else if (choice == 3) {
            if (!recorded) {
                cout << "Please record grades first (Option 1).\n";
                continue;
            }

            cout << "\nGrades Table:\n";
            cout << "          Sub1  Sub2  Sub3\n";
            for (int i = 0; i < 3; ++i) {
                cout << "Student " << (i + 1) << " ";
                for (int j = 0; j < 3; ++j) {
                    cout << setw(5) << grades[i][j];
                }

                int total = 0;
                for (int j = 0; j < 3; ++j) total += grades[i][j];
                double avg = total / 3.0;

                cout << "   | Total: " << setw(3) << total
                     << " Avg: " << fixed << setprecision(2) << avg << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}