#include <bits/stdc++.h>

using namespace std;

bool solve(){

    int n, m;

    string s, t;

    cin >> n >> m >> s >> t;
    reverse(t.begin(), t.end());
    string st = s + t;
    
    int last = st[0];
    int errores = 0;
    for(int i = 1; i < st.size(); i++){
        if(st[i] == last) errores++;

        last = st[i];

        if (errores > 1) return 0;
    }
    return 1;
}

int main(){
    int t;

    cin >> t;

    while(t--){
        if(solve()){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

}