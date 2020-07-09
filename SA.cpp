#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX_N 400100
using namespace std;

const int INF = 1e9 + 7;

int n, k = 0, len;
int CNT[MAX_N], POS[MAX_N];
string s, input;
vector<int> c, p, c_new, p_new, lcp;

pair<int, int> stringMatch() {
	int lo = 0, hi = n-1, mid = lo;
	while(lo < hi){
		mid = lo + (hi - lo)/2;
		if(s.compare(p[mid], len, input) >= 0) hi = mid;
		else lo = mid+1;
	}
	if(s.compare(p[lo], len, input) != 0) return make_pair(-1, -1);
	pair<int, int> ans; ans.first = lo;
	lo = 0; hi = n-1;
	while(lo < hi){
		mid = lo + (hi - lo)/2;
		if(s.compare(p[mid], len, input) > 0) hi = mid;
		else lo = mid+1;
	}
	if(s.compare(p[hi], len, input) != 0) hi--;
	ans.second = hi;
	return ans;
}

void counting_sort(){

	memset(CNT, 0, sizeof(CNT));
	for(int i = 0; i < n; i++) CNT[c[i]]++;

	POS[0] = 0;
	for(int i = 1; i < n; i++) POS[i] = POS[i-1] + CNT[i-1];

	for(int x : p){
		int i = c[x];
		p_new[POS[i]] = x;
		POS[i]++;
	}
	p = p_new;
}

void makeSA(){
	c.resize(n); p.resize(n);
	c_new.resize(n); p_new.resize(n);
	{
		vector<pair<char, int>> a(n);
		for(int i = 0; i < n; i++) a[i] = make_pair(s[i], i);
		sort(a.begin(), a.end());

		for(int i = 0; i < n; i++) p[i] = a[i].second;
		c[p[0]] = 0;
		for(int i = 1; i < n; i++) 
			c[p[i]] = c[p[i-1]] + (a[i].first == a[i-1].first ? 0 : 1);
	}
	k = 0;
	while((1<<k) < n){
		for(int i = 0; i < n; i++) 
			p[i] = (p[i] - (1<<k) + n)%n;

		counting_sort();

		c_new[p[0]] = 0;
		pair<int, int> prev = make_pair(c[p[0]], c[(p[0] + (1<<k))%n]);
		for(int i = 1; i < n; i++){
			pair<int, int> cur = make_pair(c[p[i]], c[(p[i] + (1<<k))%n]);
			c_new[p[i]] = c_new[p[i-1]] + (prev == cur ? 0 : 1);
			prev = cur;
		}
		c = c_new;
		k++;
	}
	return;
}

void makeLCP(){
	lcp.resize(n);
	k = 0;
	for(int i = 0; i < n-1; i++){
		int pi = c[i];
		int j = p[pi - 1];
		while(s[i +k] == s[j + k]) k++;
		lcp[pi] = k;
		k = max(0, k-1);
	}
	return;
}

int main(void)
{
	FAST
	cin >> s;
	s += "$";
	n = s.length();	
	makeSA();

	/*
	for(int i = 0; i < n; i++) cout << p[i] << ' ';
	cout << '\n';
	*/

	/*
	int TC; cin >> TC;
	while(TC--){
		cin >> input;
		len = input.length();
		auto ans = stringMatch();
		cout << (ans.first == -1 ? 0 : ans.second - ans.first + 1 ) << '\n';
	}
	*/

	/*
	makeLCP();
	ll sum = 0;
	for(int i = 1; i < n; i++) sum += i - lcp[i];
	cout << sum << '\n';
	*/

	return 0;
}
