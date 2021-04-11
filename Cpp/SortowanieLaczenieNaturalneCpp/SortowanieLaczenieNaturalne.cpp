#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> Merge(vector<vector<int>>& tapeA, vector<vector<int>>& tapeB)
{
	vector<vector<int>> tapeC;

	int i = 0;

	while (i < tapeA.size() || i < tapeB.size())
	{
		if (i >= tapeA.size())
		{
			tapeC.push_back(tapeB[i++]);
			continue;
		}

		if (i >= tapeB.size())
		{
			tapeC.push_back(tapeA[i++]);
			continue;
		}

		int a = 0;
		int b = 0;

		vector<int> s;

		while (a < tapeA[i].size() || b < tapeB[i].size())
		{
			if (a >= tapeA[i].size())
			{
				s.push_back(tapeB[i][b++]);
				continue;
			}

			if (b >= tapeB[i].size())
			{
				s.push_back(tapeA[i][a++]);
				continue;
			}

			if (tapeA[i][a] < tapeB[i][b])
			{
				s.push_back(tapeA[i][a++]);
			}
			else
			{
				s.push_back(tapeB[i][b++]);
			}
		}

		tapeC.push_back(s);

		i++;
	}

	vector<int> output;

	for (int i = 0; i < tapeC.size(); i++)
	{
		vector<int> s = tapeC[i];

		for (int j = 0; j < s.size(); j++)
		{
			output.push_back(s[j]);
		}
	}

	return output;
}

vector<int> Sort(vector<int>& tab, int n)
{
	vector<vector<int>> tapeA;
	vector<vector<int>> tapeB;

	int tape = 0;

	for (int i = 0; i < n; i++)
	{
		auto s = vector<int>();

		s.push_back(tab[i]);

		while (i + 1 < n && tab[i + 1] >= tab[i])
		{
			s.push_back(tab[i + 1]);
			i++;
		}

		if (tape == 0)
		{
			tapeA.push_back(s);
		}
		else
		{
			tapeB.push_back(s);
		}

		tape = (tape + 1) % 2;
	}

	return Merge(tapeA, tapeB);
}

int main()
{
	int n = 0;
	int iter = 0;

	cin >> n;
	cin >> iter;

	vector<int> tab;

	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		tab.push_back(num);
	}

	for (int i = 0; i < iter; i++)
	{
		tab = Sort(tab, n);

		if (i == iter - 1) {
			for (int i = 0; i < tab.size(); i++)
			{
				cout << tab[i];
			}
		}
	}

	return 0;
}