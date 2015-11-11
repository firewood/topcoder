#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	int a[100] = {}, b[101] = {};
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		b[x] += a[i];
	}
	bool ans = b[0] >= *max_element(b + 1, b + 101);
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
