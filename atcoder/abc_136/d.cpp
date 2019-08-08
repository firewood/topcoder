// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int len = (int)s.length();
	s += 'R';
	vector<int> elements, count(len);
	char prev = -1;
	int pos = -1;
	for (int i = 0; i <= len; ++i) {
		if (s[i] == 'R') {
			if (prev == 'L') {
				for (int x : elements) {
					count[pos + (abs(pos - x) % 2)] += 1;
				}
				elements.clear();
			}
			pos = i;
		}
		elements.push_back(i);
		prev = s[i];
	}
	for (int i = 0; i < len; ++i) {
		if (i) cout << " ";
		cout << count[i];
	}
	cout << endl;
	return 0;
}
