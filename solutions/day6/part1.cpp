#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int dx[4]{ -1, 0, 1, 0, };
const int dy[4]{ 0, 1, 0, -1 };
int n, m;
vector<string> a;
vector<vector<bool>> vis;

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
	vis.assign(n, vector<bool>(m));
	// We search for the starting position
	int x, y, dir = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '^') {
				x = i, y = j;
			}
		}
	}
	// We just simulate the process
	while (ok(x, y)) {
		vis[x][y] = true;
		while (ok(x + dx[dir], y + dy[dir]) && a[x + dx[dir]][y + dy[dir]] == '#') {
			dir = (dir + 1) % 4;
		}
		x += dx[dir], y += dy[dir];
	}
	int answer = 0;
	for (auto& row : vis) {
		answer += count(row.begin(), row.end(), true);
	}
	fout << answer;
}
