#include "Menu.h"

sf::View view(sf::FloatRect(0, 0, 640, 480));

Menu::Menu(sf::RenderWindow &window)
{

	if (!music.openFromFile("data/darude.ogg"))
	{
	}

	vol = 50;
	music.setVolume(vol);

	txt = new Text(window);
	game = new Game(window);

	state = GameState::menu;

	res[0] = "640x480", v[0].x = 640, v[0].y = 480;
	res[1] = "800x600", v[1].x = 800, v[1].y = 600;
	res[2] = "1024x768", v[2].x = 1024, v[2].y = 768;

	txt->opt[3].setString(to_string(int(vol)));
	txt->opt[5].setString(res[0]);
	txt->opt[8].setString("Off");

	contor = 0;

	texture.loadFromFile("data/life6.png");
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(window.getSize().x * 0.003, window.getSize().x * 0.003));
	sprite.setPosition(sf::Vector2f(window.getSize().x / 2 - sprite.getLocalBounds().width / 2 - window.getSize().x / 9 + 10, window.getSize().y / 4 * 2));

	apply = false;

	rezcounter = 0;
	vs = 0;

	window.setView(view);
}


Menu::~Menu()
{
	delete txt;
	delete game;
}

void Menu::setimg(int k)
{
	switch (k)
	{
	case 6:
		texture.loadFromFile("data/life6.png");
		sprite.setTexture(texture);
		break;
	case 5:
		texture.loadFromFile("data/life5.png");
		sprite.setTexture(texture);
		break;
	case 4:
		texture.loadFromFile("data/life4.png");
		sprite.setTexture(texture);
		break;
	case 3:
		texture.loadFromFile("data/life3.png");
		sprite.setTexture(texture);
		break;
	case 2:
		texture.loadFromFile("data/life2.png");
		sprite.setTexture(texture);
		break;
	case 1:
		texture.loadFromFile("data/life1.png");
		sprite.setTexture(texture);
		break;
	}
}

void Menu::applysettings(sf::RenderWindow &window)
{
	if (apply == true)
	{
		switch (vs)
		{
		case 1:
			window.setVerticalSyncEnabled(true);
			vs = 0;
			cout << "active";
			break;
		case 2:
			window.setVerticalSyncEnabled(false);
			vs = 0;
			cout << "disactive";
			break;
		}

		music.setVolume(vol);
		window.setSize(sf::Vector2u(v[rezcounter].x, v[rezcounter].y));
		window.setView(sf::View(sf::FloatRect(0, 0, v[rezcounter].x, v[rezcounter].y)));
		window.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width / 2) - v[rezcounter].x / 2,
			(sf::VideoMode::getDesktopMode().height / 2) - v[rezcounter].y / 2));

		sprite.setScale(sf::Vector2f(window.getSize().x * 0.003, window.getSize().x * 0.003));
		if (window.getSize().x == 640)
		{
			sprite.setPosition(sf::Vector2f(window.getSize().x / 2 - sprite.getLocalBounds().width / 2 - window.getSize().x / 9 + 10, window.getSize().y / 4 * 2));
		}
		else
		sprite.setPosition(sf::Vector2f(window.getSize().x / 2 - sprite.getLocalBounds().width / 2 - window.getSize().x / 9, window.getSize().y / 4 * 2));

		txt->update(window);
		apply = false;
	}
}

void Menu::setres(sf::RenderWindow &window)
{

	if (txt->opt[5].getColor() == sf::Color::Red)
	{
		if (contor == 1 && event.mouseButton.button == sf::Mouse::Button::Left)
		{
			click.play();
			rezcounter++;
			if (rezcounter > 2)
				rezcounter = 0;
			txt->opt[5].setString(res[rezcounter]);
			contor = 0;
		}
		else if (contor == 1 && event.mouseButton.button == sf::Mouse::Button::Right)
		{
			click.play();
			rezcounter--;
			if (rezcounter < 0)
				rezcounter = 2;
			txt->opt[5].setString(res[rezcounter]);
			contor = 0;
		}
	}
	txt->opt[5].setCharacterSize(window.getSize().x / 18);
	txt->opt[5].setPosition(sf::Vector2f(window.getSize().x / 4 * 3 - txt->opt[5].getLocalBounds().width / 2, window.getSize().y / 10 * 4.3));
}

void Menu::victory(sf::RenderWindow &window)
{
	game->cuvantfinal(window);

	while (state == GameState::victory)
	{


		events(window);

		window.clear();

		window.draw(txt->victorie);
		window.draw(game->cuvant);
		window.draw(txt->enter);

		window.display();
	}

	game->restart();
}

void Menu::defeat(sf::RenderWindow &window)
{
	game->cuvantfinal(window);

	while (state == GameState::defeat)
	{
		events(window);

		window.clear();

		window.draw(txt->lose);
		window.draw(game->cuvant);
		window.draw(txt->enter);

		window.display();
	}

	game->restart();
}

void Menu::setvsync(sf::RenderWindow &window)
{
	string comp;
	comp = txt->opt[8].getString();
	if (txt->opt[8].getColor() == sf::Color::Red)
	{
		if (contor == 1 && event.mouseButton.button == sf::Mouse::Button::Left)
		{
			click.play();
			if (comp.compare("Off") == 0)
				txt->opt[8].setString("On"), vs = 1;
			else txt->opt[8].setString("Off"), vs = 2;
		}
	}
	txt->opt[8].setCharacterSize(window.getSize().x / 18);
	txt->opt[8].setPosition(sf::Vector2f(window.getSize().x / 4 * 3 - txt->opt[8].getLocalBounds().width / 2, window.getSize().y / 10 * 5.2));
}

