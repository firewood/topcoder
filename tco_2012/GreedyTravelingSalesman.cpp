// BEGIN CUT HERE
/*
// TCO12 Round 2C Easy (300)

問題
セールスマンがN個の都市を0から順番にまわる。
全ての都市は、片方向の道路が両方向で用意されており、どの都市からどの都市へも移動できる。
セールスマンは、未訪問の都市のうち、コストが最小の道路を選んで移動する。
各道路のコストが与えられる。ただし道路の1つが工事中のため、1～9999の間で変化する可能性がある。
最悪のコストを求める。

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<II> IIVec;

class GreedyTravelingSalesman {

	int N;
	int cost[32][32];

	int eval(void) {
		int total = 0;
		int i;
		int pos = 0;
		IntVec visited(N);
		while (true) {
			visited[pos] = 1;
			int MinCost = 10000;
			int MinIndex = -1;
			for (i = 0; i < N; ++i) {
				if (pos != i && !visited[i]) {
					if (cost[pos][i] < MinCost) {
						MinIndex = i;
						MinCost = cost[pos][MinIndex];
					}
				}
			}
			if (MinIndex < 0) {
				break;
			}
			pos = MinIndex;
			total += MinCost;
		}
		return total;
	}

public:
	int worstDistance(vector <string> thousands, vector <string> hundreds, vector <string> tens, vector <string> ones) {
		N = (int)thousands.size();
		IIVec sorted[32];
		memset(cost, 0, sizeof(cost));
		int i, j;
		for (i = 0; i < N; ++i) {
			IIVec v;
			const string &a = thousands[i];
			const string &b = hundreds[i];
			const string &c = tens[i];
			const string &d = ones[i];
			for (j = 0; j < N; ++j) {
				cost[i][j] = (a[j] - '0') * 1000 + (b[j] - '0') * 100 + (c[j] - '0') * 10 + (d[j] - '0');
				if (i != j) {
					v.push_back(II(cost[i][j], j));
				}
			}
			sort(v.begin(), v.end());
			sorted[i] = v;
		}

		IIVec path;
		int pos = 0;
		IntVec visited(N);
		while (true) {
			visited[pos] = 1;
			int MinCost = 10000;
			int MinIndex = -1;
			for (i = 0; i < N; ++i) {
				if (pos != i && !visited[i]) {
					if (cost[pos][i] < MinCost) {
						MinIndex = i;
						MinCost = cost[pos][MinIndex];
					}
				}
			}
			if (MinIndex < 0) {
				break;
			}
			path.push_back(II(pos, MinIndex));
			pos = MinIndex;
		}

		int res = 0;
		for (i = 0; i < (int)path.size(); ++i) {
			const II &p = path[i];
			int prev = cost[p.first][p.second];
			cost[p.first][p.second] = 9999;
			res = max(res, eval());

			for (j = 1; j < (N-1); ++j) {
				cost[p.first][p.second] = sorted[p.first][j].first;
				res = max(res, eval());
				cost[p.first][p.second] = sorted[p.first][j].first - 1;
				res = max(res, eval());
			}
			cost[p.first][p.second] = prev;

			for (j = 1; j < N; ++j) {
				if (j != p.first && j != p.second) {
					prev = cost[p.first][j];
					cost[p.first][j] = max(1, cost[p.first][p.second] - (j > p.second));
					res = max(res, eval());
					cost[p.first][j] = prev;
				}
			}
		}

		return res;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"055", "505", "550"};
			string Arr1[] = {"000", "000", "000"};
			string Arr2[] = {"000", "000", "000"};
			string Arr3[] = {"000", "000", "000"};
			int Arg4 = 14999;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, worstDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"018", "101", "990"};
			string Arr1[] = {"000", "000", "990"};
			string Arr2[] = {"000", "000", "990"};
			string Arr3[] = {"000", "000", "990"};
			int Arg4 = 17999;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, worstDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"00888", "00999", "00099", "00009", "00000"};
			string Arr1[] = {"00000", "00999", "00099", "00009", "00000"};
			string Arr2[] = {"00000", "10999", "11099", "11109", "11110"};
			string Arr3[] = {"01000", "00999", "00099", "00009", "00000"};
			int Arg4 = 37997;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, worstDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
			string Arr1[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
			string Arr2[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
			string Arr3[] = {"011111", "101111", "990998", "999099", "999809", "999980"};
			int Arg4 = 39994;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, worstDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"00", "00"};
			string Arr1[] = {"00", "00"};
			string Arr2[] = {"00", "00"};
			string Arr3[] = {"01", "10"};
			int Arg4 = 9999;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, worstDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0930", "1064", "0104", "1070"};
			string Arr1[] = {"0523", "1062", "6305", "0810"};
			string Arr2[] = {"0913", "0087", "3109", "1500"};
			string Arr3[] = {"0988", "2030", "6103", "5530"};
			int Arg4 = 14124;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, worstDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0329", "2036", "2502", "8970"};
			string Arr1[] = {"0860", "5007", "0404", "2770"};
			string Arr2[] = {"0111", "2087", "2009", "2670"};
			string Arr3[] = {"0644", "1094", "7703", "7550"};
			int Arg4 = 17785;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, worstDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"098444156277392825243100607342", "200097656837707947798866622385",
"290231695687128834848596019656", "407026565077650435591867333275",
"843401002617957470339040852874", "349970591997218853400632158696",
"419933000593511123878416328483", "696294503254214847884399055978",
"641473980706392541888675375279", "936720077098054565078142449625",
"203476089500970673371115103717", "511071853860312304204656816567",
"347105714685052402147763392257", "125122220860203856679947732062",
"121462979669220132944063071653", "928254504048223043681383050365",
"502607124708785202536036594373", "793596587517012870906900400361",
"712360060935346182084840996318", "761671392040312345002273366240",
"812935320276738878200716148806", "228506917464479046839069740872",
"755395721473881083093906155745", "192597782177910118061710039501",
"721382839206745793530453013267", "076061794267810491768114700256",
"857528357758085424372388710251", "173322450800442594145600093043",
"761667192345925280210514410800", "521229810525064090301842864060"};
			string Arr1[] = {"098270581534726237580246464451", "108829763716747148395013332067",
"830061279541380758964430491222", "431005058477371114834129826284",
"601807314489142917339949914290", "330640126699733151822328009407",
"851821069798846354566780680271", "648888407535627630663351884365",
"051398660825518466890170447894", "631934884097214069747147155777",
"768071219404930950472885304916", "924954163330715847561718395488",
"189910033179029204426829479070", "960645776060701332402794474433",
"244875842263950931884758650019", "528470075229660077692189442311",
"752198673046476808978058423064", "899325998610605600525587569431",
"965750123741820904031880230236", "121658852172052167706008445728",
"556199378085507717770434101126", "864838242791403197110088834005",
"593435343245223500439707230479", "622529771475840345624500421425",
"503486612623475041392122088159", "518334626169655694269507400008",
"967091631529233593414345370288", "300474162107271438029222620086",
"010527691044447729596127150108", "742822904991333205419603623270"};
			string Arr2[] = {"029421809872798033258029765788", "705135039569772524273274786652",
"170567418260893393020344098265", "401043354947659563658581268242",
"746709065616595245635350557925", "739570024549618413776557843034",
"184597012262496958610853505745", "689811400727818703807051112784", 
"894453010121164288965541305235", "323145029073008946088869964941", 
"834269564400729646453274750586", "538976762970745472202055589093", 
"765511399939087047106252621388", "906733295711605356366138410423", 
"107653940551700559321642810836", "428402693021051075533830345295", 
"386782660475155103347385287948", "936626025836194580089064628716", 
"718522629491464055045890912121", "370656945845300237607868352243", 
"951908186614186444840337711498", "535178875249889835014025850038", 
"505970047705717604298603983975", "484398304612602344941130624527", 
"048342694079170795987835013947", "860331019262176299872846206272", 
"549663926438975145562538360932", "329735455392841851511474791078", 
"711755200061373546828858448100", "778808866574640894148527759780"};
			string Arr3[] = {"050738147930236727719964251439", "804492562859282318664226330103", 
"610197568193830684654773608216", "279000416545607314567843085541", 
"782201171759873927350740022455", "043370803444176631019883186675", 
"566092086050401228622782761449", "469598907881602996036692882305", 
"116923500417992303845370254124", "796876115092839169954790509461", 
"783836410405270687557924090071", "095144151150833738671751747749", 
"354474585664039135189964700948", "328968176148004939648962631420", 
"829651915384290848347221555092", "170980383407813034573738951375", 
"728655435703349509419725538350", "121896684176286430427852435647", 
"315710894574884960021671476788", "592177839598531202003634382961", 
"876587919610157913350259498196", "505517243779897451333006271744", 
"618607877753891664471800511372", "826358757330233811836040764274", 
"206641252044293046424432092833", "704519364781672964993499009545", 
"624793571592392775564426440338", "571938479010503551295729304078", 
"077967252884369103891335711508", "870185204806328841827105139840"};
			int Arg4 = 39896;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, worstDistance(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GreedyTravelingSalesman ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
