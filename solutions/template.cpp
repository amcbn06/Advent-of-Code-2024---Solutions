#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<string> input;

void read() {
	string line;
	while (getline(fin, line)) {
		input.push_back(line);
	}
}

long long solve() {


}

int main() {
	auto start_time = chrono::high_resolution_clock::now();
	read();
	fout << solve();
	auto end_time = chrono::high_resolution_clock::now();
	double duration = chrono::duration<double>(end_time - start_time).count();
	cerr << "Duration: " << duration;
}
