#include<iostream>

using namespace std;

int main()
{
    int* arr=new int[18]{2,4,3,-6,-4,1,7,-2,6,4,-3,2,3,-9,-6,-4,4,8};

    int bsu=arr[0],bs=0,be=0,csu=arr[0],cs=0,ce=0;

    for(int i=1;i<18;i++)
    {
       if(arr[i]+csu<arr[i])
       {csu=arr[i];
        cs=i;
        ce=i;}
       else
       {
           csu+=arr[i];
           ce=i;
       }

       if(csu>bsu)
       {
           bsu=csu;
           bs=cs;
           be=ce;
       }
       
    }

    for(int i=bs;i<be;i++)
    cout<<arr[i]<<" + ";
    cout<<arr[be];
    cout<<" = "<<bsu;
}