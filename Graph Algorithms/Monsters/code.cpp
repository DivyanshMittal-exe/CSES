#pragma GCC optimize("Ofast,unroll-loops") 
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
const char parent[4]{'R','D','L','U'};



// ----------------------<MATH>--------------------------- 
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down
bool is_valid_graph(int x, int y, int rows, int cols){return x >= 0 && y >= 0 && x < cols && y < rows;}

int main()
{

    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        auto start = std::chrono::high_resolution_clock::now();
    #endif

    fastio;


    ll n,m;
    cin >> n >> m;

    char graph[m][n];
    // bool vis[m][n] = {0};
    char par[m][n];
    deque<pair<int,int>> q;

    pair<int,int> me;

    rep(i,0,n){
        rep(j,0,m){
            cin >> graph[j][i];
            if(graph[j][i] == 'M'){
                q.push_back({j,i});
            }else if(graph[j][i] == 'A' ){
                me = {j,i};

                if(j == 0 || i == 0 || j == m -1 || i == n-1){
                    cout << "YES\n0";
                    return 0;
                }
            }
        }
    }

    q.push_back(me);

    



    pair<int,int> backtrack_from = {-1,-1};

    while (!q.empty())
    {
        
        auto e = q[0];
        q.pop_front();
        rep(i,0,4){
            int nx = e.first + dx[i];
            int ny = e.second + dy[i];
            if(is_valid_graph(nx,ny,n,m)){
                if(graph[nx][ny] == '.'){
                    par[nx][ny] = parent[i];
                    q.push_back({nx,ny});
                    graph[nx][ny]  = graph[ e.first][e.second];
                    if(nx == 0 || ny == 0 || nx == m-1 || ny == n-1){
                            if(graph[nx][ny] == 'A'){
                                backtrack_from = {nx,ny};
                                break;
                            }
                    }
                }
            }
        }
         
    }

    if(backtrack_from.first != -1){
        deque<char> s;
        while (backtrack_from != me)
        {
            s.push_front(par[backtrack_from.first][backtrack_from.second]);
            switch (par[backtrack_from.first][backtrack_from.second])
            {
                case 'L':
                    backtrack_from.first += 1;
                break;
            
                case 'R':
                    backtrack_from.first -= 1;
                break;
                case 'U':
                    backtrack_from.second += 1;
                break;
                case 'D':
                    backtrack_from.second -= 1;
                break;
            }
        }
        
        if(sz(s) != 0){
            cout << "YES\n";
            cout << sz(s) << endl;
            tr(ii,s){
                cout << *ii ;
            }

            return 0;
        }
        

    }
    
    cout << "NO\n";



    #ifndef ONLINE_JUDGE
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        cerr << "Time taken: "<< duration.count() << " ms" << endl;
    #endif
    return 0;
}
