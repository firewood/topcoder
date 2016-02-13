#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int cnt = 0;
	string w;
	map<int, vector<string> > m;
	for (int i = 0; i < (int)s.length() - 2; ++i) {
		if (s[i] == -17 && s[i + 1] == -67 && s[i+2] == -105) {
			i += 2;
			++cnt;
		} else {
			if (cnt > 0 && !w.empty()) {
				m[-cnt].push_back(w);
				w.clear();
			}
			cnt = 0;
			w += s[i];
		}
	}
	if (cnt > 0 && !w.empty()) {
		m[-cnt].push_back(w);
	}
	if (!m.empty()) {
		for (string s : m.begin()->second) {
			cout << s << endl;
		}
	}
	return 0;
}
