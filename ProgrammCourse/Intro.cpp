
#include "Intro.h"

Intro::Intro(float width, float height) {	
	this->width = width;
	this->height = height;
	spritesheet.loadFromFile("anim.png");
	object.setTexture(spritesheet);
	frame = 0;
	dx = 0;
	smooth = 0;
	inc = 1;
	font.loadFromFile("../19888.ttf");
	name.setFont(font);
	name.setFillColor(Color::White);
	name.setString(L"Lykor");
	name.setPosition(Vector2f(width / 2.5f, height / 2.5f));

}


void Intro::draw(RenderWindow& window){
	while (1) {
		if (Keyboard::isKeyPressed(Keyboard::Space)) break;
		if (Mouse::isButtonPressed(Mouse::Button::Right)) break;
		window.clear();
			object.setTextureRect(IntRect(0 + dx, 0, 240, 280));
								if (frame == 4) {
									dx = 0;
									frame = 0;
								}
								if (inc) {
									smooth++;
									inc = (smooth == 11) ? 0 : 1;
								}
								else {
									smooth--;
									inc = (smooth == -11) ? 1 : 0;
								}
								dx += 240;
								frame++;
							object.setPosition((width / 2) - 100, (height / 2) - 100 + (frame * 10));
						name.setPosition(Vector2f((width / 2.5f), (height / 2.5f) + smooth));
					window.draw(name);
				window.draw(object);	
			Sleep(100);
		window.display();
	}
}



