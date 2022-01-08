#pragma once
#include "SFML/Graphics.hpp"
const int max_items = 4;									// ������������ ���������� ������ � ����
using namespace sf;
// ����� ����
class Menu
{
public:
	Menu(float width, float height);						// �����������
	void draw(RenderWindow& window,int* selectedMenu);		// ������� ������� � �������
private:
	float width;											// ������
	float height;											// ������							
	Font font;												// �����
	Text menutext[max_items];								// �����
	Texture bgtexture;										// �������� ������� ����
	Sprite bgsprite;										// ������ ������� ����
};

