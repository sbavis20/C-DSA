#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Queue {
  int* arr;
  int qfront;
  int rear;
  int size;

public:
    Queue() {
      size =100000;
      arr=new int[size];
      qfront =0;
      rear =0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront==rear){
          return true;
        }else{
          return false;
        }
    }

    void enqueue(int data) {
        if(rear==size){
          cout<<"Queue is full"<<endl;
        }else{
          arr[rear]=data;
          rear++;
        }
    }

    int dequeue() {
        if(qfront==rear){
          return -1;
        }else{
          int ans = arr[qfront];
          arr[qfront]=-1;
          qfront++;
          if(qfront==rear){
            qfront=0;
            rear=0;
          }
          return ans;
        }
    }

    int qfront() {
        if(qfront==rear){
          return -1;
        }else{
        return  arr[qfront];
        }
    }
};


int main(){



  return 0;
}
