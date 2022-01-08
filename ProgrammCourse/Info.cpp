#include "Info.h"
info::info(float width, float height) {
	font.loadFromFile("../19888.ttf");

	textabout[0].setFont(font);
	textabout[0].setFillColor(Color::White);
	textabout[0].setString(L"∆арков ¬алерий ёрьевич");
	textabout[0].setPosition(Vector2f((width / 2)-90, height/2 - 90));

	textabout[1].setFont(font);
	textabout[1].setFillColor(Color::White);
	textabout[1].setString(L"ќм√“”");
	textabout[1].setPosition(Vector2f((width / 2)-100, height/2));
}

void info::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 2; i++) {
		window.draw(textabout[i]);
	}
}