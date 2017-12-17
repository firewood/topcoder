// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

bool possible(int x, vector<int> &v) {
	set<int> s;
	s.insert(0);
	for (int i : v) {
		set<int> n;
		for (int j : s) {
			n.insert(j + i);
			n.insert(j - i);
		}
		s = n;
	}
	return s.find(x) != s.end();
}

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int x, y, dist = 0;
	cin >> x >> y;
	bool dir = true, first = true;
	vector<int> v;
	for (char c : s) {
		if (c == 'F') {
			if (first) {
				--x;
			} else if (dir) {
				++dist;
			}
		} else {
			first = false;
			dir = !dir;
			if (dist) {
				v.push_back(dist);
				dist = 0;
			}
		}
	}
	if (dist) {
		v.push_back(dist);
		dist = 0;
	}
	bool ans = possible(x, v);
	if (ans) {
		v.clear();
		dist = 0;
		dir = false;
		for (char c : s) {
			if (c == 'F') {
				if (dir) {
					++dist;
				}
			} else {
				dir = !dir;
				if (dist) {
					v.push_back(dist);
					dist = 0;
				}
			}
		}
		if (dist) {
			v.push_back(dist);
			dist = 0;
		}
		ans = possible(y, v);
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
