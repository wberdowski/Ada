#include <iostream>

using namespace std;

bool* odwiedzone;

int czyIstniejeDroga(bool** macierz, int wPocz, int wKon, int n) {
	if (macierz[wPocz][wKon]) return 1;
	if (wPocz == wKon) return 1;

	for (int i = 0; i < n; i++) {
		if (!odwiedzone[i] && macierz[wPocz][i]) {
			if (macierz[i][wKon] || czyIstniejeDroga(macierz, i, wKon, n)) {
				return 1;
			}
		}
	}

	odwiedzone[wPocz] = true;

	return 0;
}

int main() {
	int n;

	cin >> n;

	bool** macierz;
	macierz = new bool* [n] {false};

	for (int i = 0; i < n; i++) {
		macierz[i] = new bool[n];
	}

	while (true) {
		int cmd, wPocz, wKon;

		cin >> cmd;

		switch (cmd) {
		case 0:
			cin >> wPocz;
			cin >> wKon;

			macierz[wPocz][wKon] = 1;
			break;
		case 1:
			cin >> wPocz;
			cin >> wKon;

			macierz[wPocz][wKon] = 1;
			macierz[wKon][wPocz] = 1;
			break;
		case 2:
			cin >> wPocz;
			cin >> wKon;

			odwiedzone = new bool[n] {
				false
			};
			cout << czyIstniejeDroga(macierz, wPocz, wKon, n);
			break;
		case -1:
			return 0;
		}
	}
}