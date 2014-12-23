#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<int> Queue;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	int v[10001] = {};
	Queue q;
	q.push_back(1);
	int ans = 0;
	v[1] = 1;
	while (q.size() > 0) {
		++ans;
		Queue next;
		for (int i = 0; i < q.size(); ++i) {
			int a = q[i];
			int b = popcount(a);
			if (a == N) {
				cout << ans << endl;
				return 0;
			}
			int c = a - b;
			if (c >= 1 && !v[c]) {
				v[c] = 1;
				next.push_back(c);
			}
			c = a + b;
			if (c <= N && !v[c]) {
				v[c] = 1;
				next.push_back(c);
			}
		}
		q = next;
	}
	ans = -1;
	cout << ans << endl;
	return 0;
}
