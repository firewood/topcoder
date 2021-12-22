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

int64_t solve(int N, int K, std::vector<int> a) {
    map<int, int> m;
    int left = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        m[a[i]] += 1;
        while (m.size() > K) {
            int x = a[left];
            if (m[x] == 1) {
                m.erase(x);
            } else {
                m[x] -= 1;
            }
            ++left;
        }
        ans = max(ans, i + 1 - left);
    }
	return ans;
}

int main() {
    int N, K;
	std::cin >> N >> K;
	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	cout << solve(N, K, a) << endl;
	return 0;
}
