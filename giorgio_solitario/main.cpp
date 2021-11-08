#include <bits/stdc++.h>
#include "Card.cpp"
#include "Deck.cpp"
#include "Table.cpp"
using namespace std;

int main() {

	float wins = 0;
	int tries = 100000;

	for(int i=0; i<tries; i++) {
		Table t;
		if(t.play())
			wins ++;
	}

	cout << "Wins: \t" << wins << endl;
	cout << "Tries: \t" << tries << endl;
	cout << "Probability: \t" << (wins/tries)*100 << "%" << endl;

	return 0;
}
