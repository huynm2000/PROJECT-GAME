#ifndef TEXT_H
#define TEXT_H

#define MAXO 9
#define MAXM 3

#include "incl.h"



class Text
{
public:
	Text(sf::RenderWindow &window);
	~Text();


	void update(sf::RenderWindow &window);

	sf::Text t1, t2, t3, litera, viata, intr, temp, enter, lose, victorie;
	sf::Text menu[MAXM], opt[MAXO];
	sf::Text title;
	sf::Font font;	
	
};

#endif

