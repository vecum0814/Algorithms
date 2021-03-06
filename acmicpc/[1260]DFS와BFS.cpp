#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001
vector<int> graph[MAX];
bool visited_dfs[MAX];
bool visited_bfs[MAX];
int N,M,V;
void dfs(int V){
    cout << V << " ";
    visited_dfs[V] = true;
    for(int i = 0; i < graph[V].size(); i++){
        int a = graph[V][i];
        if(!visited_dfs[a]){
            dfs(a);
        }
    }
}
void bfs(int V){
    queue<int> q;
    q.push(V);
    visited_bfs[V] = true;
    while(!q.empty()){
        int a = q.front();
        cout << a << " ";
        q.pop();
        for(int i = 0; i < graph[a].size(); i++){
            int b = graph[a][i];
            if(!visited_bfs[b]){
                visited_bfs[b] = true;
                q.push(b);
            }
        }
        
    }
}
int main(){
    cin >> N >> M >> V;
    for(int i = 0; i < M; i++){
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    for(int i = 1; i <= N; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(V);
    cout << endl;
    bfs(V);

    return 0;
}
