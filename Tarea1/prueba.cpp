#include<iostream>
#include<vector>

using namespace std;
/*
bool aux(int a, int b){
    if (a > b){
        return true;
    }
    else{
        return false;
    }
}
*/
int main(){
    long long i, n,num;
    long long k;
    int win_streak = 0;
    int indx;

    cin>>n;
    cin>>k;
    vector <long long> nivel_jugadores(n);
    

    for(i=0; i<n; i++){
        cin>>num;
        nivel_jugadores[i] = num;

    }
    long long winner = nivel_jugadores[0];

    
    for (i=1 , indx=0; win_streak != k;  i++){
        if (winner == n){
            win_streak = k;
            break;
        }

        else if (winner > nivel_jugadores[i]){
            win_streak += 1;
            nivel_jugadores.push_back(nivel_jugadores[i]);
        }
        
        else if (winner < nivel_jugadores[i]){
            winner = nivel_jugadores[i];
            nivel_jugadores.push_back(nivel_jugadores[indx]);
            indx = i;
            win_streak = 1;
        }
    }
    

    cout<<winner<< endl;
    return 0;
}