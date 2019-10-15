// Cipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

string encryption(string plaintext, string key)
{
	string encrypted;
	int n = key.length();
	int textlength = plaintext.length();
	double temp = static_cast<double>(textlength) / n;
	cout << temp << endl;
	int modulo = textlength % n;
	int m = ceil(temp);
	int t = m - 1;
	char* tab = NULL;
	tab = new char[n];
	char** tablica = new char*[m];
	for (int i = 0; i < m; i++)
		tablica[i] = new char[n];
	cout << n << " " << textlength << " " << m <<" " << modulo << endl;
	//wpisywanie tekstu do tablicy
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != t)
			{
				tablica[i][j] = plaintext[i*n + j];
				
			}
			else if(i==t && j<modulo)
			{
				tablica[i][j] = plaintext[i*n + j];
			}
			else
			{
				tablica[i][j] = 'x';
			}
			cout << tablica[i][j];
		}
		cout << endl;
	}
	//wpisywanie klucza do tablicy
	for (int i = 0; i < n; i++)
	{
		int min = key[0];
		int index = 0;
		for (int j = 0; j < n; j++)
		{
			if (min > key[j])
			{
				min = key[j];
				index = j;
			}
		}
		tab[i] = index;
		key[index] =125;
	}
	int k;
	//wpisywanie zaszyfrowanego tekstu do stringa
	for (int i = 0; i < n; i++)
	{
		k = tab[i];
		for (int j = 0; j < m; j++)
		{
			if (k >= 0)
			{
				encrypted += tablica[j][k];
				k--;
			}
			else
			{
				k = n-1;
				encrypted += tablica[j][k];
				k--;
			}
		}
	}

	return encrypted;
}

string decrytption(string encrypted, string key)
{
	string decrypted;
	int n = key.length();
	int textlength = encrypted.length();
	double temp = static_cast<double>(textlength) / n;
	cout << temp << endl;
	int modulo = textlength % n;
	int m = ceil(temp);
	int t = m - 1;
	char* tab = NULL;
	tab = new char[n];
	char** tablica = new char*[m];
	for (int i = 0; i < m; i++)
		tablica[i] = new char[n];
	cout << n << " " << textlength << " " << m << " " << modulo << endl;
	//wpisywanie klucza do tablicy
	for (int i = 0; i < n; i++)
	{
		int min = key[0];
		int index = 0;
		for (int j = 0; j < n; j++)
		{
			if (min > key[j])
			{
				min = key[j];
				index = j;
			}
		}
		tab[i] = index;
		key[index] = 125;
	}
	int k;
	//wpisywanie zakodowanego tekstu do tablicy
	int licznik = 0;
	for (int i = 0; i < n; i++)
	{
		k = tab[i];
		for (int j = 0; j < m; j++)
		{
			if (k > -1)
			{
				tablica[j][k] = encrypted[licznik++];
				k--;
			}
			else
			{
				k = n - 1;
				tablica[j][k] = encrypted[licznik++];
				k--;
			}
		}

	}
	//wyswietlanie tablicy z tekstem
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << tablica[i][j];
		}
		cout << endl;
	}
	//wpisywanie odszyfrowanego tekstu do stringa

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < t)
			{
				decrypted += tablica[i][j];
			}
			else
			{
				if (tablica[i][j] == 'x')
				{
					break;
				}
				else
				{
					decrypted += tablica[i][j];
				}
			}
		}
	}
	return decrypted;
}

int main()
{
	//regex [A-Za-z0-9 _.,!"'/$]*
	string plaintext, encrypted, decrypted, key;
	key = "maroko";
	std::cout << "Podaj swoj tekst"<<endl;
	std::cin >> plaintext;
	encrypted = encryption(plaintext, key);
	std::cout << "Zakodowany tekst " << endl;
	std::cout << encrypted << endl;
	decrypted = decrytption(encrypted, key);
	std::cout << "Zdekodowany tekst " << endl;
	std::cout << decrypted << endl;
}