/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

link: https://leetcode.com/problems/reverse-integer/description/
*/
#include <iostream>
using namespace std;
class Solution {
    public:
        int reverse(int x) {
            int temp = 0;
            while(x!=0){
                temp = x%10 + temp*10;

                x = x/10;
                //cout<<temp<<endl;
                //cout<<x<<endl;
           }
            cout<<temp<<endl;
        }
    };

int main(){
    Solution s;
    int n =0;
    cin>>n;
    s.reverse(n);
}
