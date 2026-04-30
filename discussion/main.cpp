#include <iostream>
using namespace std;

double residential();
double business();

int main()
{
    char customerType;
    double amountDue = 0;

    cout << "Enter customer type (R/r for Residential, B/b for Business): ";
    cin >> customerType;

    if (customerType == 'R' || customerType == 'r')
    {
        amountDue = residential();
        cout << "Amount due = $" << amountDue << endl;
    }
    else if (customerType == 'B' || customerType == 'b')
    {
        amountDue = business();
        cout << "Amount due = $" << amountDue << endl;
    }
    else
    {
        cout << "Invalid customer type." << endl;
    }

    return 0;
}

double residential()
{
    int premiumChannels;

    cout << "Enter number of premium channels: ";
    cin >> premiumChannels;

    return 25.00 + (premiumChannels * 6.00);
}

double business()
{
    int premiumChannels;

    cout << "Enter number of premium channels: ";
    cin >> premiumChannels;

    return 80.00 + (premiumChannels * 12.00);
}