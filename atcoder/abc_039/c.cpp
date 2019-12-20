// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
	static const char* keyboards = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
	static const char* names[] = { "Do", "Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La", "Si" };
	string s;
	cin >> s;
	int pos = strstr(keyboards, s.c_str()) - keyboards;
	cout << names[pos] << endl;
	return 0;
}
