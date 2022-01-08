#pragma once
#include "SFML/Graphics.hpp"
const int max_items = 4;									// максимальное количество выбора в меню
using namespace sf;
// класс меню
class Menu
{
public:
	Menu(float width, float height);						// конструктор
	void draw(RenderWindow& window,int* selectedMenu);		// главная функция в объекте
private:
	float width;											// ширина
	float height;											// высота							
	Font font;												// шрифт
	Text menutext[max_items];								// текст
	Texture bgtexture;										// текстура заднего фона
	Sprite bgsprite;										// спрайт заднего фона
};

