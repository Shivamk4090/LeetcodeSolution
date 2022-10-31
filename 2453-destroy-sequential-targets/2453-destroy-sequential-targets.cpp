#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef complex<lld> cd;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<lld,lld> pd;
typedef pair<ull, ull> pul;
typedef vector<int> vi;
typedef vector<lld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef  map<int, int> mii;
template<class T> using pqg = priority_queue<T>;
template<class T> using pqs = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define pf push_front
#define MM multimap
#define P pair

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define IT iterator
#define RIT reverse_iterator

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n]
#define init(arr,val) memset(arr,val,sizeof(arr))
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

#define loop(i,a,b) for(int i=a;i<=b;i++)
#define loops(i,a,b,step) for(int i=a;i<=b;i+=step)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define w(x)  int x; cin >> x; while (x--)

#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x <<" " ; _print(x); cerr<< endl;
#else
#define deb(x)
#endif
void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define inf 1e9
#define maxn 1e5
#define mod 1000000007
#define PI 3.141592653589793238462
#define nl "\n"
static const auto speedup = []() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();

class Solution {
public:
    int destroyTargets(vector<int>& a, int s) {
        
        mii m;
        trav(e,a){
            m[e%s]++;
        }
        int ans = 0;
        trav(e, m){
            ans = max(ans, e.S);
        }
        set<int> rem;
        trav(e, m) if(e.second==ans)rem.insert(e.first);

        ans = 1e9+1;
        trav(e, a){
            if(rem.find(e%s)!=rem.end()) ans = min(ans, e);
        }

        return ans;

    }
};

void solve(){
    vector<int>a={6, 2, 5};
    vector<vector<int>>g={

    };

    Solution x;

    int d =  x.destroyTargets(a, 100);
    deb(d);
}

void starter(){
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("Error.txt", "w", stderr);
    #endif
}
// int main(){ starter(); solve();}