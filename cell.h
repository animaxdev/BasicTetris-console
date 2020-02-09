#pragma once

#include <Windows.h>
#include <windows.h>
#include <iostream>

using namespace std;

BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;

	return SetConsoleTextAttribute(hConsole, wAttributes);
}

class Cell
{
public:
	Cell() { }
	Cell(int xx, int yy, int c = 0) {  }
	void setXY(int i, int j)
	{
		x = i; y = j;
	}
	void setColor(int a)
	{
		color = a;
	}
	bool validity()//�������Ϸ�������1�����򷵻�0
	{
		if (x == 24 || y == 0 || y == 11) return false;//�Ƿ����Χ��⣻
		if (color != 0)return false;		//����validity��⣻
		return true;//����ͨ������ò����Ϸ���
	}
	void print()
	{
		SetConsoleColor(color);
		cout << "��";
		SetConsoleColor(0);
	}
	bool Left()
	{
		x--;
		return true;
	}
	bool Right()
	{
		x++;
		return true;
	}
	bool Drop()
	{
		y++;
		return true;
	}
	//private:
	int x = 0;
	int y = 0;
public:
	int color = 0;
	friend class Tetris;
	friend class Space;
	friend class Tetris_I;
};
