#include "stdafx.h"
#include "TheseRomans.h"

#include <iostream>
#include <fstream>
#include <iomanip> 


TheseRomans::TheseRomans(std::string fileName)
{
	//std::cout << fileName << std::endl;
	std::ifstream input(fileName);
	auto cinbuf = std::cin.rdbuf(input.rdbuf());
	std::cin >> rom1 >> rom2;
	std::cin.ignore();
	num1 = romanToInt(rom1);
	num2 = romanToInt(rom2);
	sum = num1 + num2;

}


int TheseRomans::value(char v)
{
	switch (v)
	{
	case 'I':return 1;
	case 'V':return 5;
	case 'X':return 10;
	case 'L':return 50;
	case 'C':return 100;
	case 'D':return 500;
	case 'M':return 1000;
	}
}

int TheseRomans::romanToInt(std::string romanStr)
{
	int i, n, ans = 0, p = 0;

	n = romanStr.length() - 1;

	for (i = n; i >= 0; i--)
	{
		if (value(romanStr[i]) >= p)
			ans += value(romanStr[i]);
		else
			ans -= value(romanStr[i]);

		p = value(romanStr[i]);

	}

	return ans;
}

int TheseRomans::digitHelper(char num1, char num2, int i, char *c)
{
	c[i++] = num1;
	c[i++] = num2;
	return i;
}

int TheseRomans::digit(char ch, int n, int i, char *c)
{
	for (int j = 0; j < n; j++)
		c[i++] = ch;
	return i;
}

void TheseRomans::print(int num)
{
	char c[10001];
	int i = 0;


	while (num != 0)
	{
		if (num >= 1000)
		{
			i = digit('M', num / 1000, i, c);
			num = num % 1000;
		}

		else if (num >= 500)
		{
			if (num < 900)
			{
				i = digit('D', num / 500, i, c);
				num = num % 500;
			}
			else
			{
				i = digitHelper('C', 'M', i, c);
				num = num % 100;
			}
		}
		else if (num >= 100)
		{
			if (num < 400)
			{
				i = digit('C', num / 100, i, c);
				num = num % 100;
			}
			else
			{
				i = digitHelper('C', 'D', i, c);
				num = num % 100;
			}
		}
		else if (num >= 50)
		{
			if (num < 90)
			{
				i = digit('L', num / 50, i, c);
				num = num % 50;
			}
			else
			{
				i = digitHelper('X', 'C', i, c);
				num = num % 10;
			}
		}
		else if (num >= 10)
		{
			if (num < 40)
			{
				i = digit('X', num / 10, i, c);
				num = num % 10;
			}
			else
			{
				i = digitHelper('X', 'L', i, c);
				num = num % 10;
			}
		}
		else if (num >= 5)
		{
			if (num < 9)
			{
				i = digit('V', num / 5, i, c);
				num = num % 5;
			}
			else
			{
				i = digitHelper('I', 'X', i, c);
				num = 0;
			}
		}
		else if (num >= 1)
		{
			if (num < 4)
			{
				i = digit('I', num, i, c);
				num = 0;
			}
			else
			{
				i = digitHelper('I', 'V', i, c);
				num = 0;
			}
		}
	}
	for (int j = 0; j < i; j++)
		std::cout << c[j];
}

void TheseRomans::Execute()
{
	std::cout << "La somma tra " << rom1 << "(" << num1 << ")" << " e " << rom2 << "(" << num2 << ")" << " e' pari a: ";
	print(sum);
	std::cout << "(" << sum << ")" << std::endl;
}
