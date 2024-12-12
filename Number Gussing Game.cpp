#include <iostream>
#include <cstdlib> 
#include <ctime>  
using namespace std;

int main() {
    int num, guess, tries = 0;
    
   
    srand(time(0)); 
    num = (rand() % 100 + 1);
    
    cout << "Let's start the number guessing game!" << endl;
    cout << "You have to guess a number between 1 and 100." << endl;
    
    do {
        cout << "Enter a number: ";
        cin >> guess;
        tries++;
        
        if (guess < num) {
            cout << "Wow buddy, it's too low!" << endl;
        } else if (guess > num) {
            cout << "Wow buddy, it's too high!" << endl;
        } else {
            cout << "It's correct buddy!" << endl;
            cout << "Number of tries: " << tries << endl;
        }
    } while (guess != num);
    
    cout << "Nice play buddy!" << endl;
    return 0;
}
