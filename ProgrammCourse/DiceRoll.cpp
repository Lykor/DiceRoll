#include "DiceRoll.h"

DiceRoll::DiceRoll(float width,float height) {
	font.loadFromFile("../19888.ttf");
	this->width = width;
	this->height = height;
	number = 0;
	result = 0;
	winText.setFont(font);
	winText.setFillColor(Color::White);
	winText.setString(L"You Win");
	loseText.setFont(font);
	loseText.setFillColor(Color::Red);
	loseText.setString(L"You Lose");
	frame = 0;
	row = 0;
	col = 0;
	for (int i = 0; i < 6; i++) {
		choise[i].setFont(font);
		choise[i].setFillColor(Color::Yellow);
		choise[i].setString(num[i]);
	}
	spritesheet.loadFromFile("images/diceroll.png");
	dice.setTexture(spritesheet);
	isWin = -1;
	dx = 94;
	dy = 0;
	isUp=1;

	winText.setPosition(Vector2f(width / 2.5f, height / 15.5f));
	loseText.setPosition(Vector2f(width / 2.7f, height / 15.5f));
	for (int i = 0; i < 6; i++) {
		choise[i].setPosition(Vector2f((width / 3) + (55 * i), height / 7));
	}
}

void DiceRoll::draw(RenderWindow& window) {
	if (number){
		result = result > 0 ? result:1+(rand()%6);
		switch (result) {
			case 1: row = 0;
				break;
			case 2: row = 100;
				break;
			case 3: row = 200;
				break;
			case 4: row = 300;
				break;
			case 5: row = 390;
				break;
			case 6: row = 500;
				break;
		}

		if (frame == 14) {
			dx = 0;
			isWin = (number == result) ? 1 : 0;
			number = 0;
			result = 0;
		}

		if (dy > -60 && isUp) {
			dy -= 10;
		}
		else if (dy != 0) {
			isUp = 0;
			dy += 10;
		}
		dice.setTextureRect(IntRect(10 + col, 0 + row, 90, 100));
		dice.setPosition(Vector2f((window.getSize().x / 2.5f) + (col / 10), (window.getSize().y / 2.5f) + dy));
		dice.setRotation(dy);
		window.draw(dice);

		Sleep(100);
		if (dx > 0) {
			frame++;
			col += dx;
		}
	}
	else {
		for (int i = 0; i < 6; i++) {
			if (IntRect(choise[i].getPosition().x, choise[i].getPosition().y, 25, 50).contains(Mouse::getPosition(window))) {
				choise[i].setFillColor(Color::Red);
				if (Mouse::isButtonPressed(Mouse::Button::Left)) {
					number = i + 1;
					frame = 0;
					col = 0;
					dx = 94;
					isUp = 1;
				}
			}
			else {
				choise[i].setFillColor(Color::Yellow);
			}
		}
		if (frame == 14) {
			if (isWin) {
				window.draw(winText);
			}
			else {
				window.draw(loseText);
			}
		}
		dice.setTextureRect(IntRect(10 + col, 0 + row, 90, 100));
		dice.setPosition(Vector2f((window.getSize().x / 2.5f) + (col / 10), (window.getSize().y / 2.5f) + dy));
		dice.setRotation(dy);
		window.draw(dice);
	}

	for (int i = 0; i < 6; i++) {
		window.draw(choise[i]);
	}
}