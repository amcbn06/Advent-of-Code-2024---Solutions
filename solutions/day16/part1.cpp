#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");


const int dx[4]{ 0, 1, 0, -1 };
const int dy[4]{ -1, 0, 1, 0 };

vector<string> input;
int n, m;
vector<vector<long long>> src[4];

void read() {
	string line;
	while (getline(fin, line)) {
		input.push_back(line);
	}
}

long long solve() {
	n = input.size() - 2;
	m = input[0].size() - 2;
	for (int k = 0; k < 4; ++k) {
		src[k].assign(n + 2, vector<long long>(m + 2, 1e18));
	}
	int si = -1, sj = -1, ei = -1, ej = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (input[i][j] == 'S') {
				si = i, sj = j;
			}
			else if (input[i][j] == 'E') {
				ei = i, ej = j;
			}
		}
	}
	priority_queue<tuple<long long, int, int, int>, vector<tuple<long long, int, int, int>>, greater<tuple<long long, int, int, int>>> pq;
	src[2][si][sj] = 0;
	pq.push(make_tuple(0, 2, si, sj));
	while (pq.size()) {
		long long cd = get<0>(pq.top());
		int k = get<1>(pq.top());
		int i = get<2>(pq.top());
		int j = get<3>(pq.top());
		pq.pop();
		if (src[k][i][j] != cd) {
			continue;
		}
		// forward
		if (input[i + dx[k]][j + dy[k]] != '#' && src[k][i + dx[k]][j + dy[k]] > src[k][i][j] + 1) {
			src[k][i + dx[k]][j + dy[k]] = src[k][i][j] + 1;
			pq.push(make_tuple(src[k][i + dx[k]][j + dy[k]], k, i + dx[k], j + dy[k]));
		}
		// rotate
		if (src[(k + 1) % 4][i][j] > src[k][i][j] + 1000) {
			src[(k + 1) % 4][i][j] = src[k][i][j] + 1000;
			pq.push({ src[(k + 1) % 4][i][j], (k + 1) % 4, i, j });
		}
		if (src[(k + 3) % 4][i][j] > src[k][i][j] + 1000) {
			src[(k + 3) % 4][i][j] = src[k][i][j] + 1000;
			pq.push({ src[(k + 3) % 4][i][j], (k + 3) % 4, i, j });
		}
	}
	long long answer = 1e18;
	for (int k = 0; k < 4; ++k) {
		answer = min(answer, src[k][ei][ej]);
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
