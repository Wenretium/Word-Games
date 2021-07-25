#pragma once
#include<list>
#include"Word.h"
class LetterBall;
class LetterBallB;

// 用于Game3，每局创建一个WordBurger
// 把Word英文单词拆成一组LetterBall，存入letterlayers
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