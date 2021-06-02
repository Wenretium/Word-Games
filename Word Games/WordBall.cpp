#include"WordBall.h"
int WordBall::count = 0;//静态数据成员，控制在场球数
WordBall::WordBall(Word a, int xx, double sspeed) :Word(a.word, a.meaning), Ball(xx, 10), speed(sspeed)
{
	count++;
}
void WordBall::operator()(WordBall w)//用来替代print成员函数，便于使用for_each算法
{
	setcolor(BLACK);
	IMAGE cat;
	loadimage(&cat, _T("..\\cat1.jpg"), 75, 50, true);
	putimage(w.x, w.y, &cat);
	setbkmode(TRANSPARENT);
	const char* c = (w.word).c_str();
	int movesteps = 0;
	if (w.word.size() <= 6)movesteps = 12;
	outtextxy(w.x + movesteps, w.y + 25, c);
}
/*void WordBall::print()
{	
	setcolor(BLACK);
	IMAGE cat;
	loadimage(&cat, _T("..\\cat1.jpg"), 75, 50, true); 
	putimage(x, y, &cat);
	setbkmode(TRANSPARENT);
	const char* c = (this->word).c_str();
	int movesteps = 0;
	if (this->word.size() <= 6)movesteps = 12;
	outtextxy(x + movesteps, y + 25, c);
}*/
bool operator==(WordBall a, WordBall b)
{
	if (a.getWord() == b.getWord() && a.getMeaning() == b.getMeaning())
		return true;
	else return false;
}