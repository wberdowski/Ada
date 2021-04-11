#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& k, int n, int idx) {

	if (idx < n) {
		cout << k[idx];
		print(k, n, idx * 2 + 1);
		print(k, n, idx * 2 + 2);
	}
}

void restore(vector<int>& k, int n) {

	bool chng = false;
	int idx = 0;
	int mul = 1;
	int parent, leftChild, rightChild;
	int half = n / 2;

	for (int i = 0; i < half; i++) {

		if (chng) {
			i = 0;
			chng = false;
		}

		parent = k[i];
		idx = 2 * i;

		if (n == idx + 2) {
			leftChild = k[idx + 1];

			if (leftChild < parent) {
				chng = true;
				swap(k[i], k[idx + 1]);
			}
		}
		else {
			leftChild = k[idx + 1];
			rightChild = k[idx + 2];

			if (leftChild < parent || rightChild < parent) {
				if (leftChild < rightChild) {
					chng = true;
					swap(k[i], k[idx + 1]);
				}
				else {
					chng = true;
					swap(k[i], k[idx + 2]);
				}
			}
		}
	}
}

void sort(vector<int>& k, int n) {
	for (int i = 0; i < n; i++) {
		cout << k[n - 1 - i];
		swap(k[0], k[n - 1 - i]);
		restore(k, n - 1 - i);
	}
}

int main()
{
	int n = 0;
	cin >> n;
	vector<int> k;

	for (int i = 0; i < n; i++) {
		int val = 0;
		cin >> val;
		k.push_back(val);
		restore(k, i);
	}

	print(k, n, 0);
	sort(k, n);

	return 0;
}