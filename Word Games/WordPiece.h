#pragma once
#include"Word.h"

// �̳�Ball������˽�г�Ա��ĸ����ΪGame2��ÿ�����ֵ���ĸ
class LetterBall :public Ball
{
protected:
	char letter;
public:
	LetterBall(char nletter, int xx, int yy) :Ball(xx, yy), letter(nletter) {}
	virtual void print()=0;
	char getLetter() { return letter; }
};

// ����LetterBall��������ʵ��Game2�в�ͬ���������Ǿ����ˣ�
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

// ����Game2��ÿ�ִ���һ��WordPiece
// ��WordӢ�ĵ��ʲ��һ��LetterBall������letterballs��myanswer��������õ��Ľ��
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
