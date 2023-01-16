/*This program is a word guessing game where the user is given a random word of fixed length (5 letters) and a set number of guesses (6) to correctly guess the word. The program reads a list of words from a file named "wordbank.txt" and randomly selects one as the secret word for the user to guess. The program prompts the user for a guess, validates that it is the correct length, and then checks whether each letter of the guess appears in the correct position and/or in the secret word. The user will be notified if a letter is in the correct position, in the word but not in the correct position, or not in the word at all. The game also provides the first letter of the secret word as a hint to help the user in guessing the word. The game ends when the user correctly guesses the word or runs out of guesses.*/
// Zhonwei Li, 1/12/2023,(https://github.com/coolxv)
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cctype>
using namespace std;
// program constants
const string FILENAME = "wordbank.txt";
const int num_letters = 5;
const int num_guesses = 6;
string guess;
// helper function declarations
string getWord();
string getGuess(string prompt);
void process_guess(string guess, string secret);
// stub function declaration
string get_hint(string guess, string secret);
/*The program is a simple word guessing game where the user is given a random word of fixed length (5 letters) and a set number of guesses (6) to correctly guess the word. The game reads a list of words from a file named "wordbank.txt" and randomly selects one as the secret word for the user to guess.

The main function starts by calling the getWord() function to select a random word from the wordbank.txt file and to capitalize its letters. It then enters a loop that runs for the number of guesses allowed, where in each iteration the user is prompted to enter a guess by calling the getGuess() function.

The program then calls the get_hint() function that gives the first letter of the secret word and then process the guess by calling the process_guess() function. This function checks whether each letter of the guess appears in the correct position and/or in the secret word. The user will be notified if a letter is in the correct position, in the word but not in the correct position, or not in the word at all.

The loop continues until the user correctly guesses the word or runs out of guesses. If the user correctly guesses the word, a message is displayed saying "You guessed the word!" otherwise "You ran out of guesses before guessing the word: " along with the secret word is displayed.*/
int main() {
    string secret = getWord();
    for (int i = 0; i < num_guesses; i++) {
        guess = getGuess("Guess #" + to_string(i + 1) + ": ");
        if (guess == secret) break;
        string hint = get_hint(guess, secret);
        cout << "Hint: " << hint << endl;
        process_guess(guess, secret);
    }

    if (guess == secret) {
        cout << "You guessed the word!" << endl;
    } else {
        cout << "You ran out of guesses before guessing the word: " << secret << endl;
    }
    return 0;
}

// picks a random word from the specified file
string getWord() {
// open the file
ifstream f(FILENAME);
// read words line-by-line into a vector (array-like data structure)
vector<string> allWords;
string word;
while (getline(f,word)) {
allWords.push_back(word);
}
// close the file
f.close();
// pick a random word from the vector and capitalize its letters
srand(time(nullptr));
word = allWords[rand()%allWords.size()];
for (int i=0; i<word.length(); i++) {
word[i] = toupper(word[i]);
}
return word;
}
string getGuess(string prompt) {
    string guess;
    do {
        cout << prompt;
        cin >> guess;
        for (int i = 0; i < guess.length(); i++) {
    guess[i] = toupper(guess[i]);//I use toupper function instead of creating a loop to go through and capitalize each word bank letter character-by-character
}
        if (guess.length() != num_letters) {
            cout << "Your guess must be " << num_letters << " letters." << endl;
        }
    } while (guess.length() != num_letters);
    return guess;
}
void process_guess(string guess, string secret) {
    for (int i = 0; i < num_letters; i++) {
        char letter = guess[i];
        if (secret[i] == letter) {
            cout << letter << " is in position " << i + 1 << endl;
        } else {
            bool in_word = false;
            for (int j = 0; j < num_letters; j++) {
                if (secret[j] == letter) {
                    in_word = true;
                    break;
                }
            }
            if (in_word) {
                cout << letter << " is in the word but not in position " << i + 1 << endl;
            } else {
                cout << letter << " is not in the word" << endl;
            }
        }
    }
}
// stub function definition
string get_hint(string guess, string secret) {
    string hint;
    hint += secret[0];
    for (int i = 1; i < num_letters; i++) {
        hint += "_";
    }
    return hint;
}
