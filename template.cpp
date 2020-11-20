//clear adj and visited vector declared globally after each test case
//check for long long overflow
//while adding and subs check if mod becomes -ve
//while using an integer directly in a builtin function add ll
//Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;
//Dont keep array name as size or any other key word

#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;
#define Fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define f(i, n) for (long long int i = 0; i < n; i++)
#define ll long long int
#define fo(i, a, b) for (long long int i = a; i <= b; i++)
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long int>>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define mll map<ll,ll>
#define umll unordered_map<ll,ll>
#define newl cout<<"\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll inf = 1e9 + 7;
const ll mod = 998244353;
#define MAX 100002

// cell in grid where we can go in one step
ll Dx[4] = {1,0,-1,0};
ll Dy[4] = {0,1,0,-1};

// gcd in a efficient way(Euclidean theorem)-------------time complexity O(log(min(a,b)))
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


void bsearch(){
    ll n;
    cin>>n;
    ll l = 1,r = n;
    ll ans = 0;
    while(l<=r){
        ll mid = (l+r)/2;
        // cout<<check(mid,n)<<" "<<mid;
        // newl;
        if(check(mid,n))ans = mid,r = mid-1;
        else l = mid+1;
    }
    cout<<ans;
}

//efficient method to find all the factors of N
vl find_factor_vector(ll n){
  vl F;
  F.pb(1),F.pb(n);
  fo(i,2,int(sqrt(n))){
      if(n%i==0){
        if(n/i == i)F.pb(i);
        else F.pb(i),F.pb(n/i);
      }
  }
  return F;
}

//func to cAlculate powers of big numbers modulo inf
ll power(ll n, ll k)
{
  ll result, pow;
  if(k==0)
    return 1;
  if(n==0)
    return 0;
  if(n==1)
    return 1;
  result=n%inf;
  pow=1;
  while(pow*2<=k)
  {
    pow=pow*2;
    result=(result*result);
    result=result%inf;
  }
 
  if(k-pow!=0)
  result=result*power(n, k-pow);
  result=result%inf;
 
  return result;
}

//Sieve of Eratosthenes(simple sieve) ............... to calculate all primes less than equal to n(n<=1000000)
//time complexity = O(n)
//time complexity O(log(n))log(log(n)))
bool prime[MAX] = {true};

void sieve(ll n){
    ll p = 2;
    while(p*p<=n){
        if(prime[p]==true){
            for(ll i = p*p;i<=n;i+=p)
                prime[i]=false;
        }
      p+=1;
    }
}

// same sieve with limits to optimize space complexity
void simple_sieve(ll limit, vl &P){

  bool mark[limit+1];
  fo(i,1,limit)mark[i] = true;

  for(ll p = 2;p*p<=limit;p++){
    if(mark[p]){
      for(ll i = p*p;i<=limit;i+=p){
        mark[i] = false;
      }
    }
  }

  fo(p,2,limit){
    if(mark[p]){
      P.pb(p);
    }
  }
}

// segmented sieve(finding prime in every segment of sqrt(n) size)efficient for memory limitation
// time complexity is same as simple_Sieve
void segmented_Sieve(int n){
    ll limit = int(sqrt(n))+1;
    vl prime;
    simple_sieve(limit, prime);

    ll low = limit;
    ll high = 2*limit;

    while(low < n){
      if(high >= n)high = n;

      bool mark[limit + 1];
      fo(i,1,limit)mark[i] = true;

      f(i,prime.size()){
        int loLim = floor(low/prime[i])*prime[i];
        if(loLim < low)loLim += prime[i];

        for(ll j=loLim;j<high;j+=prime[i])mark[j-low] = false;
      }
      for(ll i = low;i<high;i++){
        if(mark[i-low])cout<<i<<" ";
      }
      low += limit;
      high += limit;
    }
}


//Code to calculate A^n in log(N) time---------Binary exponentiation
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

//Kadane's algorithm for max sum subarray(optimized soln)
//it will work for all elemnts + - ..................in O(n) time
ll max_sum_subarray(ll n, vl &A){
    ll max_ending_here = 0,max_so_far = 0;
    ll l=0,r=0;//if question ask you to print subarray 
    for(int i = 0; i < n; i++)
    {
      max_ending_here = max_ending_here + A[i];
      if(max_ending_here < A[i])
      {
          max_ending_here = A[i];
          l = i;
      }
      if(max_so_far < max_ending_here)
      {
          max_so_far = max_ending_here;
          r = i;
      }
    }
    return max_so_far;
}

// comparator function
struct cmp{
    bool operator()(ll a,ll b){
        return a>b;
}
};


int main()
{
    Fio;
    
    return 0;
}
