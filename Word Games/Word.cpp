#include"Word.h"

//Word
Word::Word(string nword, string nmeaning) : word(nword), meaning(nmeaning)
{

}
ostream& operator<<(ostream& cout, Word a)
{
	cout << a.word << " " << a.meaning << endl;
	return cout;
}
void Word::print()const
{
	cout << *this;
}
//功能：获取
void wordmean_separate(string &wordmean, string& nword, string& nmeaning)
{
	int word_begin;
	int word_end;
	int meaning_begin;
	bool flag1 = false;//word begins
	bool flag2 = false;//word ends
	for (int i = 0; i < wordmean.size(); i++)
	{
		if (flag1 != true &&isalpha(wordmean[i]))
		{
			word_begin = i;
			flag1 = true;
		}
		else if (flag1 == true && flag2 == false && wordmean[i] == ' ')
		{
			word_end = i - 1;
			flag2 = true;
		}
		else if (flag2 == true && wordmean[i] != ' ')
		{
			meaning_begin = i;
			break;
		}
	}
	nword = wordmean.substr(word_begin, word_end - word_begin + 1);
	nmeaning = wordmean.substr(meaning_begin, wordmean.size() - meaning_begin + 1);
}
//Basket
void Basket::print(string item)
{
	IMAGE bas;
	//路径太长也会导致无法输出图片
	if (item == "basket") 
	{ 
		loadimage(&bas, _T("..\\basket.jpg"), BasketSize, BasketSize, true); 
		putimage(x, y, &bas);
	}
	else if (item == "bread")
	{
		loadimage(&bas, _T("..\\hamburger\\bread_begin.jpg"), LayerWidth, LayerThickness, true);
		IMAGE maskbitmap; //掩码图
		loadimage(&maskbitmap, _T("..\\hamburger\\bread_begin_b.jpg"), LayerWidth, LayerThickness, true);
		putimage(x, y, &maskbitmap, SRCAND);
		putimage(x, y, &bas, SRCPAINT);
	}
}

void Basket::move(int step)
{
	x += step;
	if (x <= 0 && step < 0)x = Width;
	if (x >= Width && step > 0)x = 0;
}
bool Word::operator==(Word a)
{
	if (word == a.word&&meaning == a.meaning)
		return true;
	else return false;
}
bool Word::operator>(Word w)
{
	if (this->word > w.word)return true;
	else return false;
}
bool Word::operator<(Word w)
{
	if (this->word < w.word)return true;
	else return false;
}
