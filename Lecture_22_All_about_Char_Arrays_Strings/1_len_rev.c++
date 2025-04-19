#include<iostream>
using namespace std;

void reverse(char name[],int n){
    int s =0;
    int e=n-1;
    while(s<e){
        swap(name[s++],name[e--]);
    }
}

int length(char name[]){
    int cnt=0;
    for(int i=0;name[i]!='\0';i++){
        cnt++;
    }

    return cnt;
}

int main(){
    char name[20];
    cin>>name;

    int len = length(name);
    cout<<"Length= "<<len<<endl;

    reverse(name,len);
    cout<<name;


    return 0;
}
