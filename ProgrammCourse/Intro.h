#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
using namespace sf;
// класс заставки
class Intro
{
public:
	Intro(float width, float height);	// конструктор, параметры - размеры окна
	void draw(RenderWindow& window);	// главная функция в данном объекте
private:
	float width;						// ширина
	float height;						// высота
	int frame;							// кадр
	int smooth;							// переменная для плавного движения по y
	int inc;							// регулирует размер переменной smooth
	int dx;								// смещение по x
	Texture spritesheet;				// текстура объекта в движении
	Sprite object;						// спрайт объекта
	Font font;							// шрифт
	Text name;							// имя разработчика
};

