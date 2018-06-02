#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string>
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
  string s;
  int k;
  cin >> s;
  cin >> k;
  map<string, int> mp;
  REP(i,s.size()){
    for(int j = max(i-5,0); j < i+1; j++){
      mp[s.substr(j,i-j+1)]++;
    }
  }

  int i = 0;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    i++;
    if(i==k)cout << itr->first << endl;
  }




  return 0;
}
