// BEGIN CUT HERE
/*
SRM 740 Div1 Easy (250)

問題
-Ilkoは天気予報士であり、翌日が雨かどうかをilkoProb%で当てることができる
-Ilkoの情報を何人かのTVキャスターに順次伝える
-各TVキャスターiは、その情報をdeliverProbs[i]%の確率で反転する
-TVで放送される天気予報の確率を最大化したい
-TVの天気予報と実際の天気が一致する確率を求めよ

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
