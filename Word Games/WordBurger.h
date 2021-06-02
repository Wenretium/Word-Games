#pragma once
#include<list>
#include"Word.h"
class LetterBall;
class LetterBallB;
class WordBurger :public Word
{
private:
	list<LetterBall*>letterlayers;
public:
	WordBurger(Word nword);
	~WordBurger();
	virtual void print() ;
	bool moveNextLetter(list<LetterBall*>& ls);
	bool letterlayers_empty();
};