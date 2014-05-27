// Google Code Jam 2014 R1B
// Problem B. New Lottery Game

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 1; t <= T; ++t) {
		int A = 0, B = 0, K = 0;
		getline(cin, s);
		stringstream ss(s);
		ss >> A >> B >> K;

		int ans = 0;
		for (int a = 0; a < A; ++a) {
			for (int b = 0; b < B; ++b) {
				ans += ((a & b) < K);
			}
		}

		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}

