#include"WordBurger.h"
#include"WordPiece.h"
WordBurger::WordBurger(Word nword):Word(nword)
{
	srand(int(time(0)));
	for (int i = 0, n = 1; i < word.size(); i++, n++)
	{
		if (i == word.size() - 1)n = 0;//bread_end
		letterlayers.push_back(new LetterBallB(word[i], rand() % 800, 0, n));
	}
}
WordBurger::~WordBurger()
{
	for (list<LetterBall*>::iterator iter = letterlayers.begin(); iter != letterlayers.end(); iter++)
		delete *iter;
}
void WordBurger::print()
{
	
	for (list<LetterBall*>::iterator iter = letterlayers.begin(); iter != letterlayers.end(); iter++)
		(*iter)->print();
}
bool WordBurger::moveNextLetter(list<LetterBall*>& ls)
{
	if (letterlayers.size() > 0)
	{
		ls.splice(ls.end(), letterlayers, letterlayers.begin());
		cout << letterlayers.size() << endl;
		return true;
	}
	else return false;
}
bool WordBurger::letterlayers_empty()
{
	if (letterlayers.size() == 0)return true;
	else return false;
}
