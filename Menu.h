#ifndef MENU_H
#define MENU_H

#include "incl.h"
#include "Text.h"
#include "Game.h"

class Menu
{
public:
	Menu(sf::RenderWindow &window);
	~Menu();

	void gamemenu(sf::RenderWindow &window);
	void options(sf::RenderWindow &window);
	void playgame(sf::RenderWindow &window);
	void victory(sf::RenderWindow &window);
	void defeat(sf::RenderWindow &window);

	GameState state;
	sf::Music music;
private:
	void button(sf::RenderWindow &window, sf::Text *text);
	void events(sf::RenderWindow &window);
	void setvolume(sf::RenderWindow &window);
	void setres(sf::RenderWindow &window);
	void setvsync(sf::RenderWindow &window);
	void applysettings(sf::RenderWindow &window);
	void setimg(int k);

	string cuv, res[3];
	sf::Vector2i mouse_pos;
	sf::Music click;
	int startposX, startposY, width, height, contor, rand, rezcounter, vs;
	sf::Event event;
	sf::Sprite sprite;
	sf::Texture texture;
	bool apply;

	struct Rez
	{
		unsigned int x, y;
	}v[3];

	float vol;
	Text *txt;
	Game *game;
};

#endif
