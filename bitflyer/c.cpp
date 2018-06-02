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

// bit_sum O(log n) for a query
// 1. set n;
// 2. init bit[n+1];

const int MAX_N = 100000;

ll bit[MAX_N+1], n;

ll bit_sum(int i){
  ll s = 0;
  while(i > 0){
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void bit_add(int i, ll x){
  while(i <= n){
    bit[i] += x;
    i += i & -i;
  }
}



int main(){
  ll d;
  cin >> n >> d;
  ll x[n+1];
  REP(i,n){
    cin >> x[i];
  }
  x[n] = INFll;

  ll dp[n];
  int i = 0, j = 0;
  while(i < n){
    while(j < n && x[j] - x[i] <= d){
      j++;
    }
    while(x[j] - x[i] > d || (j == n && i < n) ){
      dp[i] = j-i-1;
      i++;
    }
  }



  REP(i,n+1) bit[i] = 0;
  REP(i,n){
    bit_add(i+1,dp[i]);
  }

  // REP(i,n){
  //   cout << bit_sum(i) << endl;
  // }


  ll ans = 0;

  REP(i,n){
    ll tmp = dp[i];
    ans += bit_sum(i+1+tmp) - bit_sum(i+1) - tmp * (tmp-1) / 2;
    // cout <<  bit_sum(i+1+tmp) - bit_sum(i+1) - tmp * (tmp-1) / 2 << endl;
  }

  cout << ans << endl;

  return 0;
}
