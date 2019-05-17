#include "SplashScreen.h"


SplashScreen::SplashScreen()
{
	txt = new Text(window);
	window.create(sf::VideoMode(420, 100), "", sf::Style::None);
	//splash.loadFromFile("data/hangman.png");
	//splash.setSmooth(true);
	//sprite.setTexture(splash);
	//makeWindowTransparent();
	txt->title.setCharacterSize(80);
	txt->title.setPosition(sf::Vector2f(window.getSize().x / 2 - txt->title.getLocalBounds().width / 2, 50));
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::makeWindowTransparent()
{
	HWND hwnd = window.getSystemHandle();
	SetWindowLongPtr(hwnd, GWL_EXSTYLE, GetWindowLongPtr(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
}

void SplashScreen::setWindowAlpha(sf::Uint8 alpha)
{
	SetLayeredWindowAttributes(window.getSystemHandle(), (255, 0, 0), alpha, LWA_COLORKEY);
}

void SplashScreen::show()
{

	while (window.isOpen())
	{
		deltaTime = clock.restart();
		elapsedTime += deltaTime;

		if (elapsedTime > sf::seconds(1.5))
			window.close();


		window.clear();
		window.draw(txt->title);
		window.display();
	}
}
