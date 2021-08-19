#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ff 					first
#define ss 					second
#define int 				long long
#define ll					long long int
#define pb 					push_back
#define mp 					make_pair
#define pii					pair<int,int>
#define vi					vector<int>
#define endl				"\n"

#define mii					map<int,int>
#define pqb					priority_queue<int>
#define pqs					priority_queue<int,vi,greater<int>>
#define setbits(x)			__builtin_popcountll(x) //number of setbits
#define zrobits(x)			__builtin_ctzll(x) //number of zeros before 1 from the right
#define mod					1000000007
#define inf					1e18
#define ps(x,y)				fixed<<setprecision(y)<<x
#define endl				"\n"


//converts x upto y decimal places
#define mk(arr,n,type)		type *arr=new type[n];
#define w(t)				int t; cin>>t; while(t--)
mt19937						rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(arr,arr+n,rng)
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {

/*sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);*/

template < class c > struct rge { c b, e; };
template < class c > rge<c> range(c i, c j) { return rge<c> {i, j}; }
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);

struct debug {
	~debug() { cerr << endl; }

	//eni(!=) cerr << boolalpha << i; ris; }        Part 1

	template < class c > typename \
	enable_if < sizeof dud<c>(0) != 1, debug& >::type operator<<(c i) {
		cerr << boolalpha << i;
		return * this;
	}

	//eni(==) ris << range(begin(i), end(i)); }     Part 2

	template < class c > typename \
	enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
		return * this << range(begin(i), end(i));
	}

	/*sim, class b dor(pair < b, c > d) {           Part 3
		ris << "(" << d.first << ", " << d.second << ")";
	}*/

	template < class c, class b > debug & operator << (pair < b, c > d) {
		return * this << "(" << d.first << ", " << d.second << ")";
	}

	/*sim dor(rge<c> d) {                           Part 4
		*this << "[";
		for (auto it = d.b; it != d.e; ++it)
			*this << ", " + 2 * (it == d.b) << *it;
		ris << "]";
	}*/

	template < class c > debug & operator <<(rge<c> d) {
		*this << "[";
		for (auto it = d.b; it != d.e; ++it)
			*this << ", " + 2 * (it == d.b) << *it;
		return * this << "]";
	}

};

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int nkladdertopdown(int n, int k) {
	if (n == 0)
		return 1;

	if (n < 0)
		return 0;
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		ans += nkladdertopdown(n - i, k);
	}
	return ans;

}

int nkladdertopdowndp(int n, int k, vi &dp) {
	if (n == 0) {
		return 1;
	}
	if (n < 0)
		return 0;

	if (dp[n] != 0)
		return dp[n];

	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += nkladdertopdowndp(n - i, k, dp);
	}
	dp[n] = ans;

	return dp[n];
}


int nkladderbottomupdp(int n, int k) {
	vi dp(n + 1, 0);

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
			}
		}
	}
	return dp[n];
}

int nkladderbottomupopt(int n, int k) {
	vi dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= k; i++) {
		dp[i] = 2 * dp[i - 1];
	}

	for (int i = k + 1; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 1] - dp[i - k - 1];
	}

	return dp[n];
}



int32_t main()
{
	c_p_c();
	int n ;
	int k;
	cin >> n;
	cin >> k;
	vi dp(n + 1, 0);
	cout << nkladdertopdown(n, k) << endl;
	cout << nkladdertopdowndp(n, k, dp) << endl;
	cout << nkladderbottomupdp(n, k) << endl;
	cout << nkladderbottomupopt(n, k) << endl;

}