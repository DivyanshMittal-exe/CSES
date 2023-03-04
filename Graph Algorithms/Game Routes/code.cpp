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



// ----------------------<MATH>--------------------------- 
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down

ll count_path(ll query_node,const vector<vector<ll>>& graph, vector<ll> &count_path_from_node ){
    ll n = graph.size();


    debug(query_node);
    debug(count_path_from_node);

    if(query_node == n-1){
        count_path_from_node[query_node] = 1;
        return 1;
    }


    if(graph[query_node].size()==0){
        return -INF;
    }


    if(count_path_from_node[query_node] != -1){
        return count_path_from_node[query_node];
    }

    ll total_paths = 0;
    for(auto x: graph[query_node]){
        ll len_from_x = count_path(x,graph,count_path_from_node);
        debug(query_node,x,len_from_x);
        if(len_from_x != -INF){
            total_paths +=  len_from_x;
            total_paths %= MOD;
        }
    }

    count_path_from_node[query_node] = total_paths;
    debug(count_path_from_node);

    return total_paths;

}

void recursive_print(ll query_node,const vector<vector<ll>>& graph, vector<ll> &count_path_from_node ){
    if(query_node == graph.size()-1){
        cout << query_node + 1 ;
        return;
    }

    debug(query_node);

    cout << query_node + 1 << " ";
    ll max_index = -1;
    ll max_element = -INF;


    for(auto x: graph[query_node]){
         if(count_path_from_node[x] >= max_element){
            max_element = count_path_from_node[x];
            max_index = x;
         }
    }

    if(max_index == -1){
        return;
    }

    recursive_print(max_index,graph,count_path_from_node);

    // std::distance(sampleArray.begin(),std::max_element(sampleArray.begin(), sampleArray.end()))
}

int main()
{

    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        auto start = std::chrono::high_resolution_clock::now();
    #endif

    fastio;


    ll n,m;
    cin >> n  >> m;
    vector<vector<ll>> graph(n);
    vector<ll> in_degree(n,0);
    // vector<ll> values(n);
    for (int i = 0; i < m; i++)
    {
        ll a,b;
        cin >> a >> b;

        --a;
        --b;
        graph[a].push_back(b);
        // in_degree[b]++;
        // cin >> values[i];

    }

    debug(graph);


    vector<ll> count_path_from_node(n,-1);

    ll max_len = count_path(0,graph,count_path_from_node);

    debug(max_len);
    
    debug("Printing Mode");
    debug(count_path_from_node); 

    cout << max_len;


    // if(max_len == -INF){
    //     cout << "IMPOSSIBLE";
    // }else{
    //     cout << max_len + 1 << endl;

    //     // recursive_print(0,graph,count_path_from_node);
    // }
    






    #ifndef ONLINE_JUDGE
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        cerr << "Time taken: "<< duration.count() << " ms" << endl;
    #endif
    return 0;
}
