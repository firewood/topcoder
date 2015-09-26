#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int N, T;
	cin >> N >> T;
	int total = 0;
	vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		total += a;
		v[i] = a - b;
	}
	sort(v.rbegin(), v.rend());
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (total <= T) {
			break;
		}
		++ans;
		total -= v[i];
	}
	cout << (total <= T ? ans : -1) << endl;
	return 0;
}
