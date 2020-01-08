// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		vector<II> sa(n), ea(n), sb(n), eb(n);
		for (int i = 0; i < n; ++i) {
			cin >> sa[i].first >> ea[i].first >> sb[i].first >> eb[i].first;
			sa[i].second = ea[i].second = sb[i].second = eb[i].second = i;
		}
		vector<II> osa = sa, oea = ea, osb = sb, oeb = eb;
		sort(sa.begin(), sa.end());
		sort(ea.begin(), ea.end());
		sort(sb.begin(), sb.end());
		sort(eb.begin(), eb.end());
		bool ans = true;
		for (int i = 0; i < n; ++i) {
			int va = 0, vb = 0;
			{
				int a = lower_bound(ea.begin(), ea.end(), II(osa[i].first, 0)) - ea.begin();
				while (a > 0 && ea[a].first >= osa[i].first) {
					--a;
				}
				if (ea[a].first < osa[i].first) {
					va = a + 1;
				}
				int b = lower_bound(sa.begin(), sa.end(), II(oea[i].first + 1, 0)) - sa.begin();
				if (b < n) {
					va += (n - b);
				}
			}
			{
				int a = lower_bound(eb.begin(), eb.end(), II(osb[i].first, 0)) - eb.begin();
				while (a > 0 && eb[a].first >= osb[i].first) {
					--a;
				}
				if (eb[a].first < osb[i].first) {
					vb = a + 1;
				}
				int b = lower_bound(sb.begin(), sb.end(), II(oeb[i].first + 1, 0)) - sb.begin();
				if (b < n) {
					vb += (n - b);
				}
			}
			if (va != vb) {
				ans = false;
			}
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
