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

// Just count the number of paths to 9s using BFS
int countReachable(int i, int j) {
	vector<vector<int>> dp(n, vector<int>(m));
	queue<pair<int, int>> q;
	dp[i][j] = 1;
	q.push({ i, j });
	int cnt = 0;
	while (q.size()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		if (input[i][j] == '9') {
			cnt += dp[i][j];
			continue;
		}
		for (int k = 0; k < 4; ++k) {
			int ii = i + dx[k], jj = j + dy[k];
			if (ok(ii, jj) && input[ii][jj] == input[i][j] + 1) {
				if (!dp[ii][jj]) {
					q.push({ ii, jj });
				}
				dp[ii][jj] += dp[i][j];
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
