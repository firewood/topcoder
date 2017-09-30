#include <iostream>
#include <sstream>
using namespace std;
int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int level = 0;
	int length = (int)s.length();
	bool is_dict = s.compare("{}") == 0;
	for (int i = 0; i < length; ++i) {
		switch (s[i]) {
		case '{':
			++level;
			break;
		case '}':
			--level;
			break;
		case ':':
			if (level == 1) {
				is_dict = true;
			}
			break;
		}
	}
	cout << (is_dict ? "dict" : "set") << endl;
	return 0;
}
