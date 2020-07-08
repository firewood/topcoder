// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		m[s] += 1;
	}
	for (string s : {"AC", "WA", "TLE", "RE"}) {
		cout << s << " x " << m[s] << endl;
	}
	return 0;
}
