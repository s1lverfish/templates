#include <bits/stdc++.h>
using namespace std;

/*<DEBUG>*/
#define tem template <typename 
#define can_shift(_X_, ...) enable_if_t<sizeof test<_X_>(0) __VA_ARGS__ 8, debug&> operator<<(T i)
#define _op debug& operator<<
tem C > auto test(C *x) -> decltype(cerr << *x, 0LL);
tem C > char test(...);
tem C > struct itr{C begin, end; };
tem C > itr<C> get_range(C b, C e) { return itr<C>{b, e}; };
struct debug{
#ifdef _LOCAL
	~debug(){ cerr << endl; }
	tem T > can_shift(T, ==){ cerr << boolalpha << i; return *this; }
	tem T> can_shift(T, !=){ return *this << get_range(begin(i), end(i)); }
	tem T, typename U > _op (pair<T, U> i){ 
		return *this << "< " << i.first << " , " << i.second << " >"; }
	tem T> _op (itr<T> i){
		*this <<  "{ ";
		for(auto it = i.begin; it != i.end; it++){
			*this << " , " + (it==i.begin?2:0) << *it;
		}
		return *this << " }";
	}
#else
tem T> _op (const T&) { return *this; }
#endif 
};

string _ARR_(int* arr, int sz){
	string ret = "{ " + to_string(arr[0]); 
	for(int i = 1; i < sz; i++) ret += " , " +  to_string(arr[i]);
	ret += " }"; return ret;
}

#define exp(...) " [ " << #__VA_ARGS__ << " : " << (__VA_ARGS__) << " ]"
/*</DEBUG>*/

typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t uint;
typedef pair<int, int> pii;

#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define TC int __TC__; cin >> __TC__; while(__TC__--)

const int INF = 1e9 + 7;
const int MxN = 1e5 + 100;

vector<int> adj[MxN];
int parent[MxN], blocked[MxN], sz[MxN];

//find answer for paths going through root
ll solveTree(int root, int compSize){
	return 0;
}

int calcSum(int v, int p){
	sz[v] = 1;
	parent[v] = p;

	for(int u : adj[v]){
		if(u != p && !blocked[u]){
			sz[v] += calcSum(u, v);
		}
	}
	return sz[v];
}

ll findAns(int entryPoint){
	//calc subtree sizes
	calcSum(entryPoint, entryPoint);
	int best = sz[entryPoint];
	int centroid = entryPoint;

	//find centroid and component size
	queue<int> q;
	q.push(entryPoint);
	int compSize = 0;

	while(!q.empty()){
		int cur = q.front();
		compSize++;
		q.pop();
		int mx = sz[entryPoint] - sz[cur];
		for(int u : adj[cur]){
			if(u != parent[cur] && !blocked[u]){
				q.push(u);
				mx = max(mx, sz[u]);
			}
		}
		if(mx < best){
			best = mx;
			centroid = cur;
		}
	}
	
	//solve tree for paths through centroid
	ll ans = solveTree(centroid, compSize);
	blocked[centroid] = 1;

	//recurse
	for(int u : adj[centroid]){
		if(!blocked[u]) ans += findAns(u);
	}

	return ans;
}

int main(void)
{
	FAST;
	memset(blocked, 0, sizeof blocked);

	int n; cin >> n;
	for(int i = 1; i < n; i++){
	}

	ll ans = findAns(0);
	//ll ans = solveTree(4, 7);

	cout << ans << '\n';
	return 0;
}
