#ifndef __TABLE__
#define __TABLE__

#include <bits/stdc++.h>
#include "Card.cpp"
#include "Deck.cpp"

class Table {

private:
	Deck deck;
	vector<Card> table;


public:
	bool play() {

		table.clear();
		deck.mescola();
		//deck.toString(); cout << endl;
		insert(deck.draw());

		for(int i=0; i<deck.SIZE-1; i++) {
			insert(deck.draw());
			//cout << "carta " << i << endl;
			//toString();
			restore();
		}

		//toString();
		//cout << endl << endl;

		return table.size() == 1;
	}

	//--------------------------------------------------------------------------------------------

	void toString() {
		for(auto c: table){
			c.toString();
			cout << " -- ";
		}
		//cout << endl << endl;
	}

	//--------------------------------------------------------------------------------------------

	void insert(Card c) {
		table.push_back(c);
	}

	//--------------------------------------------------------------------------------------------

	void restore() {
		bool modified = false, quit = false;
		int last = table.size()+400, last_cp; //last_cp è una copia di last

		do {
			last = min(last-1, (int)(table.size()-1));
			//toString();
			//cout << "Table size: " << table.size() << ", last: ";
			//cout << last << endl;

			last_cp = last;

			do {
				//questo è quello che faccio con la carta appena pescata
				modified = false;

				if(last_cp-1 >= 0 && table[last_cp] == table[last_cp-1]) {
					table[last_cp-1] = table[last_cp];
					table.erase(table.begin()+(last_cp));
					last_cp = last_cp-1;
					modified = true;
				}
				else if(last_cp-2 >= 0 && table[last_cp] == table[last_cp-2]) {
					table[last_cp-2] = table[last_cp];
					table.erase(table.begin()+(last_cp));
					last_cp = last_cp-2;
					modified = true;
				}

			} while(modified && table.size() != 1);


		} while(last >= 1 && modified);
	}

	//--------------------------------------------------------------------------------------------
};

#endif
