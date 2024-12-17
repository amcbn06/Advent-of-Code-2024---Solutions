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

vector<int> getNumbers(string str) {
	vector<int> foo;
	regex number("\\d+");
	auto bgn = sregex_iterator(str.begin(), str.end(), number);
	for (; bgn != sregex_iterator(); ++bgn) {
		foo.push_back(stoi(bgn->str()));
	}
	return foo;
}

vector<int> run(vector<long long> reg, vector<int> program) {
	vector<int> output;
	for (int i = 0; i + 1 < program.size(); i += 2) {
		int literal = program[i + 1];
		long long combo = program[i + 1];
		if (combo > 3) {
			combo = reg[combo - 4];
		}
		switch (program[i])
		{
		case 0:
			reg[0] = reg[0] >> combo;
			break;
		case 1:
			reg[1] ^= literal;
			break;
		case 2:
			reg[1] = combo & 7;
			break;
		case 3:
			if (reg[0] != 0) {
				i = literal - 2;
			}
			break;
		case 4:
			reg[1] ^= reg[2];
			break;
		case 5:
			output.push_back(combo & 7);
			break;
		case 6:
			reg[1] = reg[0] >> combo;
			break;
		case 7:
			reg[2] = reg[0] >> combo;
			break;
		}
	}
	return output;
}

void solve() { 
	vector<int> program = getNumbers(input[4]);
	vector<long long> reg(3);
	long long A = 0; // only the last 3 bits matter;
	for (int i = 0; i < program.size(); ++i) {
		reg[0] = A;
		while (run(reg, program) != vector<int>(program.end() - i - 1, program.end())) {
			reg[0] = ++A;
		}
		cout << A << "\n";
		A <<= 3;
	}
	fout << A;
}

int main() {
	auto start_time = chrono::high_resolution_clock::now();
	read();
	solve();
	auto end_time = chrono::high_resolution_clock::now();
	double duration = chrono::duration<double>(end_time - start_time).count();
	cerr << "Duration: " << duration;
}
