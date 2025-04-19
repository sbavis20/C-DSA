#include <iostream>
using namespace std;

void calculateNotes(int amount) {
    int hundreds = 0, fifties = 0, twenties = 0, tens = 0, ones = 0;

    switch (1) { // Using switch as a control structure
        case 1:
            hundreds = amount / 100;
            amount %= 100;
        case 2:
            fifties = amount / 50;
            amount %= 50;
        case 3:
            twenties = amount / 20;
            amount %= 20;
        case 4:
            tens = amount / 10;
            amount %= 10;
        case 5:
            ones = amount;
    }

    cout << "100s: " << hundreds << endl;
    cout << "50s: " << fifties << endl;
    cout << "20s: " << twenties << endl;
    cout << "10s: " << tens << endl;
    cout << "1s: " << ones << endl;
}

int main() {
    int amount;
    cout << "Enter the total amount: ";
    cin >> amount;

    calculateNotes(amount);

    return 0;
}
