#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int pagemax = 1000;
set<int> behind[pagemax];

// Comparator to check if two pages are in order
bool compare(int x, int y) {
	return behind[y].count(x);
}

int main() {
	// We read the page ordering rules
	string line;
	while (getline(fin, line)) {
		if (line.empty()) {
			break;
		}
		int i = find(line.begin(), line.end(), '|') - line.begin();
		int x = stoi(string(line.begin(), line.begin() + i));
		int y = stoi(string(line.begin() + i + 1, line.end()));
		behind[y].insert(x);
	}
	int answer = 0;
	// We read the arrays of pages
	while (getline(fin, line)) {
		stringstream ss(line);
		string token;
		vector<int> aux;
		while (getline(ss, token, ',')) {
			int x = stoi(token);
			aux.push_back(x);
		}
		// If the ordering is correct, we add the middle page to the result
		if (is_sorted(aux.begin(), aux.end(), &compare)) {
			answer += aux[aux.size() / 2];
		}
	}
	fout << answer;
}
