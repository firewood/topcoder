#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int main() {
	int L[3], R[3];
	cin >> L[0] >> L[1] >> L[2] >> R[0] >> R[1] >> R[2];
	sort(L, L + 3);
	sort(R, R + 3);
	int ans = (L[0] + L[1]) * R[2] + (L[0] + L[2]) * R[1] + (L[1] + L[2]) * R[0];
	ans = min(ans, (L[0] + L[1]) * R[0] + (L[0] + L[2]) * R[2] + (L[1] + L[2]) * R[1]);
	ans = min(ans, (L[0] + L[1]) * R[0] + (L[0] + L[2]) * R[1] + (L[1] + L[2]) * R[2]);
	cout << ans * 2 << endl;
	return 0;
}
