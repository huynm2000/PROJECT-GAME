#include "Game.h"

const char cuv[16][20] = { "alone", "stream", "spam", "mouse", "cat", "masage", "information", "rock", "harrypoter",
								"banana", "cartoon", "motorbike", "aligator", "baseball", "professor" };

Game::Game(sf::RenderWindow &window)
{
	life = 6;

	txt = new Text(window);

	srand((unsigned)time(0));
	random = rand() % 15;

	for (int i = 0; i < strlen(cuv[random]); i++)
		now.insert(i, ToStr('*'));

	contor = 0;
}


Game::~Game()
{
	delete txt;
}

void Game::cuvantfinal(sf::RenderWindow &window)
{
	cuvant.setFont(txt->font);
	cuvant.setColor(sf::Color::White);
	for (int i = 0; i < strlen(cuv[random]); i++)
		word.insert(word.getSize(), cuv[random][i]);
	cuvant.setString("This word is " + word + ".");
	cuvant.setCharacterSize(window.getSize().x / 18);
	cuvant.setPosition(window.getSize().x / 2 - cuvant.getLocalBounds().width / 2, window.getSize().y / 6 * 3);
}

void Game::restart()
{
	for (int i = 0; i < strlen(cuv[random]); i++)
		ghicit[i] = NULL;

	introduse.clear();
	word.clear();
	now.clear();

	random = rand() % 15;

	life = 6;

	for (int i = 0; i < strlen(cuv[random]); i++)
		now.insert(i, ToStr('*'));
}

int Game::casewin(sf::RenderWindow &window)
{
	if (win() == 1)
	{

		return 1;
	}
	else return 0;
}

int Game::caselose(sf::RenderWindow &window)
{
	if (life == 0)
	{
		return 1;
	}
	else return 0;
}

void Game::plaseaza(char c, int i)
{
	ghicit[i] = c;
}

int Game::win()
{
	if (strcmp(ghicit, cuv[random]) == 0)
		return 1;
	return 0;
}

int Game::verif(char c)
{
	for (int i = 0; i<strlen(cuv[random]); i++)
		if (c == ghicit[i])
			return 0;
	return 1;
}

int Game::exista(char c)
{
	contor = 0;

	for (int i = 0; i<strlen(cuv[random]); i++)
		if (c == cuv[random][i])
		{
			contor++;
			plaseaza(c, i);
			now.replace(i, 1, ToStr(c));
		}
	if (contor == 0)
		return 0;
	else return contor;
}

void Game::guess(char c)
{
	if (verif(c) == 0)
	{
		k = 1;
	}
	else
	{
		if (exista(c))
		{
			k = 2;
		}
		else
		{
			life--;
			k = 3;
		}
	}

}

string Game::ToStr(char c)
{
	return string(1, c);
}
