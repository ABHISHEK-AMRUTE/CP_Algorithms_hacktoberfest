#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int size1 , size2 ;
	cin >> size1;
	vector <long long int> arr1 (size1);
	for(long long int k = 0 ; k< size1 ; k++){
		cin >> arr1[k];
	}
	cin >> size2;
	vector <long long int> arr2 (size2);
	for(long long int k = 0 ; k< size2 ; k++){
		cin >> arr2[k];
	}
	long long int i , j ;
	long long int table[size2+1][size1+1];
	for(i = -1 ; i< size2 ; i++){
			for(j = -1 ; j < size1 ;j++){
	           if( i == -1 || j == -1){
	        	   table[i+1][j+1] = 0;
	           }
	           if (i != -1 && j!= -1 && arr2[i] == arr1[j]){
	        	   table[i+1][j+1] = table[i][j] + 1 ;
	           }
	           if(i != -1 && j!= -1 && arr2[i] != arr1[j]){
	        	   table[i+1][j+1] = max (table[i][j+1] , table[i+1][j]);
	           }
			}
		}
		cout << table[i][j];
	return 0;
}