#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
// ����� ���������� �� ������
class info
{
public:
	info(float width, float height);	// �����������, ��������� - ������� ����(������,������)
	void draw(RenderWindow& window);	// ������� �������, ��������� - ����, ������� � ������������ ��� ������
private:
	Font font;							// � ������ ���������� �������� ����� ��� ������ ������������� �����
	Text textabout[2];					// ������ �� ���� ��������� ����������
};



