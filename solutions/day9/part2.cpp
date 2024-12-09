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


long long answer = 0;
string line;

struct sequence {
	int id;
	int pos;
	int len;
};

vector<int> ids;
map<int, set<int>> freemem;
void dbgmem() {
	cout << "mem: ";
	for (auto& it : freemem) {
		for (auto& pos : it.second) {
			cout << "{" << it.first << "," << pos << "} ";
		}
	}
	cout << "\n";
}
void remmem(int pos, int len) {
	if (len > 0 && freemem.count(len) && freemem[len].count(pos)) {
		freemem[len].erase(pos);
		if (freemem[len].empty()) {
			freemem.erase(len);
		}
	}
}
void addmem(int pos, int len) {
	if (len > 0) {
		freemem[len].insert(pos);
	}
}
vector<sequence> blocks;

void readInput(){
	getline(fin, line);
	int pos = 0, id = 0;
	for (int i = 0; i < line.size(); ++i) {
		int len = line[i] - '0', curid = -1;
		if (i % 2 == 0) {
			curid = id++;
			if (len > 0) {
				blocks.push_back(sequence{ curid, (int)ids.size(), len });
			}
		}
		else {
			addmem(ids.size(), len);
		}
		if (len > 0) {
			for (int i = 0; i < len; ++i) {
				ids.push_back(curid);
			}
		}
	}
}

int main() {
	startTimer();
	readInput();
    	// Sort from the highest ID to the lowest
	sort(blocks.begin(), blocks.end(), [&](const sequence& lhs, const sequence& rhs) {
		return lhs.id > rhs.id;
		});
	for (auto& block : blocks) {
		// find the leftmost empty sequence that can fit this block
		int freepos = 1e9, freelen = -1;
		for (auto it : freemem) {
			if (it.first >= block.len && *it.second.begin() < freepos) {
				freepos = *it.second.begin(), freelen = it.first;
			}
		}
		if (freepos >= block.pos) {
			continue;
		}
		// Case I: the sequence is adjacent to us, therefore we just shift the block to the left
		if (freepos + freelen == block.pos) {
			// Remove the chosen empty sequence from our dictionary
			remmem(freepos, freelen);
			// Remove the empty sequence after the block
			int auxpos = block.pos + block.len, auxlen = 0;
			while (auxpos + auxlen < ids.size() && ids[auxpos + auxlen] == -1) {
				++auxlen;
			}
			remmem(auxpos, auxlen);
			// Transfer the block
			for (int k = block.pos; k < block.pos + block.len; ++k) {
				ids[k] = -1;
			}
			for (int k = freepos; k < freepos + block.len; ++k) {
				ids[k] = block.id;
			}
			// Add the newly formed empty sequence
			freepos += block.len, freelen = 0;
			while (freepos + freelen < ids.size() && ids[freepos + freelen] == -1) {
				++freelen;
			}
		}
		else { // case II: there are other blocks between us and the empty sequence
			// Remove the chosen empty sequence from out dictionary
			remmem(freepos, freelen);
			// Transfer the block
			for (int k = block.pos; k < block.pos + block.len; ++k) {
				ids[k] = -1;
			}
			for (int k = freepos; k < freepos + block.len; ++k) {
				ids[k] = block.id;
			}
			// Add the remaining empty sequence
			addmem(freepos + block.len, freelen - block.len);
			// Remove the empty sequence to the left of the block
			freepos = block.pos, freelen = 0;
			while (freepos - 1 >= 0 && ids[freepos - 1] == -1) {
				++freelen, --freepos;
			}
			remmem(freepos, freelen);
			// Remove the empty sequence to the right of the block
			int auxpos = block.pos + block.len, auxlen = 0;
			while (auxpos + auxlen < ids.size() && ids[auxpos + auxlen] == -1) {
				++auxlen;
			}
			remmem(auxpos, auxlen);
			// Add the newly formed empty sequence
			addmem(freepos, freelen + block.len + auxlen);
		}
	}
	for (int i = 0; i < ids.size(); ++i) {
		if (ids[i] == -1) {
			continue;
		}
		answer += i * ids[i];
	}
	fout << answer;
	cerr << "Duration: " << timer();
}
