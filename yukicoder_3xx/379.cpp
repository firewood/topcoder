#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	cout.precision(30);
	long long N, G;
	long double V, ans;
	cin >> N >> G >> V;
	N /= 5;
	ans = (long double)N * G / V;
	cout << ans << endl;
	return 0;
}
