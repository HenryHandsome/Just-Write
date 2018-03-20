#include<iostream>
#include<string>
#include<cmath>
using namespace std;

char a[11], b[11];

int compare(char a[], char b[]) {
	if (strlen(a) == strlen(b)) {
		if ((strcmp(a, b)==0)) return 2;
		else {
			for (int i = 0; a[i] != '\0'&&b[i] != '\0'; i++)
				if (abs(a[i] - b[i]) == 32 || abs(a[i] - b[i]) == 0)
					continue;
				else return 4;
		}
	}
	else return 1;
	return 3;
}

int main() {
	cin >> a;
	cin >> b;
	cout << compare(a, b) << endl;
}
