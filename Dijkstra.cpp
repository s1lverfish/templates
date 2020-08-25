#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define TC int tc; cin >> tc; while(tc--)

using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

const int INF = 1e9 + 7;


const int MxN = 3e5 + 10;

vector<pair<int, pair<int, int>>> g[MxN];

int main(void)
{
	FAST;

	set<pair<long long, int>> q; q.insert({0,0}); //indexed queue + initialize
	vector<long long> d(n, INF); d[0] = 0; //initialize first d value
	vector<int> p(n, -1); //parent pointers

	while(!q.empty()){
		auto it = q.begin();
		int k = it->second;
		q.erase(it);

		for(auto x : g[k]){
			int to = x.first; 
			ll w = x.second.first;
			int index = x.second.second; //index of edge
			if(d[to] > d[k] + w){
				q.erase({d[to], to});
				d[to] = d[k] + w;
				p[to] = k;
				q.insert({d[to], to});
			}
		}
	}
	return 0;
}
