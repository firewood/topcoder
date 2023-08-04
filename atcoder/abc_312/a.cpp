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

bool solve(std::string S) {
	const string chords[] = {"ACE","BDF","CEG","DFA","EGB","FAC","GBD"};
	for (auto s : chords) {
		if (s == S) return true;
	}
	return false;
}

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif
	std::string S;
	std::cin >> S;
	cout << (solve(S) ? "Yes" : "No") << endl;
	return 0;
}
