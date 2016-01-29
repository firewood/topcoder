#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	long long int A, B;
	cin >> A >> B;
	long long ans = 1;
	if (A > 0 && B > 0) {
		for (ans = 2;; ++ans) {
			long long p = (A * ans) / (A + B);
			long long q = ans - p;
			long long a = (p * 100 + (p + q) / 2) / (p + q);
			long long b = (q * 100 + (p + q) / 2) / (p + q);
			if (a == A && b == B) {
				break;
			}
			++p;
			--q;
			a = (p * 100 + (p + q) / 2) / (p + q);
			b = (q * 100 + (p + q) / 2) / (p + q);
			if (a == A && b == B) {
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
