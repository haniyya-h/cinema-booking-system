#include <iostream>
#include <string>
using namespace std;

const int rows = 5;
const int cols = 10;

char seats[rows][cols];
int seatTypes[rows][cols];

const int economyPrice = 600;
const int standardPrice = 800;
const int luxuryPrice = 1000;

const int maxBookingSeats = rows * cols;
int lastBookedRows[maxBookingSeats];
int lastBookedCols[maxBookingSeats];
int lastBookedCount = 0;
int savedMovieChoice = 0;
int savedTimeChoice = 0;
bool hasReceipt = false;

string movieNames[4] = {
    "Zootopia 2",
    "Everything Everywhere All at Once",
    "Kabhi Khushi Kabhi Gham",
    "Inception"
};

void DisplayMovies() {
    cout << endl << "Available Movies:" << endl;
    cout << endl;

    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << movieNames[i] << endl;
    }
    cout << endl;
}

string GetMovieName(int choice) {
    if (choice >= 1 && choice <= 4) return movieNames[choice - 1];
    return "Invalid";
}

void DisplayTimes() {
    cout << endl << "Available Showtimes:" << endl;
    cout <<endl;

    cout << "1. 06-01-2026 18:00" << endl;
    cout << "2. 06-01-2026 21:00" << endl;
    cout << "3. 07-01-2026 18:00" << endl;
    cout << "4. 07-01-2026 21:00" << endl;
    cout << endl;
}

string GetTimeString(int choice) {
    switch(choice) {
        case 1: return "06-01-2026 18:00";
        case 2: return "06-01-2026 21:00";
        case 3: return "07-01-2026 18:00";
        case 4: return "07-01-2026 21:00";
        default: return "Invalid";
    }
}

void InitializeSeats() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            seats[i][j] = 'O';
            if (i < 2) seatTypes[i][j] = 1;      // Economy
            else if (i < 4) seatTypes[i][j] = 2; // Standard
            else seatTypes[i][j] = 3;            // Luxury
        }
    }
}

void DisplaySeats() {
    cout << endl << "Seat Layout (O = Available, X = Booked):\n" << endl << "   ";
    for (int j = 0; j < cols; j++) {
        cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < rows; i++) {
        cout << i << "  ";
        for (int j = 0; j < cols; j++) {
            cout << seats[i][j] << " ";
        }
        if (i < 2) cout << "(Economy - 600 rps)";
        else if (i < 4) cout << "(Standard - 800 rps)";
        else cout << "(Luxury - 1000 rps)";
        cout << endl;
    }
}

void SelectAndBookSeats() {
    cout << endl << "How many seats do you want to book? ";
    int numberOfSeats;
    cin >> numberOfSeats;

    if (numberOfSeats <= 0 || numberOfSeats > maxBookingSeats) {
        cout << "Invalid number of seats." << endl;
        return;
    }

    lastBookedCount = 0;

    for (int i = 0; i < numberOfSeats; ++i) {
        DisplaySeats();
        cout << endl << "Seat " << i + 1 << " - Enter row (0-4) and column (0-9): ";
        int r, c;
        cin >> r >> c;

        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "Invalid seat position! Try again." << endl;
            i--;
            continue;
        }

        if (seats[r][c] == 'X') {
            cout << "Seat already booked! Select another seat." << endl;
            i--;
            continue;
        }

        seats[r][c] = 'X';
        lastBookedRows[lastBookedCount] = r;
        lastBookedCols[lastBookedCount] = c;
        lastBookedCount++;
        cout << "Seat booked at Row " << r << ", Column " << c << endl;
    }
    hasReceipt = true;
}

void Receipt() {
    if (!hasReceipt) {
        cout << endl << "No booking found. Please book seats first." << endl;
        return;
    }

    int originalTotal = 0;

    cout << endl;
    cout << "====================================================" << endl;
    cout << "\t\t CINEMA RECEIPT" << endl;
    cout << "====================================================" << endl;

    cout << "Movie\t\t: " << GetMovieName(savedMovieChoice) << endl;
    cout << "Showtime\t: " << GetTimeString(savedTimeChoice) << endl;

    cout << "----------------------------------------------------" << endl;
    cout << "Seat\t\tType\t\tPrice (Rs)" << endl;
    cout << "----------------------------------------------------" << endl;

    for (int i = 0; i < lastBookedCount; i++) {
        int r = lastBookedRows[i];
        int c = lastBookedCols[i];
        int price;
        string typeStr;

        if (seatTypes[r][c] == 1) {
            price = economyPrice;
            typeStr = "Economy";
        }
        else if (seatTypes[r][c] == 2) {
            price = standardPrice;
            typeStr = "Standard";
        }
        else {
            price = luxuryPrice;
            typeStr = "Luxury";
        }

        cout << "R" << r << "C" << c << "\t\t" << typeStr;

        if (typeStr == "Standard")
            cout << "\t";
        else
            cout << "\t\t";

        cout << price << endl;

        originalTotal = originalTotal + price;
    }

    cout << "----------------------------------------------------" << endl;

    cout << "Price Before Discount\t: " << originalTotal << " Rs" << endl;

    int discountedTotal = originalTotal;
    if (lastBookedCount >= 5) {
        discountedTotal = (originalTotal * 9) / 10;
        cout << "Discount\t\t: 10% Applied" << endl;
    }

    cout << "Price After Discount\t: " << discountedTotal << " Rs" << endl;
    cout << "Seats Booked\t\t: " << lastBookedCount << endl;

    cout << "====================================================" << endl;
    cout << "\t Thank you for booking with us!" << endl;
    cout << "====================================================" << endl;
}


void Menu() {
    cout << endl << "Menu Options:" << endl;
    cout <<endl;
    cout << "1. Display available seats" << endl;
    cout << "2. Select and book seats" << endl;
    cout << "3. Receipt" << endl;
    cout << "4. Exit" << endl;
    cout <<endl;
}

int main() {
    cout << "====================================================" << endl;
    cout << "-------Welcome to the Cinema Booking System!--------" << endl;
    cout << "====================================================" << endl;

    DisplayMovies();
    cout << "Select a movie (1-4): ";
    cin >> savedMovieChoice;

    DisplayTimes();
    cout << "Select showtime (1-4): ";
    cin >> savedTimeChoice;

    InitializeSeats();

    int choice;
    while (true) {
        Menu();
        cout << "Enter menu option: ";
        cin >> choice;

        if (choice == 1) DisplaySeats();
        else if (choice == 2) SelectAndBookSeats();
        else if (choice == 3) Receipt();
        else if (choice == 4) {
            cout <<endl;
            cout << "Thank you for using the Cinema Booking System!" << endl;
            cout << "Exiting system. Goodbye!" << endl;
            break;
        }
        else cout << "Invalid option. Try again." << endl;
    }

    return 0;
}