#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

long long dp[100010]; // 이번에는 동물을 우리에 넣지 않는 경우를 처리하지 않고 계산해보자
//dp[i] = 세로 크기가 i인 동물원을 채우는 방법의 수, 단 i번째 줄에는 반드시 동물이 존재해야 할 경우
//dp[i - 1] 에는 동물을 배치하는 경우의 수가 하나밖에 없지만, dp[i - 2]줄 부터는 2개의 옵션, 즉 원래 존재하는 하나의 옵션과 dp[i - 1]의 해당하는 칸에 동물을 배치하지 않을 경우까지 합쳐서 2가지가 있다.
//즉, i -> i - 1, dp[i - 1], i -> i - 2, 2 x dp[i - 2]
int score[10010];
long long save[100010]; // save[i] = dp[1] + dp[2] +...+ dp[i];
//dp[i] = dp[i - 1] + 2 * save[i - 2];

int main(){
    int N;
    cin >> N;
    dp[0] = 1;
    save[0] = 1;
    dp[1] = 2;
    save[1] = dp[0] + dp[1];
    for(int i = 2; i <= N; i++){
        dp[i] = dp[i - 1] + 2 * save[i - 2];
        save[i] = dp[i] + save[i - 1];
        dp[i] %= 9901;
        save[i] %= 9901;
    }
    cout << save[N];
    
   
    return 0;
}


