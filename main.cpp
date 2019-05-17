#include "Menu.h"
#include "SplashScreen.h"

int main()
{
	SplashScreen sscreen;
	sscreen.show();

	sf::RenderWindow window(sf::VideoMode(640, 480), "hangman", sf::Style::Resize | sf::Style::Default);

	sf::Image icon;
	icon.loadFromFile("data/icon.png");
	window.setIcon(512, 512, icon.getPixelsPtr());

	Menu *m;
	m = new Menu(window);

	m->music.play();
	m->music.setLoop(true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		switch (m->state)
		{
		case GameState::menu:
			m->gamemenu(window);
			break;
		case GameState::options:
			m->options(window);
			break;
		case GameState::play:
			m->playgame(window);
			break;
		case GameState::victory:
			m->victory(window);
			break;
		case GameState::defeat:
			m->defeat(window);
			break;
		case GameState::exit:
			window.close();
			break;
		default:
			break;
		}

		window.display();
	}

	return 0;
}
