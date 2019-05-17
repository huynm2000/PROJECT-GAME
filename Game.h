#ifndef GAME_H
#define GAME_H

#include "Text.h"

class Game
{
public:
	Game(sf::RenderWindow &window);
	~Game();
	
	int casewin(sf::RenderWindow &window);
	int caselose(sf::RenderWindow &window);
	void guess(char c);
	void restart();
	void cuvantfinal(sf::RenderWindow &window);

	char c;
	int  k, life;
	sf::String introduse, word;
	string now;
	sf::Text cuvant;
private:
	int win();
	int verif(char c);
	int exista(char c);
	string ToStr(char c);
	void plaseaza(char c, int i);

	
	char ghicit[20];
	int contor, random, rest;
	Text *txt;
	GameState state;
};

#endif
