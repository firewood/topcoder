#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string a, b;
	cin >> a >> b;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	string ans = (a == b) ? "YES" : "NO";
	cout << ans << endl;
	return 0;
}
