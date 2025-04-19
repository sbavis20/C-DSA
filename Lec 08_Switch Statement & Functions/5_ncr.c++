/*
In mathematics, "nCr" represents the number of combinations of n items taken r at a time, calculated as n! / (r! * (n-r)!).

*/
#include<iostream>
using namespace std;

int factorial(int n){
    int fact = 1;

    for(int i = 1; i<=n ; i++){
        fact = fact * i;
    }

    return fact;
}

int ncr(int n, int r){
        int num = factorial(n);

        int denom = factorial(r) * factorial(n-r);

        int ans  = num/denom;

        return ans;

    }


int main(){
    int n,r;
    cin>>n>>r;

    int ans = ncr(n,r);

    cout<<ans<<endl;




}
