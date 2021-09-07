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
	double d;
	cin >> d;
	int xy = round(d * 10), x = xy / 10, y = xy % 10;
	cout << x;
	if (y <= 2) {
		cout << "-";
	} else if (y >= 7) {
		cout << "+";
	}
	cout << endl;
	return 0;
}
