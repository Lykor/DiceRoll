#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Intro.h"
#include "Info.h"
#include "Tetris.h"
#include "DiceRoll.h"
/*
3.6.11 - ������� ������
����������� ��������� �������


3.4.4 - ��������������, �������, ��������, ��������������
����������� ����������-��������� ��������� ����� �� 1 �� 6. ������ ����� ����������� �� ����� ������ (��� ��������).
������������� ��������� ��������, �������� ������ (��������) � ���������� �����.
*/
using namespace sf;
int main() {
	// ������� ������� ���� ����������
	srand(time(NULL)); // ��� ��������� ���������� ��������
	HWND hWnd = GetConsoleWindow(); // �������� ����� �������
	ShowWindow(hWnd, SW_HIDE); // �������� �������
	RenderWindow window(VideoMode(1000, 500), "Course project by Zharkov V.Y."); // �������� ����
	window.setKeyRepeatEnabled(false); // ���������� ���������� ������� � ����
	window.setVerticalSyncEnabled(1); // ��������� ������������ �������������
	window.setFramerateLimit(60); // ����������� ������
	Menu menu(window.getSize().x, window.getSize().y); // ������� ������ ���� � ��������� �������� ���� � ����������
	Game tetris; // ������� ������ ������
	DiceRoll dice(window.getSize().x,window.getSize().y); // ������� ������ ���� � ������� � ��������� �������� ���� � ����������
	info about(window.getSize().x, window.getSize().y); // ������� ������ ���������� �� ������, � ��������� �������� ����
	int selectedMenu = 6; // ���������� ������� ������������ ��� ������������ ��������� 
	Intro intro(window.getSize().x, window.getSize().y); // ������� ������ � ������� ������� �������� � ��������� �������� ����
	int firstrun = 1; // ���������� ������������ ��� ����, ����� � ������ ���������� �����, ��� ������ �������. ����� �������� ����� �������� ����� ������ 0.
	while (window.isOpen()) {
		// ������������ ������� � �����
		Event event;
		while (window.pollEvent(event)) {
			// ����� �������� ������� ���� ���� ����� ����������� �� ������� �� Escape
			if (event.type == Event::Closed ||
				(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
				window.close();
			}
			// ���� ������ ������ ������ ����, �� ����� ��������� ���������� ��� ������������ ��������� 6, ��� ������������ ��������� ������� "����"
			if (Mouse::isButtonPressed(Mouse::Button::Right)) {
				selectedMenu = 6;
			}
			// ����������, ������ ������ ��� ����������� � ������� ������� Space
			if (Event::KeyPressed == event.type && event.key.code == Keyboard::Space) {
				selectedMenu = 6;
			}		
			
			// ��� �������� �������, ����� ����������� ������� ��������� � ������� ���� 0-1-2-3 (4 - ��� �����, ������� ��� ������ �.�. ����� ������ �� �������)
			// 0 - ��������, 1 - ����� � 6 �������, 2 - ������, 3 - ���������� �� ������
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
		// ���� ��� ������ ������, �� ������ �� ������ ����� �����. � ������� ���� �����������, �� ������� ������ Space ��� ������ ������ ����. 
		// ����� ���� ��� � ���� ����� ���������� �����, � �������� ����� ����� ������� ������ ����� �� ������ 0(����)
		if (firstrun) {
			firstrun--;
			intro.draw(window);
		}
		else {
			// �������		
			window.clear();
			// �� ���������� ���������� ��� ����� �����������
			switch (selectedMenu) {
			case 0: intro.draw(window); // ��������� �����
				break;
			case 1: dice.draw(window); // ��������� ���� � �������
				break;
			case 2: tetris.draw(window); // ��������� ���� ������
				break;
			case 3: about.draw(window); // ��������� ���������� �� ������
				break;
			case 4: window.close(); // �������� ����(���������� ���������)
				break;
			default: menu.draw(window,&selectedMenu); // ��������� � ����, �� ���������
				break;
			}
			// ����� �� �����
			window.display();
		}
	}
	return 0;
}