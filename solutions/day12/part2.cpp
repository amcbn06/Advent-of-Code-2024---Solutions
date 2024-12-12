#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<string> input;
int n, m;
vector<vector<bool>> vis;

void read() {
	string line;
	while (getline(fin, line)) {
		input.push_back(line);
	}
}

const int dx[4]{ 0, 1, 0, -1 };
const int dy[4]{ -1, 0, 1, 0 };

bool ok(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

// Fetch the position of the current component
void ffill(int i, int j, set<pair<int, int>>& positions) {
	vis[i][j] = true;
	positions.insert({ i, j });
	for (int k = 0; k < 4; ++k) {
		int ii = i + dx[k], jj = j + dy[k];
		if (ok(ii, jj) && !vis[ii][jj] && input[ii][jj] == input[i][j]) {
			ffill(ii, jj, positions);
		}
	}
}

// Compute the number of sides of the component given the positions
int computeSides(set<pair<int, int>>& positions) {
	map<int, vector<int>> byx, byy;
	for (auto& pos : positions) {
		int i = pos.first, j = pos.second;
		byx[i].push_back(j);
		byy[j].push_back(i);
	}
  // We traverse each row and count with how many up / down sides does it contribute
	int sides = 0;
	for (const auto& it : byx) {
		int i = it.first;
		int cntUp = 0, cntDown = 0;
		int last_j = -2;
		for (const auto& j : it.second) {
			if (last_j + 1 != j) {
				cntUp = cntDown = 0;
			}
			if (!positions.count({ i - 1, j })) {
				sides += cntUp++ == 0;
			}
			else {
				cntUp = 0;
			}
			if (!positions.count({ i + 1, j })) {
				sides += cntDown++ == 0;
			}
			else {
				cntDown = 0;
			}
			last_j = j;
		}
	}
  // We traverse each column and count with how many left / right sides does it contribute
	for (const auto& it : byy) {
		int j = it.first;
		int cntLeft = 0, cntRight = 0;
		int last_i = -2;
		for (const auto& i : it.second) {
			if (last_i + 1 != i) {
				cntLeft = cntRight = 0;
			}
			if (!positions.count({ i, j - 1 })) {
				sides += cntLeft++ == 0;
			}
			else {
				cntLeft = 0;
			}
			if (!positions.count({ i, j + 1 })) {
				sides += cntRight++ == 0;
			}
			else {
				cntRight = 0;
			}
			last_i = i;
		}
	}
	return sides;
}

long long solve() {
	n = input.size(), m = input[0].size();
	vis.assign(n, vector<bool>(m));
	long long answer = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j]) {
				set<pair<int, int>> positions;
				ffill(i, j, positions);
				answer += (long long)positions.size() * computeSides(positions);
			}
		}
	}
	return answer;
}

int main() {
	auto start_time = chrono::high_resolution_clock::now();
	read();
	fout << solve();
	auto end_time = chrono::high_resolution_clock::now();
	double duration = chrono::duration<double>(end_time - start_time).count();
	cerr << "Duration: " << duration;
}
