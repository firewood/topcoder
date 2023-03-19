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
	int64_t N, a;
	cin >> N;
	string sep = "";
	bool f = false;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if ((a % 2) == 0) {
			cout << sep << a;
			sep = " ";
		}
	}
	cout << endl;
	return 0;
}
