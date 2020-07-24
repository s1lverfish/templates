//Fenwick Tree - Binary Indexed Tree
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e9 + 7;

struct BIT{
	int sz;
	vector<int> table;
	void init(int size){
		size++;
		table.assign(size, 0);
		sz = size;
	}

	void update(int i, int delta){
		while(i < sz){
			table[i] += delta;
			i += (i&(-i));
		}
		return;
	}

	int prefSum(int i){
		int sum = 0;
		while(i){
			sum += table[i];
			i -= (i&(-i));
		}
		return sum;
	}

	int rangeSum(int i, int j){
		return prefSum(j) - prefSum(i);
	}
};

int main(void)
{
	FAST
	
	int v[] = {1, 2, 3 ,4 ,5 , 6, 7, 8, 9 ,10};
	BIT ft;
	ft.init(10);

	for(int i = 1; i < 11; i++) ft.update(i, v[i-1]); 

	cout << ft.prefSum(10) << endl;
	cout << ft.prefSum(9) << endl;
	cout << ft.prefSum(8) << endl;
	cout << ft.prefSum(7) << endl;
	cout << ft.rangeSum(8, 10) << endl;

	int i = 6;
	cout << ft.rangeSum(i-1, i) << endl;
	ft.update(i, (3 - ft.rangeSum(i-1, i)));
	cout << ft.rangeSum(i-1, i) << endl;
	cout << ft.prefSum(10) << endl;

	return 0;
}
