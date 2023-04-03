#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int n;

    while(cin>>n){
        stack<int> pila;
        queue<int> cola;
        priority_queue<int> pcola;

        bool cs=1, cq=1, cpq=1;
        int input, val;
        while(n--){
            cin>> input >> val;
            if(input == 1){
                pila.push(val);
                cola.push(val);
                pcola.push(val);
            }
            else{
                if(pila.empty() || pila.top() != val) cs = 0;
                else pila.pop();
                if(cola.empty() || cola.front() != val) cq = 0;
                else cola.pop();
                if(pcola.empty() || pcola.top() != val) cpq = 0;
                else pcola.pop();
            }
            if (!cs && !cq && !cpq) cout <<"impossible"<<endl;
            else if (cs && !cq && !cpq) cout <<"stack"<<endl;
            else if (!cs && cq && !cpq) cout <<"queue"<<endl;
            else if (!cs && !cq && cpq) cout <<"priority queue"<<endl;
            else cout<<"not sure"<<endl;
        }
        return 0;
        
    }
}