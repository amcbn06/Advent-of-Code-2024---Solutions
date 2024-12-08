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

int main() {
	startTimer();
	int answer = 0;
	vector<string> input;
	string line;
	while (getline(fin, line)) {
		input.push_back(move(line));
	}

	// Solution goes here

	fout << answer;
	cerr << "Duration: " << timer();
}
