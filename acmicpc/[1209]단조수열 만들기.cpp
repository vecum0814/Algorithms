#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,ans,a[2001],t[2001],b[2001];
int f[2001][2001],minf[2001][2001];
bool cmp(int a,int b)
{
    return a > b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1;i <= n; i++)
    {
        cin >> a[i];
        t[i] = a[i];
    }
    sort(t + 1,t + n + 1);
    int now =- 1;
    for(int i = 1;i <= n;i++){
        if(now != t[i]){
            b[++m] = t[i];
            now = t[i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=minf[i-1][j]+abs(a[i]-b[j]);
            if(j == 1){
                minf[i][j] =f[i][j];
            }
            else{
                minf[i][j]=min(minf[i][j-1],f[i][j]);
            }
        }
    }
    ans = minf[n][m];
    memset(f, 0, sizeof(f));
    memset(minf, 0, sizeof(minf));
    sort(b + 1, b + m + 1, cmp);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            f[i][j] = minf[i - 1][j] + abs(a[i] - b[j]);
            if(j == 1){
                minf[i][j] = f[i][j];
            }
            else{
                minf[i][j] = min(minf[i][j - 1],f[i][j]);
            }
        }
    }
    ans = min(ans, minf[n][m]);
    cout << ans << '\n';;
    return 0;
}
