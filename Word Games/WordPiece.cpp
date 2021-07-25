#include"WordPiece.h"
void LetterBallA::print()
{
	IMAGE let;
	// 这里loadimage的第二个参数，如果换成字符串变量或常量，会报错。似乎只能逐个列举，直接写入路径。
	// （也许这就是屎山的由来吧==
	switch(letter)
	{ 
	case 'a':
	case 'A':
		loadimage(&let, _T("..\\Letters\\A.jpg"), LetterSize, LetterSize, true); break;
	case 'b':
	case 'B':
		loadimage(&let, _T("..\\Letters\\B.jpg"), LetterSize, LetterSize, true); break;
	case 'c':
	case 'C':
		loadimage(&let, _T("..\\Letters\\C.jpg"), LetterSize, LetterSize, true); break;
	case 'd':
	case 'D':
		loadimage(&let, _T("..\\Letters\\D.jpg"), LetterSize, LetterSize, true); break;
	case 'e':
	case 'E':
		loadimage(&let, _T("..\\Letters\\E.jpg"), LetterSize, LetterSize, true); break;
	case 'f':
	case 'F':
		loadimage(&let, _T("..\\Letters\\F.jpg"), LetterSize, LetterSize, true); break;
	case 'g':
	case 'G':
		loadimage(&let, _T("..\\Letters\\G.jpg"), LetterSize, LetterSize, true); break;
	case 'h':
	case 'H':
		loadimage(&let, _T("..\\Letters\\H.jpg"), LetterSize, LetterSize, true); break;
	case 'i':
	case 'I':
		loadimage(&let, _T("..\\Letters\\I.jpg"), LetterSize, LetterSize, true); break;
	case 'j':
	case 'J':
		loadimage(&let, _T("..\\Letters\\J.jpg"), LetterSize, LetterSize, true); break;
	case 'k':
	case 'K':
		loadimage(&let, _T("..\\Letters\\K.jpg"), LetterSize, LetterSize, true); break;
	case 'l':
	case 'L':
		loadimage(&let, _T("..\\Letters\\L.jpg"), LetterSize, LetterSize, true); break;
	case 'm':
	case 'M':
		loadimage(&let, _T("..\\Letters\\M.jpg"), LetterSize, LetterSize, true); break;
	case 'n':
	case 'N':
		loadimage(&let, _T("..\\Letters\\N.jpg"), LetterSize, LetterSize, true); break;
	case 'o':
	case 'O':
		loadimage(&let, _T("..\\Letters\\O.jpg"), LetterSize, LetterSize, true); break;
	case 'p':
	case 'P':
		loadimage(&let, _T("..\\Letters\\P.jpg"), LetterSize, LetterSize, true); break;
	case 'q':
	case 'Q':
		loadimage(&let, _T("..\\Letters\\Q.jpg"), LetterSize, LetterSize, true); break;
	case 'r':
	case 'R':
		loadimage(&let, _T("..\\Letters\\R.jpg"), LetterSize, LetterSize, true); break;
	case 's':
	case 'S':
		loadimage(&let, _T("..\\Letters\\S.jpg"), LetterSize, LetterSize, true); break;
	case 't':
	case 'T':
		loadimage(&let, _T("..\\Letters\\T.jpg"), LetterSize, LetterSize, true); break;
	case 'u':
	case 'U':
		loadimage(&let, _T("..\\Letters\\U.jpg"), LetterSize, LetterSize, true); break;
	case 'v':
	case 'V':
		loadimage(&let, _T("..\\Letters\\V.jpg"), LetterSize, LetterSize, true); break;
	case 'w':
	case 'W':
		loadimage(&let, _T("..\\Letters\\W.jpg"), LetterSize, LetterSize, true); break;
	case 'x':
	case 'X':
		loadimage(&let, _T("..\\Letters\\X.jpg"), LetterSize, LetterSize, true); break;
	case 'y':
	case 'Y':
		loadimage(&let, _T("..\\Letters\\Y.jpg"), LetterSize, LetterSize, true); break;
	case 'z':
	case 'Z':
		loadimage(&let, _T("..\\Letters\\Z.jpg"), LetterSize, LetterSize, true); break;
	}
	putimage(x, y, &let);
}
LetterBallB::LetterBallB(char nletter, int xx, int yy, int num) :LetterBall(nletter, xx, yy), num(num),stop(false)
{
	if (num == 0)//bread_end
	{
		loadimage(&pictures[0], _T("..\\hamburger\\bread_end.jpg"), LayerWidth, LayerThickness, true);
		loadimage(&pictures[1], _T("..\\hamburger\\bread_end_b.jpg"), LayerWidth, LayerThickness, true);
	}
	switch (num)
	{
	case 1:loadimage(&pictures[0], _T("..\\hamburger\\stuff1.jpg"), LayerWidth, LayerThickness, true); 
				loadimage(&pictures[1], _T("..\\hamburger\\stuff1_b.jpg"), LayerWidth, LayerThickness, true);
				break;
	case 2:loadimage(&pictures[0], _T("..\\hamburger\\stuff2.jpg"), LayerWidth, LayerThickness, true);
				loadimage(&pictures[1], _T("..\\hamburger\\stuff2_b.jpg"), LayerWidth, LayerThickness, true);
				break;
	case 3:loadimage(&pictures[0], _T("..\\hamburger\\stuff3.jpg"), LayerWidth, LayerThickness, true);
				loadimage(&pictures[1], _T("..\\hamburger\\stuff3_b.jpg"), LayerWidth, LayerThickness, true);
				break;
	case 4:loadimage(&pictures[0], _T("..\\hamburger\\stuff7.jpg"), LayerWidth, LayerThickness, true);
				loadimage(&pictures[1], _T("..\\hamburger\\stuff7_b.jpg"), LayerWidth, LayerThickness, true);
				break;
	case 5:loadimage(&pictures[0], _T("..\\hamburger\\stuff8.jpg"), LayerWidth, LayerThickness, true);
				loadimage(&pictures[1], _T("..\\hamburger\\stuff8_b.jpg"), LayerWidth, LayerThickness, true);
				break;
	case 6:loadimage(&pictures[0], _T("..\\hamburger\\stuff4.jpg"), LayerWidth, LayerThickness, true);
				loadimage(&pictures[1], _T("..\\hamburger\\stuff4_b.jpg"), LayerWidth, LayerThickness, true);
				break;
	case 7:loadimage(&pictures[0], _T("..\\hamburger\\stuff6.jpg"), LayerWidth, LayerThickness, true);
				loadimage(&pictures[1], _T("..\\hamburger\\stuff6_b.jpg"), LayerWidth, LayerThickness, true);
				break;
	case 8:loadimage(&pictures[0], _T("..\\hamburger\\stuff1.jpg"), LayerWidth, LayerThickness, true);
				loadimage(&pictures[1], _T("..\\hamburger\\stuff1_b.jpg"), LayerWidth, LayerThickness, true);
				break;
	case 9:loadimage(&pictures[0], _T("..\\hamburger\\stuff5.jpg"), LayerWidth, LayerThickness, true);
				loadimage(&pictures[1], _T("..\\hamburger\\stuff5_b.jpg"), LayerWidth, LayerThickness, true);
				break;
	}
}
void LetterBallB::print()
{
	IMAGE let;
	loadimage(&let, _T("..\\hamburger\\stuff1.jpg"), LayerWidth, LayerThickness, true);
	putimage(x, y, &pictures[1], SRCAND);
	putimage(x, y, &pictures[0], SRCPAINT);
	setcolor(WHITE);
	settextstyle(30, 0, _T("Consola"));
	outtextxy(x+LayerWidth/2, y+LayerThickness/2,letter);
}
bool LetterBallB::fall(int limit,int distance)
{
	if (y >= limit)
	{ 
		stop = true;
		return false;
	}
	if (stop == false) { y += distance; return true; }
}
WordPiece::WordPiece(Word a) :Word(a)
{
	srand(int(time(0)));
	int xx;
	int yy;
	for (int i = 0; i < word.size(); i++)//x:50-920,y:0-570
	{
		//避免字母间重叠
		bool valid = false;
		while (!valid)
		{
			valid = true;
			xx = rand() % 870 + 50;
			yy = rand() % 570;
			for (int i = 0; i < letterballs.size(); i++)
				if (abs(xx - letterballs[i]->x) <= LetterSize && abs(yy - letterballs[i]->y) <= LetterSize)
				{
					valid = false;
					break;
				}
		}
		if (word[i] >= 'A'&&word[i] <= 'Z')word[i] += 32;
		letterballs.push_back(new LetterBallA(a.word[i], xx, yy));		
	}
}
//深复制
WordPiece::WordPiece(const WordPiece& wp)
{
	for (int i = 0; i < letterballs.size(); i++)
		letterballs.push_back(new LetterBallA(*dynamic_cast<LetterBallA*>(wp.letterballs[i])));
}
WordPiece::~WordPiece()
{
	for(int i = 0; i < letterballs.size(); i++)
	delete letterballs[i];
}
void WordPiece::print()const
{
	for (int i = 0; i < letterballs.size(); i++)
		letterballs[i]->print();
}
bool WordPiece::check_click(int cx,int cy)
{
	for (int i = 0; i < letterballs.size(); i++)
	{
		if ((cx-letterballs[i]->x )<= LetterSize && (cx - letterballs[i]->x)>=0
			&&(cy-letterballs[i]->y) <= LetterSize && (cy - letterballs[i]->y) >= 0)
		{
			myanswer.push_back(letterballs[i]->getLetter());
			letterballs.erase(letterballs.begin()+i);
			return true;
		}
	}
}
bool WordPiece::letterballs_empty()
{
	if (letterballs.empty())return true;
	else return false;
}
