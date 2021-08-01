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
	int64_t Q, P, X, offset = 0;
	cin >> Q;
	priority_queue<int64_t, vector<int64_t>, greater<>> q;
	for (int i = 0; i < Q; ++i) {
		cin >> P;
		if (P == 1) {
			cin >> X;
			q.emplace(X - offset);
		} else if (P == 2) {
			cin >> X;
			offset += X;
		} else {
			cout << (q.top() + offset) << endl;
			q.pop();
		}
	}
	return 0;
}
