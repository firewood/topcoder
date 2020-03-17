// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> b = a;
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	map<int, int> m;
	for (size_t i = 0; i < b.size(); ++i) {
		m[b[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		cout << m[a[i]] << endl;
	}
	return 0;
}
