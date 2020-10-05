#include <iostream>

using namespace std;

int **input(int r, int c)
{
  cout << "hello" << r << " - " << c;
  int **arr = new int *[r];
  for (int i = 0; i < r; i++)
  {
    arr[i] = new int[c];
    for (int j = 0; j < c; j++)
    {
      cout << "Enter the value for the cell " << i << " , " << j << endl;
      cin >> arr[i][j];
    }
  }
  return arr;
}

int main(int argc, char **argv)
{

  int **arr;
  int r1, c1;
  cout << "Enter the no. of rows and columns for matrix 1" << endl;
  cin >> r1 >> c1;

  arr = input(r1, c1);

  int **brr;
  int r2, c2;
  cout << "Enter the no. of rows and columns for matrix 1" << endl;
  cin >> r2 >> c2;

  brr = input(r2, c2);
  for (int i = 0; i < r2; i++)
  {
    for (int j = 0; j < c2; j++)
      cout << brr[i][j] << " ";

    cout << endl;
  }

  int **crr = new int *[r1];
  for (int i = 0; i < r1; i++)
  {
    crr[i] = new int[c2];
  }

  if (c1 != r2)
    cout << " Cannot be multiplied";

  else
  {
    for (int i = 0; i < r1; i++)
      for (int j = 0; j < c2; j++)
        for (int k = 0; k < c1; k++)
        {
          crr[i][j] = 0; 
          crr[i][j] += arr[i][k] * brr[k][j];
        }

    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c2; j++)
        cout << crr[i][j] << " ";

      cout << endl;
    }
  }
}