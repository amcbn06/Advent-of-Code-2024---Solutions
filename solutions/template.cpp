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

vector<string> input;
int answer = 0;

void readInput() {
	string line;
	while (getline(fin, line)) {
		input.push_back(move(line));
	}
}

int main() {
	startTimer();
	readInput();

	// Solution goes here

	fout << answer;
	cerr << "Duration: " << timer();
}
