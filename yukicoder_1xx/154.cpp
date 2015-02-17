#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

bool can(const string &s) {
	string r = s;
	reverse(r.begin(), r.end());
	while (r.length() > 1) {
		int pos = r.find('R', 1);
		if (pos < 0) {
			break;
		}
		r = r.substr(0, pos) + r.substr(pos + 1);
		pos = r.find('G', pos);
		if (pos < 0) {
			return false;
		}
		r = r.substr(0, pos) + r.substr(pos + 1);
		int first = -1;
		for (int i = pos; i < (int)r.length(); ++i) {
			if (r[i] == 'W' || r[i] == 'X') {
				r[i] = 'X';
				if (first < 0) {
					first = i;
				}
			}
		}
		if (first < 0) {
			return false;
		}
		r = r.substr(0, first) + r.substr(first + 1);
	}
	if (r.length() < 3 || r[0] != 'R') {
		return false;
	}
	int g = 0;
	bool f = false;
	for (int i = 1; i < (int)r.length(); ++i) {
		if (r[i] == 'R') {
			return false;
		} else if (r[i] == 'G') {
			if (++g > 1) {
				return false;
			}
		} else {
			if (g) {
				f = true;
			} else if (r[i] == 'W') {
				return false;
			}
		}
	}
	return f;
}

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int i = 0; i < T; ++i) {
		getline(cin, s);
		cout << (can(s) ? "possible" : "impossible") << endl;
	}
	return 0;
}
