#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
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



int main(){
  ll h, w, n, m;
  cin >> h >> w >> n >> m;
  string a[n];
  REP(i,n) cin >> a[i];
  ll st[n][m];
  REP(i,n)REP(j,m){
    if(a[i][j] == '#') st[i][j] = 1;
    else st[i][j] = 0;
  }

  ll ru[n][m], lu[n][m], rd[n][m], ld[n][m];

  REP(i,n)REP(j,m){
    ru[i][j] = st[i][j];
    if(i>0)ru[i][j] += ru[i-1][j];
    if(j>0)ru[i][j] += ru[i][j-1];
    if(i>0 && j>0)ru[i][j] -= ru[i-1][j-1];

    lu[i][j] = st[i][m-1-j];
    if(i>0)lu[i][j] += lu[i-1][j];
    if(j>0)lu[i][j] += lu[i][j-1];
    if(i>0 && j>0)lu[i][j] -= lu[i-1][j-1];

    rd[i][j] = st[n-1-i][j];
    if(i>0)rd[i][j] += rd[i-1][j];
    if(j>0)rd[i][j] += rd[i][j-1];
    if(i>0 && j>0)rd[i][j] -= rd[i-1][j-1];

    ld[i][j] = st[n-1-i][m-1-j];
    if(i>0)ld[i][j] += ld[i-1][j];
    if(j>0)ld[i][j] += ld[i][j-1];
    if(i>0 && j>0)ld[i][j] -= ld[i-1][j-1];
  }

  REP(i,n)REP(j,m){
    ll tmp = 0;
    tmp = ru[i][j];
    if(n-(h-i) > 0) tmp -= ru[n-(h-i)][j];
    if(m-(w-j) > 0) tmp -= ru[i][m-(w-j)];
    if(n-(h-i) > 0 && m-(w-j) > 0) tmp += ru[n-(h-i)][m-(w-j)];
  }


  return 0;
}
