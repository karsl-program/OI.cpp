#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int f[N], g[N], n, m, v[N];
int main() {
    cin>>n>>m;
    f[0]=g[0]=1;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++) {
        for(int j=m;j>=v[i];j--){
            f[j]=(f[j]+f[j-v[i]])%10;
        }
    }
    for (int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)g[j]=f[j];
        for(int j=v[i];j<=m;j++) {
            g[j] = (g[j] - g[j-v[i]] + 10)%10;
        }for(int j=1;j<=m;j++)cout<<g[j];
        cout<<endl;
    }
    return 0;
}