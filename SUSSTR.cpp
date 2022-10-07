#include <iostream>

using namespace std;

int main() {
	// your code goes here
    int meranumber;
	cin >> meranumber;
	for(int i =0; i < meranumber; i++){
        int temp;
        cin>>temp;
        string testkarunga;
        cin>> testkarunga;
        string nayastring="";
        int x=0;
        int y=temp-1;
        while(x<=y){
            if(testkarunga[x]=='0'){
                nayastring=testkarunga[x]+nayastring;
            }
            else
            nayastring=nayastring+testkarunga[x];
            if(x<y){
                if(testkarunga[y]=='0')
                nayastring=nayastring+testkarunga[y];
                else
                nayastring=testkarunga[y]+nayastring;
                y--;
            }
            x++;
        }
        cout<<nayastring<<endl;
    }
	
	
	
	
	return 0;
}
