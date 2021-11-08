#ifndef __CARD__
#define __CARD__

#include <iostream>
using namespace std;

class Card {

private:
	int value, suit, coperta = true;

public:

	Card() {
		value = -1;
		suit = -1;
	}

	Card(int v, int s) {
		value = v;
		suit = s;
	}

	int getValue() {
		return value;
	}

	int getSuit() {
		return suit;
	}

	bool getCoperta() {
		return coperta;
	}

	void scopri() {
		coperta = false;
	}

	void toString() {
		cout << suit << ", " << value;
	}

	bool operator ==(const Card& c) {
		return (value == c.value || suit == c.suit);
	}

	bool operator !=(const Card& c) {
		return (value != c.value && suit != c.suit);
	}

	//void operator =(const Card)

};


#endif
