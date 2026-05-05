#include "Shapes.h"
Shape::Shape(double x, double y) :xCenter(x), yCenter(y) {}
void Shape::moveCenter(double dx, double dy)
{
	xCenter += dx;
	yCenter += dy;
}
void Circle::draw(TextGraphics& tg) const
{
	for (int i = 0; i < tg.height(); i++)
	{
		for (int j = 0; j < tg.width(); j++)
		{
			if (((j - xCenter) * (j - xCenter)) / (1.0 * radius * radius) + ((i -
				yCenter) * (i - yCenter)) / (1.0 * radius * radius) <= 1.0)
			{
				tg.putCharAt(i, j, '*', Color::Cyan);
			}
		}
	}
}
Circle::Circle(double r, double x, double y) :Shape(x, y), radius(r) {}
void Rect::draw(TextGraphics& tg) const
{
	//To do: draw me!
	for (int i = yCenter - height / 2; i < yCenter + height / 2; i++)
	{
		for (int j = xCenter - width / 2; j < xCenter + width / 2; j++)
		{
			if (i >= 0 && i < tg.height() && j >= 0 && j < tg.width())
			{
				tg.putCharAt(i, j, '#', Color::Green);
			}
		}
	}
}
Rect::Rect(double w, double h, double x, double y) :Shape(x, y), width(w),
height(h) {
}
Square::Square(double s, double x, double y) :Rect(s, s, x, y) {}
void deleteVector(vector<Shape*>& v)
{

	for (auto p : v)
	{
		delete p;
	}
	v.clear();
}
//here we're describing the math behind the triangle we want to print - Amrit
Triangle::Triangle(double b, double h, double x, double y)
	: Shape(x, y), base(b), height(h) {}

void Triangle::draw(TextGraphics& tg) const {
	for (int i = 0; i < tg.height(); i++) {
		for (int j = 0; j < tg.width(); j++) {
		//I'm choosing to do an isoceles facing upwards (bigger on bottom)
			double relativeY = i - (yCenter - height / 2);
			double halfWidthAtY = (relativeY / height) * (base / 2);
			//we declared height and base in the shapes.h : )

			if (relativeY >= 0 && relativeY <= height) {
				double halfWidthAtY = (relativeY / height) * (base / 2.0);

				if (j >= xCenter - halfWidthAtY && j <= xCenter + halfWidthAtY) {
					tg.putCharAt(i, j, '^', Color::Red);
				}
			}
		}
	}
}
