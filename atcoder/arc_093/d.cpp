// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solve(int a, int b, char ca, char cb) {
	vector<string> r;
	if (a > 1) {
		--b;
		r.push_back(string(100, cb));
		while (a > 1) {
			int x = min(a - 1, 49);
			string s;
			for (int i = 0; i < x; ++i) {
				s += cb;
				s += ca;
			}
			s += string(100 - s.length(), cb);
			r.push_back(s);
			r.push_back(string(100, cb));
			a -= x;
		}
	}
	r.push_back(string(100, ca));
	while (b > 0) {
		int x = min(b, 49);
		string s;
		for (int i = 0; i < x; ++i) {
			s += ca;
			s += cb;
		}
		s += string(100 - s.length(), ca);
		r.push_back(s);
		r.push_back(string(100, ca));
		b -= x;
	}
	return r;
}

int main(int argc, char *argv[])
{
	int a, b;
	cin >> a >> b;
	vector<string> r = solve(min(a, b), max(a, b), a < b ? '.' : '#', a < b ? '#' : '.');
	cout << r.size() << " " << r[0].length() << endl;
	for (auto s : r) {
		cout << s << endl;
	}
	return 0;
}
