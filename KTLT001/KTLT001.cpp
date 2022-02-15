#include <iostream>
#include <stdlib.h>

#define MAXN 100

using namespace std;

void input(int &n, int &k, int a[]) {
	cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;
	cout << "Enter " << n << " integers: " << endl;
	for (size_t i = 0; i < n; i++)
		cin >> a[i];
}

void process(int n, int k, int a[]) {
	cout << "Result: " << endl;
	for (size_t i = 0; i < n-1; i++)
	{
		for (size_t j = i+1; j < n; j++)
		{
			if (a[i] + a[j] == k) {
				cout << a[i] << " " << a[j] << endl;
			}
		}
	}
}

int main()
{
	int n, k, a[MAXN];
	input(n, k, a);
	process(n, k, a);
    return 0;
}