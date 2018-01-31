// matrixChains.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void print(int s[5][5], int i, int j) {
	if (i == j)
		cout << "A" << i;
	else {
		cout << "(";
		print(s, i, s[i][j]);
		print(s, s[i][j] + 1, j);
		cout << ")";
	}
}

int main()
{
	int j, l;
	int p[5] = { 5, 10, 2, 7, 3 };
	int n = 5;
	int m[5][5];
	int s[5][5];
	for (int i = 1; i < 5; i++)    //This loops on the rows.
	{
		for (int j = 1; j < 5; j++) //This loops on the columns
		{
			s[i][j] = 0;
		}
	}
	for (int i = 1; i < n; i++) {
		m[i][i] = 0;
	}
	for (l = 2; l < n; l++) {
		for (int i = 1; i < n - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++) {
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	
	cout << "m table:\n";
	for (int i = 1; i < 5; i++)    //This loops on the rows.
	{
		for (int j = 1; j < 5; j++) //This loops on the columns
		{
			cout << m[i][j] << "  ";
		}
		cout << endl;
	}

	cout << "\ns table:\n";
	for (int i = 1; i < 5; i++)    //This loops on the rows.
	{
		for (int j = 1; j < 5; j++) //This loops on the columns
		{
			cout << s[i][j] << "  ";
		}
		cout << endl;
	}
	
	cout << "\noptimal parens: ";
	print(s, 1, n-1);
	cout << endl;
	return 0;
}

