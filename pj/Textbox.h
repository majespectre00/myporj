#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class NTextbox {
public:
	NTextbox(){ }

	NTextbox(int size, sf::Color color, bool sel) {
		textbox.setCharacterSize(size);
		textbox.setColor(color);
		isSeleted = sel;
		if (sel) {
			textbox.setString("_");
		}
		else {
			textbox.setString("");
		}
	}
	void setFont(sf::Font& font) {
		textbox. setFont(font);
	}

	void setPosition(sf::Vector2f pos) {
		textbox. setPosition(pos);
	}
	void setLimit(bool ToF) {
		haslimit = ToF;
	}
	void setLinit(bool ToF, int lim) {
		haslimit = ToF;
		limit = lim-1;
	}

	void setSelected(bool sel) {
		isSeleted = sel;
		if (!sel) {
			std::string t = text.str();
			std::string newT = "";
			for (int i = 0; i < t.length() - 1;i++) {
				newT += t[i];
			}
			textbox.setString(newT);
		}
	}
	std::string getText() {
		return text.str();
	}

	void drawTo(sf::RenderWindow& window) {
		window.draw(textbox);
	}
	void typedOn(sf::Event input) {
		if (isSeleted) {
			int charTyped = input.text.unicode;
			if (charTyped < 128) {
				if (haslimit) {
					if (haslimit) {
						if (text.str().length() <= limit) {
							inputlogic(charTyped);
						}
						else if (text.str().length() > limit && charTyped == DELETE_KEY) {
							deleteLastchar();
						}
					}
					else {
						inputlogic(charTyped);
					}
				}
			}
		}
	}
private:
	sf::Text textbox;
	std::ostringstream text;
	bool isSeleted = false;
	bool haslimit = false;
	int limit;

	void inputlogic(int charTyped) {
		if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped
			!= ESCAPE_KEY)
		{
			text << static_cast<char>(charTyped);
		}
		else if (charTyped == DELETE_KEY) {
			if (text.str().length() > 0) {
				deleteLastchar();
			}
		}
		textbox.setString(text.str() + "_");
	}
	void deleteLastchar() {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length();i++) {
			newT += t[i];
		}
		text.str("");
		text << newT;
		textbox.setString(text.str());
	}
};