// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	string s, t;
	cin >> s >> t;
	int n = (int)s.length();
	vector<vector<int>> next_pos(n);
	vector<int> last(26);
	for (int i = 0; i < 26; ++i) {
		last[i] = s.find('a' + i);
	}
	for (int i = n - 1; i >= 0; --i) {
		next_pos[i] = last;
		last[s[i] - 'a'] = i;
	}
	LL pos = 0;
	for (char c : t) {
		LL curr = pos % n;
		if (c != s[curr]) {
			LL next = next_pos[curr][c - 'a'];
			if (next < 0) {
				pos = -1;
				break;
			}
			pos += (next + n - curr) % n;
		}
		++pos;
	}
	cout << pos << endl;
	return 0;
}
