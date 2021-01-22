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

typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<II, LL> III;
typedef priority_queue<II, vector<II>, greater<>> Queue;
static const LL INF = 1LL << 60;

void solve(long long N, long long C, std::vector<long long> &a, std::vector<long long> &b, std::vector<long long> &c) {
	LL ans = 0, sum = 0, last = 0;
	set<LL> days;
	vector<III> v;
	for (int i = 0; i < N; i++) {
		v.emplace_back(III(II(a[i], b[i]), i));
		days.insert(a[i]);
		days.insert(b[i] + 1);
	}
	sort(v.begin(), v.end());
	Queue q;
	int index = 0;
	last = *(days.begin());
	for (LL day : days) {
		LL cost = min(sum, C);
		ans += cost * (day - last);
		last = day;
		while (!q.empty() && q.top().first == day) {
			LL i = q.top().second;
			sum -= c[i];
			q.pop();
		}
		while (index < N) {
			int i = v[index].second;
			if (a[i] > day) {
				break;
			}
			sum += c[i];
			q.emplace(II(b[i] + 1, i));
			++index;
		}
	}
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	long long C;
	std::cin >> C;
	std::vector<long long> a(N);
	std::vector<long long> b(N);
	std::vector<long long> c(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
		std::cin >> b[i];
		std::cin >> c[i];
	}
	solve(N, C, a, b, c);
	return 0;
}
