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

long long answer = 0;

// Function to get numbers from string
vector<long long> split(string str) {
	regex number("\\d+");
	vector<long long> numbers;
	auto bgn = sregex_iterator(str.begin(), str.end(), number);
	for (auto it = bgn; it != sregex_iterator(); ++it) {
		smatch match = *it;
		numbers.push_back(stoll(match.str()));
	}
	return numbers;
}

// Try all the combinations
bool backtrack(int i, long long current, vector<long long>& a) {
	if (i == a.size()) {
		return a[0] == current;
	}
	return backtrack(i + 1, current + a[i], a) // +
		|| backtrack(i + 1, current * a[i], a) // *
		|| backtrack(i + 1, stoll(to_string(current) + to_string(a[i])), a); // ||
}

int main() {
	startTimer();
	string line;
	while (getline(fin, line)) {
		vector<long long> a = split(line);
		if (backtrack(2, a[1], a)) {
			answer += a[0];
		}
	}
	fout << answer;
	cerr << "Duration: " << timer();
}
