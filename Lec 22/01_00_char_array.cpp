#include<iostream>
using namespace std;

int getLength(char arr[]){
    int count = 0;
    for(int i = 0; arr[i]!='\0'; i++ ){
        count++;
    }

    return count;
}

void reverse(char arr[],int l){
    int s = 0;
    int e = l-1;

    while(s<=e){
        swap(arr[s],arr[e]);
        s++;
        e--;
        //or swap(arr[s++],arr[e--]);
    }

    cout<<"Reverse: "<<arr<<endl;

}

int main(){

    // char a ='z'; //limitation can only store one character what if we have have tos tore more

    // char arr[10]= {'n','a','r','u','t','o'};

    // cout<<arr<<endl;


    char name[10];
    cout<<"Enter ur name: "<<endl;
    cin>>name;

    cout<<name<<endl;

    /*cin will stop execution when it sees space , tab '\t', new line '\n'*/

//    name[3] = '\0'; //forcefully add null char at index 3 so it will only print till index 2

    int len = getLength(name);

    cout<<"Length: " <<len<<endl;

    reverse(name,len);














    return 0;
}
