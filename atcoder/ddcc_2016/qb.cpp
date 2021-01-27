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

typedef pair<int, int> II;

void solve(int N, std::vector<int> &A) {
    if (*max_element(A.begin(), A.end()) == A.front()) {
        --N;
        A.erase(A.begin());
    }
    vector<II> v;
    for (int i = 0; i < N; i++) {
        v.emplace_back(II(A[i], i));
    }
    sort(v.begin(), v.end());
    int pos = 0, ans = 1, i = 0;
    while (i < N) {
        int prev_pos = pos;
        int rightmost_pos = N;
        int current_value = v[i].first;
        while (i < N && v[i].first == current_value) {
            if (v[i].second < pos) {
                ++ans;
            }
            pos = v[i].second;
            if (pos < prev_pos) {
                rightmost_pos = pos;
            }
            ++i;
        }
        pos = min(pos, rightmost_pos);
    }
	cout << ans << endl;
}

int main() {
#if DEBUG
	freopen("in.txt", "r", stdin);
#endif
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	solve(N, A);
	return 0;
}
