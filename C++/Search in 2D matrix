/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
1) Integers in each row are sorted from left to right.
2) The first integer of each row is greater than the last integer of the previous row.
example -
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
Output: true
*/

#include<bits/stdc++.h>

bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m=matrix.size();

        if(m==0) return false;

        int n=matrix[0].size(),low =0,high= m-1,mid;

        if(n==0) return false;

        if(matrix[0][0] >target) return false;
        if(matrix[m-1][n-1]<target ) return false;

        while (low<=high){
            mid=(low+high)/2;

            if(matrix[mid][n-1]==target) return true;

            else if (matrix[mid][n-1] < target) low=mid+1;

            else high=mid-1;

            }


        if(matrix[mid][n-1] < target) mid+=1;
        if(mid-1>=0 && matrix[mid-1][n-1] >target )
            mid-=1;

        low=0; high =n-1;
        int mi;

         while (low<=high){
            mi=(low+high)/2;

            if(matrix[mid][mi]==target) return true;

            else if (matrix[mid][mi] < target) low=mi+1;

            else high=mi-1;

         }

         return false;

    }
