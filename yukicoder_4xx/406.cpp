#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	int x[100000];
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x[i];
	}
	sort(x, x + N);
	int d = x[1] - x[0];
	bool ans = x[0] >= 0 && d > 0;
	for (int i = 1; i < N; ++i) {
		if ((x[i] - x[i - 1]) != d) {
			ans = false;
			break;
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
