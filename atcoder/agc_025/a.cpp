// A. 

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int ans = 1<<30;
	for (int a = 1; a < n; ++a) {
		int sum = 0;
		for (char c : to_string(a)) {
			sum += c - '0';
		}
		for (char c : to_string(n - a)) {
			sum += c - '0';
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
