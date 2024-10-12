#include <iostream>
using namespace std;

void reserveSeats();
// Void function reserves a seat on an airline and has no input arguments.
// It establises a 2D char array that can change the values to incidcate a seats availability.

int main() 
{
    // Calls the void function to reserve a seat on an airline.
    reserveSeats();

    return 0; 
}

// Function definition for the void function reserveSeats
void reserveSeats()
{
    // Variable declarations and initialization
    string userString = "yes"; // do-while loop conditional statement
    int availableSeats = 28; // Number of seats on the plane
    char rowNumber, seatLetter; // User seat selection

    // Defines the 2D character array
    char seatingChart[7][5] = { {'1', 'A', 'B', 'C', 'D'}, 
                                {'2', 'A', 'B', 'C', 'D'}, 
                                {'3', 'A', 'B', 'C', 'D'}, 
                                {'4', 'A', 'B', 'C', 'D'}, 
                                {'5', 'A', 'B', 'C', 'D'},
                                {'6', 'A', 'B', 'C', 'D'}, 
                                {'7', 'A', 'B', 'C', 'D'}};

    // Will continue to reserve a seat until user quits or all seats are reserved
    do 
    {
        cout << "Available seats: " << endl;
        
        // Nested for loop will display all elements of the seating array
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << seatingChart[i][j] << " ";
            }

            // New line for the new row
            cout << "\n";
        }

        cout << "\n";

        // Prompts the user to select a seat
        cout << "To reserve an available seat enter a row number and seat letter separated by a space: ";
        cin >> rowNumber >> seatLetter;
        cout << "\n";

        // Prompts the user to enter a valid seat ID
        // ASCII table was used to determine conditional statement parameters
        while (!((rowNumber > 48 ) && (rowNumber < 56)) || !((seatLetter > '@') && (seatLetter < 'E')))
        {
            cout << "Selected seat does not exist.\n";
            cout << "Please enter a valid row number and seat letter separated by a space: ";
            cin >> rowNumber >> seatLetter;
            cout << "\n";
        }

        // Prompts the user to enter a seat that isn't already reserved
        // ASCII table and type casting was used to convert the seat ID in the array to an index
        while (seatingChart[static_cast<int>(rowNumber - 49)][static_cast<int>(seatLetter - 64)] == 'X')
        {
            cout << "The selected seat is already reserved. Please select another." << endl;
            cout << "Please enter a valid row number and seat letter separated by a space: ";
            cin >> rowNumber >> seatLetter;
            cout << "\n";
        }

        // Edits the seating array to reserve a seat
        seatingChart[static_cast<int>(rowNumber - 49)][static_cast<int>(seatLetter - 64)] = 'X';

        // Displays message confirming the seat reservation.
        cout << "Your seat " << rowNumber << seatLetter << " has been reserved.\n" << endl;

        // Edits the nummber of seats available to be reserved.
        availableSeats -= 1; 

        // Nested for loop will display all elements of the seating array updated with the reserved seats.
        cout << "Available seats:\n";
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << seatingChart[i][j] << " ";
            }

            // New line for the new row
            cout << "\n";
        }

        cout << "\n";

        // Terminates the program if all seats have been reserved.
        if (availableSeats == 0)
        {
            cout << "All seats have been reserved." << endl;
            break;
        }

        // Prompts the user to make another reservation
        cout << "Would you like to reserve another seat? Enter yes or Yes to continue or any other key to exit. ";
        cin >> userString;
        cout << "\n" << "\n";

    } while ((userString == "yes") || (userString == "Yes"));

    cout << "Program has been ended.\n" << endl;
}
