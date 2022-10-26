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

string solve(int A, int B) {
	char w[16];
	sprintf(w, "%.03lf", double(B) / A);
	return w;
}

int main() {
	int A, B;
	std::cin >> A >> B;
	cout << solve(A, B) << endl;
	return 0;
}
