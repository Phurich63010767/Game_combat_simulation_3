#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<conio.h>

using namespace std;
void attack(int s, int b, int i, int l, int h[], int v, int c, int g)
{
	int at[10] = { 20, 25 , 30 }, * a;
	a = &at[v];
	for (int i = 0; i < 10; i++)
	{
		s = (rand() % 100) + 1;
	}
	if (s <= b)
	{
		cout << "Enemy blocked your attack!" << endl;
		goto BLOCK;
	}
	for (int i = 0; i < 10; i++)
	{
		l = (rand() % 100) + 1;
	}
	if (l <= c)
	{
		h[v] = h[v] - (*a * 2);
		cout << "You critical attacked!" << endl;
	}
	else
	{
		h[v] = h[v] - *a;
		cout << "You attacked!" << endl;
	}
BLOCK:
	Sleep(1200);
	system("CLS");
}

void fireball(int h[], int v, int m)
{
	h[v] = h[v] - m;
	cout << "You use Fire ball!" << endl;
	Sleep(1200);
	system("CLS");
}

void ultimate(int g, int h[], int v, int r)
{
	if (g < 100)
	{
		cout << "Can not use ultimate while gauge is under 100 %." << endl;
	}
	else
	{
		h[v] = h[v] - r;
		cout << "You use Ultimate!" << endl;
	}
	Sleep(1200);
	system("CLS");
}

int main()
{
	srand(time(0));
	int  c, l, b, s, v = 0, i, m, r, g;
	int h[10] = { 100,150,175 };
	int at[10] = { 20, 25 , 30 };
	int* a;
	m = 15;
	c = 30;
	b = 25;
	v = 0;
	i = 0;
	r = 60;
	g = 0;
	s = (rand() % 100) + 1;
	l = (rand() % 100) + 1;
START:system("CLS");
	a = &at[v];
	cout << "Attack: " << *a << "                                                             " << "Monster HP: " << h[v] << " Level: " << v + 1 << endl;
	cout << "Critical chance: " << c << " %" << "                                                  " << "Monster block chance: " << b << " %" << endl;
	cout << "Press Spacebar to attack." << endl;
	cout << "Press Q to cast Fire ball. " << endl;
	cout << "Fie ball deal 15 damage. Can't be blocked but can't critical." << endl;
	cout << "Press R to use Ultimate." << endl;
	cout << "Ultimate deal 60 damage. Can't be blocked but can't critical." << endl;
	cout << "Ultimate gauge: " << g << " %" << endl;
	cout << "Attack to gain ultimate gauge." << " Can use ultimate when gauge is 100 %." << endl;
	char ch = _getch();
	do
	{
		if (ch == 32)
		{
			attack(s, b, i, l, h, v, c, g);
			if (g < 100)
			{
				g = g + 20;
			}

			fflush(stdin);
		}
		if (ch == 113)
		{
			fireball(h, v, m);

			fflush(stdin);
		}
		if (ch == 114)
		{
			ultimate(g, h, v, r);
			if (g == 100)
			{
				g = g - 100;
			}

			fflush(stdin);
		}
		if (h[v] > 0) {
			goto START;
		}
		if (h[v] <= 0) {
			goto END;
		}
		else
		{
			goto START;
		}

	} while (ch != 'x');
END:
	v++;
	if (v < 3)
	{
		goto START;
	}
	cout << "You win!" << endl;
	system("pause");
	return 0;
}