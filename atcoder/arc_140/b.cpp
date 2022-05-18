#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int solve(int N, std::string S) {
	int ans = 0, ac = 0, cc = 0, st = -1;
	map<int, int> q;
	S += 'X';
	for (char c : S) {
		if (c != 'C' && st == 2) {
			q[min(ac, cc)] += 1;
		}
		switch (c) {
		case 'A':
			if (st != 0) {
				st = 0;
				ac = 0;
				cc = 0;
			}
			ac += 1;
			break;
		case 'R':
			if (st == 0) {
				st = 1;
			} else {
				st = -1;
			}
			break;
		case 'C':
			if (st == 1) {
				st = 2;
			} else if (st != 2) {
				st = -1;
			}
			cc += 1;
			break;
		}
	}

	for (int i = 0; !q.empty(); ++i) {
		++ans;
		int key = i % 2 ? q.begin()->first : q.rbegin()->first;
		q[key] -= 1;
		if (q[key] == 0) {
			q.erase(key);
		}
		if ((i % 2) == 0 && key >= 2) {
			q[key - 1] += 1;
		}
	}
	return ans;
}

int main() {
	int N;
	std::string S;
	std::cin >> N >> S;
	cout << solve(N, S) << endl;
	return 0;
}
