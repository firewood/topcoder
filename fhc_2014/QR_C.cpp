// Facebook Hacker Cup 2014 Qualification Round
// C. Tennison

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

typedef map<long double, long double> DD;
typedef vector<DD> DDVec;

long double solve(int K, long double P_sun, long double P_rain, long double P_init, long double P_up, long double P_win, long double P_down, long double P_lose)
{
	const long double zero = 0.0;
	const long double one = 1.0;

	long double total = 0.0;
	DD::const_iterator it;
	DDVec current(K+1);
	current[0][P_init] = 1.0;
	for (int set_no = 0; set_no < K*2; ++set_no) {
		DDVec next(K+1);
		for (int wins = 0; wins < K+1; ++wins) {
			DD &s = current[wins];
			int loses = set_no - wins;
			if (loses >= K) {
				continue;
			}
			if (wins >= K) {
				for (it = s.begin(); it != s.end(); ++it) {
					total += it->second;
				}
				continue;
			}
			for (it = s.begin(); it != s.end(); ++it) {
				long double sun = it->first;
				long double p = it->second;
				long double sunny = p * sun;
				long double rainy = p - sunny;
				long double sunny_win = sunny * P_sun;
				long double sunny_lose = sunny - sunny_win;
				long double sunny_up = sunny_win * P_win;
				long double sunny_down = sunny_lose * P_lose;
				long double rainy_win = rainy * P_rain;
				long double rainy_lose = rainy - rainy_win;
				long double rainy_up = rainy_win * P_win;
				long double rainy_down = rainy_lose * P_lose;
				next[wins+1][min(one,sun+P_up)] += sunny_up+rainy_up;
				next[wins+1][sun] += sunny_win-sunny_up+rainy_win-rainy_up;
				next[wins][max(zero,sun-P_down)] += sunny_down+rainy_down;
				next[wins][sun] += sunny_lose-sunny_down+rainy_lose-rainy_down;
			}
		}
		current = next;
	}

	return total;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		int K = 0;
		long double P_sun, P_rain, P_init, P_up, P_win, P_down, P_lose;
		ss >> K >> P_sun >> P_rain >> P_init >> P_up >> P_win >> P_down >> P_lose;
		double ans = solve(K, P_sun, P_rain, P_init, P_up, P_win, P_down, P_lose);
		printf("Case #%d: %.016f\n", t+1, ans);
	}

	return 0;
}

