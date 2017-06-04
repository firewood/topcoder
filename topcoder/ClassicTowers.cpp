#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <fstream>
#include <numeric>

using namespace std;

typedef long long LL;

typedef pair<int, int> II;
typedef vector<II> IIVec;

struct ClassicTowers {
    LL k;
    LL sum;
    string t(LL a, LL b, LL c) {

        
        
        
        return "";
    }

    string findTowers(long long _k, vector<int> count) {
        k = _k;
        sum = accumulate(count.begin(), count.end(), 0LL);
        string ans;
        LL rbits = sum - count[2];
//        LL rm = 1LL << rbits;
        if (rbits <= 0) {
            
        } else {
            LL mm = (1LL << (rbits - 1)) + ((1LL << (rbits - 1)) - 1);
            if (k >= mm) {
                cout << "hoge" << endl;
            }
        }
/*
            
            
        }if (k >= rm) {
            LL r = k - rm;
            
            
        }
        
        int p[64] = {};
        memset(p, -1, sizeof(p));
        

        
        
        
        for (int t = 0; t != count.size(); ++t) {
            LL r = k;

            
            
        }
        
        ans = t(count[0], count[1], count[2]);
        if (ans.empty()) {
            ans = t(count[0], count[2], count[1]);
            if (ans.empty()) {
                ans = t(count[1], count[0], count[2]);
                if (ans.empty()) {
                    ans = t(count[1], count[2], count[0]);
                    if (ans.empty()) {
                        ans = t(count[2], count[0], count[1]);
                        if (ans.empty()) {
                            ans = t(count[2], count[1], count[0]);
                        }
                    }
                }
            }
        }
*/
        return ans;
    }
};

// CUT begin
ifstream data("ClassicTowers.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(long long k, vector<int> count, string __expected) {
    time_t startClock = clock();
    ClassicTowers *instance = new ClassicTowers();
    string __result = instance->findTowers(k, count);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        long long k;
        from_stream(k);
        vector<int> count;
        from_stream(count);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(k, count, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1496192850;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "ClassicTowers (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
