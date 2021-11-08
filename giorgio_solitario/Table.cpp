
#ifndef TABLE
#define TABLE

#include <bits/stdc++.h>
#include "Card.cpp"
#include "Deck.cpp"
using namespace std;

const int CPS = 10; //cps = carte per seme
const int NDS = 4; //nds = numero di semi

class Table {
private:
	Deck d; //da qui prendi tutte le carte per riempire il tavolo e dopo ti avanzano le 4 carte da cui peschi quando non hai più mosse
	Card tavolo [NDS][CPS];
	Card inMano; //la carta che tieni in mano
	Card temp; //per gli scambi delle carte

public:
	Table() {
		d.mescola();
		for(int i=0; i<NDS; i++) {
			for(int j=0; j<CPS-1; j++) { //CPS-1 perché lascio l'ultimo spazio per i re
				tavolo[i][j] = d.draw();
			}
		}
	}

	void move() { //esce da qui solo quando peschi un re e non hai più carte da pescare
		inMano.scopri();

		//se peschi un re e hai finito il mazzo devi controllare che le carte coperte siano nel posto corretto
		if(inMano.getValue() == 9 && d.finito()) {
			tavolo[inMano.getSuit()][inMano.getValue()] = inMano;
		}
		//se peschi un re e non hai finito il mazzo, pesca e muovi ancora
		else if(inMano.getValue() == 9 && !d.finito()) {
			tavolo[inMano.getSuit()][inMano.getValue()] = inMano;
			inMano = d.draw();
			move();
		}
		//se peschi una carta che non è un re, muovi ancora
		else if(inMano.getValue() != 9) {
			temp = tavolo[inMano.getSuit()][inMano.getValue()];
			tavolo[inMano.getSuit()][inMano.getValue()] = inMano;
			inMano = temp;
			move();
		}
	}

	void controllaCarteCoperte() {
		for(int i=0; i<NDS; i++) {
			for(int j=0; j<CPS; j++) {
				if(tavolo[i][j].getCoperta() && tavolo[i][j].getSuit() == i && tavolo[i][j].getValue() == j)
					tavolo[i][j].scopri();
			}
		}

	}

	bool vinto() {
		bool win = true;

		for(int i=0; i<NDS; i++) {
			for(int j=0; j<CPS; j++) {
				if(tavolo[i][j].getCoperta())
					win = false;
			}
		}

		return win;
	}


	bool play() {
		inMano = d.draw();
		move();
		controllaCarteCoperte();

		return vinto();
	}

};

#endif
