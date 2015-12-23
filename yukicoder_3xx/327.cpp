#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	long long N, A = 1;
	cin >> N;
	string ans;
	while (true) {
		ans += 'A';
		A *= 26;
		if (A > N) {
			break;
		}
		N -= A;
	}
	A = ans.length();
	while (N > 0) {
		ans[--A] += N % 26;
		N /= 26;
	}
	cout << ans << endl;
	return 0;
}
