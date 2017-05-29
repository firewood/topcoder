#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	string a, b, c;
	cin >> a >> b >> c;
	string s[] = {a,b,c};
	sort(s, s + 3);
	cout << s[1] << endl;
	return 0;
}
