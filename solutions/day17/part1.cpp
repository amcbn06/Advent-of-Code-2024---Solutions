#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");


const int dx[4]{ 0, 1, 0, -1 };
const int dy[4]{ -1, 0, 1, 0 };

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

void solve() {
	int reg[3];
	for (int k = 0; k < 3; ++k) {
		reg[k] = getNumbers(input[k])[0];
	}
	vector<int> program = getNumbers(input[4]);
	vector<int> output;
	for (int i = 0; i + 1 < program.size(); i += 2) {
		int literal = program[i + 1];
		int combo = program[i + 1];
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
	for (int i = 0; i < output.size();++i) {
		fout << output[i];
		if (i + 1 < output.size()) {
			fout << ',';
		}
	}
}

int main() {
	auto start_time = chrono::high_resolution_clock::now();
	read();
	solve();
	auto end_time = chrono::high_resolution_clock::now();
	double duration = chrono::duration<double>(end_time - start_time).count();
	cerr << "Duration: " << duration;
}
