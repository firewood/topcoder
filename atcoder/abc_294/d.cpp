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
	int N, Q, type, x, seq = 0;
	cin >> N >> Q;
	set<int> s;
	for (int q = 0; q < Q; ++q) {
		cin >> type;
		if (type == 1) {
			s.insert(++seq);
		}
		if (type == 2) {
			cin >> x;
			s.erase(x);
		}
		if (type == 3) {
			cout << *(s.begin()) << endl;
		}
	}
	return 0;
}
