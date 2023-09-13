/*
Task 5: MOVIE TICKET BOOKING SYSTEM
Details: Develop a program that simulates a movie ticket booking system. Allow users to view movie listings, select seats, make bookings, and calculate the total cost. Consider implementing seat availability and seat selection validation.

Intern name: Imam Hasan
Intern ID:CS07WX36582
*/

#include <iostream>
#include <vector>
using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 5;

struct Seat {
    int row;
    int col;
    bool booked;
};

struct MovieListing {
    string title;
    string time;
};

vector<vector<Seat>> theater(NUM_ROWS, vector<Seat>(NUM_COLS));
vector<MovieListing> movieListings;

void initializeTheater() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            theater[i][j].row = i + 1;
            theater[i][j].col = j + 1;
            theater[i][j].booked = false;
        }
    }
}

void displayMovieListings() {
    cout << "Movie Listings:" << endl;
    for (size_t i = 0; i < movieListings.size(); i++) {
        cout << "[" << i + 1 << "] " << movieListings[i].title << " at " << movieListings[i].time << endl;
    }
}

void displayTheater() {
    cout << "Theater Seating:" << endl;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (theater[i][j].booked) {
                cout << "[X] "; 
            } else {
                cout << "[" << theater[i][j].row << theater[i][j].col << "] ";
            }
        }
        cout << endl;
    }
}

bool bookSeat(int row, int col) {
    if (row >= 1 && row <= NUM_ROWS && col >= 1 && col <= NUM_COLS) {
        if (!theater[row - 1][col - 1].booked) {
            theater[row - 1][col - 1].booked = true;
            return true; 
        }
    }
    return false; 
}

int main() {
    initializeTheater();

    
    movieListings.push_back({"Movie 1", "10:00 AM"});
    movieListings.push_back({"Movie 2", "1:30 PM"});
    movieListings.push_back({"Movie 3", "4:45 PM"});

    while (true) {
        cout << "Options:" << endl;
        cout << "1. View Movie Listings" << endl;
        cout << "2. View Theater Seating" << endl;
        cout << "3. Book a Ticket" << endl;
        cout << "4. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            displayMovieListings();
        } else if (choice == 2) {
            displayTheater();
        } else if (choice == 3) {
            int movieIndex, row, col;
            displayMovieListings();
            cout << "Enter the movie number: ";
            cin >> movieIndex;
            if (movieIndex >= 1 && movieIndex <= static_cast<int>(movieListings.size())) {
                displayTheater();
                cout << "Enter the row and column for your seat: ";
                cin >> row >> col;
                if (bookSeat(row, col)) {
                    cout << "Seat booked successfully!" << endl;
                } else {
                    cout << "Invalid seat selection or seat is already booked." << endl;
                }
            } else {
                cout << "Invalid movie selection." << endl;
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}

