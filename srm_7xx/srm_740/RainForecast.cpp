// BEGIN CUT HERE
/*
SRM 740 Div1 Easy (250)

PROBLEM STATEMENT

Ilko is a meteorologist whose goal is to predict the weather for the report given in the evening news on TV.
Ilko has a complex numerical model that tries to predict a single boolean: whether it will rain tomorrow.
The success rate of the model's predictions is ilkoProb percent.
Every day at 4:47 pm, Ilko runs the model, reads its output, thinks about it, and finally he sends a one-word instruction to the TV station: he either tells them to broadcast the word "sunny" or the word "rainy".

However, the TV station does not simply broadcast the word Ilko sent.
There is a whole chain of people who get involved:
Ilko reports the forecast to his contact person, that person tells their secretary to pass it on, the secretary writes it down and uses internal mail to send it to a different floor, and so on.
The problem is that each person in the chain will, with some probability, mix up the message and deliver the opposite forecast from the one they received.

You are given the vector <int> deliverProbs.
Each element of deliverProbs corresponds to one person in the chain, in the order in which the message passes through them.
Person i will correctly deliver the forecast they receive with probability deliverProbs[i] percent.

Ilko knows all the information mentioned above, including all the probabilities.
His reputation depends on the accuracy of the forecast that actually gets aired by the TV station.
Thus, he will do all he can to maximize the accuracy of that forecast.

Compute and return the probability that the forecast aired by the TV station tonight will match the weather tomorrow.


DEFINITION
Class:RainForecast
Method:predictRain
Parameters:int, vector <int>
Returns:double
Method signature:double predictRain(int ilkoProb, vector <int> deliverProbs)


NOTES
-Formally, assume that all random events mentioned in the statement are mutually independent. In particular, the probability that Ilko's model correctly predicts whether it will rain tomorrow is ilkoProb/100.
-Your answer will be accepted if it has a relative or an absolute error up to 1e-9.
-Remember that Ilko has perfect knowledge of all things mentioned in the problem statement, and that he is actively trying to maximize the probability that the weather will match the forecast broadcast by the station.


CONSTRAINTS
-ilkoProb will be between 0 and 100, inclusive.
-deliverProbs will have between 0 and 50 elements, inclusive.
-Each element of deliverProbs will be between 0 and 100, inclusive.


EXAMPLES

0)
93
{}

Returns: 0.93

Ilko's model correctly predicts rain with probability 93%.
There are no people involved in the TV station.
Thus, what happens is that:

Ilko looks at the prediction given by his model.
Ilko sends that prediction to the TV station.
The prediction goes straight into the broadcast.

Obviously, the forecast aired on the news will match reality with probability 93%.


1)
93
{50}

Returns: 0.5

Ilko uses the same model, but now he reports to a person who always loses it and then just flips a coin to determine what forecast the station will broadcast that night.


2)
100
{90,90}

Returns: 0.82


In this test case, Ilko's model is completely accurate. Sadly, the forecast goes through two people before it gets aired, and each of them will make a mistake with probability 10%. That's still good enough to mostly preserve the forecast Ilko reports to the station, but they do introduce some mistakes here and there.

Note that the actual probability that the station airs the correct forecast is 82%, not 81%.
This is because the following is also a possible chain of events:

Ilko reports the correct forecast to the station.
The first person makes a mistake and reports the opposite forecast to the second person.
The second person also makes a mistake and broadcasts the opposite forecast from the one they received - but that is the forecast Ilko originally sent!


3)
89
{13, 92, 7}

Returns: 0.7084846399999999


4)
50
{3, 17, 92, 34, 2, 14}

Returns: 0.5

This time, the accuracy of Ilko's model is as good as a coin flip. The people at the TV station don't really matter, the final forecast will still be correct with probability exactly 50 percent.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class RainForecast {
public:
	double predictRain(int ilkoProb, vector <int> deliverProbs) {
		double x = ilkoProb * 0.01, y = 1.0 - x;
		for (int p : deliverProbs) {
			double a = x, b = y, d = p * 0.01;
			x = a * d + b * (1.0 - d);
			y = a * (1.0 - d) + b * d;
		}
		return max(x, 1.0 - x);
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 93;
			// int Arr1[] = {};
			double Arg2 = 0.93;

			vector <int> Arg1;
			verify_case(n, Arg2, predictRain(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 93;
			int Arr1[] = {50};
			double Arg2 = 0.5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, predictRain(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arr1[] = {90,90};
			double Arg2 = 0.82;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, predictRain(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 89;
			int Arr1[] = {13, 92, 7};
			double Arg2 = 0.7084846399999999;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, predictRain(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arr1[] = {3, 17, 92, 34, 2, 14};
			double Arg2 = 0.5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, predictRain(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RainForecast ___test;
	___test.run_test(-1);
}
// END CUT HERE
