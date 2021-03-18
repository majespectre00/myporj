#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>

#include"Header.h"
#include <string>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include <vector>

using namespace std;

void setmenu();
sf::Vector2i Block_Until_Mouse_Click() {

	static bool pressed = false;
	sf::Vector2i position;
	while (true) {

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed) {
				position = sf::Mouse::getPosition();
				pressed = true;
				break;
			}
		}
		else {
			pressed = false;
		}
	}

	return position;
}

int main() {
	
	sf::Music music;
	if (!music.openFromFile("sound1.ogg"))
	{
		std::cout << "error" << endl;
	}
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "CODING BOOSTER");
	sf::Event ev;

	sf::Sprite background_menu;
	sf::Texture background_menu_texture;

	background_menu_texture.loadFromFile("images/background.png");
	background_menu.setTexture(background_menu_texture);

	sf::Sprite logo;
	sf::Texture logo_texture;

	logo_texture.loadFromFile("images/logo.png");
	logo.setTexture(logo_texture);
	logo.setPosition(sf::Vector2f(450, -300));
	logo.setScale(sf::Vector2f(1, 1));

	sf::Sprite bplay;
	sf::Texture bplay_texture;
	sf::Texture bplay_on_texture;

	bplay_texture.loadFromFile("images/bplay.png");
	bplay_on_texture.loadFromFile("images/bplay_on.png");
	bplay.setTexture(bplay_texture);
	bplay.setPosition(sf::Vector2f(750, 400));
	bplay.setScale(sf::Vector2f(1, 1));

	sf::Sprite binfo;
	sf::Texture binfo_texture;

	binfo_texture.loadFromFile("images/binfo.png");
	binfo.setTexture(binfo_texture);
	binfo.setPosition(sf::Vector2f(760, 600));
	binfo.setScale(sf::Vector2f(1, 1));

	sf::Sprite bhigh;
	sf::Texture bhigh_texture;

	bhigh_texture.loadFromFile("images/bhigh.png");
	bhigh.setTexture(bhigh_texture);
	bhigh.setPosition(sf::Vector2f(250, 300));
	bhigh.setScale(sf::Vector2f(1.7, 1.7));

	sf::Sprite imgbox;
	sf::Texture imgbox_texture;

	imgbox_texture.loadFromFile("images/imgbox.png");
	imgbox.setTexture(imgbox_texture);
	imgbox.setPosition(sf::Vector2f(100, 100));
	imgbox.setScale(sf::Vector2f(1, 1));


	sf::Sprite infoo;
	sf::Texture infoo_texture;

	infoo_texture.loadFromFile("images/info.jpg");
	infoo.setTexture(infoo_texture);
	infoo.setPosition(sf::Vector2f(250, 100));
	infoo.setScale(sf::Vector2f(1, 1));

	sf::Sprite mod1;
	sf::Texture mod1_texture;

	mod1_texture.loadFromFile("images/mod1.png");
	mod1.setTexture(mod1_texture);
	mod1.setPosition(sf::Vector2f(360, 200));
	mod1.setScale(sf::Vector2f(1.4, 1.4));

	sf::Sprite mod2;
	sf::Texture mod2_texture;

	mod2_texture.loadFromFile("images/mod2.png");
	mod2.setTexture(mod2_texture);
	mod2.setPosition(sf::Vector2f(360, 420));
	mod2.setScale(sf::Vector2f(1.4, 1.4));

	sf::Sprite mod3;
	sf::Texture mod3_texture;

	mod3_texture.loadFromFile("images/mod3.png");
	mod3.setTexture(mod3_texture);
	mod3.setPosition(sf::Vector2f(360, 640));
	mod3.setScale(sf::Vector2f(1.4, 1.4));



	sf::Sprite buttbacktomenu;
	sf::Texture buttback_texture;

	buttback_texture.loadFromFile("images/buttback.png");
	buttbacktomenu.setTexture(buttback_texture);
	buttbacktomenu.setPosition(sf::Vector2f(1500, 820));
	buttbacktomenu.setScale(sf::Vector2f(0.8, 0.7));

	sf::Font font;
	font.loadFromFile("font/Inconsolata-Regular.ttf");


	Textbox text1(20, true);
	text1.setPosition({ 100, 100 });
	text1.setLimit(false, 30);
	text1.setFont(font);

	sf::Sprite textinputbox;
	sf::Texture textinputbox_texture;
	textinputbox_texture.loadFromFile("images/textinputbox.png");
	textinputbox.setTexture(textinputbox_texture);
	textinputbox.setPosition(sf::Vector2f(100, 100));
	textinputbox.setScale(sf::Vector2f(1, 1));

	sf::Sprite bok;
	sf::Texture bok_texture;
	bok_texture.loadFromFile("images/ok1.png");
	bok.setTexture(bok_texture);
	bok.setPosition(sf::Vector2f(0, 0));
	bok.setScale(sf::Vector2f(10, 10));

	sf::Sprite quizwar;
	sf::Texture quiz;
	quizwar.setPosition(sf::Vector2f(160, 330));
	quizwar.setScale(sf::Vector2f(1.2, 1.2));


	sf::Sprite logomod2;
	logomod2.setTexture(mod2_texture);
	logomod2.setPosition(sf::Vector2f(180, 10));
	logomod2.setScale(sf::Vector2f(1.5, 1.5));

	sf::Sprite logomod1;
	logomod1.setTexture(mod1_texture);
	logomod1.setPosition(sf::Vector2f(170, 80));
	logomod1.setScale(sf::Vector2f(2, 2));

	window.clear();

	window.draw(background_menu);
	window.draw(logo);
	window.draw(bplay);
	window.draw(binfo);
	
	//window.draw(textinputbox);

	window.display();
	int gamestate = 0;
	int correct = 0;
	int totalscore = 0;
	std::cout << "gamestate is now " << gamestate << endl;

	music.play();
	music.setLoop(true);
	music.setVolume(5);
	while (window.isOpen())
	{
	
		while (window.pollEvent(ev))
		{
			
			if (ev.type == sf::Event::Closed)
			{
				window.close();
			}
			if (ev.type == sf::Event::MouseButtonReleased)
			{
				if (ev.mouseButton.button == sf::Mouse::Left)
				{
			
					if (gamestate == 0)
					{
						if (bplay.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
						{

							gamestate = 1;
							std::cout << "gamestate is now " << gamestate << endl;
							window.clear();
							window.draw(background_menu);
							window.draw(mod1);
							window.draw(mod2);
							window.draw(mod3);
							window.draw(buttbacktomenu);
							window.display();
						}

						if (binfo.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
						{

							gamestate = 1;
							cout << "gamestate is now " << gamestate << endl;
							window.clear();
							window.draw(background_menu);
							window.draw(infoo);
							window.draw(buttbacktomenu);
							window.display();
						}
					}//g0
					/*
					if (gamestate == 1)
					{
						if (mod1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
						{


								window.clear();
								gamestate = 2;
								cout << "gamestate is now " << gamestate << endl;
								window.draw(background_menu);
								window.display();

						}
						if (mod2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
						{

								window.clear();
								gamestate = 3;
								cout << "gamestate is now " << gamestate << endl;
								window.draw(background_menu);
								window.display();

						}
						if (mod3.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
						{

								window.clear();
								gamestate = 4;
								cout << "gamestate is now " << gamestate << endl;
								window.draw(background_menu);
								window.display();

						}
						if (buttbacktomenu.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
						{

								gamestate = 0;
								cout << "gamestate is now " << gamestate << endl;
								window.clear();
								window.draw(background_menu);
								window.draw(logo);
								window.draw(bplay);
								window.draw(binfo);
								window.draw(bhigh);
								window.display();

						}
					}//playmenu*/
				}
			}
			if (ev.type == sf::Event::MouseButtonPressed && gamestate == 1)
			{
				if (ev.mouseButton.button == sf::Mouse::Left)
				{
					if (mod1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{


						window.clear();
						gamestate = 2;
						std::cout << "gamestate is now " << gamestate << endl;
						window.draw(background_menu);
						window.display();

					}
					if (mod2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{

						window.clear();
						gamestate = 3;
						std::cout << "gamestate is now " << gamestate << endl;
						window.draw(background_menu);
						window.display();

					}
					if (mod3.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{

						window.clear();
						gamestate = 4;
						cout << "gamestate is now " << gamestate << endl;
						window.draw(background_menu);
						window.display();

					}
					if (buttbacktomenu.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{

						gamestate = 0;
						cout << "gamestate is now " << gamestate << endl;
						window.clear();
						window.draw(background_menu);
						window.draw(logo);
						window.draw(bplay);
						window.draw(binfo);
						window.display();

					}
				}
			}
		}
		if (gamestate == 2)
		{
			window.clear();
			window.draw(background_menu);
			window.draw(logomod1);
			window.draw(buttbacktomenu);
			window.draw(bok);
			window.display();
			int count = 0;
			long int starttime = time(0);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && gamestate == 2 && bok.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				ifstream wordsource("wordmode.txt");
				string input = "", textline;
				vector<string> fixword;
				while (getline(wordsource, textline))
				{
					wordsource >> ws;
					fixword.push_back(textline);
				}
				while (input != "exit")
				{
					int x = rand() % fixword.size();
					string texture = fixword[x];
					cout << "Type if !! -->" << texture << endl;
					getline(cin, input);
					if (texture == input)
					{
						cout << "correct" << endl;
						correct++;
						fixword.erase(fixword.begin()+x-1);
						count++;
					}
					else
					{
						if (input != "exit")
						{
							cout << "you fueck up" << endl;
							count++;
						}
					}
				}
				long int elapse = time(0) - starttime;
				cout << endl << elapse<<" s"<<endl;
				cout << "end game"<<endl;
				correct *= (count * 8 / elapse);
				gamestate = 10;				
			}
		}
		if (gamestate == 3)
		{
			window.clear();
			window.draw(background_menu);
			window.draw(logomod2);
			window.draw(bok);
			window.display();
			int count = 0;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && gamestate == 3 && bok.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				string userinp = "";
				ifstream ans("answer2.txt");
				string textline;
				vector<string> answer;
				while (getline(ans, textline)) {
					answer.push_back(textline);
					cout << "pushed\n";
				}
				cout << answer.size() << endl;
				window.clear();
				while (count != 12)
				{
					int x = rand() % answer.size();
					cout << "rand : " << x << endl;
					int y = x + 1;
					string imgcaller = to_string(y);
					imgcaller += ".jpg";
					string realimgcaller = "images/" + imgcaller;
					quiz.loadFromFile(realimgcaller);
					quizwar.setTexture(quiz);
					window.draw(background_menu);
					window.draw(logomod2);
					window.draw(imgbox);
					window.draw(quizwar);

					window.display();
					getline(cin, userinp);
					if (userinp == answer[x])
					{
						cout << "Correct\n";
						correct++;
						window.clear();
					}
					else if (userinp == "exit") {
						break;
					}
					else
					{
						cout << "Incorrect\n";
						window.clear();
					}
					count++;
				}
				gamestate = 10;
			}
				
		}

		if (gamestate == 4)
		{
			while (true)
			{
				cout << "This is gamemode 3 the programmer\n";
				string input = "";
				cout << "pimaraigordai\n";
				getline(cin, input);
				cout << "your input: " << input << endl;
				if (input == "e") {
					gamestate = 0;
					cout << "gamestate is now " << gamestate << endl;
					window.clear();
					window.draw(background_menu);
					window.draw(logo);
					window.draw(bplay);
					window.draw(binfo);
					window.display();
					break;
				}
			}
		}
		if (gamestate == 10)
		{
			window.clear();
			window.draw(background_menu);
			window.draw(buttbacktomenu);
			window.display();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && gamestate == 10 && buttbacktomenu.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				cout << "your score = " << correct * 10 << endl;
				totalscore += correct * 10;
				correct = 0;
				gamestate = 0;
				cout << "gamestate is now " << gamestate << endl;
				window.clear();
				window.draw(background_menu);
				window.draw(logo);
				window.draw(bplay);
				window.draw(binfo);

				window.display();
			}
		}
	}
	return 0;
}
/*
					if (buttbacktomenu.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						window.clear();

						window.draw(background_menu);
						window.draw(logo);
						window.draw(bplay);
						window.draw(binfo);
						window.draw(bhigh);

						window.display();
					}
					if (mod1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						window.clear();
						gamestate = 1;
						window.draw(background_menu);
						window.display();
					}
					if (mod2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						window.clear();
						gamestate = 2;
						window.draw(background_menu);
						window.display();
					}
					if (mod3.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						window.clear();
						gamestate = 3;
						window.draw(background_menu);
						window.display();
					}
					while (window.pollEvent(ev) && gamestate == 4)
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				if (ev.mouseButton.button == sf::Mouse::Left)
				{

					if (mod1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						window.clear();
						gamestate = 1;
						window.draw(background_menu);
						window.display();
					}
					if (mod2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						window.clear();
						gamestate = 2;
						window.draw(background_menu);
						window.display();
					}
					if (mod3.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						window.clear();
						gamestate = 3;
						window.draw(background_menu);
						window.display();
					}
					if (buttbacktomenu.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						gamestate = 0;
						window.clear();

						window.draw(background_menu);
						window.draw(logo);
						window.draw(bplay);
						window.draw(binfo);
						window.draw(bhigh);

						window.display();
					}
					cout << "it's break";
					break;
				}
			}
		}
		while (window.pollEvent(ev) && gamestate == 0)
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::TextEntered:
					if (textinputbox.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						window.draw(background_menu);
						window.draw(logo);
						window.draw(bplay);
						window.draw(binfo);
						window.draw(bhigh);
						window.draw(textinputbox);
						text1.typedOn(ev);
						text1.drawTo(window);
						window.display();
					}
				break;

			case sf::Event::MouseButtonPressed:
				if (ev.mouseButton.button == sf::Mouse::Left)
				{
					if (bplay.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						gamestate = 4;
						window.clear();

						window.draw(background_menu);
						window.draw(mod1);
						window.draw(mod2);
						window.draw(mod3);
						window.draw(buttbacktomenu);

						window.display();
					}
					break;
				}

			}

		}
		/*
		while (gamestate == 1) {
			cout << "This is gamemode 1 typing master\n";
			string input = "";
			cout << "pimaraigordai\n";
			getline(cin, input);
			cout << "your input: " << input << endl;
			if (input == "e") {
				gamestate = 0;
				window.clear();
				window.draw(background_menu);
				window.draw(logo);
				window.draw(bplay);
				window.draw(binfo);
				window.draw(bhigh);
				window.display();
				break;
			}
		}
		while (gamestate == 2) {
			cout << "This is gamemode 2 quiz warrior\n";
			string input = "";
			cout << "pimaraigordai\n";
			getline(cin, input);
			cout << "your input: " << input << endl;
			if (input == "e") {
				gamestate = 0;
				window.clear();
				window.draw(background_menu);
				window.draw(logo);
				window.draw(bplay);
				window.draw(binfo);
				window.draw(bhigh);
				window.display();
				break;
			}
		}
		while (gamestate == 3) {
			cout << "This is gamemode 3 the programmer\n";
			string input = "";
			cout << "pimaraigordai\n";
			getline(cin, input);
			cout << "your input: " << input << endl;
			if (input == "e") {
				gamestate = 0;
				window.clear();
				window.draw(background_menu);
				window.draw(logo);
				window.draw(bplay);
				window.draw(binfo);
				window.draw(bhigh);
				window.display();
				break;
			}

		}

	}
					*/