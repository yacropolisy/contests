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
  int a, b, n;
  string x;
  cin >> a >> b >> n;
  cin >> x;
  REP(i,n){
    if(x[i] == 'S' && a > 0){
      a--;
    }else if(x[i] == 'C' && b > 0){
      b--;
    }else if(x[i] == 'E'){
      if(a >= b && a > 0){
        a--;
      }else if(b > 0){
        b--;
      }
    }
  }
  cout << a << endl << b << endl;

  return 0;
}
