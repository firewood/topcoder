#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	cout << (s + (s.length() > 3 ? "ham" : "")) << endl;
	return 0;
}
