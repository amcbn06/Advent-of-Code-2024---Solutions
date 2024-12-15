#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int dx[4]{ 0, 1, 0, -1 };
const int dy[4]{ -1, 0, 1, 0 };
const string arr = "<v>^";

vector<string> input;
string instructions;
int n, m;

bool ok(int i, int j) {
	return 1 <= i && i <= n && 1 <= j && j <= n;
}

void read() {
	string line;
	while (getline(fin, line)) {
		if (line.empty()) {
			break;
		}
		input.push_back(line);
	}
	while (getline(fin, line)) {
		if (line.empty()) {
			break;
		}
		instructions += line;
	}
}

long long solve() {
	n = input.size() - 2;
	m = input[0].size() - 2;
	int ri, rj;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (input[i][j] == '@') {
				ri = i, rj = j;
			}
		}
	}
	for (auto& ch : instructions) {
		int k = arr.find(ch);
        // Find the end position of the chain of Os that move
		int ci = ri, cj = rj;
		while (input[ci + dx[k]][cj + dy[k]] == 'O') {
			ci += dx[k], cj += dy[k];
		}
        // If we can move the whole chain, we do it
		if (input[ci + dx[k]][cj + dy[k]] == '.') {
            // We move from the last to the first
			while ((dx[k] ? (ci - ri) / dx[k] : (cj - rj) / dy[k]) >= 0) {
				swap(input[ci][cj], input[ci + dx[k]][cj + dy[k]]);
				ci -= dx[k], cj -= dy[k];
			}
			ri += dx[k], rj += dy[k];
		}
	}
	long long answer = 0;
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= m + 1; ++j) {
			if (input[i][j] == 'O') {
				answer += i * 100 + j;
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