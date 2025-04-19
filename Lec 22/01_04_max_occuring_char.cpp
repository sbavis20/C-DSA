#include<iostream>
using namespace std;

char maxOcc(string s){

    int arr[26]={0};

    for(int i = 0;i<s.length();i++){
        char ch = s[i];
        int number = 0;
        //lowercase
        if(ch>='a' && ch<='z'){
            number = ch -'a';
        }else{//uppercase
            number = ch - 'A';
        }
        arr[number]++;
    }

    int max = -1, ans = -1;
    for (int i = 0; i<26; i++){
        if(max < arr[i]){
            ans = i;
            max = arr[i];
        }
    }

    char finalAns = 'a' + ans;

    return finalAns;


}

int main(){

    string str;
    cin>>str;

    cout<< maxOcc(str)<< endl;



    return 0;
}
