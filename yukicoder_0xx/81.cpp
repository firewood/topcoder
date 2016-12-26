#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	long long a = 0, b = 0;
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		long long n = atoll(s.c_str());
		double d = 0;
		const char *p = strchr(s.c_str(), '.');
		if (p) {
			sscanf(p, "%lf", &d);
		}
		long long e = (long long)(d * 1e+10 + 0.1);
		a += n;
		b += (s[0] == '-') ? -e : e;
		if (b >= 10000000000) {
			a += 1;
			b -= 10000000000;
		}
		if (b <= -10000000000) {
			a -= 1;
			b += 10000000000;
		}
	}
	if (a < 0 || (a == 0 && b < 0)) {
		if (b <= 0) {
			b = -b;
		} else {
			a += 1;
			b = 10000000000 - b;
		}
		printf("-");
		a = -a;
	} else {
		if (b < 0) {
			a -= 1;
			b += 10000000000;
		}
	}
	printf("%lld.%010lld\n", a, b);
	return 0;
}
