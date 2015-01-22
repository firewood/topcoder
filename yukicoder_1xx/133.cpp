#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(16);
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	int A[256] = {}, B[256] = {};
	string a, b;
	getline(cin, a);
	getline(cin, b);
	stringstream sa(a), sb(b);
	for (int i = 0; i < N; ++i) {
		sa >> A[i];
		sb >> B[i];
	}
	int t = 0, w = 0;
	sort(A, A + N);
	do {
		sort(B, B + N);
		do {
			int c = 0;
			for (int i = 0; i < N; ++i) {
				c += A[i] > B[i];
			}
			++t;
			if (c > N / 2) {
				++w;
			}
		} while (next_permutation(B, B + N));
	} while (next_permutation(A, A + N));
	double ans = (double)w / (double)t;
	cout << ans << endl;
	return 0;
}
