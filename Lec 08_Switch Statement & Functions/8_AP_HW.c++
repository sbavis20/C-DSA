#include<iostream>
using namespace std;

bool AP(int firstTerm,int comdiff,int nterm){
    int ans = firstTerm + (nterm -1)*comdiff ;
    cout << ans;
}

int main(){
    int firstTerm,comdiff,nterm;
    cin>> firstTerm>>comdiff>>nterm;

    AP(firstTerm,comdiff,nterm);


    return 0;
}
