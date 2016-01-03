// A. 

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int t;
		cin >> t;
		ans = max(ans + 1, t);
	}
	cout << ans << endl;
	return 0;
}
