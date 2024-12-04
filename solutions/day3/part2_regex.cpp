#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

// Returns the product of a "mul(x,y)" instruction
long long product(string str) {
	long long res = 1;
	regex number("\\d+");
	auto bgn = sregex_iterator(str.begin(), str.end(), number);
	for (auto it = bgn; it != sregex_iterator(); ++it) {
		smatch match = *it;
		res *= stoll(match.str());
	}
	return res;
}

int main() {
	string line;
	long long answer = 0;
	// Huge mistake: `enabled` is a global variable and it keeps
	// it's value when we move from the current line to the next
	bool enabled = true;
	while (getline(fin, line)) {
		// do(), don't() or mul(x,y)
		regex pattern("do\\(\\)|don't\\(\\)|mul\\(\\d+,\\d+\\)");
        auto bgn = sregex_iterator(line.begin(), line.end(), pattern);
	    for (auto it = bgn; it != sregex_iterator(); ++it) {
            smatch match = *it;
			// We enable the instructions
			if (match.str() == "do()") {
				enabled = true;
			}
			else if (match.str() == "don't()") { // We disable the instructions
				enabled = false;
			}
			else if (enabled) { // If enabled, we handle the current instruction
				answer += product(match.str());
			}
	    }
	}
	fout << answer;
}
