#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <sys/stat.h>

using namespace std;

int N;
int M;
int Q;
string S;
long double D;
vector<string> q;

int main(int argc, const char * argv[]) {
    string filename = argv[1] ? argv[1] : "";
    struct stat _stat;
    if (stat(filename.c_str(), &_stat) == 0) {
        freopen(filename.c_str(), "r", stdin);
    }
    cin >> N >> M >> Q;

    S = string(N, 'a');
	D = 4.75;
    bool ok = false;
    while (!ok) {
		int counts[27][26] = {};
		char prev = 26;
		for (int i = 0; i < N; ++i) {
			long double sum = 0, prob[26] = {};
			for (int j = 0; j < 26; ++j) {
				if (prev != j) {
					prob[j] = 1.0 / (counts[prev][j] + 1);
					sum += prob[j];
				}
			}
			const long double rm = 1.0 / ((long double)RAND_MAX + 1);
			long double r = (sum * rand()) * rm;
			for (int j = 0; j < 26; ++j) {
				if (prev != j) {
					r -= prob[j];
					if (r <= 0) {
						S[i] = 'a' + j;
						counts[prev][j] += 1;
						prev = j;
						break;
					}
				}
			}
		}
        string x = S + S;
        set<string> s;
        ok = true;
        for (int i = 0; i < N; ++i) {
            string y = x.substr(i, M-3);
            if (s.find(y) != s.end()) {
                ok = false;
                break;
            }
            s.insert(y);
        }
    }

	string temp;
	for (char c : S) {
		int len = (rand() % 2) + 2;
		temp += string(len, c);
	}
	S = temp.substr(0, S.length());

    cout << S << endl;
    cout << D << endl;
    fflush(stdout);

    string ss = S + S;
    q.clear();
    for (int i = 0; i < Q; ++i) {
        string s;
        cin >> s;
        q.push_back(s);
    }

	long double dp[6001][8] = {};
	long double P = 1.0 / D, PR = 1.0 - P;
	for (int i = 0; i != ss.length(); ++i) {
		dp[i][M] = 1.0;
	}
	for (int i = 0; i < Q; ++i) {
		int mxi = -1;
		long double mx = 0;
		const string &target = q[i];
		for (int j = S.length() + (int)(M * D); j >= 0; --j) {
			for (int k = M - 1; k >= 0; --k) {
				dp[j][k] = PR * dp[j + 1][k];
				if (ss[j] == target[k]) {
					dp[j][k] += P * dp[j + 1][k + 1];
				}
			}
			if (dp[j][0] > mx) {
				mxi = j;
				mx = dp[j][0];
			}
		}
		cout << mxi << endl;
	}

    fflush(stdout);
    return 0;
}
