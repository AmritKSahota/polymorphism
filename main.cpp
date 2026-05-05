#include <iostream>
#include "TextGraphics.h"
#include "Shapes.h"
int main()
{
	srand(time(0)); //seed RNG with current time
	char input = 0;
	TextGraphics graphics;
	std::vector<Shape*> v;
	unsigned long long frameCount = 0;
	while (input != ESCAPE) //frame loop
	{
		///input////////////////////////////////////////////////////////
		input = graphics.readKey();
		if (input == '0') // Changed restart to '0' so 'r' is free for Rect
		{
			deleteVector(v);
		}
		if (input == 'c') // Circle
		{
			v.push_back(new Circle(rand() % 5 + 1, rand() % graphics.width(), rand() %

				graphics.height()));
		}
		if (input == 'r') // Rectangle
		{
			v.push_back(new Rect(rand() % 6 + 2, rand() % 4 + 2, rand() % graphics.width(), rand() %

				graphics.height()));
		}
		//adding in triangle to main - Amrit
		if (input == 'v') //triangle
		{
			//randomizing dimensions : )
			double b = rand() % 7 + 3; // base between 3 and 9
			double h = rand() % 5 + 3; // height between 3 and 7
			//making sure it's away from edges
			double x = (rand() % (graphics.width() - (int)b)) + (b / 2);
			double y = (rand() % (graphics.height() - (int)h)) + (h / 2);

			v.push_back(new Triangle(b, h, x, y));
			//v.push_back(new Triangle(b, h, rand() % graphics.width(), rand() % graphics.height()));
		}

		if (input == 's') // Square
		{
			v.push_back(new Square(rand() % 4 + 2, rand() % graphics.width(), rand() %

				graphics.height()));
		}
		
		///Clear and draw////////////////////////////////////////////////
		graphics.clearScreen();
		// Updated Menu String
		std::string s = "c: Circle | r: Rect | s: Square | v: Triangle : ) | 0: Restart";
		graphics.putStringAt(0, graphics.width() / 2 - s.size() / 2, s, Color::Yellow);
		for (Shape* p : v) {
			p->draw(graphics);
		}
		graphics.draw();
		///sleep////////////////////////////////////////////////////////
		frameCount++;
		graphics.sleepMs(20); //50 fps
	}
	return 0;
}
