#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int itermax = 25;
long long answer = 0;
vector<int> a;

void read() {
	string line;
	getline(fin, line);
	stringstream ss(line);
	int x;
	while (ss >> x) {
		a.push_back(x);
	}
}

map<long long, long long > dp[itermax + 1];

long long solve(int iter, long long x) {
	if (iter == 0) {
		return 1;
	}
	if (dp[iter].count(x)){
		return dp[iter][x];
	}
	if (x == 0) {
		return dp[iter][x] = solve(iter - 1, 1);
	}
	string sx = to_string(x);
	if (sx.size() % 2) {
		return dp[iter][x] = solve(iter - 1, x * 2024);
	}
	else {
		int len = sx.size();
		return dp[iter][x] = solve(iter - 1, stoll(sx.substr(0, len / 2))) +
			solve(iter - 1, stoll(sx.substr(len / 2)));
	}
}

int main() {
	read();
	for (auto& x : a) {
		answer += solve(itermax, x);
	}
	fout << answer;
}