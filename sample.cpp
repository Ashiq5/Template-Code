#include<bits/stdc++.h>

#define ll long long
#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)
#define mod 1000000007
#define digit(c) (c - '0')
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sc scanf
#define pp printf
#define INF 1e15
#define LONG_MA 1e12

using namespace std;

ll n,k,i,j,l,t,x,y,w,cnt,f,g,h,z,m,cyc,ans,par;
ll a[205],b[205];
ll sp[105],dp[105],dis[105],low[105],disc[105],parent[105],rest[105],dist[10][10];
char c,d;
string s,ss,p,qq;
vector<ll> v[105],r[105],scc[105];
vector<pair<ll,ll> > vec[105];
map<string,int> ma;
ll vis[105];
stack<ll> st;
queue<ll> q;
pair<ll,ll> pi;
priority_queue < pair<ll,ll> ,vector< pair<ll,ll> >,greater<pair<ll,ll> > > pq;
struct Edge{ll src, dest, weight;};
Edge edge[105];

//sort(a,a+n) for sorting aray a in non-decreasing pattern...sort(a,a+n,greater<int>()) for non-increasing one
//swap() for swapping 2 numbers
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
string rev(string p)
{
    reverse(p.begin(),p.end());
    return p;
}
ll lcs(ll i,ll j)
{
    if(i==s.length() || j==p.length())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==p[j])dp[i][j]=1+lcs(i+1,j+1);
    else{
        dp[i][j]=max(lcs(i+1,j),lcs(i,j+1));
    }
    return dp[i][j];
}
long long int ncr(long long int n,long long int r)//to overcome overflow -- ncr
{
    if(r<=n/2){
        r=n-r;
    }
    if(n<r)return 0;
    long long int i,res=1,d=1,cou=0;
    for(i=2;i<=(n-r);i++){
        if(i%2==0){
            d=d*(i/2);
            cou++;
        }
        else d=d*i;
    }
    for(i=n;i>=(r+1);i--){
        if(i%2==0&&cou!=0){
            res=res*(i/2);
            cou--;
        }
        else res=res*i;
    }
    return res/d;
}

bool possible(ll p)
{
    cnt=0;
    z=0;
    memset(vis,0,sizeof(vis));
    for(j=p-1;j>=0;j--){
        if(a[j]==0 || vis[a[j]]){if(z)z--;}
        else {cnt++;z+=b[a[j]-1];vis[a[j]]=1;}
    }
    if(cnt!=k)return false;
    if(z==0 && cnt==k)return true;
    return false;
}

void bis(ll l,ll r)
{
    if(l>r)return;
    ll mid=(l+r)/2;
    if(possible(mid)){
        ans=mid;
        r=mid-1;
        bis(l,r);
    }
    else {
        l=mid+1;
        bis(l,r);
    }
}

bool leap(int n)
{
    if (n%4!=0)
    {
        return false;
    }
    if (n%100!=0)
    {
        return true;
    }
    if (n%400==0)
    {
        return true;
    }
    return false;
}

ll po(int n,int r)
{
    ll ans=1;
    for(int i=1;i<=r;i++){
        ans=n*ans;
    }
    return ans;
}

ll fast_pow(ll a,long long int n) //fast power with no mod
{
    ll result = 1;
    long long int power = n;
    ll value = a;
    while(power>0)
    {
        if(power&1)
            {result = result*value;}
            //result = result%1000000007;}
        value = value*value;
        //value = value%1000000007;
        power /= 2;
        //power >>= 1;
    }
    return result;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return (a/gcd(a,b))*b;
}
/*
//memset(dp,-1,sizeof(dp);
ll rec(ll k)
{
    if(k==0)return 0;
    if(dp[k]!=-1)return dp[k];
    ll ans=1e15;
    for(int i=0;i<v.size();i++){
        ans=max(rec(k-1)+v[i]-v[i-1],rec(k));
        dp[k]=max(ans,dp[k]);
    }
    return ans;
}
*/
void topology(ll u)
{
    vis[u]=1;
    for(ll f=0;f<v[u].size();f++){
        ll q;
        q=v[u][f];
        if(!vis[q]){
            topology(q);
        }
    }
    st.push(u);
}
void dfs(ll u)  // loop through all vertices
{
    vis[u]=1;
    for(ll f=0;f<v[u].size();f++){
        ll q;
        q=v[u][f];
        if(!vis[q]){
            dfs(q);
        }
    }
}
void bfs(ll s)  // loop through all vertices
{
    dis[s]=0;
    vis[s]=1;
    q.push(s);
    while(!q.empty()){
        ll k=q.front();
        q.pop();
        for(ll j=0;j<v[k].size();j++){
            ll p=v[k][j];
            if(!vis[p]){
                vis[p]=1;
                q.push(p);
                dis[p]=dis[k]+1;
            }
        }
    }
}

