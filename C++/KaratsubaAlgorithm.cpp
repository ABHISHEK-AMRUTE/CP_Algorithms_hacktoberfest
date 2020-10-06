/*Name:Aditya Srivastava
College:DAIICT*/
#include<bits/stdc++.h>
#include <cmath>
using namespace std;

int LengthPowerofTwoandEqual(string &num1, string &num2) 
{ 
	if(num1.size()>num2.size())
	{
            int diff = num1.size()-num2.size();
            int size = num1.size();

            while(diff!=0)
            {
                num2 = '0' + num2;
                diff--;
            }
            for(int i=size;ceil(log2(i))!=floor(log2(i));i++)
            {
                num2 = '0' + num2;
                num1 = '0' + num1;
            }
             return num2.size();
    }
	else if(num2.size()>num1.size())
	{
            int diff = num2.size()-num1.size();
            int size = num2.size();
            while(diff!=0)
            {
                num1 = '0' + num1;
                diff--;
            }
            for(int i=size;ceil(log2(i))!=floor(log2(i));i++)
            {
                num2 = '0' + num2;
                num1 = '0' + num1;
            }
            return num2.size();
    }
    else
    {
        int size = num2.size();
        for(int i=size;ceil(log2(i))!=floor(log2(i));i++)
            {
                num2 = '0' + num2;
                num1 = '0' + num1;
            }
             return num2.size();
    }
} 


string BinaryStringAddition(string num1, string num2)
{
    
    
    int size = LengthPowerofTwoandEqual(num1,num2); //To retrieve the length
    int cry = 0,i;
    string finaladd;
    for ( i = size-1 ; i >= 0 ; i--)
    {
        int num1B = num1[i] - 48;
        int num2B = num2[i] - 48;
        int bitadd = (num1B + num2B + cry)%2 + 48; 
        if((num1B + num2B + cry) >= 2) 
        {
            cry = 1;
        }
        else 
        {
            cry = 0;
        }   
  	     	finaladd = (char)bitadd + finaladd; 
    }
    
     if(cry)
     {
          return '1' + finaladd;
     }   
     else
     {
       return finaladd;
     }
}
long int karatsubamult(string number1,string number2)
{
        int n = LengthPowerofTwoandEqual(number1, number2); 
        if(n==1)
        {
            return (number1[0] - 48)*(number2[0] - 48);
        }
        if(n==0)
        {
            return 0;
        }
       
        string a = number1.substr(0, n/2); //(starting point,length)
        string b = number1.substr(n/2);
        string c = number2.substr(0, n/2);
        string d = number2.substr(n/2);
        long int ac = karatsubamult(a,c);
        long int bd = karatsubamult(b,d);
        string g=BinaryStringAddition(a,b); //for binary addition of a and b.
        string h=BinaryStringAddition(c,d);
        long int e = karatsubamult(g,h);
        return ac*pow(2,n) + (e - ac - bd)*pow(2,n/2) + bd; 
}
int main() 
{
	  string s1,s2;
	  cin>>s1;
	  cin>>s2;
	  cout << karatsubamult(s1,s2);
	  return 0;
}
