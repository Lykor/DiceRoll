#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Intro.h"
#include "Info.h"
#include "Tetris.h"
#include "DiceRoll.h"
/*
3.6.11 - ИГРОВЫЕ ЗАДАЧИ
Разработать программу «тетрис»


3.4.4 - ЗВУКОГЕНЕРАЦИЯ, ГРАФИКА, ДВИЖЕНИЕ, МУЛЬТИПЛИКАЦИЯ
Разработать программму-генератор случайных чисел от 1 до 6. Выдачу числа производить на грани кубика (или вертушки).
Предусмотреть повторные бросания, вращение кубика (вертушки) и угадывание числа.
*/
using namespace sf;
int main() {
	// Создаем главное окно приложения
	srand(time(NULL)); // для генерация ислучайных значений
	HWND hWnd = GetConsoleWindow(); // получаем хэндл консоли
	ShowWindow(hWnd, SW_HIDE); // скрываем консоль
	RenderWindow window(VideoMode(1000, 500), "Course project by Zharkov V.Y."); // создание окна
	window.setKeyRepeatEnabled(false); // отключение повторения нажатия в окне
	window.setVerticalSyncEnabled(1); // включение вертикальной синхронизации
	window.setFramerateLimit(60); // ограничение кадров
	Menu menu(window.getSize().x, window.getSize().y); // создаем объект меню с указанием размеров окна в параметрах
	Game tetris; // создаем объект тетрис
	DiceRoll dice(window.getSize().x,window.getSize().y); // создаем объект игры с костями с указанием размеров окна в параметрах
	info about(window.getSize().x, window.getSize().y); // создаем объект информации об авторе, с передачей размеров окна
	int selectedMenu = 6; // переменная которая используется для переключение отрисовок 
	Intro intro(window.getSize().x, window.getSize().y); // создаем объект в котором описана заставка с передачей размеров окна
	int firstrun = 1; // переменная используемся для того, чтобы в начале выводилось интро, при первом запуске. Потом заставку можно включить нажав кнопку 0.
	while (window.isOpen()) {
		// Обрабатываем события в цикле
		Event event;
		while (window.pollEvent(event)) {
			// Кроме обычного способа наше окно будет закрываться по нажатию на Escape
			if (event.type == Event::Closed ||
				(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
				window.close();
			}
			// Если нажата правая кнопка мыши, то будет присвоено переменной для переключения отрисовки 6, что соотвествует отрисовку объекта "меню"
			if (Mouse::isButtonPressed(Mouse::Button::Right)) {
				selectedMenu = 6;
			}
			// аналогично, только теперь это реализовано с помощью клавиши Space
			if (Event::KeyPressed == event.type && event.key.code == Keyboard::Space) {
				selectedMenu = 6;
			}		
			
			// для экономии времени, можно переключать разделы программы с помощью цифр 0-1-2-3 (4 - это выход, поэтому нет смысла т.к. можно нажать на крестик)
			// 0 - заставка, 1 - кубик с 6 числами, 2 - тетрис, 3 - информация об авторе
			if (Event::KeyPressed == event.type && event.key.code == Keyboard::Num0) {
				selectedMenu = 0;
			}
			if (Event::KeyPressed == event.type && event.key.code == Keyboard::Num1) {
				selectedMenu = 1;
			}
			if (Event::KeyPressed == event.type && event.key.code == Keyboard::Num2) {
				selectedMenu = 2;
			}
			if (Event::KeyPressed == event.type && event.key.code == Keyboard::Num3) {
				selectedMenu = 3;
			}
		}
		// если это первый запуск, то первым на экране будет интро. В объекте цикл бесконечный, до нажатия кнопки Space или Правой кнопки мыши. 
		// После того как с того цикла произойдет выход, в заставку можно будет попасть только нажав на кнопку 0(ноль)
		if (firstrun) {
			firstrun--;
			intro.draw(window);
		}
		else {
			// Очистка		
			window.clear();
			// по переменной определяем что будет отрисовывак
			switch (selectedMenu) {
			case 0: intro.draw(window); // отрисовка интро
				break;
			case 1: dice.draw(window); // отрисовка игры с кубиком
				break;
			case 2: tetris.draw(window); // отрисовка игры тетрис
				break;
			case 3: about.draw(window); // отрисовка информации об авторе
				break;
			case 4: window.close(); // закрытие окна(завершение программы)
				break;
			default: menu.draw(window,&selectedMenu); // отрисовка в меню, по стандарту
				break;
			}
			// вывод на экран
			window.display();
		}
	}
	return 0;
}