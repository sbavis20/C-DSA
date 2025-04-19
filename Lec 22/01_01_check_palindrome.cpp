#include<iostream>
using namespace std;

int getLength(char arr[]){
    int count = 0;
    for(int i = 0; arr[i]!='\0'; i++ ){
        count++;
    }

    return count;
}
char toLowercase(char ch){
    if(ch>='a' && ch <='z'){
        return ch;
    }else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool checkPlaindrome(char arr[],int l){
    int s =0;
    int e = l-1;

    while(s<=e){
        if(toLowercase(arr[s])!=toLowercase(arr[e])){
            return 0;
        }

        s++;
        e--;

    }
    return 1;
}

int main(){

    char name[10];
    cin>>name;


    int len = getLength(name);
    bool p = checkPlaindrome(name,len);

    if(p==1){
        cout<<"Palindrome"<<endl;
    }else{
        cout<<"Not Palindrome"<<endl;
    }

    return 0;
}
