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

// Compute the perimeter of the component given the positions
int computePerimenter(set<pair<int, int>>& positions) {
	int res = 4 * positions.size();
	for (auto& pos : positions) {
		int i = pos.first, j = pos.second;
		for (int k = 0; k < 4; ++k) {
			int ii = i + dx[k], jj = j + dy[k];
			if (positions.count({ ii, jj })) {
				res--;
			}
		}
	}
	return res;
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
				answer += (long long)positions.size() * computePerimenter(positions);
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
