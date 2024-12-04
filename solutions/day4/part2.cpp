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
  // We pick a position for the top left corner
	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < m - 2; ++j) {
      // we extract the diagnoals of the 3x3 square corespondent to that corner
			string d1, d2;
			for (int k = 0; k < 3; ++k) {
				d1 += a[i + k][j + k];
				d2 += a[i + 2 - k][j + k];
			}
      // and we just check the condition
			if ((d1 == "MAS" || d1 == "SAM") && (d2 == "MAS" || d2 == "SAM")) {
				answer++;
			}
		}
	}
	fout << answer;
}
