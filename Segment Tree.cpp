#include<bits\stdc++.h>

using namespace std;
#define mx 10001
int arr[mx];
int tree[12][mx * 3],dp[10005][12];
void init(int node, int b, int e,int i)
{
    if (b == e) {
        tree[i][node] = dp[b][i];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid,i);
    init(Right, mid + 1, e,i);
    tree[i][node] = tree[i][Left] + tree[i][Right];
}
long long query(int node, int b, int e, int i, int j,int value,int l)
{
    if (i > e || j < b)
        return 0;
    if(b==e && arr[b]<value){
        //if(i==1 && j==2)cout<<tree[l][node]<<" ";
        return tree[l][node];
    }
    if(b==e && arr[b]>=value)
        return 0;
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j,value,l);
    int p2 = query(Right, mid + 1, e, i, j,value,l);
    return p1 + p2;
}
int main()
{
    int n,i,q,a,b,j,k;
    long long s=0;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",&arr[i]);
    for(i=1;i<=n;i++){
        dp[i][1]=1;
    }
    init(1,1,n,1);
    //for(i=1;i<=3*n;i++)cout<<tree[1][i]<<" ";
    for(j=2;j<=k+1;j++){
        for(i=1;i<=n;i++){
            if(j>i)dp[i][j]=0;
            else dp[i][j]=query(1,1,n,1,i-1,arr[i],j-1);
        }
        init(1,1,n,j);
    }
    for(i=1;i<=n;i++){
        s+=dp[i][k+1];
    }
    cout<<s;
    return 0;
}
