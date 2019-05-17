#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "incl.h"
#include "Text.h"

class SplashScreen
{
public:
	SplashScreen();
	~SplashScreen();

	void show();

private:
	void makeWindowTransparent();
    void setWindowAlpha(sf::Uint8 alpha);


	sf::Time deltaTime, elapsedTime;
	sf::Clock clock;
	sf::RenderWindow window;

	sf::Texture splash;
	sf::Sprite sprite;

	Text *txt;
};

#endif
