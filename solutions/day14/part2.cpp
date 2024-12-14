#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int inf = 0x3f3f3f3f;
vector<string> input;
vector<pair<int, int>> pos, vel;
int n = 103, m = 101;
int steps = n * m;
vector<vector<int>> a(n, vector<int>(m));

void read() {
	string line;
	while (getline(fin, line)) {
		input.push_back(line);
	}
}

// Function to extract numbers from string, also words with negative numbers
vector<int> getNumbers(string str) {
	vector<int> numbers;
	regex number("[-]?\\d+");
	auto bgn = sregex_iterator(str.begin(), str.end(), number);
	for (; bgn != sregex_iterator(); ++bgn) {
		numbers.push_back(stoi(bgn->str()));
	}
	return numbers;
}

// Simulate the passing of a second
void passSecond() {
	int k = input.size();
	for (int i = 0; i < k; ++i) {
		a[pos[i].first][pos[i].second]--;
		pos[i].first = ((pos[i].first + vel[i].first) % n + n) % n;
		pos[i].second = ((pos[i].second + vel[i].second) % m + m) % m;
		a[pos[i].first][pos[i].second]++;
	}
}

long long solve() {
	int k = input.size();
	pos.resize(k);
	vel.resize(k);
	for (int i = 0; i < k; ++i) {
		auto nums = getNumbers(input[i]);
		pos[i] = { nums[1], nums[0] };
		vel[i] = { nums[3], nums[2] };
		a[pos[i].first][pos[i].second]++;
	}
  // Just output to a file all the states 
	for (int t = 0; t <= steps; ++t) {
		fout << "After " << t << " seconds\n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j]) {
					fout << a[i][j];
				}
				else {
					fout << '.';
				}
			}
			fout << "\n";
		}
		fout << "\n";
		passSecond();
	}
	return 0;
}

int main() {
	auto start_time = chrono::high_resolution_clock::now();
	read();
	fout << solve();
	auto end_time = chrono::high_resolution_clock::now();
	double duration = chrono::duration<double>(end_time - start_time).count();
	cerr << "Duration: " << duration;
}
