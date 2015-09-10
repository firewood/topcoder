#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(16);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int A, B;
		cin >> A >> B;
		long double a = log(A) / log(10);
		long double b = a * B;
		long double c = floor(b);
		long double d = pow(10, b - c);
		long double e = floor(d);
		long double f = floor((d - e) * 10);
		cout << e << " " << f << " " << c << endl;
	}
	return 0;
}
