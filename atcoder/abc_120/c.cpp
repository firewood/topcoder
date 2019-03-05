// C.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int n = (int)s.length();
	list<int> a;
	for (int i = 0; i < n; ++i) {
		a.push_back(s[i] != '0');
	}
	int ans = 0;
	list<int>::iterator it = a.begin();
	while (it != a.end()) {
		list<int>::iterator next = it;
		++next;
		if (next == a.end()) {
			break;
		}
		if (*it == *next) {
			++it;
		} else {
			ans += 2;
			it = a.erase(it);
			it = a.erase(it);
			if (it != a.begin()) {
				--it;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