void Sieve(){
    // till 1e7
	for (ll i = 2; i <= n; i += 2)	sp[i] = 2;
	for (ll i = 2; i <= n; i +=2){
		if (!sp[i]){
			sp[i] = i;
			for (ll j = i; (j*i) <= n; j += 2){
				if (!sp[j*i])	{ sp[j*i] = i;}
			}
		}
	}
}
ll power (ll a, ll b)   //recursive fast power with mod
{
    if (b==0) return 1;
    if (b==1) return a%mod;
    ll res = power(a, b/2);
    res%=mod;
    if (b%2==1) return (((a*res)%mod)*res)%mod;
    else return res*res%mod;
}

template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}

template <class T> inline T modinverse(T a,T M)   //returns (a^-1 mod m)
{
    return bigmod(a,M-2,M);
}

template <typename T>  T StringToNumber ( const string &Text )
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}

template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}
//cycle detection in undirected or directed graph
// have to loop through every vertex
bool cycle(ll i,ll par)
{
    vis[i]=1;
    rest[i]=1;
    for(ll j=0;j<v[i].size();j++){
        ll q;
        q=v[i][j];
        if(!vis[q] && cycle(q,i)){
            //return true;  //return true for just detecting cycle
        }
        else if(rest[q] && q!=par){
            cout<<i<<" "<<q<<endl;
            cyc++; //cyc contains no. of cycles
            //cout<<cyc<<endl;
            //return true;  //return true for just detecting cycle
        }
    }
    rest[i]=0;
    //return false;  // for just detecting cycle
}


ll bridge(ll u)
{
    ll i,j;
    static int time = 0;
    vis[u] = 1;
    disc[u] = low[u] = ++time;
    for (i = 0; i <v[u].size(); ++i)
    {
        int q = v[u][i];
        if (!vis[q])
        {
            parent[q] = u;
            bridge(q);
            low[u]=min(low[u], low[q]);
            if (low[q] > disc[u]){      //for bridge
              // cout<<q<<" "<<u<<endl; //q-u is a bridge
              //c[u][q]=0; //bridge removal
              //c[q][u]=0; //bridge removal-undirected graph
            }
            /*
            if (parent[u] == NIL && children > 1)
               // u is an articulation point
            if (parent[u] != NIL && low[v] >= disc[u])
               // u is an articulation point
            */


        }
        else if (q != parent[u])
            low[u]=min(low[u],disc[q]);
    }
}

void djkstra(ll i)
{
     ll j,k,t;
     dis[i]=0;
     pq.push(make_pair(0,i));
     while(!pq.empty())
     {
         pi=pq.top();
         pq.pop();
         j=pi.second;
         t=pi.first;
         vis[j]=1;
         for(k=0;k<vec[j].size();k++){
            if(!vis[vec[j][k].second]){
                ll m=vec[j][k].second;
                ll y=vec[j][k].first;
                if(max(dis[j],y)<dis[m])dis[m]=max(dis[j],y);
                pq.push(vec[j][k]);
            }
         }
     }
}

