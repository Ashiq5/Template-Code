#include<bits/stdc++.h>
//printf("Case %lld: %lld\n",i+1,cnt);
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

ll n,k,i,j,l,x,y,w,cnt,f=1,g,h,z,cyc,ans=0,par,e,q,r,t,m;
//ll a[205],b[200005];
char c[6][6];
//ll sp[105],dp[105],dis[105],low[105],disc[105],parent[105],rest[105],dist[10][10];
//ll c,d;
//string s,ss,p,qq;
//vector<ll> v[105];//r[105],scc[105];
//vector<pair<ll,ll> > pi;
vector<string> si;
map<ll,ll > ma;
map< ll ,ll> maa;
//int gg[1005][1005];
//ll dp[115][7];
//stack<ll> st;
//queue<ll> q;
//pair<ll,ll> pi[100005],po[100005];
//priority_queue < pair<ll,ll> ,vector< pair<ll,ll> >,greater<pair<ll,ll> > > pq;
//struct Edge{ll src, dest, weight;};
//Edge edge[105];
int left(int i,int j)
{
    cnt=1;f=0;
    if(i>=3)return 1;
    if(c[i+1][j]=='.'){cnt++;f=1;}
    if(c[i+1][j]=='x')cnt++;
    if(c[i+2][j]=='.' && f==0){cnt++;return cnt;}
    if(c[i+2][j]=='x')cnt++;
    return cnt;
}
int down(int i,int j)
{
    cnt=1;f=0;
    if(j>=3)return 1;
    if(c[i][j+1]=='.'){cnt++;f=1;}
    if(c[i][j+1]=='x')cnt++;
    if(c[i][j+2]=='.' && f==0){cnt++;return cnt;}
    if(c[i][j+2]=='x')cnt++;
    return cnt;
}
int d1(int i,int j)
{
    cnt=1;f=0;
    if(j>=3 || i>=3)return 1;
    if(c[i+1][j+1]=='.'){cnt++;f=1;}
    if(c[i+1][j+1]=='x')cnt++;
    if(c[i+2][j+2]=='.' && f==0){cnt++;return cnt;}
    if(c[i+2][j+2]=='x')cnt++;
    return cnt;
}
int d2(int i,int j)
{
    cnt=1;f=0;
    if(j<=2 || i>=3)return 1;
    if(c[i+1][j-1]=='.'){cnt++;f=1;}
    if(c[i+1][j-1]=='x')cnt++;
    if(c[i+2][j-2]=='.' && f==0){cnt++;return cnt;}
    if(c[i+2][j-2]=='x')cnt++;
    return cnt;
}
int le(int i,int j)
{
    cnt=1;f=0;
    if(i>=3)return 1;
    //if(c[i+1][j]=='.'){cnt++;f=1;}
    if(c[i+1][j]=='x')cnt++;
    //if(c[i+2][j]=='.' && f==0){cnt++;return cnt;}
    if(c[i+2][j]=='x')cnt++;
    return cnt;
}
int dow(int i,int j)
{
    cnt=1;f=0;
    if(j>=3)return 1;
    //if(c[i][j+1]=='.'){cnt++;f=1;}
    if(c[i][j+1]=='x')cnt++;
    //if(c[i][j+2]=='.' && f==0){cnt++;return cnt;}
    if(c[i][j+2]=='x')cnt++;
    return cnt;
}
int d3(int i,int j)
{
    cnt=1;f=0;
    if(j>=3 || i>=3)return 1;
    //if(c[i+1][j+1]=='.'){cnt++;f=1;}
    if(c[i+1][j+1]=='x')cnt++;
    //if(c[i+2][j+2]=='.' && f==0){cnt++;return cnt;}
    if(c[i+2][j+2]=='x')cnt++;
    return cnt;
}
int d4(int i,int j)
{
    cnt=1;f=0;
    if(j<=2 || i>=3)return 1;
    //if(c[i+1][j-1]=='.'){cnt++;f=1;}
    if(c[i+1][j-1]=='x')cnt++;
    //if(c[i+2][j-2]=='.' && f==0){cnt++;return cnt;}
    if(c[i+2][j-2]=='x')cnt++;
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++){
            cin>>c[i][j];
        }
    }
    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++){
            if(c[i][j]=='x' && left(i,j)==3){
                    //cout<<i<<j;
                cout<<"YES";
                return 0;
            }
            else if(c[i][j]=='x' && down(i,j)==3){
                //cout<<i<<j;
                cout<<"YES";
                return 0;
            }
            else if(c[i][j]=='x' && d1(i,j)==3){
                //cout<<i<<j;
                cout<<"YES";
                return 0;
            }
            else if(c[i][j]=='x' && d2(i,j)==3){
                //cout<<i<<j;
                cout<<"YES";
                return 0;
            }
            else if(c[i][j]=='.' && le(i,j)==3){
                    //cout<<i<<j;
                cout<<"YES";
                return 0;
            }
            else if(c[i][j]=='.' && dow(i,j)==3){
                //cout<<i<<j;
                cout<<"YES";
                return 0;
            }
            else if(c[i][j]=='.' && d3(i,j)==3){
                //cout<<i<<j;
                cout<<"YES";
                return 0;
            }
            else if(c[i][j]=='.' && d4(i,j)==3){
                //cout<<i<<j;
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}
