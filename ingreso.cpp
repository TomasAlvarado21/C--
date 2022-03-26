#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int i, n, num;
    cout<<"How many numbers you want to enter ? ";
    cin>>n;
    cout<<"Enter "<<n<<" numbers: ";
    vector <int> lista(n);
    for(i=0; i<n; i++)
    {
        cin>>num;
        lista[i] = num;
    }
    for ( i = 0; i < n; i++)
    {
        cout<<lista[i]<<endl;
    }
    
    
    return 0;
}