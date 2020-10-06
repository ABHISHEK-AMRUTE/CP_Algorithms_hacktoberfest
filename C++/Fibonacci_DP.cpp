//Implementation of the fibonacci of the number in cpp.
#include<iostream>
using namespace std;

int fibo(int num){
    int *ans = new int[num+1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2 ;i <= num ; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[num];
}

int main(){
    int num;
    cout<<"Enter the value of num  ";
    cin>>num;
    cout<<"The fibonacci of the number "<<num<<" is "<<fibo(num)<<endl;
}
