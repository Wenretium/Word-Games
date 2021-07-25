#pragma once
#include"Word.h"

// 继承Ball，增加私有成员字母，作为Game2中每个浮现的字母
class LetterBall :public Ball
{
protected:
	char letter;
public:
	LetterBall(char nletter, int xx, int yy) :Ball(xx, yy), letter(nletter) {}
	virtual void print()=0;
	char getLetter() { return letter; }
};

// 两个LetterBall子类用于实现Game2中不同的需求（忘记具体了）
class LetterBallA :/*virtual */public LetterBall
{
public:
	LetterBallA(char nletter, int xx, int yy):LetterBall(nletter, xx,yy) {}
	LetterBallA(const LetterBallA& lb):LetterBall(lb){}
	virtual void print();
};

class LetterBallB : /*virtual*/ public LetterBall
{
private:
	int num;
	IMAGE pictures[2];//to save time
	bool stop;
public:
	LetterBallB(char nletter, int xx, int yy,int num);
	LetterBallB(const LetterBallB& lb) :LetterBall(lb),num(lb.num),stop(lb.stop) {}
	bool getStop() { return stop; }
	virtual void print();
	bool fall(int limit, int distance);
	void set(int nx) { x = nx; }
};

// 用于Game2，每局创建一个WordPiece
// 把Word英文单词拆成一组LetterBall，存入letterballs，myanswer是鼠标点击得到的结果
class WordPiece :public Word
{
private:
	vector<LetterBall*>letterballs;
	string myanswer;
public:
	WordPiece(Word a);
	WordPiece(const WordPiece& wp);
	~WordPiece();
	string getWord()const { return word; }
	string getMyanswer()const { return myanswer; }
	void print()const;
	bool check_click(int cx,int cy);
	bool letterballs_empty();
};
