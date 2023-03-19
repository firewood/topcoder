#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int64_t H, W, a;
	cin >> H >> W;
	for (int i = 0; i < H; ++i) {
		string s;
		for (int j = 0; j < W; ++j) {
			cin >> a;
			if (a) {
				s += char('A' + a - 1);
			} else {
				s += '.';
			}
		}
		cout << s << endl;
	}
	return 0;
}
