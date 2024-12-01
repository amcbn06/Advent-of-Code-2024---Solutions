#include <bits/stdc++.h>
using namespace std;
ifstream fin(".in");

int main() {
	map<int, int> fa, fb;
	int x, y;
	while (fin >> x >> y) {
		fa[x]++;
		fb[y]++;
	}
	// We'll use the contribution to solve this problem:
	// If `a` appears on the left `x` times and on the right `y` times,
	// it's contribution to the answer will be a * x * y
	long long answer = 0;
	for (auto& it : fa) {
		int a = it.first;
		int x = it.second;
		int y = fb[a];
		answer += 1ll * a * x * y;
	}
	cout << answer;
}
