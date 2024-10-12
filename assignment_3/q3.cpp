#include <iostream>
using namespace std;

void fillUp(int maxSize, int array[], int& numberUsed);
// Void function allows the user to enter up to the maxSize number of integers and stores them in an array

void decreasingSort(int array[], int numberUsed);
// Void function sorts the array made by fillUp

int main()
{
    int numberUsed = 0;
    const int size = 50;
    int storageArray[size];

    fillUp(size, storageArray, numberUsed);
    decreasingSort(storageArray, numberUsed);

    cout << "\n" << "Sorted array: " << "\n";

    for (int i = 0; i < numberUsed; i++ )
    {
        cout << storageArray[i] << " ";
    }

    cout << "\n";

    return 0;
}

void fillUp(int maxSize, int array[], int& numberUsed)
{
    int index = 0;

    cout << "Enter up to " << maxSize << " numbers. Enter a non-integer to end the input sequence." << endl;

    cin >> array[index];

    while ((typeid(array[index]) == typeid(int)) && (index < maxSize))
    {
        index += 1;
        cin >> array[index];
    }
    cout << index;

    cout << "Num elements: " << numberUsed << endl;
    cout << "last index: " << index << endl;
}

void decreasingSort(int array[], int numberUsed)
{
    int placeHolder, maxVal, currentIndex = 0;

    while (currentIndex < numberUsed - 1)
    {
        maxVal = array[currentIndex];

        for (int i = currentIndex; i < numberUsed; i++)
        {
            if (array[i] > maxVal)
            {
                placeHolder = maxVal; 
                maxVal = array[i]; 
                array[currentIndex] = maxVal;
                array[i] = placeHolder;
            }
        }
        currentIndex += 1;
    }
}
