#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	string line;
	int answer = 0;
	bool enabled = true;
	while (getline(fin, line)) {
		for (int i = 0; i < line.size(); ++i) {
			if (i + 4 <= line.size() && line.substr(i, 4) == "do()") {
				enabled = true;
				i += 3;
			}
			else if (i + 7 <= line.size() && line.substr(i, 7) == "don't()") {
				enabled = false;
				i += 6;
			}
			else if (i + 4 <= line.size() && line.substr(i, 4) == "mul(") {
				int j = i + 3, k = i + 3;
				int x = 0, y = 0;
				while (k + 1 < line.size() && isdigit(line[k + 1])) {
					x = x * 10 + line[++k] - '0';
				}
				if (j == k) { // no x
					continue;
				}
				j = ++k; // ,
				if (j >= line.size() || line[j] != ',') { // no comma
					continue;
				}
				while (k + 1 < line.size() && isdigit(line[k + 1])) {
					y = y * 10 + line[++k] - '0';
				}
				if (j == k) { // no y
					continue;
				}
				j = ++k; // )
				if (j >= line.size() || line[j] != ')') { // no paranthesis
					continue;
				}
				if (enabled) {
					answer += x * y;
				}
				i = k;
			}
		}
	}
	fout << answer;
}
