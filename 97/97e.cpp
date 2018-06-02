#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string>
#include <list>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;



double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

const int MAX_N = 100000;

typedef pair<char, int> P;

int main(){
  int n;
  cin >> n;
  char c[2*n];
  int a[2*n];
  list<P> l;
  ll ans = 0;
  REP(i,2*n){
    cin >> c[i] >> a[i];
    l.push_back(P(c[i], a[i]));
  }
  auto itr1 = l.begin();
  int ctb = 1;
  int ctw = 1;
  int ct1 = 0;
  while(ct1 != 2*n){
    int ct2 = 0;
    for (auto itr2 = l.begin(); itr2 != l.end(); itr2++){
      if(itr2->first == 'B' && itr2->second == ctb){
        ans += ct2 - ct1;
        P tmp = *itr2;
        l.erase(itr2);
        l.insert(itr1, tmp);
        ctb++;
        ct1++;
        break;
      }else if(itr2->first == 'W' && itr2->second == ctw){
        ans += ct2 - ct1;
        P tmp = *itr2;
        l.erase(itr2);
        l.insert(itr1, tmp);
        ctw++;
        ct1++;
        break;
      }
      ct2++;
    }
  }

  cout << ans << endl;

  return 0;
}
