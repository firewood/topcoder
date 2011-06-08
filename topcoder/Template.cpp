// BEGIN CUT HERE
/*
// SRM ??? Div2 
$PROBLEMDESC$
#line $NEXTLINENUMBER$ "$FILENAME$"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

class $CLASSNAME$ {
	public:
	$RC$ $METHODNAME$($METHODPARMS$) {
		
	}
};

// BEGIN CUT HERE
template <typename T> static T __str_to_val(const char *p)
{
	return p;
}
template <> static int __str_to_val(const char *p)
{
	return atoi(p);
}
template <typename T> vector<T> getVector(const char *s)
{
	static const int buffer_size = 1024000;
	static char buffer[buffer_size];
	strcpy(buffer, s);
	vector <T> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, " ,");
	}
	return v;
}

static void Test(const char *seq, int expected)
{
	vector <int> v = getVector<int>(seq);
	$CLASSNAME$ ___test;
	int result = 0;
//	$RC$ result = ___test.$METHODNAME$();
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("", 0);
	return 0;
}
// END CUT HERE
