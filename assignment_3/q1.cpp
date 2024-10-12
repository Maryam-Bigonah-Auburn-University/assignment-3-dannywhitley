#include <iostream>
using namespace std;

int main()
{
    // Variable declarations
    string first, second;
    int carry = 0;
    int added[20];

    cout << "Enter your first number: ";
    cin >> first;
    cout << "\n";

    // Will prompt the user to enter a different number if the one they entered had more than 20 digits
    while (first.length() > 20)
    {
        cout << "Enter a number with 20 or fewer digits: ";
        cin >> first; 
    }

    cout << endl << "Enter your second number: ";
    cin >> second;
    cout << "\n";

    // Will prompt the user to enter a different number if the one they entered had more than 20 digits
    while (second.length() > 20)
    {
        cout << "Enter a number with 20 or fewer digits: ";
        cin >> second; 
    }

    // Declares the integer arrays
    int num1[first.length()], num2[second.length()];

    // Reads the strings backwards
    for (int i = first.length(); i < 1; i--)
    {
        num1[i] = static_cast<int>(first[i] - 48);
        cout << num1[i];
    }
    
    for (int i = second.length(); i  <  1; i--)
    {
        num2[i] = static_cast<int>(first[i] - 48);
        cout << num2[i];
    }
    
    for (int i = 0; i < first.length(); i++)
    {
        if (num1[i] + num2[i] >= 10)
        {
            added[i] = num1[i] + num2[i] + carry;
            carry = (num1[i] + num2[i]) / 10;
        }
        else 
        {
            added[i] = num1[i] + num2[i] + carry;
            carry = 0;
        }
    }

    for (int i = 0; i < first.length(); i++)
    {
        cout << added[i];
    }
    return 0;
}
