#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
char chess[50][50];
int check(int a, int b){
    int wh = 0;
    int bl = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((i + j) % 2 == 0){
                if(chess[i + a][j + b] == 'B'){
                    wh++;
                }
                else{
                    bl++;
                }
            }
            else{
                if(chess[i + a][j + b] == 'W'){
                    wh++;
                }
                else{
                    bl++;
                }
            }
        }
    }
    if(wh > bl){
        return bl;
    }
    else{
        return wh;
    }
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("\n");
        for(int j = 0; j < M; j++){
            scanf("%c",&chess[i][j]);
        }
    }
    int ans = 64;
    for(int i = 0; i <= N - 8; i++){
        for(int j = 0; j <= M - 8; j++){
            int tmp = check(i, j);
            if(ans > tmp){
                ans = tmp;
            }
        }
    }
    cout << ans;
    return 0;
}
