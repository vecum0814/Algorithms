#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char arr[55][55];
bool broken[10]; // 망가지면 true, 정상이면 false
int possible(int c){
    if(c == 0){
        if(broken[c]){
            return 0;
        }
        else{
            return 1;
        }
    }
    int ans = 0;
    while(c > 0){
        if(broken[c % 10]){
            return 0;
        }
        ans ++;
        c /= 10;
    }
    return ans;
}
int main(){
    int N;
    cin >> N;
    int M;
    cin >> M;
    int a;
    for(int i = 0; i < M; i++){
        cin >> a;
        broken[a] = true;
    }
    int ans = N - 100; //숫자버튼을 안누르고 오직 +, 혹은 -만 누를 때
    if(ans < 0){
        ans *= -1;
    }
    for(int i = 0; i <= 1000000; i++){
        int len = possible(i);
        if(len > 0){
            int press = i - N;
            if(press < 0){
                press *= -1;
            }
            if(ans > press + len){
                ans = press + len;
            }
        }
    }
    cout << ans;
    return 0;
}
