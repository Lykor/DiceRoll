#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
using namespace sf;
// ����� ��������
class Intro
{
public:
	Intro(float width, float height);	// �����������, ��������� - ������� ����
	void draw(RenderWindow& window);	// ������� ������� � ������ �������
private:
	float width;						// ������
	float height;						// ������
	int frame;							// ����
	int smooth;							// ���������� ��� �������� �������� �� y
	int inc;							// ���������� ������ ���������� smooth
	int dx;								// �������� �� x
	Texture spritesheet;				// �������� ������� � ��������
	Sprite object;						// ������ �������
	Font font;							// �����
	Text name;							// ��� ������������
};

