// BEGIN CUT HERE 
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


Toastman is going to create several eye-popping slices of toast out of several types of bread. 



Each type of bread has a positive number X (not necessarily integer) such that if a slice of bread of that type is toasted for less than X minutes, it becomes under toasted and if it is toasted for more than X minutes, it becomes over toasted. A slice of bread that is toasted for exactly X minutes becomes an eye-popping slice of toast.  



Note that the number X for different types of bread may be different, but such numbers will be the same for every slice of bread of a particular bread type. 


Toastman has toasted several slices of bread with the hope of creating an eye-popping slice of toast from several types of bread. Unfortunately he didn't know the exact value of X for any type of bread so all the slices of bread that he toasted became either under toasted or over toasted. You are given vector <int>s undertoasted and overtoasted denoting the slices of toast that were under toasted and over toasted, respectively. Each element will be an integer denoting the number of minutes that the corresponding slice of bread was toasted. 


Toastman does not have a very good memory (his brain is made out of bread!). Although he forgot which type of bread was used for each slice of toast, he thinks that the following condition was satisfied:

Each type of bread was used for at least one under toasted slice of toast and at least one over toasted slice of toast.

Return the minumum number of types of bread that could statisfy this condition. If the condition can not be satisified return -1.

DEFINITION
Class:ToastXToast
Method:bake
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int bake(vector <int> undertoasted, vector <int> overtoasted)


NOTES
-Assume that for any positive number X, there exists a bread type that needs to be toasted for exactly X minutes in order to become an eye-popping toast.


CONSTRAINTS
-undertoasted will contain between 1 and 50 elements, inclusive.
-Each element of undertoasted will be between 1 and 1,000,000, inclusive.
-All the elements of undertoasted will be distinct.
-overtoasted will contain between 1 and 50 elements, inclusive.
-Each element of overtoasted will be between 1 and 1,000,000, inclusive.
-All the elements of overtoasted will be distinct.
-overtoasted and undertoasted will not have an element in common.


EXAMPLES

0)
{2,4}
{5,6,3}

Returns: 2

Two types of bread is sufficient as illustrated below.


1)
{5}
{4}

Returns: -1



2)
{1,2,3}
{5,6,7}

Returns: 1



3)
{1,3,5}
{2,4,6}

Returns: 2



*/
#include <string>
// END CUT HERE
#line 87 "ToastXToast.cpp"
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> VI;

class ToastXToast {
	public:
	int bake(vector <int> undertoasted, vector <int> overtoasted) {
		sort(undertoasted.begin(), undertoasted.end());
		sort(overtoasted.begin(), overtoasted.end());
		if (undertoasted.size() < 1 || overtoasted.size() < 1) {
			return -1;
		}
		if (*undertoasted.rbegin() >= *overtoasted.rbegin() ) {
			return -1;
		}
		if (*undertoasted.begin() >= *overtoasted.begin() ) {
			return -1;
		}
		if (*undertoasted.rbegin() < *overtoasted.begin()) {
			return 1;
		}
		return 2;
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

static void Test(const char *u, const char *o, int expected)
{
	vector <int> under = getVector<int>(u);
	vector <int> over = getVector<int>(o);
	ToastXToast ___test;
	int result = ___test.bake(under, over);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("2,4", "5,6,3", 2);
	Test("5", "4", -1);
	Test("1,2,3", "5,6,7", 1);
	Test("1,3,5", "2,4,6", 2);
	Test("5", "1,9", -1);
	return 0;
}
// END CUT HERE
