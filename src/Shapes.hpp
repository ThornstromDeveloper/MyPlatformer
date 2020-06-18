#ifndef SHAPES_HPP
#define SHAPES_HPP

class Point
{
public:
	float x;
	float y;

	Point();
	Point(float x, float y);
};

struct Rectangle
{
	float x;
	float y;
	int w;
	int h;

	float top;
	float bottom;
	float leftmost;
	float rightmost;

	Point center;
	Point leftCenter;
	Point rightCenter;
	Point topLeft;
	Point topRight;
	Point topCenter;
	Point bottomLeft;
	Point bottomRight;
	Point bottomCenter;

	Rectangle(float x, float y, int w, int h);
	Rectangle(Point topLeft, Point bottomRight);
	Rectangle(Rectangle* other);
	Rectangle();

	void copy(Rectangle* other);
	void addX(float x);
	void addY(float y);
	void setX(float x);
	void setY(float y);
	void stretch(float scale);
	void stretch(float scaleX, float scaleY);
	void update();
	bool overlaps(Rectangle other);
	bool overlaps(Rectangle* other);
	void placeOnTop(Rectangle* other);
};

struct Circle
{
	float x;
	float y;
	int r;

	float centerX;
	float centerY;

	Circle(float x, float y, int r);

	void addX(float x);
	void addY(float y);
};

#endif //SHAPES_HPP