void Menu::setvolume(sf::RenderWindow &window)
{

	if (txt->opt[3].getColor() == sf::Color::Red)
	{
		if (contor == 1 && event.mouseButton.button == sf::Mouse::Button::Left)
		{
			click.play();
			vol += 10;
			if (vol > 100)
				vol = 100;
			txt->opt[3].setString(to_string(int(vol)));
			contor = 0;
		}
		else if (contor == 1 && event.mouseButton.button == sf::Mouse::Button::Right)
		{
			click.play();
			vol -= 10;
			if (vol < 0)
				vol = 0;
			if (vol == 0)
				txt->opt[3].setString("OFF");
			else txt->opt[3].setString(to_string(int(vol)));
			contor = 0;
		}
	}
	txt->opt[3].setCharacterSize(window.getSize().x / 18);
	txt->opt[3].setPosition(sf::Vector2f(window.getSize().x / 4 * 3 - txt->opt[3].getLocalBounds().width / 2, window.getSize().y / 10 * 3.5));
	music.setVolume(vol);
}

void Menu::events(sf::RenderWindow &window)
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			state = GameState::exit;
			break;
		case sf::Event::MouseButtonReleased:
			contor = 1;
			break;
		case sf::Event::KeyPressed:
			if (state == GameState::victory || state == GameState::defeat)
				if (event.key.code == sf::Keyboard::Return)
					state = GameState::menu;
			break;
		case sf::Event::TextEntered:
			if (state == GameState::play)
			{
				if (isalpha(event.text.unicode))
				{
					game->c = static_cast<char>(event.text.unicode);
					game->guess(game->c);
					game->introduse.insert(game->introduse.getSize(), game->c);
					txt->viata.setString("You have: " + to_string(game->life) + " changes.");
					txt->viata.setPosition(window.getSize().x / 2 - txt->viata.getLocalBounds().width / 2, window.getSize().y / 10 * 2.3);//100
					txt->intr.setString("letter guessed: " + game->introduse);
					txt->intr.setPosition(window.getSize().x / 2 - txt->intr.getLocalBounds().width / 2, window.getSize().y / 10 * 3.8);//200
					txt->temp.setString("word: " + game->now);
					txt->temp.setPosition(window.getSize().x / 2 - txt->temp.getLocalBounds().width / 2, window.getSize().y / 10 * 4.5);//250
				}
				else if (event.text.unicode == 27)
					state = GameState::menu;
			}
			break;
		default:
			break;
		}
	}
}

void Menu::playgame(sf::RenderWindow &window)
{
	while (state == GameState::play)
	{
		window.clear();

		setimg(game->life);
		events(window);

		window.draw(txt->litera);
		window.draw(txt->viata);
		window.draw(txt->intr);
		window.draw(txt->temp);
		window.draw(sprite);

		switch (game->k)
		{
		case 1:
			window.draw(txt->t1);
			break;
		case 2:
			window.draw(txt->t2);
			break;
		case 3:
			window.draw(txt->t3);
			break;
		}

		if (game->casewin(window) == 1)
		{
			txt->intr.setString("");
			txt->temp.setString("");
			txt->viata.setString("");
			game->k = 0;
			state = GameState::victory;
			break;
		}

		if (game->caselose(window) == 1)
		{
			txt->intr.setString("");
			txt->temp.setString("");
			txt->viata.setString("");
			game->k = 0;
			state = GameState::defeat;
			break;
		}

		window.display();
	}


}

void Menu::gamemenu(sf::RenderWindow &window)
{
	while (state == GameState::menu)
	{
		events(window);


		window.clear();
		window.draw(txt->title);

		for (int i = 0; i < MAXM; i++)
		{
			window.draw(txt->menu[i]);
			button(window, &txt->menu[i]);
		}

		window.display();
	}
}

void Menu::options(sf::RenderWindow &window)
{
	while (state == GameState::options)
	{
		events(window);

		window.clear();
		setvolume(window);
		setres(window);
		setvsync(window);
		applysettings(window);

		for (int i = 0; i < MAXO; i++)
		{
			window.draw(txt->opt[i]);
			if (i == 1 || i == 3 || i == 5 || i == 6 || i == 8)
				button(window, &txt->opt[i]);
		}

		window.display();
	}
}

void Menu::button(sf::RenderWindow &window, sf::Text *text)
{
	mouse_pos = sf::Mouse::getPosition(window);

	cuv = text->getString();

	startposX = text->getPosition().x;
	startposY = text->getPosition().y - 20;
	width = text->getLocalBounds().width;
	height = text->getLocalBounds().height;

	if (mouse_pos.x >= startposX && mouse_pos.x <= startposX + width && mouse_pos.y >= startposY && mouse_pos.y <= startposY + height)
	{
		if (contor == 1 && event.mouseButton.button == sf::Mouse::Button::Left)
		{
			if (cuv.compare("Exit") == 0)
				click.play(), state = GameState::exit;
			else if (cuv.compare("Play") == 0)
				click.play(), state = GameState::play;
			else if (cuv.compare("Options") == 0)
				click.play(), state = GameState::options;
			else if (cuv.compare("Back") == 0)
				click.play(), state = GameState::menu;
			else if (cuv.compare("Apply") == 0)
				click.play(), apply = true;
			contor = 0;
		}
		else
		{
			text->setColor(sf::Color::Red);
		}
	}
	else
	{
		text->setColor(sf::Color::White);
	}
}
