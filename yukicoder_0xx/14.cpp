#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());

	vector<int> A(N), U(N);
	getline(cin, s);
	stringstream ss(s);
	for (int i = 0; i < N; ++i) {
		ss >> A[i];
	}

	int selected = 0;
	for (int i = 0; i < N; ++i) {
		int b = A[selected];
		if (i > 0) {
			cout << " ";
		}
		cout << b;
		U[selected] = 1;

		int x = 1 << 30;
		for (int j = 0; j < N; ++j) {
			if (!U[j]) {
				int c = lcm(b, A[j]);
				if (c < x || (c == x && A[j] < A[selected])) {
					x = c;
					selected = j;
				}
			}
		}
	}
	cout << endl;

	return 0;
}
