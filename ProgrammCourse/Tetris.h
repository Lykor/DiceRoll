#pragma once
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
using namespace sf;
// игра Тетрис
class Game
{
public:
	Game();								// констурктор без параметров
	void draw(RenderWindow& window);	// главная функци
	bool check();						// функция проверки объектов в игре
private:
	int dx;								// изменение по x
	int colorNum;						// цвет
	bool rotate;						// поворот
	float timer;						// время
	float delay;						// ожидание
	char st[30];						// массив для хранения строк
	Font font;							// шрифт
	Event event;						// события
	Texture t1, t2;						// текстуры
	Sprite s, background;				// задний фон
	Clock clock;						// время
};

