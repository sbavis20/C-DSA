#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cout<<i<<endl;
    }
}

/*
for( ; ; )   --> valid

for(a=1,b=1; a<n && b<n ; a++,b--) --> valid

break --> gets out of current loop
*/
