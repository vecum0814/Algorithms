#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int a[50][50];
int b[50][50];
void change(int x, int y){
    for(int i = x - 1; i <= x + 1; i++){
        for(int j = y - 1; j <= y + 1; j++){
            a[i][j] = 1 - a[i][j];
        }
    }
}
int main(){
    int N, M;
    cin >> N >> M;
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d",&a[i][j]);
        }
    }
    for(int i = 0; i < N; i++){
           for(int j = 0; j < M; j++){
               scanf("%1d",&b[i][j]);
           }
       }
    for(int i = 0; i < N - 2; i++){
        for(int j = 0; j < M - 2; j++){
            if(a[i][j] != b[i][j]){
                ans += 1;
                change(i + 1,j + 1);
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] != b[i][j]){
                cout << "-1";
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}
