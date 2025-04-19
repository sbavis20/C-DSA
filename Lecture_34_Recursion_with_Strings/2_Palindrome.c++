#include<iostream>
using namespace std;

bool isPalindrome(string str,int i, int j){
    //base condition
    if(i>j){
        return true;
    }

    if(str[i]!=str[j]){
        return false;
    }else{
        return isPalindrome(str,i+1,j-1);
    }

}

int main(){

    string s = "test";

    bool check = isPalindrome(s,0,s.length()-1);
    if(check){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }


    return 0;
}
