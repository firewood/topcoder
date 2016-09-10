#include <ctime>
#include <string>
#include <cstdio>
#include <limits>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    cout << (((N % 2) || (N >= 6 && N <= 20)) ? "Weird" : "Not Weird") << endl;
    return 0;
}
