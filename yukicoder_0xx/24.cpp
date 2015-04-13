#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <set>
#include <vector>

using namespace std;
const int MOD = 1000003;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	int p[10] = {};
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		int a, b, c, d;
		string r;
		ss >> a >> b >> c >> d >> r;
		if (r.compare("YES") == 0) {
			for (int j = 0; j < 10; ++j) {
				if (j != a && j != b && j != c && j != d) {
					p[j] = 1;
				}
			}
		} else {
			p[a] = p[b] = p[c] = p[d] = 1;
		}
	}
	int ans = 0;
	for (int j = 0; j < 10; ++j) {
		if (!p[j]) {
			ans = j;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
