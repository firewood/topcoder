#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <sys/stat.h>

using namespace std;

int N;
int K;
typedef pair<int, int> II;
typedef pair<II, II> IIII;
vector<IIII> fp;

vector<II> make_plan(int di, int b) {
    vector<II> pos;
    int sxs[4] = {0,0,N-1,N-1};
    int sys[4] = {0,N-1,0,N-1};
    int sx = sxs[di], sy = sys[di];
    int x = sx, y = sy;
    int dx = x ? -1 : 1, dy = y ? -1 : 1;
    for (int i = 0; i < N-1; ++i) {
        pos.push_back(II(y, x));
        x += dx;
        y += dy;
    }
    int ex = x, ey = y;
    for (int d = 3; d <= N-2; d += 3) {
        swap(sx, ex);
        swap(sy, ey);
        dx = -dx;
        dy = -dy;
        for (int yy = -d; yy <= d; yy += 2*d) {
            x = sx;
            y = sy + yy;
            int cnt = 0;
            for (int i = 0; i < N-1; ++i) {
                if (x >= 0 && x < N && y >= 0 && y < N) {
                    if (x == 0 || x == N-1 || y == 0 || y == N-1) {
                        ++cnt;
                        if (cnt >= 2) {
                            break;
                        }
                    }
                    pos.push_back(II(y, x));
                }
                x += dx;
                y += dy;
            }
        }
    }
    return pos;
}

vector<II> solve() {
    vector<II> ans;
    vector< vector<int> > oc(N, vector<int>(N));
    long long mn = 1LL<<60;
    for (int pi = 0; pi < 4; ++pi) {
        long long neg = 0;
        vector<II> plan = make_plan(pi, 0);
        vector<II> pos;
        vector<int> u(plan.size(), 1);

        set<int> delay;
        for (int i = 0; i != plan.size(); ++i) {
            int fsy = fp[i].first.first, fsx = fp[i].first.second;
            int fey = fp[i].second.first, fex = fp[i].second.second;
            oc[plan[i].first][plan[i].second] = i + 1;
            if (oc[fsy][fsx] > 0) {
                delay.insert(oc[fsy][fsx] - 1);
            }
            if (oc[fey][fex] > 0) {
                delay.insert(oc[fey][fex] - 1);
            }
        }
        for (int i = 0; i != plan.size(); ++i) {
            if (delay.find(i) == delay.end()) {
                pos.push_back(plan[i]);
            }
        }
        for (int i = 0; i != plan.size(); ++i) {
            if (delay.find(i) != delay.end()) {
                pos.push_back(plan[i]);
            }
        }
        for (int i = (int)plan.size(); i < K; ++i) {
            pos.push_back(II(-1,-1));
        }
        for (int i = 0; i < K; ++i) {
            int fsy = fp[i].first.first, fsx = fp[i].first.second;
            int fey = fp[i].second.first, fex = fp[i].second.second;
            if (oc[fsy][fsx] > 0 && oc[fey][fex] > 0) {
                neg += 10000;
            }
            if (i>(int)plan.size()&& oc[fsy][fsx] > 0 && !oc[fey][fex]) {
                neg += 100;
                u[oc[fsy][fsx] - 1] = 1;
                oc[fsy][fsx] = -oc[fsy][fsx];
                pos[i] = II(fsy, fsx);
            } else if (i>(int)plan.size()&& !oc[fsy][fsx] && oc[fey][fex] > 0) {
                neg += 100;
                u[oc[fey][fex] - 1] = 1;
                oc[fey][fex] = -oc[fey][fex];
                pos[i] = II(fey, fex);
            } else {
                bool f = false;
                for (int j = 0; j != plan.size(); ++j) {
                    if (u[j]) {
                        if (!f) {
                            f = true;
                            u[j] = 0;
                            pos[i] = plan[j];
                            oc[pos[i].first][pos[i].second] = j + 1;
                            break;
                        }
                    }
                }
            }
        }
        if (neg < mn) {
            mn = neg;
            ans = pos;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    string filename = argv[1] ? argv[1] : "";
    struct stat _stat;
    if (stat(filename.c_str(), &_stat) == 0) {
        freopen(filename.c_str(), "r", stdin);
    }

    cin >> N >> K;
    fp.clear();
    for (int i = 0; i < K; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        fp.push_back(IIII(II(a, b), II(c, d)));
    }

    vector<II> plan = solve();
    for (int i = 0; i < K; ++i) {
        if (i < (int)plan.size()) {
            cout << plan[i].first << " " << plan[i].second << endl;
        } else {
            cout << "-1 -1" << endl;
        }
    }
    fflush(stdout);
    return 0;
}
