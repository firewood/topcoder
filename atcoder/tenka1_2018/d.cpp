// D.

#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int a = sqrt(n * 2), b = a + 1;
	if (a * b == n * 2) {
		cout << "Yes" << endl;
		cout << b << endl;
		vector<int> u(n);
		for (int i = 0; i < b; ++i) {
			cout << a;
			vector<int> s(n + 1);
			int k = 0;
			for (int j = 0; j < a; ++j) {
				while (true) {
					if (!u[k]) {
						u[k] = i + 1;
						break;
					}
					if (u[k] >= 0 && !s[u[k]]) {
						s[u[k]] = 1;
						u[k] = -1;
						break;
					}
					++k;
				}
				cout << " " << (k + 1);
				++k;
			}
			cout << endl;
		}
	} else {
		cout << "No" << endl;
	}
	return 0;
}
