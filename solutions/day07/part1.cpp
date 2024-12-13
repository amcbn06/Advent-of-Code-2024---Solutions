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


int main() {
	startTimer();
	string line;
	while (getline(fin, line)) {
		vector<long long> a = split(line);
		long long expected = a[0];
		bool valid = false;
		//	We try out all the combinations
		for (int mask = 0; mask < (1 << (a.size() - 2)); ++mask) {
			long long current = a[1];
			for (int i = 2; i < a.size(); ++i) {
				if ((mask >> (i - 2)) & 1) {
					current *= a[i];
				}
				else {
					current += a[i];
				}
			}
			if (expected == current) {
				valid = true;
				break;
			}
		}
		if (valid) {
			answer += a[0];
		}
	}
	fout << answer;
	cerr << "Duration: " << timer();
}
