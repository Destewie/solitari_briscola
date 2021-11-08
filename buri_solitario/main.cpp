#include <bits/stdc++.h>
#include "Card.cpp"
#include "Deck.cpp"
#include "Table.cpp"

using namespace std;

int main() {



	Table t;
	int nWins = 0, nTen=1e6;
	double prob;

	//il gioco originale
	for(int i=0; i<nTen; i++)
	{
		if(t.play())
			nWins ++;
	}

	prob = ((double)nWins * 100.0) / (double)nTen;

	cout << "Wins: \t" << nWins << endl;
	cout << "Tries: \t" << nTen << endl;
	cout << "Probability: \t" << prob << "%" << endl;

	return 0;
}
