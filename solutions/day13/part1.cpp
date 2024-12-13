#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int inf = 0x3f3f3f3f;
vector<string> input;
int n, m;

void read() {
	string line;
	while (getline(fin, line)) {
		input.push_back(line);
	}
}

// Function to get the first two numbers from a string
pair<int, int> getNumbers(string str) {
	pair<int, int> foo;
	regex number("\\d+");
	auto bgn = sregex_iterator(str.begin(), str.end(), number);
	foo.first = stoi(bgn->str());
	foo.second = stoi(next(bgn)->str());
	return foo;
}

long long solve() {
	n = input.size();
	long long answer = 0;
	for (int i = 0; i < n; i += 4) {
        // The increase from button A
		auto da = getNumbers(input[i]);
        // The increase from button B
		auto db = getNumbers(input[i + 1]);
        // The coordinates of the prize
		auto dst = getNumbers(input[i + 2]);
		long long cost = inf;
        // Just bruteforce
		for (int a = 0; a <= 100; ++a) {
			int b = (dst.first - a * da.first) / db.first;
			if (a * da.first + b * db.first == dst.first && a * da.second + b * db.second == dst.second) {
				cost = min(cost, 1ll * a * 3 + b);
			}
		}
		if (cost != inf) {
			answer += cost;
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