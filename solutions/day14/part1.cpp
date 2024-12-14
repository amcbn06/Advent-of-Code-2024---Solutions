#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int inf = 0x3f3f3f3f;
vector<string> input;
int n = 103, m = 101;
int steps = 100;
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

long long solve() {
	int k = input.size();
	for (int i = 0; i < k; ++i) {
		auto nums = getNumbers(input[i]);
		int x = nums[1], y = nums[0];
		int vx = nums[3], vy = nums[2];
		// Compute the final position
		x = ((x + steps * vx) % n + n) % n;
		y = ((y + steps * vy) % m + m) % m;
		a[x][y]++;
	}
	int quadrants[4]{ 0, 0, 0, 0 };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
      			// In the middle row / column => skip
			if (2 * i + 1 == n || 2 * j + 1 == m) {
				continue;
			}
			quadrants[(2 * i + 1 < n) << 1 | (2 * j + 1 < m)] += a[i][j];
		}
	}
	long long answer = 1;
	for (int k = 0; k < 4; ++k) {
		answer *= quadrants[k];
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
