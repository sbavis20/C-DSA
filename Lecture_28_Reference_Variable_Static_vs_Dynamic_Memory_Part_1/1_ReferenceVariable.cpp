#include<iostream>
using namespace std;

//bad practice
int& func(int a){
    int num = a;
    int& ans = num;
    return ans;
}
//bad practice
int* fun(int n){
    int* ptr = &n;
    return ptr;
}

//pass by value
void update1(int n){
    n++;
}

//pass by reference
void update2(int& n){
    n++;
}

int main(){




    // int n=5;
    // int ans = func(n);
    // cout<<" "<<ans<<endl;
    // fun(n);

    // int n=5;
    // cout<<"Before "<<n<<endl;
    // update2(n);
    // cout<<"After: "<<n<<endl;

    // int i =5;
    // //create a ref variable

    // int& j =i;
    // cout<<i<<endl;
    // i++;
    // cout<<i<<endl;
    // j++;
    // cout<<i<<endl;

    return 0;
}
