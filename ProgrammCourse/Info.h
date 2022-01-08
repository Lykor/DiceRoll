#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
// класс информации об авторе
class info
{
public:
	info(float width, float height);	// конструктор, параметры - размеры окна(ширина,высота)
	void draw(RenderWindow& window);	// главная функция, параметры - окно, которое и используется для вывода
private:
	Font font;							// в данной переменной хранится шрифт для текста используемого далее
	Text textabout[2];					// массив из двух текстовых переменных
};



