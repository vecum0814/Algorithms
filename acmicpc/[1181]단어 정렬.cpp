#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool comp(string a, string b){
    if(a.size() != b.size()){
        return a.size() < b.size();
    }
    return a < b;
}

int main(){
    int N;
    cin >> N;
    vector<string> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), comp);
    string temp;
    for(int i = 0; i < N; i++){
        if(temp == v[i]){
            continue;
        }
        cout << v[i] << '\n';
        temp = v[i];
    }

    return 0;
}
