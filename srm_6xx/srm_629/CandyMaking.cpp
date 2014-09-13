// BEGIN CUT HERE
/*
SRM 629 Div2 Medium (550)

PROBLEM STATEMENT

Alice likes making candy.
Recently, she promised to make candy for all her classmates.
Alice has N classmates.
We will number them 0 through N-1, inclusive.

Each of the classmates brought Alice one container for the candy.
Each of the classmates also has a desired total weight of their candy.
You are given this information as two vector <int>s with N elements each: containerVolume and desiredWeight.
For each i, the volume of the container brought by classmate i is containerVolume[i] liters, and he or she expects the candy in the container to weigh desiredWeight[i] grams.

Alice has promised to fill all containers with candy completely.
However, she only has the time to make one type of candy, with constant density.
This means that she might be unable to meet the exact desired weights of candy.

Alice now needs to choose the density of the candy she is going to make.
In order to make everyone as happy as possible, Alice decided that she wants to minimize the sum of differences between desired and actual weights.
In other words:
For each classmate, we compute the positive difference between the desired and actual weight of candy they received.
Then, we sum all those differences.
Alice needs to choose the density of her candy so that this sum becomes as small as possible.

Compute and return the minimum sum  of differences between desired and actual weights.


DEFINITION
Class:CandyMaking
Method:findSuitableDensity
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight)


NOTES
-Your return value must have an absolute or a relative error at most 1e-9.


CONSTRAINTS
-N will be between 1 and 50.
-containerVolume and desiredWeight will each contain exactly N elements.
-Each element of containerVolume and desiredWeight will between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{5}
{1000}

Returns: 0.0

There is one classmate. Her container has 5 liters and she expects 1000 grams of candy. Alice should choose the density of 200 grams per liter. The sum of differences between desired and actual weights is 0.


1)
{10,10}
{1000,2000}

Returns: 1000.0

There are two classmates. They have a 10-liter container each. However, one of them wants 1000 grams of candy and the other wants 2000 grams. There is no way for Alice to satisfy both of them exactly. (Note that she must always fill all containers completely.)

There are multiple optimal choices for the density. For these choices, the sum of differences between desired and actual weights is 1000.


2)
{10,20,40}
{4000,2000,1000}

Returns: 5250.0


3)
{1234,1541,3321,1234,123,123,3414,123,12,2442,1421,1223,3232,1123,2121}
{3213,1231,232143,44312,132132,142424,123123,41341,41244,21312,232131,2312,2322,11,2223}

Returns: 983673.2727272725

4)
{30621,30620,2}
{1,1,1000000}

Returns: 999999.9999673415

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class CandyMaking {

	double calc(vector <int> &containerVolume, vector <int> &desiredWeight, double density) {
		double sum = 0;
		for (int i = 0; i < (int)containerVolume.size(); ++i) {
			sum += fabs(desiredWeight[i] - containerVolume[i] / density);
		}
		return sum;
	}

public:
	double findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight) {
		double a = 1e+10, b = 0;
		for (int i = 0; i < (int)containerVolume.size(); ++i) {
			double d = (double)containerVolume[i] / desiredWeight[i];
			a = min(a, d);
			b = max(b, d);
		}

		double ans = 1e+10;
		while (true) {
			double r = (b - a) / 3;
			double c = a + r;
			double d = b - r;
			double x = calc(containerVolume, desiredWeight, c);
			double y = calc(containerVolume, desiredWeight, d);
			ans = min(ans, x);
			if (fabs(x - y) < 1e-10) {
				break;
			}
			if (x > y) {
				a = c;
			} else {
				b = d;
			}
		}
		return ans;
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) <= 1e-8 ) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5};
			int Arr1[] = {1000};
			double Arg2 = 0.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findSuitableDensity(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,10};
			int Arr1[] = {1000,2000};
			double Arg2 = 1000.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findSuitableDensity(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,20,40};
			int Arr1[] = {4000,2000,1000};
			double Arg2 = 5250.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findSuitableDensity(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1234,1541,3321,1234,123,123,3414,123,12,2442,1421,1223,3232,1123,2121};
			int Arr1[] = {3213,1231,232143,44312,132132,142424,123123,41341,41244,21312,232131,2312,2322,11,2223};
			double Arg2 = 983673.2727272725;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findSuitableDensity(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {30621,30620,2};
			int Arr1[] = {1,1,1000000};
			double Arg2 = 999999.9999673415;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findSuitableDensity(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 999761, 999590, 999335, 999980, 999855, 999168, 999634, 999997, 999605, 999703, 999993, 999785, 999395, 999438, 999517, 999976, 999666, 999994, 999197, 999537, 999009, 999109, 999337, 999956, 999977, 999031, 999962, 999978, 999049, 999679, 999135, 999762, 999265, 999949, 999537, 999780, 999690, 999738, 999767, 999929, 999732, 999829, 999738, 999369, 999157, 999839, 999985, 999483, 999336 };
			int Arr1[] = { 170899, 956718, 527494, 603178, 930029, 141412, 621036, 560418, 111657, 679591, 822664, 766458, 811439, 862943, 761795, 321947, 523048, 96051, 827524, 226924, 233724, 796747, 239604, 919766, 920722, 773712, 87803, 532544, 522003, 830442, 475008, 473427, 324134, 139968, 899115, 389110, 845044, 785275, 396133, 293138, 966693, 420418, 859926, 164687, 528672, 616126, 777254, 834516, 602573 };
			double Arg2 = 1.1567727238681482E7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findSuitableDensity(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 978, 140, 820, 414, 400, 435, 872, 245, 984, 708, 882, 49, 264, 740, 614, 718, 454, 72, 833, 906, 653, 213, 1, 682, 643, 513, 770, 315, 117, 23, 786, 57, 471, 838, 877, 817, 560, 114, 232, 922, 787 };
			int Arr1[] = { 584844, 83720, 490360, 247572, 239200, 260130, 521456, 146510, 588432, 423384, 527436, 29302, 157872, 442520, 367172, 429364, 271492, 43056, 498134, 541788, 390494, 127374, 598, 407836, 384514, 306774, 460460, 188370, 69966, 13754, 470028, 34086, 281658, 501124, 524446, 488566, 334880, 68172, 138736, 551356, 470626 };
			double Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findSuitableDensity(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 999112, 999545, 999668, 999494, 999800, 999112, 999431, 999330, 999387, 999264, 999729, 999452, 999458, 999258, 999107, 999835, 999773, 999221, 999780, 999936, 999867, 999209, 999261, 999850, 999156, 999711, 999357, 999090, 999377, 999775, 999308, 999415, 999017, 999319, 999939, 999818, 999213, 999402, 999609, 999330, 999884 };
			int Arr1[] = { 5, 3, 2, 8, 10, 2, 6, 9, 2, 1, 7, 9, 1, 3, 2, 7, 8, 5, 7, 7, 4, 9, 7, 2, 9, 10, 6, 5, 7, 8, 2, 4, 5, 6, 10, 2, 5, 10, 9, 1, 8 };
			double Arg2 = 102.97418339992616;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findSuitableDensity(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CandyMaking ___test;
	___test.run_test(-1);
}
// END CUT HERE
