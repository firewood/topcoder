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

bool solve(int64_t a, int64_t b, int64_t c) {
    int64_t x = 1;
    for (int i = 0; i < b; ++i) {
        if (x * c < x) {
            return true;
        }
        x *= c;
    }
    return a < x;
}

int main() {
	int64_t a, b, c;
	std::cin >> a >> b >> c;
	cout << (solve(a, b, c) ? "Yes" : "No") << endl;
	return 0;
}
