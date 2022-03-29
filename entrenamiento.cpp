#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int i, num;
    long long n;

    cin >> n;

    int dias;
    int dias_dips = n;
    dias = 0;

    vector <int> competencias(n);

    for(i=0; i<n; i++){
        cin>>num;
        competencias[i] = num;
        

    }

    std::sort(competencias.begin(),competencias.end());
    
    /*
    for (i=n-1; dias_dips == 0;i--){
        if (competencias[i]==1 && dias_dips != 1){
            dias_dips = 0;
            i++;
        }
        else if (competencias[i]<dias_dips){
            dias_dips--;
            i++;

        }
        else if (competencias[i]>=dias_dips){

            dias_dips--;
            dias ++;
            i--;
        }
    }*/
    i = n-1;
    while (dias_dips != 0)
    {
        if (competencias[i] < dias_dips){
            dias_dips --;
        }
        else if (competencias[i] >= dias_dips){
            dias_dips --;
            dias++;
            i--;
        }
    }
    
    cout << dias << endl;
    
    return 0;
    
}