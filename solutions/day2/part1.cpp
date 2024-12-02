#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

// Function to check if an array is safe
bool safe(vector<int>& arr) {
    if (arr.size() < 2) {
        return true;
	}
    bool increasing = true, decreasing = true;
	for (int i = 1; i < arr.size(); ++i) {
		int delta = arr[i] - arr[i - 1];
		increasing &= 1 <= delta && delta <= 3;
		decreasing &= -3 <= delta && delta <= -1;
	}
	return increasing || decreasing;
}

int main() {
	int answer = 0;
	string line;
	while (getline(fin, line)) {
        stringstream ss(line);
		vector<int> arr;
		int x;
		while (ss >> x) {
			arr.push_back(x);
		}
		if (safe(arr)) {
			answer++;
		}
	}
	fout << answer;
}
