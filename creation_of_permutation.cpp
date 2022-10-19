#include <bits/stdc++.h>

using namespace std;

//Display elements of the array
void display(vector<int> a, int n){
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
}

int main()
{
    //Obtaining length of array
    int n;
    cin >> n;

    //Declaring a vector of integers
    vector<int> a(n);
    
    //Taking input of array of integers
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    do{
        //Display the current permutation
        display(a, n);
    }while(next_permutation(a.begin(), a.end())); //Generate next permutation till it is not lexicographically largest

    return 0;
}
