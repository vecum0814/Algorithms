#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

int N;
int adj[1001][1001];
int n_edge[1001];

void dfs(int x){
    for(int y = 1; y <= N; y++){
        while(adj[x][y]){
            adj[x][y]--;
            adj[y][x]--;
            dfs(y);
        }
    }
    cout << x << " ";
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> adj[i][j];
            n_edge[i] += adj[i][j];
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(n_edge[i] % 2 != 0){
            cout << -1;
            return 0;
        }
    }
    dfs(1);
    return 0;
}

