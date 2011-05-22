// BEGIN CUT HERE
/*
// SRM 504.5 Div2 Middle (500)
// PROBLEM STATEMENT
// 
John believes that the digits 4 and 7 are lucky, and all other digits are unlucky.
A positive integer is called a lucky number if its last digit is lucky.
For example, 4, 14 and 207 are lucky numbers, while 40, 741 and 3 are not lucky numbers.
John would like to represent the int n as a sum of only lucky numbers, and he would like to do this using the minimal possible number of summands.
Return the number of summands in the representation, or -1 if it is impossible to achieve the goal.



DEFINITION
Class:TheNumbersWithLuckyLastDigit
Method:find
Parameters:int
Returns:int
Method signature:int find(int n)


CONSTRAINTS
-n will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
99

Returns: 4

One?of?the?possible?representations?is?99=14+24+27+34.

1)
11

Returns: 2

11=4+7.

2)
13

Returns: -1

It is impossible to achieve the goal.

3)
1234567

Returns: 1

*/
#line 55 "TheNumbersWithLuckyLastDigit.cpp"
// END CUT HERE
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef map<int, int> II;

class TheNumbersWithLuckyLastDigit {
	public:
	int find(int n) {
II _ii;
_ii[4]=1;
_ii[7]=1;
_ii[8]=2;
_ii[11]=2;
_ii[12]=3;
_ii[14]=1;
_ii[15]=3;
_ii[16]=4;
_ii[17]=1;
_ii[18]=2;
_ii[19]=4;
_ii[20]=5;
_ii[21]=2;
_ii[22]=3;
_ii[23]=5;
_ii[24]=1;
_ii[25]=3;
_ii[26]=4;
_ii[27]=1;
_ii[28]=2;
_ii[29]=4;
_ii[30]=5;
_ii[31]=2;
_ii[32]=3;
_ii[33]=5;
_ii[34]=1;
_ii[35]=3;
_ii[36]=4;
_ii[37]=1;
_ii[38]=2;
_ii[39]=4;
_ii[40]=5;
_ii[41]=2;
_ii[42]=3;
_ii[43]=5;
_ii[44]=1;
_ii[45]=3;
_ii[46]=4;
_ii[47]=1;
_ii[48]=2;
_ii[49]=4;
_ii[50]=5;
_ii[51]=2;
_ii[52]=3;
_ii[53]=5;
_ii[54]=1;
_ii[55]=3;
_ii[56]=4;
_ii[57]=1;
_ii[58]=2;
_ii[59]=4;
_ii[60]=5;
_ii[61]=2;
_ii[62]=3;
_ii[63]=5;
_ii[64]=1;
_ii[65]=3;
_ii[66]=4;
_ii[67]=1;
_ii[68]=2;
_ii[69]=4;
_ii[70]=5;
_ii[71]=2;
_ii[72]=3;
_ii[73]=5;
_ii[74]=1;
_ii[75]=3;
_ii[76]=4;
_ii[77]=1;
_ii[78]=2;
_ii[79]=4;
_ii[80]=5;
_ii[81]=2;
_ii[82]=3;
_ii[83]=5;
_ii[84]=1;
_ii[85]=3;
_ii[86]=4;
_ii[87]=1;
_ii[88]=2;
_ii[89]=4;
_ii[90]=5;
_ii[91]=2;
_ii[92]=3;
_ii[93]=5;
_ii[94]=1;
_ii[95]=3;
_ii[96]=4;
_ii[97]=1;
_ii[98]=2;
_ii[99]=4;

		if (n >= 100) {
			n = (n % 10) + 40;
		}
		II::const_iterator it = _ii.find(n);
		if (it != _ii.end()) {
			return it->second;
		}
		return -1;
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
	TheNumbersWithLuckyLastDigit ___test;
//	int result = 0;
//	int result = ___test.find();
//	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	return 0;
}
// END CUT HERE
