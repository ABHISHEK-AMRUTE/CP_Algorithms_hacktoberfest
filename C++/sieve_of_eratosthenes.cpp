/* Ravi Kishor
   KCC Institute of Technology and Management
*/

#include <bits/stdc++.h>
#include <iostream>
#define endl "\n"
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

void sieveOfEratosthenes(int n)
{

    bool isPrime[n + 1];
    memset(isPrime, 1, sizeof(isPrime));

    for (int p = 2; p * p <= n; p++)
    {
        // If isPrime[p] is not changed, then it is a prime number
        if (isPrime[p] == 1)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already marked in isPrime array.
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = 0;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (isPrime[p])
            cout << p << " ";
}

int main()
{
    FAST;
    int n;
    cin >> n;
    cout << "The prime numbers smaller than or equal to " << n << " are: ";
    sieveOfEratosthenes(n);
    return 0;
}
