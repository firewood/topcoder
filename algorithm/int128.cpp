#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

#ifdef __GNUC__
#define int128_t __int128
#else
#include <boost/multiprecision/cpp_int.hpp>
typedef boost::multiprecision::int128_t int128_t;
#endif

std::ostream& operator<<(std::ostream& dest, int128_t &x) {
	string s;
	if (x == 0) {
		s = "0";
	} else {
		if (x < 0) {
			cout << "-";
			x = -x;
		}
		while (x > 0) {
			s += char('0' + x % 10);
			x /= 10;
		}
	}
	reverse(s.begin(), s.end());
	dest << s;
	return dest;
}

int main(int argc, char* argv[]) {
	int128_t x = 1;
	x <<= 100;
	cout << x << endl;		// 1267650600228229401496703205376

	x = -1000;
	cout << x << endl;

	x = 0;
	cout << x << endl;

	return 0;
}
