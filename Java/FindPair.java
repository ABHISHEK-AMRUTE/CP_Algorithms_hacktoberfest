/*
Given a list of numbers and a number k, 
            return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
*/

/*
  Input
  
    6             // n value
    1 4 45 6 10 8 // arr
    16            // k value
   

  Output
   
    True
    
*/


import java.io.*;
import java.util.*;

public class FindPair{

    public static void main(String args[])
    {

        Scanner sc=new Scanner(System.in);

        int n=sc.nextInt(); // size of input array

        int arr[]=new int[n];

        int k;

        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt(); //input array
        }

        k=sc.nextInt(); 

        //sort and applying two pointer approach
        Arrays.sort(arr);

        int left=0;

        int right=n-1;

        int flag=0;

        while(left<right)
        {
            if(arr[left]+arr[right] == k) // if pair exists inc flag and break
            {
                flag++;
                break;
            }

            else if(arr[left]+arr[right] > k) // if sum > k moving to next higher elt from right end
            {
                right--;
            }

            else                     
            {
                left++;
            }
        }
        
        if(flag==1)
            System.out.println(true);
        
        else
            System.out.println(false);

    }

}


/*
    Contributed by
      
        Pavan Kalyan Konudula

        SASTRA Deemed University
*/