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
	long long answer = 0;
	string line;
	getline(fin, line);
	int pos = 0, id = 0;
    // We recreate the sequence
	vector<int> ids;
	for (int i = 0; i < line.size(); ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < line[i] - '0'; ++j) {
				ids.push_back(id);
			}
			id++;
		}
		else {
			for (int j = 0; j < line[i] - '0'; ++j) {
				ids.push_back(-1);
			}
		}
	}
    // we take memory from the back and bring it to the front
	for (int i = 0; i < ids.size(); ++i) {
		while (i < ids.size() && ids[i] == -1) {
			ids[i] = ids.back();
			ids.pop_back();
		}
		if (i < ids.size()) {
			answer += i * ids[i];
		}
	}
	fout << answer;
	cerr << "Duration: " << timer();
}