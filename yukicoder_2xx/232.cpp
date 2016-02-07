#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int T, A, B;
	cin >> T >> A >> B;
	if ((T == 1 && A == 0 && B == 0) || A > T || B > T) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		vector<string> v(T);
		int i;
		for (i = 0; i < A; ++i) {
			v[i] += "^";
		}
		while (i <= T / 2 && i <= T - 2) {
			v[i++] += "^";
			v[i++] += "v";
		}
		for (i = 0; i < B; ++i) {
			v[T - 1 - i] += ">";
		}
		while (i <= T / 2 && i <= T - 2) {
			v[T - 1 - i++] += ">";
			v[T - 1 - i++] += "<";
		}
		for (int i = 0; i < T; ++i) {
			cout << v[i] << endl;
		}
	}
	return 0;
}
