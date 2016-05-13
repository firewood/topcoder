#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	int N, u, sum = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		sum += a;
	}
	cin >> u;
	cout << (sum - u) << endl;
	return 0;
}
