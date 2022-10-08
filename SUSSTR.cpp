#include <iostream>

using namespace std;

int main() {
	// your code goes here
    int number;
	cin >> number;
	for(int i =0; i < number; i++){
        int temp;
        cin>>temp;
        string test;
        cin>> test;
        string newstring="";
        int x=0;
        int y=temp-1;
        while(x<=y){
            if(test[x]=='0'){
                newstring=test[x]+newstring;
            }
            else
            newstring=newstring+test[x];
            if(x<y){
                if(test[y]=='0')
                newstring=newstring+test[y];
                else
                newstring=test[y]+newstring;
                y--;
            }
            x++;
        }
        cout<<newstring<<endl;
    }
	
	
	
	
	return 0;
}
