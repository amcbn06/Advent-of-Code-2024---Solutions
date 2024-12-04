#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int dx[8]{ 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const string pattern = "XMAS";
int n, m;
vector<string> a;

bool ok(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
	string line;
	while (getline(fin, line)) {
		a.push_back(line);
	}
	n = a.size();
	m = a[0].size();
	int answer = 0;
	// We pick a position for the first character
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
      			// and a direction along which we search the word "XMAS"
			for (int k = 0; k < 8; ++k) {
				bool match = true;
        			// and we just check the pattern
				for (int pos = 0; pos < pattern.size(); ++pos) {
					int ii = i + dx[k] * pos;
					int jj = j + dy[k] * pos;
					match &= ok(ii, jj) && a[ii][jj] == pattern[pos];
				}
				answer += match;
			}
		}
	}
	fout << answer;
}
