#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int dx[4]{ 0, 1, 0, -1 };
const int dy[4]{ -1, 0, 1, 0 };
const string arr = "<v>^";

vector<string> input;
string instructions;
int n, m;

bool ok(int i, int j) {
	return 1 <= i && i <= n && 1 <= j && j <= n;
}

bool isBox(char ch) {
	return ch == '[' || ch == ']';
}

void read() {
	string line;
	while (getline(fin, line)) {
		if (line.empty()) {
			break;
		}
		// Modify the input
		string nline;
		for (auto& ch : line) {
			if (ch == 'O') {
				nline += "[]";
			}
			else if (ch == '#') {
				nline += "##";
			}
			else {
				nline += ch;
				nline += '.';
			}
		}
		input.push_back(nline);
	}
	while (getline(fin, line)) {
		if (line.empty()) {
			break;
		}
		instructions += line;
	}
}

// Find the set of elements that move
void ffill(int i, int j, int k, set<pair<int, int>>& positions) {
	positions.insert({ i, j });
	i += dx[k], j += dy[k];
	if ( isBox(input[i][j])) {
		if (!positions.count({ i, j })) {
			ffill(i, j, k, positions);
		}
		if (input[i][j] == '[') {
			++j;
		}
		else {
			--j;
		}
		if (!positions.count({ i, j })) {
			ffill(i, j, k, positions);
		}
	}
}

void debug() {
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= m + 1; ++j) {
			cout << input[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

long long solve() {
	n = input.size() - 2;
	m = input[0].size() - 2;
	int ri, rj;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (input[i][j] == '@') {
				ri = i, rj = j;
			}
		}
	}
	for (auto& ch : instructions) {
		int k = arr.find(ch);
		set<pair<int, int>> positions;
		ffill(ri, rj, k, positions);
		// If each position has either another position from the set or an empty cell in the direction `k`, we can move
		bool can_move = true;
		for (auto& pos : positions) {
			int i = pos.first, j = pos.second;
			int ii = i + dx[k], jj = j + dy[k];
			if (!(positions.count({ ii, jj }) || input[ii][jj] == '.')) {
				can_move = false;
				break;
			}
		}
		if (can_move) {
			// Sort the cells from the furtherest to the closest
			vector<pair<int, int>> inOrder(positions.begin(), positions.end());
			sort(inOrder.begin(), inOrder.end(), [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
				if (dx[k] != 0) {
					return abs(lhs.first - ri) > abs(rhs.first - ri);
				}
				else {
					return abs(lhs.second - rj) > abs(rhs.second - rj);
				}
			});
			// Than just move from the last to the first
			for (auto& pos : inOrder) {
				int i = pos.first, j = pos.second;
				int ii = i + dx[k], jj = j + dy[k];
				swap(input[i][j], input[ii][jj]);

			}
			ri += dx[k], rj += dy[k];
		}
		//cout << "Move: " << ch << "\n";
		//debug();
	}
	long long answer = 0;
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= m + 1; ++j) {
			if (input[i][j] == '[') {
				answer += i * 100 + j;
			}
		}
	}
	return answer;
}

int main() {
	auto start_time = chrono::high_resolution_clock::now();
	read();
	fout << solve();
	auto end_time = chrono::high_resolution_clock::now();
	double duration = chrono::duration<double>(end_time - start_time).count();
	cerr << "Duration: " << duration;
}
