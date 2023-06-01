#include<iostream>
#include<string.h>

using namespace std;
const int mx = 1000;
struct stack{
    int arr[mx];
    int top;
};

void constructor(stack& t){
    t.top = -1;
}

bool empty(stack& t){
    return (t.top == -1);
}

bool full(stack& t){
    return (t.top == mx -1);
}

int add(stack& t, int element){
    if(!full(t)){
        t.arr[++t.top] = element;
        return 1;
    }
    else return 0;
}

int remove(stack& t){
    if(!empty(t)){
        --t.top;
        return 1;
    }
    else    return 0;
}

int pop(stack& t){
    if(!empty(t)){
        int elem = t.arr[t.top];
        --t.top;
        return elem;
    }
    else return 0;
}
void convert_into_bin(stack& t, int N){
    constructor(t);
    while(N>0&&add(t, N%2))
        N/=2;
}

void display(stack& t){
    while(!empty(t)){
        cout<<pop(t);
    }
}

int main(){
    stack t;
    constructor(t);
    convert_into_bin(t,256);
    display(t);
}