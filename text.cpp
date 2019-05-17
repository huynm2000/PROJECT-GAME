#include "Text.h"


Text::Text(sf::RenderWindow &window)
{
	if (!font.loadFromFile("data/font.ttf"))
	{
	}


	intr.setFont(font);
	intr.setColor(sf::Color::White);
	intr.setCharacterSize(window.getSize().x / 25);

	temp.setFont(font);
	temp.setColor(sf::Color::White);
	temp.setCharacterSize(window.getSize().x / 25);

	litera.setFont(font);
	litera.setColor(sf::Color::White);
	litera.setString("LET GUESS.");
	litera.setCharacterSize(window.getSize().x / 25);
	litera.setPosition(window.getSize().x / 2 - litera.getLocalBounds().width / 2, window.getSize().y / 10 * 1.5);

	viata.setFont(font);
	viata.setColor(sf::Color::White);
	viata.setCharacterSize(window.getSize().x / 25);

	t1.setFont(font);
	t1.setColor(sf::Color::White);
	t1.setString("the letter was guessed");
	t1.setCharacterSize(window.getSize().x / 25);
	t1.setPosition(window.getSize().x / 2 - t1.getLocalBounds().width / 2, window.getSize().y / 10 * 3);//150

	t2.setFont(font);
	t2.setColor(sf::Color::White);
	t2.setString("yesss!");
	t2.setCharacterSize(window.getSize().x / 25);
	t2.setPosition(window.getSize().x / 2 - t2.getLocalBounds().width / 2, window.getSize().y / 10 * 3);

	t3.setFont(font);
	t3.setColor(sf::Color::White);
	t3.setString("Incorect.");
	t3.setCharacterSize(window.getSize().x / 25);
	t3.setPosition(window.getSize().x / 2 - t3.getLocalBounds().width / 2, window.getSize().y / 10 * 3);

	victorie.setFont(font);
	victorie.setColor(sf::Color::Green);
	victorie.setString("YOU WON!");
	victorie.setCharacterSize(window.getSize().x / 8);
	victorie.setPosition(window.getSize().x / 2 - victorie.getLocalBounds().width / 2, window.getSize().y / 6 * 2);

	lose.setFont(font);
	lose.setColor(sf::Color::Red);
	lose.setString("YOU LOSE !");
	lose.setCharacterSize(window.getSize().x / 8);
	lose.setPosition(window.getSize().x / 2 - lose.getLocalBounds().width / 2, window.getSize().y / 6 * 2);

	enter.setFont(font);
	enter.setColor(sf::Color::White);
	enter.setString("press enter to continue");
	enter.setCharacterSize(window.getSize().x / 20);
	enter.setPosition(window.getSize().x / 2 - enter.getLocalBounds().width / 2, window.getSize().y / 6 * 4);


	title.setFont(font);
	title.setCharacterSize(window.getSize().x / 8);
	title.setColor(sf::Color::White);
	title.setString("Hangman");
	title.setPosition(sf::Vector2f(window.getSize().x / 2 - title.getLocalBounds().width / 2, window.getSize().y / 5 * 1.5));

	menu[0].setFont(font);
	menu[0].setCharacterSize(window.getSize().x / 18);
	menu[0].setColor(sf::Color::White);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(window.getSize().x / 4 - menu[0].getLocalBounds().width / 2, window.getSize().y / 5 * 3));

	menu[1].setFont(font);
	menu[1].setCharacterSize(window.getSize().x / 18);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(window.getSize().x / 4 * 2 - menu[1].getLocalBounds().width / 2 + 7, window.getSize().y / 5 * 3));

	menu[2].setFont(font);
	menu[2].setCharacterSize(window.getSize().x / 18);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(window.getSize().x / 4 * 3 - menu[2].getLocalBounds().width / 2 + 5, window.getSize().y / 5 * 3));


	opt[0].setFont(font);
	opt[0].setCharacterSize(window.getSize().x / 8);
	opt[0].setColor(sf::Color::White);
	opt[0].setString("Options");
	opt[0].setPosition(sf::Vector2f(window.getSize().x / 2 - opt[0].getLocalBounds().width / 2, window.getSize().y / 10 * 1.5));

	opt[1].setFont(font);
	opt[1].setCharacterSize(window.getSize().x / 18);
	opt[1].setColor(sf::Color::White);
	opt[1].setString("Back");
	opt[1].setPosition(sf::Vector2f(window.getSize().x / 4 - opt[1].getLocalBounds().width / 2, window.getSize().y - 50));

	opt[2].setFont(font);
	opt[2].setCharacterSize(window.getSize().x / 18);
	opt[2].setColor(sf::Color::White);
	opt[2].setString("Volume");
	opt[2].setPosition(sf::Vector2f(window.getSize().x / 4 - opt[2].getLocalBounds().width / 2, window.getSize().y / 10 * 3.5));

	opt[3].setFont(font);
	opt[3].setColor(sf::Color::White);

	opt[4].setFont(font);
	opt[4].setCharacterSize(window.getSize().x / 18);
	opt[4].setColor(sf::Color::White);
	opt[4].setString("Resolution");
	opt[4].setPosition(sf::Vector2f(window.getSize().x / 4 - opt[4].getLocalBounds().width / 2, window.getSize().y / 10 * 4.3));

	opt[5].setFont(font);
	opt[5].setColor(sf::Color::White);

	opt[6].setFont(font);
	opt[6].setCharacterSize(window.getSize().x / 18);
	opt[6].setColor(sf::Color::White);
	opt[6].setString("Apply");
	opt[6].setPosition(sf::Vector2f(window.getSize().x / 4 * 3 - opt[6].getLocalBounds().width / 2, window.getSize().y - 50));

	opt[7].setFont(font);
	opt[7].setCharacterSize(window.getSize().x / 18);
	opt[7].setColor(sf::Color::White);
	opt[7].setString("VSync");
	opt[7].setPosition(sf::Vector2f(window.getSize().x / 4 - opt[7].getLocalBounds().width / 2, window.getSize().y / 10 * 5.2));

	opt[8].setFont(font);
	opt[8].setColor(sf::Color::White);
}


