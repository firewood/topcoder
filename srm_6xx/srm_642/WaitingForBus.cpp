// BEGIN CUT HERE
/*
SRM 642 Div1 Easy (250)

PROBLEM STATEMENT
The bus station in Joseph's town operates randomly.
Before the bus station opens, there are N buses at the station.
The buses are numbered 0 through N-1.
Whenever a bus has to depart the station, one of these buses is chosen at random.
Different buses may be chosen with different probabilities.
More precisely, for each i, the probability that bus i will be chosen is prob[i]/100.
After bus i departs the station, it follows its specific route.
The time the bus needs to complete its route is time[i].

The bus station opens at time 0.
At that time, the first random bus will depart.
During the day, as soon as a bus returns from its route, a new bus is randomly chosen to depart in that same moment.
(The probability distribution is the same for each random choice, and the random choices are mutually independent.
It is possible that the bus chosen to depart will again be the bus that just arrived.)

Joseph just arrived to the bus station.
The current time is s.
He is going to wait for the next bus.
(If there is a bus departing precisely at the time s, Joseph can still catch it.
In this case, his waiting time is zero.)

You are given the vector <int>s time and prob, and the int s.
Return Joseph's expected waiting time.


DEFINITION
Class:WaitingForBus
Method:whenWillBusArrive
Parameters:vector <int>, vector <int>, int
Returns:double
Method signature:double whenWillBusArrive(vector <int> time, vector <int> prob, int s)


NOTES
-Your return value must have an absolute or relative error smaller than 1e-6


CONSTRAINTS
-time will contain between 1 and 100 elements, inclusive.
-prob will contain the same number of elements as time
-Each element of time will be between 1 and 10^5, inclusive.
-Each element of prob will be between 1 and 100, inclusive.
-The sum of all elements of prob will be exactly 100. 
-s will be between 0 and 10^5, inclusive. 


EXAMPLES

0)
{5,100}
{90,10}
5

Returns: 9.5

Joseph will arrive to the bus station at time 5.
At time 0, one of the two buses was chosen.
With probability 90% it was bus 0.
This bus will return to the station at time 5.
Therefore, a new bus will be chosen to depart at time 5 and Joseph can board it immediately.
With probability 10% the bus that departed the station at time 0 was bus 1.
If this was the case, the next bus will depart the station at time 100, which means that Joseph's waiting time will be 95.
Thus, the expected waiting time is 0.9 * 0 + 0.1 * 95 = 9.5.


1)
{5}
{100}
101

Returns: 4.0


2)
{5,10}
{50,50}
88888

Returns: 3.666666666666667


3)
{1,2,3,4}
{10,20,30,40}
1000

Returns: 1.166666666666667


4)
{10,100,1000,10000,100000}
{90,4,3,2,1}
100000

Returns: 21148.147303578935

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class WaitingForBus {
public:
	double whenWillBusArrive(vector <int> time, vector <int> prob, int s) {
		long double a[200002] = {}; 
		a[0] = 1.0; 
		int N = (int)time.size(); 
		for (int t = 0; t < s; ++t) {
			if (a[t] > 0) {
				for (int i = 0; i < N; ++i) { 
					long double p = prob[i] * a[t]; 
					a[t + time[i]] += p * 0.01;
				}
			}
		}
		long double ans = 0;
		for (int t = 1; t <= 100000; ++t) {
			ans += a[s + t] * (long double)t;
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) <= 1.0e-6) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,100};
			int Arr1[] = {90,10};
			int Arg2 = 5;
			double Arg3 = 9.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5};
			int Arr1[] = {100};
			int Arg2 = 101;
			double Arg3 = 4.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,10};
			int Arr1[] = {50,50};
			int Arg2 = 88888;
			double Arg3 = 3.666666666666667;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4};
			int Arr1[] = {10,20,30,40};
			int Arg2 = 1000;
			double Arg3 = 1.166666666666667;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,100,1000,10000,100000};
			int Arr1[] = {90,4,3,2,1};
			int Arg2 = 100000;
			double Arg3 = 21148.147303578935;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WaitingForBus ___test;
	___test.run_test(-1);
}
// END CUT HERE
