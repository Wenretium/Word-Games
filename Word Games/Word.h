#pragma once
#include<string>
#include<iostream>
#include<graphics.h>
#include<vector>
#include<Windows.h>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<conio.h>
#include<algorithm>
#include<map>
#include<sstream>
#include<ctype.h>
#include<iterator>
#include<functional>
extern const int Width;
extern const int Height;
extern const int Limit;
extern const int WordBallSize;
extern const int BasketSize;
extern const int HeartSize;
extern const int LetterSize;
extern const int LayerThickness;
extern const int LayerWidth;
using namespace std;
// ������������
// Word������Ӣ�ĺͶ�Ӧ��˼����˽�г�Ա����WordBall��
class Word
{
private:
	string word;
	string meaning;
public:
	Word(string nword = "", string nmeaning = "");
	string getWord() { return word; }
	string getMeaning() { return meaning; }
	virtual void print()const;
	friend ostream& operator<<(ostream& cout, Word a);
	friend class WordBall;
	friend class WordPiece;
	friend class WordBurger;
	bool operator==(Word a);
	bool operator>(Word w);
	bool operator<(Word w);
};
//
class Ball
{
protected:
	int x;
	int y;
public:
	Ball() :x(0), y(0) {}
	Ball(int xx, int yy) :x(xx), y(yy) {}
	int getX() { return x; }
	int getY() { return y; }
	friend class WordBall;
	friend class LetterBall;
	friend class WordPiece;
};
//
class Basket
{
private:
	int x;
	int y;
public:
	Basket() :x(100), y(Limit) {}
	Basket(int xx, int yy) :x(xx), y(yy) {}
	void move(int step);
	void set(int nx) { x = nx; }
	int getX() { return x; }
	int getY() { return y; }
	void print(string item);
};
template<typename T>//����ģ�壬��alist�����ݴ�blist���޳�������blist��ӡ��btxt��
void refresh_alist(vector<T> alist, vector<T> blist, ofstream& btxt)
{
	for (int i = 0; i < alist.size(); i++)
	{
		typename vector<T>::iterator iter = find(blist.begin(), blist.end(), alist[i]);//find�㷨
		if (iter != blist.end())
			blist.erase(iter);
	}
	for (int i = 0; i < blist.size(); i++)
		btxt << blist[i];
}
