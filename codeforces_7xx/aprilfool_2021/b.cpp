#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int a;
	cin >> a;
	while (a >= 10) {
		int b = 0;
		while (a) {
			b += a % 10;
			a /= 10;
		}
		a = b;
	}
	cout << a << endl;
	return 0;
}
