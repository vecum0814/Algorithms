#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N;
int arr[15][15];
int ans[10];

bool check(int idx){
    int sum = 0;
    for(int i = idx; i >= 0; i--){
        sum += ans[i];
        if(arr[i][idx] == 0){
            if(sum != 0){
                return false;
            }
        }
        else if(arr[i][idx] > 0){
            if(sum <= 0){
                return false;
            }
        }
        else{
            if(sum >= 0){
                return false;
            }
        }
    }
    return true;
}
bool go(int idx){
    if(idx == N){
        return true;
    }
    if(arr[idx][idx] == 0){
        ans[idx] = 0;
        return check(idx) && go(idx + 1);
    }
    for(int i = 1; i <= 10; i++){
        ans[idx] = i * arr[idx][idx];
        if(check(idx) && go(idx + 1)){
            return true;
        }
    }
    return false;
}
int main() {
    cin >> N;
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(s[count] == '0'){
                arr[i][j] = 0;
            }
            else if(s[count] == '+'){
                arr[i][j] = 1;
            }
            else{
                arr[i][j] = -1;
            }
            count ++;
        }
    }
    go(0);
    for(int i = 0; i < N; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
