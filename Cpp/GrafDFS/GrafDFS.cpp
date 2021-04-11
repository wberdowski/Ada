#include <iostream>

using namespace std;

void addDirectedEdge(bool** tab, int s, int e) {
	tab[s][e] = true;
}

void addNonDirectedEdge(bool** tab, int s, int e) {
	tab[s][e] = true;
	tab[e][s] = true;
}

bool routeExists(bool** tab, int n, int s, int e, bool* v) {
	if (tab[s][e] || s == e) {
		return true;
	}

	v[s] = true;

	for (int i = 0; i < n; i++) {
		if (tab[s][i] && !v[i]) {

			if (tab[i][e]) {
				return true;
			}

			if (routeExists(tab, n, i, e, v)) {
				return true;
			}

		}
	}

	return false;
}

int main() {
	int n = 0;
	int c = -1;
	int s = 0;
	int e = 0;

	cin >> n;

	bool** tab = new bool* [n];

	for (int i = 0; i < n; i++) {
		tab[i] = new bool[n] {
			false
		};
	}

	while (true) {
		cin >> c;

		if (c == 0) {
			cin >> s;
			cin >> e;

			addDirectedEdge(tab, s, e);
		}
		else if (c == 1) {
			cin >> s;
			cin >> e;

			addNonDirectedEdge(tab, s, e);
		}
		else if (c == 2) {
			cin >> s;
			cin >> e;

			bool* v = new bool[n] {0};
			cout << routeExists(tab, n, s, e, v);
		}
		else if (c == -1) {
			return 0;
		}
	}
}