"""
Name: Sreejan Chaudhury
College Name: University of Calcutta
"""

# To access a range of characters in the String, method of slicing is used. Slicing in a String is done by using a Slicing operator (colon)

# Python Program to 
#demonstrate String slicing 
  
# Creating a String 
String1 = "GeeksForGeeks"
print("Initial String: ")  
print(String1) 
  
# Printing 3rd to 12th character 
print("\nSlicing characters from 3-12: ") 
print(String1[3:12]) 
  
# Printing characters between  
# 3rd and 2nd last character 
print("\nSlicing characters between " +
    "3rd and 2nd last character: ") 
print(String1[3:-2]) 

"""
Output:

Initial String: 
GeeksForGeeks

Slicing characters from 3-12: 
ksForGeek

Slicing characters between 3rd and 2nd last character: 
ksForGee

"""
