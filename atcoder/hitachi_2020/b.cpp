// B.

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
		int A = -1, B, M, x, y, c;
		cin >> A >> B >> M;
		if (A < 0) return 0;
		vector<int> a(A), b(B);
		for (int i = 0; i < A; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < B; ++i) {
			cin >> b[i];
		}
		int ans = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
		for (int i = 0; i < M; ++i) {
			cin >> x >> y >> c;
			ans = min(ans, a[x - 1] + b[y - 1] - c);
		}
		cout << ans << endl;
	}
	return 0;
}
