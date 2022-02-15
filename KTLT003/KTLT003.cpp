#include <iostream>
using namespace std;
#define MAXN 1000
void input(int &n, int a[]) {
    cout << "n = "; cin >> n;
	for (size_t i = 0; i < n; i++)
		cin >> a[i];
}
void process(int n, int a[]) {
	bool passed = false;
	size_t i = 0, j = n-1;
	while (i != j && i + 1 != j && i != j - 1) {
		
		if (a[i] == a[j]) passed = true;
		else {
			passed = false;
			break;
		}
		i++;
		j--;
	}
	if (passed)
		cout << "Passed" << endl;
	else cout << "Failed" << endl;
}
int main()
{
	int n, a[MAXN];
	input(n, a);
	process(n, a);
}
