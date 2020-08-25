// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		string s;
		cin >> s;
		if (s.empty()) return 0;
		string ans = s, head, tail, camel, snake;
		bool camelCase = true, snake_case = true;
		while (!s.empty() && s.front() == '_') {
			head += '_';
			s = s.substr(1);
		}
		while (!s.empty() && s.back() == '_') {
			tail += '_';
			s = s.substr(0, s.length() - 1);
		}
		if (!s.empty()) {
			if (!isalpha(s.front()) || toupper(s.front()) == s.front()) {
				camelCase = false, snake_case = false;
			}
			char prev = 0;
			for (char c : s) {
				if (prev == '_') {
					if (!(isalpha(c) && tolower(c) == c)) {
						camelCase = false, snake_case = false;
					}
					camel += toupper(c);
				} else if (c == '_') {
					camelCase = false;
				} else {
					if (isalpha(c) && toupper(c) == c) {
						snake_case = false;
						snake += '_';
					}
					camel += c;
					snake += tolower(c);
				}
				prev = c;
			}
			if (camelCase) {
				ans = head + snake + tail;
			}
			if (snake_case) {
				ans = head + camel + tail;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
