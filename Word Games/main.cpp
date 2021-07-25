#include"WordBall.h"
#include"WordPiece.h"
#include"WordBurger.h"
#pragma comment(lib,"winmm.lib")//timeGetTime()����
const int Width = 1000;
const int Height = 700;
const int Ground = Height - 48;
const int Limit = Ground - BasketSize * 67 / 220;
const double BasketSpeed = 0.5;
const int BasketSize = 110;//����
const int WordBallSize = 35;//�뾶
const int HeartSize = 20;
const int CatWidth = 90;
const int CatHeight = 60;
const int LetterSize = 80;
const int LayerThickness = 80;
const int LayerWidth = 200;
const double LayerSpeed = 0.2;
using namespace std;
void wordmean_separate(string &wordmean, string& nword, string& nmeaning);
void printStage(int score, int lives, IMAGE heart,IMAGE heart_b);
void printLose(vector<Word>& list);
void print_onshow(Word* onshow_word);
void print_Record(ifstream& readFile);
int main()
{
	//get words
	vector<Word>words;
	ifstream readFile("..\\myCET-4.txt");
	string s;
	while (getline(readFile, s, '\n'))//sentences
	{
		string nword, nmeaning;
		wordmean_separate(s, nword, nmeaning);
		words.push_back(Word(nword, nmeaning));
	}
	int words_num = words.size();
	readFile.close();
	//settings
	initgraph(Width, Height, SHOWCONSOLE);
	HWND hwnd = GetHWnd();
	MoveWindow(hwnd, 50, 0, Width, Height, true);
	//
	int score;
	int lives;
	
	IMAGE heart;
	IMAGE heart_b;
	loadimage(&heart, _T("..\\heartblack.jpg"), HeartSize, HeartSize, true);
	loadimage(&heart_b, _T("..\\heart_b.jpg"), HeartSize, HeartSize, true);
	BeginBatchDraw();
	
	//cover
	IMAGE g1;
	IMAGE g2;
	IMAGE g3;
	IMAGE play;
	IMAGE exit;
	IMAGE back;
	IMAGE back_b;
	loadimage(&g1, _T("..\\cover\\Game1.jpg"), 200, 200, true);
	loadimage(&g2, _T("..\\cover\\Game2.jpg"), 200, 200, true);
	loadimage(&g3, _T("..\\cover\\Game3.jpg"), 200, 200, true);
	loadimage(&play, _T("..\\cover\\play.jpg"), 130, 55, true);
	loadimage(&exit, _T("..\\cover\\exit.jpg"), 130, 55, true);
	loadimage(&back, _T("..\\cover\\back.jpg"), 90, 90, true);
	loadimage(&back_b, _T("..\\cover\\back_b.jpg"), 90, 90, true);
	string instuction0("��Ϸ˵����");
	string instuction1a("��AD�����ƶ�����ס���½����Ķ�Ӧ�ĵ��ʡ�");
	string instuction1b("�ӶԵ�һ�֣��Ӵ��һ�֣�û�ӵ���һ����������3��������");
	string instuction2a("�������������ε�����½����Ķ�Ӧ�ĵ��ʸ���ĸ��");
	string instuction2b("ƴ�Ե�һ�֣�ƴ���һ����������3��������");
	string instuction3a("��������ƶ�����ס��������ĺ����㡣");
	string instuction3b("�ӵ�����������һ�֣�������Ϸ������");
	string instuction4("��play��ʼ��Ϸ��");
	const char* c0 = instuction0.c_str();
	const char* c1a = instuction1a.c_str();
	const char* c1b = instuction1b.c_str();
	const char* c2a = instuction2a.c_str();
	const char* c2b = instuction2b.c_str();
	const char* c3a = instuction3a.c_str();
	const char* c3b = instuction3b.c_str();
	const char* c4 = instuction4.c_str();
	FlushBatchDraw();
	bool exitflag = false;
	while (!exitflag)
	{
		bool lose = false;
		int game = 0;
		int readygame = 0;
		vector<Word>wrongwords;
		vector<Word>rightwords;
		setbkcolor(RGB(255, 252, 232));
		while (!game && !exitflag)
		{
			cleardevice();
			putimage(100, 150, &g1);
			putimage(350, 150, &g2);
			putimage(600, 150, &g3);
			putimage(380, 500, &play);
			putimage(380, 575, &exit);
			int cx = 0, cy = 0;
			if (MouseHit())
			{
				MOUSEMSG msg = GetMouseMsg();
				if (msg.uMsg == WM_LBUTTONDOWN)//�������				
				{
					cx = msg.x;
					cy = msg.y;
				}
			}
			if (cx >= 100 && cx <= 300 && cy >= 150 && cy <= 350)readygame = 1;
			else if (cx >= 350 && cx <= 550 && cy >= 150 && cy <= 350)readygame = 2;
			else if (cx >= 600 && cx <= 800 && cy >= 150 && cy <= 350)readygame = 3;
			else if (cx >= 380 && cx <= 510 && cy >= 500 && cy <= 555)game = readygame;
			else if (cx >= 380 && cx <= 510 && cy >= 575 && cy <= 630)exitflag = true;
			setcolor(RED);
			if (readygame == 1 || readygame == 2 || readygame == 3)
			{
				line(100 + 250 * (readygame - 1) - 10, 150 - 10, 300 + 250 * (readygame - 1) + 10, 150 - 10);
				line(300 + 250 * (readygame - 1) + 10, 150 - 10, 300 + 250 * (readygame - 1) + 10, 350 + 10);
				line(100 + 250 * (readygame - 1) - 10, 350 + 10, 300 + 250 * (readygame - 1) + 10, 350 + 10);
				line(100 + 250 * (readygame - 1) - 10, 150 - 10, 100 + 250 * (readygame - 1) - 10, 350 + 10);
				setcolor(BLACK);
				outtextxy(570, 540, c0);
				outtextxy(570, 630, c4);
				switch (readygame)
				{
				case 1:
					outtextxy(570, 570, c1a);
					outtextxy(570, 600, c1b); break;
				case 2:
					outtextxy(570, 570, c2a);
					outtextxy(570, 600, c2b); break;
				case 3:
					outtextxy(570, 570, c3a);
					outtextxy(570, 600, c3b); break;
				}
			}
			FlushBatchDraw();
		}

		//Game One
		if (game == 1)
		{
			SetWindowText(hwnd, "Game One");
			srand(int(time(0)));
			Basket my(400, Ground - BasketSize);
			score = 0;
			lives = 3;
			deque<WordBall>present_balls;
			bool waiting = false;
			int time=0;
			double interval;
			int havewaited;
			deque<WordBall>ready_balls;
			bool finding = false;
			WordBall goalball;
			//
			DWORD t1, t2;
			setbkcolor(RGB(246, 233, 217));
			while (!lose)
			{
				/*setcolor(WHITE);
				line(50, 50, 60, 50);
				FlushBatchDraw();*/
				t1 = timeGetTime();
				/*IMAGE background;
				loadimage(&background, _T("E:\\�������\\WordsGame\\background.jpg"), Width, Height, true);
				putimage(0, 0, &background);*/
				cleardevice();
				my.print("basket");//��ӡ����
				if (!finding)
				{
					//�������λ��x��100-900���ٶȣ�0.1-0.2
					goalball = WordBall(words[rand() % (words_num - 1)], rand() % 800 + 100, (rand() % 100 + 100) / 1000.0);
					ready_balls.push_back(goalball);
					ready_balls.push_back(WordBall(words[rand() % (words_num - 1)], rand() % 800 + 100, (rand() % 100 + 100) / 1000.0));
					ready_balls.push_back(WordBall(words[rand() % (words_num - 1)], rand() % 800 + 100, (rand() % 100 + 100) / 1000.0));
					ready_balls.push_back(WordBall(words[rand() % (words_num - 1)], rand() % 800 + 100, (rand() % 100 + 100) / 1000.0));
					random_shuffle(ready_balls.begin(), ready_balls.end());
					finding = true;
				}
				if (finding)
				{
					string tempstring = goalball.getMeaning();
					const char* c = tempstring.c_str();
					setbkmode(TRANSPARENT);
					setcolor(RED);
					outtextxy(20, 625, c);
				}
				if (!waiting)
				{
					interval = rand() % 1500 + 500;//0.5s-2s
					havewaited = 0;
					waiting = true;
				}
				if (havewaited >= interval && WordBall::count <= 5)//if the number of balls is not more than 5
				{
					if (!ready_balls.empty())
					{
						present_balls.push_back(WordBall(ready_balls.front()));
						ready_balls.erase(ready_balls.begin());
					}
					else present_balls.push_back(WordBall(words[rand() % (words_num - 1)], rand() % 800 + 100, (rand() % 100 + 100) / 1000.0));
					waiting = false;
				}
				printStage(score, lives, heart, heart_b);
				for_each(present_balls.begin(), present_balls.end(), WordBall());			

				FlushBatchDraw();
				for (deque<WordBall>::iterator iter= present_balls.begin(); iter!= present_balls.end();)//����̨��ÿ������б���
				{				
					//present_balls.front().print(false);//��ȥ������
					/*if (present_balls.front().getY()+WordBallSize >= Limit)*///�򵽴���͵�
					if (iter->getY() + CatHeight >= Limit)
					{					
							//�����ӽ�ס
						if (iter->getX() - my.getX() >= -30 && my.getX() + BasketSize - (iter->getX() + CatWidth) >= -30)
						{
							if (*iter == goalball)//�ӵ�Ŀ����
							{
								finding = false;
								score++;
								rightwords.push_back(Word(present_balls.front()));
								/*setcolor(RED);
								char getscore[3]  = "+1";

								outtextxy(my.getX() + BasketSize + 10, Limit + 10, getscore);
								Sleep(50);*/
							}
							else//�ӵ������� 
							{
								score--;
								wrongwords.push_back(Word(*iter));
							}
						}
						else if (*iter == goalball)//û�ӵ�Ŀ����
						{
							lives--;
							finding = false;
							wrongwords.push_back(Word(*iter));
						}
						iter=present_balls.erase(iter);//ɾ������ע�������ʧЧ����					
						continue;
					}
					else 
					{	
						iter->falldown(time);//����������
						iter++;
					}
				}
				//my.print(false);//��ȥ����
				if (_kbhit())
				{
					char c = _getch();
					if (c == 'A' || c == 'a')my.move(-BasketSpeed * time);
					else if (c == 'D' || c == 'd')my.move(BasketSpeed*time);
				}
				t2 = timeGetTime();
				time = t2 - t1;
				havewaited += time;
				if (lives == 0)
				{
					lose = true;
					cleardevice();
					printStage(score, lives, heart, heart_b);
				}
				//cout << time << endl;//�������50ms�ڣ���֤������
			}
		}
		//Game Two
		else if (game == 2)
		{
			SetWindowText(hwnd, "Game Two");
			setbkcolor(RGB(188, 216, 235));

			score = 0;
			lives = 3;
			srand(int(time(0)));
			while (!lose)
			{
				cleardevice();
				WordPiece question(words[rand() % (words_num - 1)]);
				question.print();
				setcolor(BLACK);
				string questionmeaning = question.getMeaning();
				const char* c = questionmeaning.c_str();
				outtextxy(20, 625, c);
				printStage(score, lives, heart, heart_b);
				FlushBatchDraw();
				string myanswer;
				int cx = 0, cy = 0;
				while (1)
				{
					if (MouseHit())
					{
						MOUSEMSG msg = GetMouseMsg();
						if (msg.uMsg == WM_LBUTTONDOWN)//�������				
						{
							cx = msg.x;
							cy = msg.y;
							if (question.check_click(cx, cy))//��Ч�����ˢ��
							{
								cleardevice();
								question.print();
								printStage(score, lives, heart, heart_b);
								outtextxy(20, 625, c);
								FlushBatchDraw();
								/*cout << cx << " " << cy << endl;*/
								if (question.letterballs_empty())
								{
									if (question.getMyanswer() == question.getWord())
									{
										score++;
										rightwords.push_back(Word(question.getWord(), question.getMeaning()));
										break;//��ȷ����һ��
									}
									else//����
									{
										lives--;
										wrongwords.push_back(Word(question.getWord(), question.getMeaning()));
										break;
									}
								}
							}
						}
					}
				}
				if (lives == 0)
				{
					lose = true;
					cleardevice();
					printStage(score, lives, heart, heart_b);
				}
			}
		}
		//Game Three
		else if (game == 3)
		{
			POINT point = { 0,0 };
			SetWindowText(hwnd, "Game Three");
			//setbkcolor(RGB(188, 216, 235));
			IMAGE background;
			loadimage(&background, _T("..\\hamburger\\food_delivery.jpg"), Width - 15, 662, true);
			score = 0;
			lives = 1;
			int interval = 3000;//3s
			int havewaited = 0;
			int pastedtime;
			int limit;
			double speed = LayerSpeed;
			srand(int(time(0)));
			Basket mybread(400, Ground - LayerThickness);
			DWORD t1, t2;
			while (!lose)
			{
				WordBurger onshow(words[rand() % (words_num - 1)]);
				list<LetterBall*>present_balls;
				limit = Ground - 50;
				int positions[10] = { 0 };

				bool over = false;
				while (!over && !lose)
				{
					putimage(0, 0, &background);

					t1 = timeGetTime();
					if (havewaited >= interval)
					{
						if (onshow.moveNextLetter(present_balls))
						{
							havewaited = 0;
							limit -= 40;
						}
						else 
						{ 
							over = true; 
							score++;
						}
					}

					//�ƶ����//��֤ͬ����
					GetCursorPos(&point);//��¼���Ǿ�������
					mybread.set(point.x - 50 - LayerWidth / 2);//�����������+����������
					mybread.print("bread");

					//����
					int j = 0;//����forѭ����һ���־ͻ���ֱ�����
					for (list<LetterBall*>::iterator iter = present_balls.begin(); iter != present_balls.end(); iter++, j++)
					{
						LetterBallB* tempp = dynamic_cast<LetterBallB*>(*iter);
						if (tempp->getStop() == false)//��ûֹͣ
						{
							if (!tempp->fall(limit, LayerSpeed*pastedtime))//Ӧ��ֹͣ
							{
								positions[j] = (*iter)->getX() - point.x;//��¼�¸������λ��					
								if (abs(positions[j] + 50 + LayerWidth / 2) >= 50) { lives--; break; }//û��ס

							}
						}
						//�Ѿ�ֹͣ
						else/* if(tempp->getStop()==true)*/
						{
							tempp->set(point.x + positions[j]);
						}
					}
					/*for_each(present_balls.begin(), present_balls.end(),mem_fun(&LetterBallB::print));*/
					for (auto p : present_balls) p->print();
					/*for (list<LetterBall*>::iterator iter = present_balls.begin(); iter != present_balls.end(); iter++)
						(*iter)->print();*/
					//
					setcolor(BLACK);
					settextstyle(22, 0, _T("΢���ź�"));
					string onshowmeaning = onshow.getMeaning();
					const char* c = onshowmeaning.c_str();
					outtextxy(20, 635, c);
					printStage(score, lives, heart, heart_b);

					FlushBatchDraw();
					t2 = timeGetTime();
					pastedtime = t2 - t1;
					havewaited += pastedtime;

					if (lives == 0)
					{
						lose = true;
						printStage(score, lives, heart, heart_b);
					}
				
				}//һ�����ʽ���
				putimage(0, 0, &background);
				printStage(score, lives, heart, heart_b);
				print_onshow(&onshow);
			}
		}
		
		if (game)//You lose  ����
		{
			printLose(wrongwords);
			
			//Record  ��¼ÿ����Ϸ����&����
			multimap<int,string>records;
			ifstream readFile;
			ofstream recordScore;
			switch (game)
			{		
			case 1:
				readFile.open("..\\Record1.txt");	break;
			case 2:
				readFile.open("..\\Record2.txt"); break;
			case 3:
				readFile.open("..\\Record3.txt"); break;
			}			
			string strrecord;
			while (getline(readFile, strrecord, '\n'))
			{
				int nscore;
				string strnscore;
				string ndate;
				for(int i=0;i<strrecord.size();i++)
					if (!isdigit(strrecord[i])) 
					{ 
						strnscore = strrecord.substr(0, i);
						nscore=stoi(strnscore, 0, 10);
						ndate= strrecord.substr(i, strrecord.size()-i+1);
						break;
					}
				records.insert(make_pair(nscore, ndate));
			}
			readFile.close();
			readFile.clear(ios::goodbit);
			SYSTEMTIME sys;
			GetLocalTime(&sys);
			int intdate[3] = { sys.wYear , sys.wMonth , sys.wDay};
			string strdate[3];
			string nowdate = "      ";
			for (int i = 0; i < 3; i++)
			{
				stringstream ss;
				ss <<intdate[i];
				ss >>strdate[i];
				nowdate += strdate[i];
				if(i!=2)nowdate+="/";
			}
			if(records.size()<5)records.insert(make_pair(score,nowdate));//��¼5����߷�
			else
			{
				if ((*records.begin()).first < score)//create new record 
				{
					records.erase(records.begin());
					records.insert(make_pair(score, nowdate));
				}
			}	
			switch (game)
			{
			case 1:
				recordScore.open("..\\Record1.txt"/*, ios_base::app*/); break;
			case 2:
				recordScore.open("..\\Record2.txt"/*, ios_base::app*/); break;
			case 3:
				recordScore.open("..\\Record3.txt"/*, ios_base::app*/); break;
			}
			for (multimap<int, string>::const_reverse_iterator iter = records.rbegin(); iter != records.rend(); iter++)
				recordScore << iter->first  << iter->second << endl;//����txt��
				recordScore.close();	
				switch (game)
				{
				case 1:
					readFile.open("..\\Record1.txt");
					break;
				case 2:
					readFile.open("..\\Record2.txt");
					break;
				case 3:
					readFile.open("..\\Record3.txt");
					break;
				}
			print_Record(readFile);
			readFile.close();
	
			//Refresh mylist  (����Ϸ12)ն���ѱ����ʣ��õ��ʲ������ڵ��ʿ��г���
			if (game == 1 || game == 2)
			{
				ofstream refresh("..\\myCET-4.txt");//�ҵĴʻ��
				refresh_alist(rightwords, words, refresh);
				refresh.close();
			}

			//����
			putimage(880, 500, &back_b, SRCAND);
			putimage(880, 500, &back, SRCPAINT);
			FlushBatchDraw();
			bool next = false;
			while (!next)
			{
				int cx = 0, cy = 0;
				if (MouseHit())
				{
					MOUSEMSG msg = GetMouseMsg();
					if (msg.uMsg == WM_LBUTTONDOWN)//�������				
					{
						cx = msg.x;
						cy = msg.y;
					}
				}
				if (cx >= 880 && cx <= 970 && cy >= 500 && cy <= 590)next = true;
			}
		}
	}
	EndBatchDraw();

	return 0;
}
void printStage(int score, int lives, IMAGE heart,IMAGE heart_b)
{

	//
	setbkmode(TRANSPARENT);
	//Score
	string strscore = "Score��";
	string newstr = strscore + to_string(score);
	const char* tempc = newstr.c_str();
	outtextxy(900, 615, tempc);
	//Lives
	if (lives == 1)
	{
		putimage(900, 590, &heart_b, SRCAND);
		putimage(900, 590, &heart, SRCPAINT);
	}
	else if (lives == 2)
	{
		putimage(900, 590, &heart_b, SRCAND);	
		putimage(900, 590, &heart, SRCPAINT);
		putimage(900 + HeartSize + 2, 590, &heart_b, SRCAND);
		putimage(900 + HeartSize + 2, 590, &heart, SRCPAINT);
	}
	else if (lives == 3)
	{
		putimage(900, 590, &heart_b, SRCAND);
		putimage(900, 590, &heart, SRCPAINT);
		putimage(900 + HeartSize + 2, 590, &heart_b, SRCAND);
		putimage(900 + HeartSize + 2, 590, &heart, SRCPAINT);
		putimage(900 + (HeartSize + 2) * 2, 590, &heart_b, SRCAND);
		putimage(900 + (HeartSize + 2) * 2, 590, &heart, SRCPAINT);
	}
}
void printLose(vector<Word>& list)
{
	string youlose = "You Lose";
	const char* cyoulose = youlose.c_str();
	setcolor(RED);
	outtextxy(450, 50, cyoulose);
	setcolor(BLACK);
	for (int i = 0; i < list.size(); i++)
	{
		string tempword = list[i].getWord();
		const char* cword = tempword.c_str();
		string tempmeaning = list[i].getMeaning();
		const char* cmeaning = tempmeaning.c_str();
		outtextxy(400, 150 + i * 22, cword);
		outtextxy(500, 150 + i * 22, cmeaning);
	}
}
void print_onshow(Word* onshow_word)
{
	setcolor(BLACK);
	settextstyle(22, 0, _T("΢���ź�"));
	string tempword = onshow_word->getWord();
	const char* cword = tempword.c_str();
	string tempmeaning = onshow_word->getMeaning();
	const char* cmeaning = tempmeaning.c_str();
	outtextxy(400, 150, cword);
	outtextxy(500, 150, cmeaning);
	FlushBatchDraw();
	Sleep(3000);//3s
}
void print_Record(ifstream& readFile)
{
	string Record = "Record:";
	const char* tempcr = Record.c_str();
	outtextxy(810, 175, tempcr);
	string nrecord;
	int i = 0;
	while (getline(readFile, nrecord, '\n'))
	{
		const char* tempc = nrecord.c_str();
		outtextxy(800, 200+i*25, tempc);
		i++;
	}
}