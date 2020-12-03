#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> seq(n);
	iota(seq.begin(), seq.end(), 0);
	string ans = "None";
	do {
		string t;
		for (int x : seq) {
			t += s[x];
		}
		string r = t;
		reverse(r.begin(), r.end());
		if (s != t && s != r) {
			ans = t;
			break;
		}
	} while (next_permutation(seq.begin(), seq.end()));
	cout << ans << endl;
	return 0;
}
