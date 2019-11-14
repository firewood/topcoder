// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, m, ans = 0, a, b;
		cin >> n >> m;
		if (n <= 0) return 0;
		int edge[16][16] = {};
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			--a, --b;
			edge[a][b] = edge[b][a] = 1;
		}
		int seq[] = { 0,1,2,3,4,5,6,7 };
		do {
			int i;
			for (i = 1; i < n; ++i) {
				if (!edge[seq[i - 1]][seq[i]]) {
					break;
				}
			}
			ans += i >= n;
		} while (next_permutation(seq + 1, seq + n));
		cout << ans << endl;
	}
	return 0;
}
