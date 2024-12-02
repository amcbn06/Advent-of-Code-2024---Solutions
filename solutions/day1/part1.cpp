#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	vector<int> a, b;
	int x, y;
	while (fin >> x >> y) {
		a.push_back(x);
		b.push_back(y);
	}
	assert(a.size() == b.size());
	// We sort the arrays so that each on each index i, a[i] is paired with b[i]
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	// We compute the distance
	int answer = 0;
	for (int i = 0; i < a.size(); ++i) {
		answer += abs(a[i] - b[i]);
	}
	fout << answer;
}