void BellmanFord(ll src)
{
    dis[src] = 0;
    for (int i = 1; i <= n-1; i++) //n is the vertex number
    {
        for (int j = 0; j < m; j++) //m is the edge number
        {
            ll u = edge[j].src;
            ll v = edge[j].dest;
            ll weight = edge[j].weight;
            if (dis[u] != INF && dis[u] + weight < dis[v])
                dis[v] = dis[u] + weight;
        }
    }

    //check for negative-weight cycles.
    for (int i = 0; i < m; i++)
    {
        ll u = edge[i].src;
        ll v = edge[i].dest;
        ll weight = edge[i].weight;
        if (dis[u] != INF && dis[u] + weight < dis[v])
            printf("Graph contains negative weight cycle");
    }
    return;
}

void floydwarshall()
{
    for (k = 0; k < n; k++){ //n is the number of vertices
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j]) //dist is adjacency matrix of the graph
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

void primMST()
{
    ll src = 0; // Taking vertex 0 as source
    vector<ll> key(n, INF);
    vector<ll> parent(n, -1);
    vector<bool> inMST(n, false);
    pq.push(make_pair(0, src));
    key[src] = 0;
    while (!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();
        inMST[u] = true;  // Include vertex in MST
        for(ll k=0;k<vec[u].size();k++)
        {
            ll q=vec[u][k].ff;
            ll weight =vec[u][k].second;
            if (inMST[q] == false && key[q] > weight){
                key[q] = weight;
                pq.push(make_pair(key[q], q));
                parent[q] = u;
            }
        }
    }

    // Print edges of MST using parent array
    for (ll i = 1; i < n; ++i)
        printf("%d - %d\n", parent[i], i);
}

int longestPalSubstr()
{
    bool table[n][n];
    memset(table, 0, sizeof(table));
    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
    int start = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }
    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n-k+1 ; ++i)
        {
            int j = i + k - 1;
            if (table[i+1][j-1] && str[i] == str[j])
            {
                table[i][j] = true;
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    //cout<<start<<" "<<maxLength<<endl;
    return maxLength; // return length of LPS
}
int main()
{
    return 0;
}

/*
int candle[10001];
void merge(int min,int mid,int max)
{
    int tmp[1000];
    int i,j,k,m;
    j=min;
    m=mid+1;
    for(i=min;j<=mid&&m<=max;i++){
        if(candle[j]<=candle[m]){
            tmp[i]=candle[j];
            j++;
        }
        else{
            tmp[i]=candle[m];
            m++;
        }
    }
    if(j>mid){
        for(k=m; k<=max; k++){
            tmp[i]=candle[k];
            i++;
        }
    }
    else{
        for(k=j; k<=mid; k++){
            tmp[i]=candle[k];
            i++;
        }
    }
    for(k=min; k<=max; k++)
         candle[k]=tmp[k];
}
void part(int min,int max)
{
    int mid;
    if(min<max){
        mid=(min+max)/2;
        part(min,mid);
        part(mid+1,max);
        merge(min,mid,max);
    }
}

I can tell you about the way I interpreted it, but usually in math/statistics problems there are many ways to understand a concept. When you understand it in your own terms, maybe you can find an easier way to model the problem :).

Let's consider test case #3:
3
3 -6 -9

There are 3 doors, and we are to find the expected amount of time it will take to get out of the maze. Let's call that expected value E. Now, E has to be equal to the average of the times that it takes to get out from each door, correct? Let's say T1 is the amount of time to get out of the maze when taking door #1, and T2 and T3 are defined similarly. Then:
E = (T1 + T2 + T3) / 3

It's easy to see that T1 is 3, but what about T2 and T3? You can think about it like this: if you take door number 2, you will spend 6 minutes going through the maze, and you end up at the starting point, and from there, how much time will it take you to get out? Well, E is the expected time it will take you to get out from the start, right? So, you can say:
T2 = 6 + E
T3 = 9 + E

Putting all that together, the original equation becomes:
E = 3/3 + (6/3 + E/3) + (9/3 + E/3)
E = 6 + 2E/3
E/3 = 6
E = 18

So the final answer is 18. Incidentally, you can see that something curious happens when there is no answer: if all doors take you back to the beginning, then all the occurrences of E in the equation can be cancelled, so you're left with a mathematical relation where you can't find a solution for E. Hope that helps
*/

