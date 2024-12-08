#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

chrono::steady_clock::time_point start_time;
void startTimer() {
	start_time = chrono::high_resolution_clock::now();
}
double timer() {
	return chrono::duration<double>(chrono::high_resolution_clock::now() - start_time).count();
}

int main() {
	startTimer();
	int answer = 0;
	vector<string> input;
	string line;
	while (getline(fin, line)) {
		input.push_back(move(line));
	}
	int n = input.size();
	int m = input[0].size();
	vector<vector<bool>> antenna(n, vector<bool>(m));
	map<char, vector<pair<int, int>>> pos;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (input[i][j] != '.') {
				pos[input[i][j]].push_back({ i, j });
			}
		}
	}
	auto ok = [&](pair<int, int> foo) {
		return 0 <= foo.first && foo.first < n && 0 <= foo.second && foo.second <= m;
	};
	for (auto& it : pos) {
		for (int i = 0; i < it.second.size(); ++i) {
			for (int j = 0; j < it.second.size(); ++j) {
				if (i == j) {
					continue;
				}
				pair<int, int> a = it.second[i];
				pair<int, int> b = it.second[j];
				pair<int, int> c(2 * it.second[j].first - it.second[i].first, 2 * it.second[j].second - it.second[i].second);
				if (ok(c)) {
					antenna[c.first][c.second] = true;
				}
			}
		}
	}
	for (auto& row : antenna) {
		answer += count(row.begin(), row.end(), true);
	}
	fout << answer;
	cerr << "Duration: " << timer();
}
