// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {
	int n, a;
	set<int> s;
	bool ans = true;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (s.find(a) != s.end()) {
			ans = false;
		}
		s.insert(a);
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
