#ifndef __DECK__
#define __DECK__

#include <bits/stdc++.h> //fix
#include <assert.h>
#include "Card.cpp"
using namespace std;

class Deck {

private:
	vector<Card> deck;
	int iCard = 0;


public:
	static const int SIZE = 40;

	Deck() {
		for(int i=0; i<4; i++ ) {
			for(int j=0; j<10; j++) {
				deck.push_back(Card(j, i));
			}
		}
	}

	void toString() {
		cout << " - ";
		for(auto c: deck){
			c.toString();
			cout << " - ";
		}
	}

	void mescola() {
		random_device rd;
		default_random_engine rng(rd());

		shuffle(deck.begin(), deck.end(), rng);
		iCard = 0;
	}

	const Card draw() {
		assert (iCard < SIZE);
		return deck[iCard++];
	}

	bool finito() {
		return iCard > 39;
	}
};

#endif
