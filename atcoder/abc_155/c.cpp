// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	map<string, int> m;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		m[s] += 1;
		cnt = max(cnt, m[s]);
	}
	for (auto kv : m) {
		if (kv.second == cnt) {
			cout << kv.first << endl;
		}
	}
	return 0;
}
