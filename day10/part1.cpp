#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int dx[4]{ 0, 1, 0, -1 };
const int dy[4]{ -1, 0, 1, 0 };

int answer = 0;
vector<string> input;
int n, m;


bool ok(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

// Just count the number of reachable 9s with BFS
int countReachable(int i, int j) {
	vector<vector<bool>> vis(n, vector<bool>(m));
	queue<pair<int, int>> q;
	q.push({ i, j });
	int cnt = 0;
	while (q.size()) {
		int i = q.front().first;
		int j = q.front().second;
		vis[i][j] = true;
		q.pop();
		if (input[i][j] == '9') {
			++cnt;
			continue;
		}
		for (int k = 0; k < 4; ++k) {
			int ii = i + dx[k], jj = j + dy[k];
			if (ok(ii, jj) && !vis[ii][jj] && input[ii][jj] == input[i][j] + 1) {
				vis[ii][jj] = true;
				q.push({ ii, jj });
			}
		}
	}
	return cnt;
}

int main() {
	string line;
	while (getline(fin, line)) {
		input.push_back(line);
	}
	n = input.size(), m = input[0].size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (input[i][j] == '0') {
				answer += countReachable(i, j);
				cout<<i<<" "<<j<<" "<< countReachable(i, j) << "\n";
			}
		}
	}
	fout << answer;
}
