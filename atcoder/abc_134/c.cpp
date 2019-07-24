// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		m[a[i]] += 1;
	}
	for (int i = 0; i < n; ++i) {
		map<int, int>::reverse_iterator it = m.rbegin();
		int mx = it->first;
		if (a[i] == mx && it->second == 1) {
			++it;
			mx = it->first;
		}
		cout << mx << endl;
	}
	return 0;
}
