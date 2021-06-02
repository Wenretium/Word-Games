#pragma once
#pragma once
#include"Word.h"
class WordBall :public Word, public Ball
{
private:
	double speed;
public:
	WordBall() :Word(), Ball() {};
	WordBall(Word a, int xx, double sspeed);
	WordBall(const WordBall& wb) :Word(wb), Ball(wb), speed(wb.speed){ count++; }
	~WordBall() { count--; }
	int getX() { return x; }
	int getY() { return y; }
	void falldown(int time) { y += speed * time; }
	/*virtual void print();*/
	static int count;
	friend bool operator==(WordBall a, WordBall b);
	void operator()(WordBall w);
};