
//
// Google Code Jam 2012 QR
// A. Speaking in Tongues
//

#include <iostream>
#include <sstream>
#include <map>

using namespace std;

typedef map<int, int> IntMap;

static string solve(const IntMap &m, string s) {
	int i;
	for (i = 0; i < (int)s.length(); ++i) {
		IntMap::const_iterator it = m.find(s[i]);
		if (it != m.end()) {
			s[i] = it->second;
		}
	}
	return s;
}

int main(int argc, char *argv[])
{
	const char a[] = "yeqz"
			"ejp mysljylc kd kxveddknmc re jsicpdrysi"
			"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
			"de kr kd eoya kw aej tysr re ujdr lkgc jv";
	const char b[] = "aozq"
			"our language is impossible to understand"
			"there are twenty six factorial possibilities"
			"so it is okay if you want to just give up";

	IntMap m;
	const char *p = a, *q = b;
	while (*p) {
		m[*p] = *q, ++p, ++q;
	}

	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	int t;
	for (t = 0; t < T; ++t) {
		getline(cin, s);
		s = solve(m, s);
		cout << "Case #" << (t+1) << ": " << s << endl;
	}

	return 0;
}

