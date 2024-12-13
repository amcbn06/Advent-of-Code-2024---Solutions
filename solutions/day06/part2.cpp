#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int dx[4]{ -1, 0, 1, 0, };
const int dy[4]{ 0, 1, 0, -1 };
int n, m;
vector<string> a;
vector<vector<vector<bool>>> vis;
vector<vector<bool>> candidate;

bool ok(int i, int j) {
	return 1 <= i && i <= n && 1 <= j && j <= m;
}

// Simulate if starting from a given position and direction the guard will loop
bool willCycle(int x, int y, int dir) {
	set<tuple<int, int, int>> seen;
	do {
		seen.insert(make_tuple(x, y, dir));
		while (ok(x + dx[dir], y + dy[dir]) && a[x + dx[dir]][y + dy[dir]] == '#') {
			dir = (dir + 1) % 4;
		}
		x += dx[dir], y += dy[dir];
	} while (ok(x, y) && !seen.count(make_tuple(x, y, dir)));
	return seen.count(make_tuple(x, y, dir));
}

int main() {
	string line;
	while (getline(fin, line)) {
		line = '$' + line + '$';
		a.push_back(line);
		
	}
	n = a.size();
	m = a[0].size() - 2;
	a.insert(a.begin(), string(m + 2, '$'));
	a.insert(a.end(), string(m + 2, '$'));
	vis.assign(n + 2, vector<vector<bool>>(m + 2, vector<bool>(4)));
	candidate.assign(n + 2, vector<bool>(m + 2));
	int x, y, dir = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '^') {
				x = i, y = j;
			}
		}
	}
    // We simulate the path of the guard just like before
	while (ok(x, y)) {
		vis[x][y][dir] = true;
		while (ok(x + dx[dir], y + dy[dir]) && a[x + dx[dir]][y + dy[dir]] == '#') {
			dir = (dir + 1) % 4;
		}
		int ax = x + dx[dir], ay = y + dy[dir], adir = dir;
		// If the next position is available (the guard doesn't exit the map)
		if (ok(ax, ay)) {
			a[ax][ay] = '#';
			while (ok(x + dx[dir], y + dy[dir]) && a[x + dx[dir]][y + dy[dir]] == '#') {
				dir = (dir + 1) % 4;
			}
			// We search for the position that will be picked next
			int bx = x + dx[dir], by = y + dy[dir], bdir = dir;
			// If i haven't visited position A before (if i have visited it i can't place an obstacle),
			// and position B was already visited before or will make us loop in the future (which we can 
			// check with another simulation), position A is a candidate for a potential obstacle
			if (count(vis[ax][ay].begin(), vis[ax][ay].end(), true) == 0 && ((ok(bx, by) && vis[bx][by][bdir]) || willCycle(x, y, bdir))) {
				candidate[ax][ay] = true;
			}
			a[ax][ay] = '.';
		}
		x = ax, y = ay, dir = adir;
	}	int answer = 0;
	for (auto& row : candidate) {
		answer += count(row.begin(), row.end(), true);
	}
	fout << answer;
}
