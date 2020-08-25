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

const int INF = 1e9;

int n, a, b;

int main(void)
{
	FAST;
	cin >> n >> a >> b;
	int cnt = 1;
	int timer = 1; 
	while(cnt < n){
		if(timer % a == 0) cnt++;
		if(timer % b == 0) cnt++;
		timer++;
	}
	timer--;

	cout << timer + min(a,b) << '\n';


	return 0;
}
