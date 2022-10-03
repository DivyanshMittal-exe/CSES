#pragma GCC optimize("Ofast,unroll-loops") 
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), RNG);

// ----------------------<DEBUG>--------------------------- 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// ----------------------<MACROS>--------------------------- 
using ll = long long;
using ld = long double;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define tr(ii, c) for (__typeof((c).begin()) ii = (c).begin(); ii != (c).end(); ii++)
#define rtr(ii, c) for (__typeof((c).rbegin()) ii = (c).rbegin(); ii != (c).rend(); ii++)
#define maX(a, b) ((a) > (b) ? (a) : (b))
#define miN(a, b) ((a) < (b) ? (a) : (b))
#define max3(A, B, C) max(max((A), (B)), (C))
#define max4(A, B, C, D) max(max((A), (B)), max((C), (D)))
#define min3(A, B, C) min(min((A), (B)), (C))
#define min4(A, B, C, D) min(min((A), (B)), min((C), (D)))
#define count_1(n) __builtin_popcountll(n)
#define fsb(index) (index & -index)
#define maximum(a) max_element(a.begin(),a.end()) 
#define minimum(a) min_element(a.begin(),a.end()) 
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) static_cast<int>((x).size())
#define MP make_pair
#define FI first
#define SE second
#define MT make_tuple
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
typedef tuple<int, int, int> iii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e6;
const ll INF = 1e15 - 1;
const ld EPS = 1e-8;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};



// ----------------------<MATH>--------------------------- 
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down


int dpt[100005][102];


int dp(int index, int val_before_index,int n, int m, const vector<int> & values){
    // debug(index);

    if(index >= n){
        debug(index,val_before_index);
        return 0;
    }

    if(dpt[index][val_before_index] != -1){
        return dpt[index][val_before_index];
    }


    if(index == n-1){
        if(values[index] == 0){
            if(val_before_index == 1 || val_before_index == m)
                return 2;
            else
                return 3;       
        }else if(values[index] - val_before_index <= 1 and values[index] - val_before_index >= -1){
            
            return 1;
        }else{
            return 0;
        }
    }

    // debug(values[index] - val_before_index <= 1 && values[index] - val_before_index >= -1);

    if(val_before_index == 0 and values[index] == 0){
        ll sum = 0;
        rep(i,1,m+1){
            sum += dp(index + 1, i,n,m,values)% MOD ;
        }
        return sum;
    }else if(values[index] == 0){
        if(val_before_index == 1){
            return dp(index + 1, val_before_index ,n,m,values) + dp(index + 1, val_before_index + 1 ,n,m,values) % MOD ;
        }else if(val_before_index == m){
            return dp(index + 1, val_before_index ,n,m,values) + dp(index + 1, val_before_index - 1 ,n,m,values) % MOD ;
        }else{
            return dp(index + 1, val_before_index + 1,n,m,values) + dp(index + 1, val_before_index ,n,m,values) + dp(index + 1, val_before_index - 1 ,n,m,values) % MOD ;
        }
    }else if(values[index] - val_before_index <= 1 && values[index] - val_before_index >= -1){
        // debug("Got here");
        return dp(index + 1, values[index] ,n,m,values);
    }else{
        return 0;
    }


}

int main()
{

    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        auto start = std::chrono::high_resolution_clock::now();
    #endif

    fastio;


int mod = 1e9+7;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dp(n,vector<int>(m+1,0));
  int x0;
  cin >> x0;
  if (x0 == 0) {
    fill(dp[0].begin(), dp[0].end(), 1);
  } else {
    dp[0][x0] = 1;
  }
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0) {
      for (int j = 1; j <= m; j++) {
	for (int k : {j-1,j,j+1}) {
	  if (k >= 1 && k <= m) {
	    (dp[i][j] += dp[i-1][k]) %= mod;
	  }
	}
      }
    } else {
      for (int k : {x-1,x,x+1}) {
	if (k >= 1 && k <= m) {
	  (dp[i][x] += dp[i-1][k]) %= mod;
	}
      }
    }
  }
  int ans = 0;
  for (int j = 1; j <= m; j++) {
    (ans += dp[n-1][j]) %= mod;
  }
  cout << ans << endl;


    #ifndef ONLINE_JUDGE
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        cerr << "Time taken: "<< duration.count() << " ms" << endl;
    #endif
    return 0;
}
