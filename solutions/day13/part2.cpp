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
pair<long long, long long> getNumbers(string str) {
	pair<long long, long long> foo;
	regex number("\\d+");
	auto bgn = sregex_iterator(str.begin(), str.end(), number);
	foo.first = stoll(bgn->str());
	foo.second = stoll(next(bgn)->str());
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
		dst.first += 10000000000000;
		dst.second += 10000000000000;
        	// Solve by formula
		// a * da.first + b * db.first = dst.first | * db.second
		// a * da.second + b * db.second = dst.second | * db.first
		// a * (da.first * db.second - da.second * db.first) = dst.first * db.second - dst.second * db.first
		long long a = (dst.first * db.second - dst.second * db.first) / (da.first * db.second - da.second * db.first);
		long long b = (dst.first - a * da.first) / db.first;
		if (a >= 0 && b >= 0 && a * da.first + b * db.first == dst.first && a * da.second + b * db.second == dst.second) {
			answer += 3 * a + b;
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
