#include <bits/stdc++.h>
#include "Card.cpp"
#include "Deck.cpp"
using namespace std;

int main() {

	int cont = -1;
	Card last;
	int nWins = 0;
	const int tries = 1000000;
	double prob;

	Deck d;

	for(int i=0; i<tries; i++) {
		cont = -1;
		d.mescola();
		do {
			cont = (cont+1) % 3;
			last = d.draw();
			//cout << "cont: " << cont << " - valore: " << last.getValue() << endl;
		} while(cont != last.getValue()  &&  !d.finito());

		if(d.finito() && cont != last.getValue())
			nWins ++;
	}

	prob = ((double)nWins * 100.0) / (double)tries;

	cout << "Wins: \t" << nWins << endl;
	cout << "Tries: \t" << tries << endl;
	cout << "Probability: \t" << prob << "%" << endl;

	return 0;
}
