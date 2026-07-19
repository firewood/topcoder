#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const string YES = "Alice";
const string NO = "Bob";

bool solve(int64_t N, vector<int64_t> A) {
	int oc = 0;
	for (auto x : A) {
		if (x == 1) {
			++oc;
		} else {
			if (oc > 0 && oc != 2) {
				return true;
			}
			oc = 0;
		}
	}
	return (oc > 0 && oc != 2);
}

void process_case() {
	int64_t N;
	cin >> N;
	vector<int64_t> A(N);
	for (int64_t i = 0; i < N; ++i) {
		cin >> A[i];
	}
	auto ans = solve(N, A);
	cout << (ans ? YES : NO) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		process_case();
	}
}
