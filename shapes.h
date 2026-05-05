#pragma once
#include "TextGraphics.h"
#include <iostream>
#include <vector>
using namespace std;
class Shape
{
public:
	virtual void draw(TextGraphics& tg) const = 0;
	void moveCenter(double dx, double dy);
	Shape(double x, double y);
	virtual ~Shape() {};
protected:
	double xCenter, yCenter;
};
class Circle : public Shape
{
public:
	void draw(TextGraphics& tg) const override;
	Circle(double r, double x, double y);
private:
	double radius;
};
class Rect : public Shape
{
public:
	void draw(TextGraphics& tg) const override;
	Rect(double w, double h, double x, double y);
protected:
	double width, height;
};
//adding in the properties of a new shape so that they can be called on in the other files; Amrit
class Triangle : public Shape
{
public:
	Triangle(double b, double h, double x, double y);
	virtual void draw(TextGraphics& tg) const override;
private:
	double base;
	double height;
};
//that's all we need for a new shape here : )

class Square : public Rect
{
public:
	Square(double s, double x, double y);
};
void deleteVector(vector<Shape*>& v);
////////////////////////////////////////////////////////////
