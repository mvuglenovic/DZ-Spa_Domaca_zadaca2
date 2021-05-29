#include "game_of_life.h"
#include <time.h>

int game_of_life::random_broj(int min, int max) {
	return rand() % (max - min + 1) + min;
}


bool game_of_life::slucajna_vrijednost()
{
	if (random_broj(1, 4) == 2)
		return true;
	else
		return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (this->_generacija[i][j] == true)
		return true;
	else
		return false;
}

void game_of_life::init_polje()
{
	int dovoljnaRazina;
	do {
		dovoljnaRazina = 0;
		for (int i = 0; i < REDAKA; i++) {
			for (int j = 0; j < STUPACA; j++) {
				if (slucajna_vrijednost()) {
					this->_generacija[i][j] = 1;
					dovoljnaRazina++;
				}
				else {
					this->_generacija[i][j] = 0;
				}
			}
		}

	} while (!(dovoljnaRazina == ((REDAKA * STUPACA) / 4)));

}

bool game_of_life::zivot_smrt(int i, int j)
{
	int brojac = 0;
	if ((i - 1) >= 0 && (j - 1) >= 0) {
		if (this->_generacija[i - 1][j - 1] == 1)
			brojac++;
	}
	if ((i - 1) >= 0) {
		if (this->_generacija[i - 1][j] == 1)
			brojac++;
	}
	if ((i - 1) >= 0 && (j + 1) < STUPACA) {
		if (this->_generacija[i - 1][j + 1] == 1)
			brojac++;
	}
	if ((j - 1) >= 0) {
		if (this->_generacija[i][j - 1] == 1)
			brojac++;
	}
	if ((j + 1) < STUPACA) {
		if (this->_generacija[i][j + 1] == 1)
			brojac++;
	}
	if ((i + 1) < REDAKA && (j - 1) >= 0) {
		if (this->_generacija[i + 1][j - 1] == 1)
			brojac++;
	}
	if ((i + 1) < REDAKA) {
		if (this->_generacija[i + 1][j] == 1)
			brojac++;
	}
	if ((i + 1) < REDAKA && (j + 1) < STUPACA) {
		if (this->_generacija[i + 1][j + 1] == 1)
			brojac++;
	}

	if (brojac == 2 || brojac == 3)
		return true;
	else
		return false;
}

bool game_of_life::radjanje(int i, int j)
{
	int brojac = 0;
	if ((i - 1) >= 0 && (j - 1) >= 0) {
		if (this->_generacija[i - 1][j - 1] == 1) {
			brojac++;
		}
	}
	if ((i - 1) >= 0) {
		if (this->_generacija[i - 1][j] == 1)
			brojac++;
	}
	if ((i - 1) >= 0 && (j + 1) < STUPACA) {
		if (this->_generacija[i - 1][j + 1] == 1)
			brojac++;
	}
	if ((j - 1) >= 0) {
		if (this->_generacija[i][j - 1] == 1)
			brojac++;
	}
	if ((j + 1) < STUPACA) {
		if (this->_generacija[i][j + 1] == 1)
			brojac++;
	}
	if ((i + 1) < REDAKA && (j - 1) >= 0) {
		if (this->_generacija[i + 1][j - 1] == 1)
			brojac++;
	}
	if ((i + 1) < REDAKA) {
		if (this->_generacija[i + 1][j] == 1)
			brojac++;

	}
	if ((i + 1) < REDAKA && (j + 1) < STUPACA) {
		if (this->_generacija[i + 1][j + 1] == 1)
			brojac++;

	}

	if (brojac == 3) {
		return true;
	}
	else {
		return false;
	}
}

game_of_life::game_of_life()
{
	srand(time(nullptr));
	init_polje();
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (celija_zauzeta(i, j)) {
				if (zivot_smrt(i, j)) {
					this->_sljedeca_generacija[i][j] = this->_generacija[i][j];
				}
				else {
					this->_sljedeca_generacija[i][j] = 0;
				}
			}
			else {
				if (radjanje(i, j)) {
					this->_sljedeca_generacija[i][j] = 1;
				}
				else {
					this->_sljedeca_generacija[i][j] = this->_generacija[i][j];
				}
			}
		}
	}
}

void game_of_life::iscrtaj()
{
	sljedeca_generacija();

	for (int i = 0; i < REDAKA; i++) {
		cout << endl;
		for (int j = 0; j < STUPACA; j++) {
			if (this->_generacija[i][j]) {
				cout << "*";
			}
			else {
				cout << "-";
			}
			this->_generacija[i][j] = this->_sljedeca_generacija[i][j];
		}
	}

}

