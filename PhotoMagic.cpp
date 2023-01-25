#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdint.h>
#include <string>
#include "FibLFSR.h"

void transform( sf::Image&, FibLFSR*);
uint16_t simple_hash(string s);

int main(int argc, char* argv[])
{
	if (argc != 4)
		return -1;
	
	string input_img = string(argv[1]);
	string output_img = string(argv[2]);
	string seed = string(argv[3]);
	uint16_t hash_value = simple_hash(seed);
	FibLFSR fib(std::to_string(hash_value));
	
	sf::Image ori_img;
	sf::Image image;
	if (!image.loadFromFile(input_img))
		return -1;
	transform(image, &fib);
	
	
	/* windows 1*/
	sf::Vector2u size = image.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Original");

	sf::Texture texture_ori;
	texture_ori.loadFromImage(ori_img);

	sf::Sprite sprite_ori;
	sprite_ori.setTexture(texture_ori);
	
	/* windows 2*/
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Encoded");

	sf::Texture texture;
	texture.loadFromImage(image);

	sf::Sprite sprite;
	sprite.setTexture(texture);
	

	while (window1.isOpen() && window2.isOpen()) 
	{ 
		sf::Event event;
		while (window1.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			window1.close();
		}
		while (window2.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			window2.close();
		}
		window1.clear();
		window1.draw(sprite_ori);
		window1.display();
		window2.clear();
		window2.draw(sprite);
		window2.display();
	}
	
	if (!image.saveToFile(output_img))
		return -1;
	return 0;
}


void transform( sf::Image& image, FibLFSR* fib)
{
	sf::Color p;
	sf::Vector2u size = image.getSize();
	int width = size.x;
	int height = size.y;
	for (int x = 0; x<width; x++) {
		for (int y = 0; y< height; y++) {
			p = image.getPixel(x, y);
			p.r = p.r ^ fib->generate(8);
			p.g = p.g ^ fib->generate(8);
			p.b = p.b ^ fib->generate(8);
			image.setPixel(x, y, p);
		}
	}
}

uint16_t simple_hash(string s)
{
	uint16_t hash_value = 0xA82F;
	for (size_t i = 0; i < s.length(); ++i)
		hash_value = hash_value + (s[i] << 4);
	return hash_value || 0x2FA8;
}


