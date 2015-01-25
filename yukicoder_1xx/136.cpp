#include <iostream>
#include <algorithm>
#include <sstream>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
	int N, K;
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> N >> K;
	int ans = 1;
	for (int i = 2; i <= N; ++i) {
		if ((N % i) == 0) {
			ans = max(ans, N / i);
		}
	}
	cout << ans << endl;
	return 0;
}
