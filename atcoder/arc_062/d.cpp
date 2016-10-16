// D.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int gc = 0, pc = 0, score = 0;
	for (char c : s) {
		if (c == 'g') {
			if (gc > pc) {
				++pc;
				++score;
			} else {
				++gc;
			}
		} else {
			if (gc > pc) {
				++pc;
			} else {
				++gc;
				--score;
			}
		}
	}
	cout << score << endl;
	return 0;
}
