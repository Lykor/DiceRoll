
#include "Menu.h"

Menu::Menu(float width, float height) {
	font.loadFromFile("../19888.ttf");

	this->width = width;
	this->height = height;

	menutext[0].setFont(font);
	menutext[0].setFillColor(Color::White);
	menutext[0].setString(L"Dice Roll");
	menutext[0].setPosition(Vector2f((width / 2) + 200, height / 5 * 1));

	menutext[1].setFont(font);
	menutext[1].setFillColor(Color::White);
	menutext[1].setString(L"Tetris");
	menutext[1].setPosition(Vector2f((width / 2) + 200, height / 5 * 2));

	menutext[2].setFont(font);
	menutext[2].setFillColor(Color::White);
	menutext[2].setString(L"Author");
	menutext[2].setPosition(sf::Vector2f((width / 2) + 200, height / 5 * 3));

	menutext[3].setFont(font);
	menutext[3].setFillColor(Color::White);
	menutext[3].setString(L"Exit");
	menutext[3].setPosition(Vector2f((width / 2)+ 200, height / 5 * 4));

	bgtexture.loadFromFile("street.png");
	bgsprite.setTexture(bgtexture);
	bgsprite.setPosition(Vector2f(0, 0));
	bgsprite.setScale(Vector2f(2.5f, 3.2f));
}

void Menu::draw(RenderWindow& window,int *selectedMenu) {
	window.draw(bgsprite);
	for (int i = 0; i < max_items; i++) {
		if (IntRect((width / 2) + 200, height / 5 * (i+1), 100, 100).contains(Mouse::getPosition(window))) {
			menutext[i].setFillColor(Color::Red);
			menutext[i].setScale(1.3f, 1.3f);
			if (Mouse::isButtonPressed(Mouse::Button::Left)) { 
				*selectedMenu = i + 1;
			}
		}
		else {
			menutext[i].setScale(1, 1);
			menutext[i].setFillColor(Color::White);
		}
	}
	for (int i = 0; i < max_items; i++) {
		window.draw(menutext[i]);
	}
}