Text::~Text()
{
}

void Text::update(sf::RenderWindow &window)
{
	temp.setCharacterSize(window.getSize().x / 25);
	viata.setCharacterSize(window.getSize().x / 25);
	intr.setCharacterSize(window.getSize().x / 25);
	litera.setCharacterSize(window.getSize().x / 25);
	litera.setPosition(sf::Vector2f(window.getSize().x / 2 - litera.getLocalBounds().width / 2, window.getSize().y / 10 * 1.5));
	t1.setCharacterSize(window.getSize().x / 25);
	t1.setPosition(sf::Vector2f(window.getSize().x / 2 - t1.getLocalBounds().width / 2, window.getSize().y / 10 * 3));
	t2.setCharacterSize(window.getSize().x / 25);
	t2.setPosition(sf::Vector2f(window.getSize().x / 2 - t2.getLocalBounds().width / 2, window.getSize().y / 10 * 3));
	t3.setCharacterSize(window.getSize().x / 25);
	t3.setPosition(sf::Vector2f(window.getSize().x / 2 - t3.getLocalBounds().width / 2, window.getSize().y / 10 * 3));

	victorie.setCharacterSize(window.getSize().x / 8);
	victorie.setPosition(sf::Vector2f(window.getSize().x / 2 - victorie.getLocalBounds().width / 2, window.getSize().y / 6 * 2));
	lose.setCharacterSize(window.getSize().x / 8);
	lose.setPosition(sf::Vector2f(window.getSize().x / 2 - lose.getLocalBounds().width / 2, window.getSize().y / 6 * 2));
	enter.setCharacterSize(window.getSize().x / 20);
	enter.setPosition(sf::Vector2f(window.getSize().x / 2 - enter.getLocalBounds().width / 2, window.getSize().y / 6 * 4));

	title.setCharacterSize(window.getSize().x / 8);
	title.setPosition(sf::Vector2f(window.getSize().x / 2 - title.getLocalBounds().width / 2, window.getSize().y / 5 * 1.5));
	menu[0].setCharacterSize(window.getSize().x / 18);
	menu[0].setPosition(sf::Vector2f(window.getSize().x / 4 - menu[0].getLocalBounds().width / 2, window.getSize().y / 5 * 3));
	menu[1].setCharacterSize(window.getSize().x / 18);
	menu[1].setPosition(sf::Vector2f(window.getSize().x / 4 * 2 - menu[1].getLocalBounds().width / 2 + 7, window.getSize().y / 5 * 3));
	menu[2].setCharacterSize(window.getSize().x / 18);
	menu[2].setPosition(sf::Vector2f(window.getSize().x / 4 * 3 - menu[2].getLocalBounds().width / 2 + 5, window.getSize().y / 5 * 3));

	opt[0].setCharacterSize(window.getSize().x / 8);
	opt[0].setPosition(sf::Vector2f(window.getSize().x / 2 - opt[0].getLocalBounds().width / 2, window.getSize().y / 10 * 1.5));
	opt[1].setCharacterSize(window.getSize().x / 18);
	opt[1].setPosition(sf::Vector2f(window.getSize().x / 4 - opt[1].getLocalBounds().width / 2, window.getSize().y - 50));
	opt[2].setCharacterSize(window.getSize().x / 18);
	opt[2].setPosition(sf::Vector2f(window.getSize().x / 4 - opt[2].getLocalBounds().width / 2, window.getSize().y / 10 * 3.5));
	opt[4].setCharacterSize(window.getSize().x / 18);
	opt[4].setPosition(sf::Vector2f(window.getSize().x / 4 - opt[4].getLocalBounds().width / 2, window.getSize().y / 10 * 4.3));
	opt[7].setCharacterSize(window.getSize().x / 18);
	opt[7].setPosition(sf::Vector2f(window.getSize().x / 4 - opt[7].getLocalBounds().width / 2, window.getSize().y / 10 * 5.1));
	opt[6].setCharacterSize(window.getSize().x / 18);
	opt[6].setPosition(sf::Vector2f(window.getSize().x / 4 * 3 - opt[6].getLocalBounds().width / 2, window.getSize().y - 50));
}
