// NAME : Yashi Srivastava
// COLLEGE: VIT Chennai

#include <iostream>
using namespace std;
void KMP(string X, string Y)
{
	int m = X.length();
	int n = Y.length();

if (n == 0)
	{
		cout << "Pattern occurs with shift 0";
		return;
	}

	if (m < n)
	{
		cout << "Pattern not found";
		return;
	}

	int next[n + 1];

	for (int i = 0; i < n + 1; i++)
		next[i] = 0;

	for (int i = 1; i < n; i++)
	{
		int j = next[i + 1];

		while (j > 0 && Y[j] != Y[i])
			j = next[j];

		if (j > 0 || Y[j] == Y[i])
			next[i + 1] = j + 1;
	}

	for (int i = 0, j = 0; i < m; i++)
	{
		if (X[i] == Y[j])
		{
			if (++j == n)
				cout << "Pattern occurs with shift " << i - j + 1 << endl;
		}
		else if(X[i]!=Y[j])
		{
			cout<<"Error pattern"<<endl;
		}
		else if (j > 0) {
			j = next[j];
			i--;	// since i will be incremented in next iteration
		}
	}
}

int main()
{
	string text,pattern;
	cout<<"Enter your text :"<<endl;
	cin>>text;
	cout<<"Enter your pattern :"<<endl;
	cin>>pattern;
	/*string text = "COCOCOLA";
	string pattern = "COLA";*/

	KMP(text, pattern);
}
