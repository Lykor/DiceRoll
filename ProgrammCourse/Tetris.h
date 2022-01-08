#pragma once
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
using namespace sf;
// ���� ������
class Game
{
public:
	Game();								// ����������� ��� ����������
	void draw(RenderWindow& window);	// ������� ������
	bool check();						// ������� �������� �������� � ����
private:
	int dx;								// ��������� �� x
	int colorNum;						// ����
	bool rotate;						// �������
	float timer;						// �����
	float delay;						// ��������
	char st[30];						// ������ ��� �������� �����
	Font font;							// �����
	Event event;						// �������
	Texture t1, t2;						// ��������
	Sprite s, background;				// ������ ���
	Clock clock;						// �����
};

