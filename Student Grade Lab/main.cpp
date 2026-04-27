#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 5;
const int COURSE_COUNT = 3;

void calculateStudent(int i, double Score[][3], double &total, double &average);
void displayAll(int n, string NameArr[], double Score[][3]);
int findTopStudent(int n, double Score[][3]);

int main()
{
    int n = 3;

    string NameArr[MAX] = {"Alice", "Bob", "Carl"};

    double Score[MAX][3] = {
        {90, 85, 95},
        {70, 80, 75},
        {88, 92, 84}
    };

    cout << fixed << setprecision(2);

    cout << "=== Student Grade Report ===" << endl;
    displayAll(n, NameArr, Score);

    int topIndex = findTopStudent(n, Score);

    double topTotal, topAverage;
    calculateStudent(topIndex, Score, topTotal, topAverage);

    cout << endl;
    cout << "Top student: " << NameArr[topIndex]
         << " | Total = " << topTotal
         << " | Average = " << topAverage << endl;

    return 0;
}

void calculateStudent(int i, double Score[][3], double &total, double &average)
{
    total = 0;

    for (int j = 0; j < COURSE_COUNT; j++)
    {
        total += Score[i][j];
    }

    average = total / COURSE_COUNT;
}

void displayAll(int n, string NameArr[], double Score[][3])
{
    for (int i = 0; i < n; i++)
    {
        double total, average;
        calculateStudent(i, Score, total, average);

        cout << NameArr[i]
             << " | Math = " << Score[i][0]
             << " | C Programming = " << Score[i][1]
             << " | Operating Systems = " << Score[i][2]
             << " | Total = " << total
             << " | Average = " << average << endl;
    }
}

int findTopStudent(int n, double Score[][3])
{
    int topIndex = 0;

    double topTotal, topAverage;
    calculateStudent(0, Score, topTotal, topAverage);

    for (int i = 1; i < n; i++)
    {
        double total, average;
        calculateStudent(i, Score, total, average);

        if (total > topTotal)
        {
            topTotal = total;
            topIndex = i;
        }
    }

    return topIndex;
}