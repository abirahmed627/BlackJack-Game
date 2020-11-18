//Black Jack Game
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

void chooseCards() {
    vector<string> cards = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    srand(time(NULL));
    string cardOne;
    string cardTwo;
    
	
        
	cout << "---------------------------------------------------------" << endl;
	cout << "          Welcome to the Black Jack Program " << endl;
	cout << "---------------------------------------------------------" << endl << endl;


	cardOne = cards[rand() % 13];
	cout << "Your first card is a " << cardOne << endl;
	for (int i = 0; i < cards.size(); i++)
	{
		if (cards[i] == cardOne) cards.erase(cards.begin() + i);
	}

	cardTwo = cards[rand() % 12];
	cout << "Your second card is a " << cardTwo << endl << endl;
	for (int i = 0; i < cards.size(); i++)
	{
		if (cards[i] == cardTwo) cards.erase(cards.begin() + i);
	}

	cout << "---------------------------------------------------------" << endl;

	
    
    cout << "Remaining cards in deck: ";
    for (int i = 0; i < cards.size(); i++) {
        cout << cards[i] << " ";
    }
    cout << endl << endl;
    
    int card1val;
    int card2Val;
    
    if (cardOne == "Ace") card1val = 1;
    else if (cardOne == "Jack" || cardOne == "Queen" || cardOne == "King") card1val = 10;
    else card1val = stoi(cardOne);
    
    if (cardTwo == "Ace") card2Val = 1;
    else if (cardTwo == "Jack" || cardTwo == "Queen" || cardTwo == "King") card2Val = 10;
    else card2Val = stoi(cardTwo);

	cout << "---------------------------------------------------------" << endl;

    
    cout << "The total value of your two cards is " << card1val + card2Val << endl << endl;
    cout << "Detrimental cards for your hand are valued greater than " << 21 - (card1val + card2Val) << endl;
    
	int badcards = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i] == "Ace") {
            if (21 - (card1val + card2Val) < 1) badcards += 1;
            else badcards += 0;
        }
        else if ((cards[i] == "Jack" || cards[i] == "Queen" || cards[i] == "King")) {
            if ((21 - (card1val + card2Val) < 10)) badcards += 1;
            else badcards += 0;
        }
        else if ((stoi(cards[i])) > (21 - (card1val + card2Val))) {
            badcards += 1;
        }
    }
    cout << "The probability of you receiving a detrimental card is " << badcards << "/" << cards.size() << endl;
    cout << "The probability of you receiving a beneficial card is " << (cards.size() - badcards) << "/" << cards.size() << endl << endl;
	cout << "---------------------------------------------------------" << endl;

    
    if (badcards < (cards.size() - badcards)) cout << "It is a good choice for you to draw another card" << endl;
    else cout << "It is not a good choice for you to draw another card" << endl;
	cout << "---------------------------------------------------------" << endl;

}


int main() {
    chooseCards();
    cout << endl;
}
