#include<iostream>//used for I/O streams
//#include<fstream>
#include<windows.h>//used for coloring scheme
#include<stdlib.h>//for random function
#include<cstdlib>//for random function
#include<ctime>//

using namespace std;

//global variables
int i;
const int ROW=9,COL=9;
int Score=0;
int TargetedScore=1000;
int Moves=20;
int TotalMoves=20;
//pointer variable TS
int *ptrTS=&TargetedScore;

//used to load the board of game
void Map_Load(char [][COL]);
//used to load the main menu
void Loading_Page(char [][COL]);
void instructions(char[][COL]);
//used to burst the matching candies
void Insert_Steric(char[][COL]);
//used to swap b/w candies
void swapping(char[][COL]);
void rewrite(char[][COL]);
//used for the movement of the cursor
void move_cursor_to_xy(int, int);
void result();

//used t generate the candies(as symbols)
void Candy_Generator(char arr[][COL])
{
	//used these symbols as candies
	char candies[5]={'#' , '$' ,'@','?','!'};
	srand(time(0));
	int r;
	for(i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			//random function to show random candies
			r=(rand()%5);
			arr[i][j]=candies[r];
		}
	}
	Loading_Page(arr);
	//recursion
	Candy_Generator(arr);
}
void Loading_Page(char arr[][COL])
{
	int number;
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,3);
	cout<<"\n\n\t\t\t\t\t\t WELCOME TO CANDY CRUSH"<<endl;
	SetConsoleTextAttribute(hConsole,12);
	cout<<"\n\t\t\t\t\t\t LOADING ";
	for(i=0;i<15;i++)
	{
		Sleep(130);
		cout<<".";
	}
	system("CLS");
	SetConsoleTextAttribute(hConsole,10);
	cout<<"\n\n\n\n\n\t\t\t\t\t\t   GAME IS STARTING...\n\n";
	Sleep(1300);
	system("cls");
	SetConsoleTextAttribute(hConsole,11);
	cout<<"\n\n\n\t\t\t\t\t\t      CANDY CRUSH :)";
		SetConsoleTextAttribute(hConsole,10);
	cout<<"\n\n\n\t\t\t\t\t\t      1. NEW GAME\n";
	cout<<"\t\t\t\t\t\t      2. INSTRUCTIONS\n";
	cout<<"\t\t\t\t\t\t      3. EXIT\n\n";
	SetConsoleTextAttribute(hConsole,15);
	cout<<"\t\t\t\t\t     Select one option to continue : ";
	cin>>number;
	if(number==1)
	{
		SetConsoleTextAttribute(hConsole,10);
		cout<<"\n\t\t\t\t\t\t  NEW GAME is Starting..."<<endl;
		//sleep is used to hold the program for a given time
		Sleep(1500);
		//cls is used for clear screen
		system("CLS");
		Map_Load(arr);
	}
	else if(number==2)
	{
		SetConsoleTextAttribute(hConsole,10);
		cout<<"\n\t\t\t\t\t\tInstructions are loading..."<<endl;
		Sleep(1500);
		system("CLS");
		instructions(arr);
		
	}
	else if(number==3)
	{
		SetConsoleTextAttribute(hConsole,10);
		cout<<"\n\t\t\t\t\t\t   Game is Closing..."<<endl;
		Sleep(1700);
		system("CLS");
		SetConsoleTextAttribute(hConsole,12);
		cout<<"\n\n\n\t\t\t\t\t\t.... Game is Closed ....\n\n\n\n\n";
		exit(5);
	}
	else
	{
		SetConsoleTextAttribute(hConsole,15);
		system("CLS");
		cout<<"\n\n\n\t\t\t\t\t....Please select a valid option ....\n"<<endl;
		system("pause");
		system("cls");
		Loading_Page(arr);
	}
}
void Map_Load(char arr[][COL])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,15);
	cout<<" +";
	for(i=1;i<=35;i++)
	{
		Sleep(30);
		cout<<"-";
		
	}
	cout<<"+"<<endl;
	for(i=0;i<9;i++)
	{
		Sleep(30);
		cout<<" | ";
		for(int j=0;j<COL;j++)
		{
			Sleep(30);
			if(arr[i][j]=='#')
			{
				SetConsoleTextAttribute(hConsole,12);
				cout<<arr[i][j];
			}
			else if(arr[i][j]=='$')
			{
				SetConsoleTextAttribute(hConsole,10);
				cout<<arr[i][j];
			}
			else if(arr[i][j]=='?')
			{
				SetConsoleTextAttribute(hConsole,11);
				cout<<arr[i][j];
			}
			else if(arr[i][j]=='@')
			{
				SetConsoleTextAttribute(hConsole,14);
				cout<<arr[i][j];
			}
			else if(arr[i][j]=='!')
			{
				SetConsoleTextAttribute(hConsole,13);
				cout<<arr[i][j];
			}
			SetConsoleTextAttribute(hConsole,15);
			cout<<" | ";
		}
		cout<<endl;
	}
	cout<<" +";
	for(i=1;i<=35;i++)
	{
		Sleep(30);
		SetConsoleTextAttribute(hConsole,15);
		cout<<"-";
	}
	cout<<"+"<<endl;
	SetConsoleTextAttribute(hConsole,11);
	cout<<"\n\n\tSCORE = "<<Score;
	cout<<"\n\tTARGETED SCORE = "<<TargetedScore;
	cout<<"\n\tREMAINING MOVES = "<<Moves;
	cout<<"\n\tTOTAL MOVES = "<<TotalMoves<<endl;
	Insert_Steric(arr);
}
void Insert_Steric(char arr[][COL])
{
	srand(time(0));
	int r;
	char candies[5] = { '#' ,'$' , '@' , '?' , '!' };
	bool flag = true;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			for (int k = 0; k < COL - 2; k++)
			{
				if (candies[i] == arr[j][k] && (candies[i] == arr[j][k + 1] && candies[i] == arr[j][k + 2] && candies[i] == arr[j][k + 3]))
				{
					arr[j][k] = '%';
					arr[j][k + 1] = '*';
					arr[j][k + 2] = '*';
					arr[j][k + 3] = '*';
				}
				else if (candies[i] == arr[j][k] && (candies[i] == arr[j + 1][k] && candies[i] == arr[j + 2][k]) && (candies[i] == arr[j + 2][k + 1] && candies[i] == arr[j + 2][k + 2]))
				{
					arr[j + 2][k + 2] = 'L';
				}
				else if (candies[i] == arr[j][k] && (candies[i] == arr[j + 1][k] && candies[i] == arr[j + 2][k]) && (candies[i] == arr[j + 2][k - 1] && candies[i] == arr[j + 2][k - 2]))
				{
					arr[j + 2][k - 2] = 'L';
				}
				else if (candies[i] == arr[j][k] && (candies[i] == arr[j][k + 1] && candies[i] == arr[j][k + 2]) && (candies[i] == arr[j + 1][k + 2] && candies[i] == arr[j + 2][k + 2]))
				{
					arr[j + 2][k + 2] = 'L';
				}
				else if (candies[i] == arr[j][k] && (candies[i] == arr[j][k + 1] && candies[i] == arr[j][k + 2]) && (candies[i] == arr[j + 1][k] && candies[i] == arr[j + 2][k]))
				{
					arr[j][k + 2] = 'L';
				}
				if (candies[i] == arr[j][k] && (candies[i] == arr[j][k + 1] && candies[i] == arr[j][k + 2]))
				{
					if (candies[i] == '#')
					{
						Score+= 50;
					}
					else if (candies[i] == '@')
					{
						Score += 50;
					}
					else if (candies[i] == '$')
					{
						Score += 50;
					}
					else if (candies[i] == '?')
					{
						Score += 50;
					}
					else if (candies[i] == '!')
					{
						Score += 50;
					}
					arr[j][k] = '*';
					arr[j][k + 1] = '*';
					arr[j][k + 2] = '*';
				}

			}
		}
		for (int a = 0; a < ROW - 2; a++)
		{
			for (int b = 0; b < COL ; b++)
			{
				if (candies[i] == arr[a][b] && (candies[i] == arr[a + 1][b] && candies[i] == arr[a + 2][b] && candies[i] == arr[a + 3][b] && candies[i] == arr[a + 4][b]))
				{
					arr[a + 4][b] = 'O';
					arr[a + 3][b] = '*';
					arr[a + 2][b] = '*';
					arr[a + 1][b] = '*';
					arr[a][b] = '*';
				}
				else if (candies[i] == arr[a][b] && (candies[i] == arr[a + 1][b] && candies[i] == arr[a + 2][b] && candies[i] == arr[a + 3][b]))
				{
					arr[a + 3][b] = '%';
					arr[a + 2][b] = '*';
					arr[a + 1][b] = '*';
					arr[a][b] = '*';
				}
				else if (candies[i] == arr[a][b] && (candies[i] == arr[a + 1][b] && candies[i] == arr[a + 2][b]))
				{
					if (candies[i] == '#')
					{
						Score += 50;
					}
					else if (candies[i] == '@')
					{
						Score += 50;
					}
					else if (candies[i] == '$')
					{
						Score += 50;
					}
					else if (candies[i] == '?')
					{
						Score += 50;
					}
					else if (candies[i] == '!')
					{
						Score += 50;
					}
					arr[a][b] = '*';
					arr[a + 1][b] = '*';
					arr[a + 2][b] = '*';
				}
			}
		}
		for (int x = 0; x < ROW; x++)
		{
			for (int y = 0; y < COL; y++)
			{
				if (arr[x][y] == '*')
				{
					while (x != 0)
					{
						arr[x][y] = arr[x - 1][y];
						x--;
					}
					r = (rand() % 5);
					arr[x][y] = candies[r];
					flag = false;
				}
			}
		}
		if (!flag)
		{
			i = -1;
		}
		flag = true;
	}
	if (Moves == TotalMoves )
	{
		Score = 0;
	}
	//use of pointer
	if(Score >= *ptrTS)
	{
		system("cls");
		result();
	}
	if (Moves > 0 || Score > TargetedScore)
	{
		rewrite(arr);
	}
	else
	{
		system("CLS");
		result();
	}
	cout << "\n\n";
}
void rewrite(char arr[][COL])
{
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");
	SetConsoleTextAttribute(hConsole,15);
	
	cout<<" +";
	for(i=1;i<=35;i++)
	{
		SetConsoleTextAttribute(hConsole,15);
		cout<<"-";
	}
	cout<<"+"<<endl;
	for(i=0;i<ROW;i++)
	{
		cout<<" | ";
		for(int j=0;j<COL;j++)
		{
			if(arr[i][j]=='#')
			{
				SetConsoleTextAttribute(hConsole,12);
				cout<<arr[i][j];
			}
			else if(arr[i][j]=='$')
			{
				SetConsoleTextAttribute(hConsole,10);
				cout<<arr[i][j];
			}
			else if(arr[i][j]=='?')
			{
				SetConsoleTextAttribute(hConsole,11);
				cout<<arr[i][j];
			}
			else if(arr[i][j]=='@')
			{
				SetConsoleTextAttribute(hConsole,14);
				cout<<arr[i][j];
			}
			else if(arr[i][j]=='!')
			{
				SetConsoleTextAttribute(hConsole,13);
				cout<<arr[i][j];
			}
			else
			{
			 	cout<<arr[i][j];	
			}
			SetConsoleTextAttribute(hConsole,15);
			cout<<" | ";
		}
		cout<<endl;
	}
	cout<<" +";
	for(i=1;i<=35;i++)
	{
		SetConsoleTextAttribute(hConsole,15);
		cout<<"-";
	}
	cout<<"+"<<endl;
	SetConsoleTextAttribute(hConsole,11);
	cout<<"\n\n\tSCORE = "<<Score;
	cout<<"\n\tTARGETED SCORE = "<<TargetedScore;
	cout<<"\n\tREMAINING MOVES = "<<Moves;
	cout<<"\n\tTOTAL MOVES = "<<TotalMoves<<endl;
	swapping(arr);
}
void swapping(char arr[][COL])
{
	int x=3,y=1,a=x;
	move_cursor_to_xy(x,y);
	bool cond=true;
	while(cond)
	{
		if(GetAsyncKeyState(VK_DOWN))
		{
			y+=1;
			if(y<=9)
			{
				move_cursor_to_xy(x,y);
			}
			else
			{
				y=9;
			}
		}
		if(GetAsyncKeyState(VK_UP))
		{
			y-=1;
			if(y>=1)
			{
				move_cursor_to_xy(x,y);
			}
			else
			{
				y=1;
			}
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			x+=4;
			a+=3;
			if(x<=35)
			{
				move_cursor_to_xy(x,y);
			}
			else
			{
				x=35;
			}
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			x-=4;
			a-=3;
			if(x>=3)
			{
				move_cursor_to_xy(x,y);
			}
			else
			{
				x=3;
			}
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			system("cls");
			Score=0,Moves=20;
			Candy_Generator(arr);
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			cond=false;
		}
	}
	int col=x-a;
	int row=y-1;
	bool flag=true;
	int move;
	while(flag)
	{
		if(GetAsyncKeyState(VK_DOWN))
		{
			Moves--;
			move=1;
			flag=false;
		}
		if(GetAsyncKeyState(VK_UP))
		{
			Moves--;
			move=2;
			flag=false;
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			Moves--;
			move=3;
			flag=false;
		}	
		if(GetAsyncKeyState(VK_RIGHT))
		{
			Moves--;
			move=4;
			flag=false;
		}
	}
	char temp;
	if(move==1)
	{
		temp=arr[row][col];
		arr[row][col]=arr[row+1][col];
		arr[row+1][col]=temp;
	}
	if(move==2)
	{
		temp=arr[row][col];
		arr[row][col]=arr[row-1][col];
		arr[row-1][col]=temp;
	}
	if(move==3)
	{
		temp=arr[row][col];
		arr[row][col]=arr[row][col-1];
		arr[row][col-1]=temp;
	}
	if(move==4)
	{
		temp=arr[row][col];
		arr[row][col]=arr[row][col+1];
		arr[row][col+1]=temp;
	}
	Insert_Steric(arr);
}
void move_cursor_to_xy(int x,int y)
{
	static HANDLE h=NULL;
	if(!h)
	{
		h=GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD cordinates;
	cordinates.X=x;
	cordinates.Y=y;
	SetConsoleCursorPosition(h,cordinates);
	Sleep(200);
}
void result()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,10);
	cout<<"\n\n\n\n\t\t\t\t\t\t\tResult :)";
	Sleep(1000);
	if(Score>=TargetedScore)
	{
		cout<<"\n\n\n\t\t\t\t\t\t  CONGRACTULATIONS...\n\t\t\t\t\t\t\tYOU WON :) ";
	}
	else if(Score<TargetedScore)
	{
		cout<<"\n\n\n\t\t\t\t\t\t\tYOU LOSE :( ";
	}
	SetConsoleTextAttribute(hConsole,3);
	cout<<"\n\n\t\t\t\t\t\tYOUR FINAL SCORE IS : "<<Score;
	cout<<"\n\t\t\t\t\t\tYOUR TARGETED SCORE IS : "<<TargetedScore;
	cout<<"\n\t\t\t\t\t\tREMAINING MOVES ARE : "<<Moves<<endl;
	cout<<"\n\t\t\t\t\t\t";
	//use of pointers 
	Score=0,Moves=20;
	system("pause");
	system("cls");
}
void instructions(char arr[][COL])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char m;
	SetConsoleTextAttribute(hConsole,10);
	cout<<"\n\n\n\t\t\t\t\t\t.... INSTRUCTIONS ...."<<endl;
	Sleep(200);
	cout<<"\n\n\n\t\t\t\t\t~ Press SPACEBAR to Select a Candy";
	cout<<"\n\t\t\t\t\t~ Use ARROW KEYS to Move a Candy";
	cout<<"\n\t\t\t\t\t~ Match THREE Candies of Same Color to Crush them";
	cout<<"\n\t\t\t\t\t~ Each brust will add 50 points to Score";
	cout<<"\n\t\t\t\t\t~ There are 20 Moves to Complete Each Level";
	cout<<"\n\t\t\t\t\t~ You have to reach TARGETED SCORE in order to win";
	cout<<"\n\t\t\t\t\t~ TargetedScore = "<<*ptrTS;
	cout<<"\n\n\n\t\t\t\t\tPress 'y' or 'Y' to Return to the Main Menu : ";
	cin>>m;
	if(m=='y' || m=='Y')
	{
		system("CLS");
		Score=0,Moves=20;
		Candy_Generator(arr);
	}
	else 
	{
		system("cls");
		cout<<"\n\n\n\t\t\t\t\tYou have entered the wrong key...";
		cout<<"\n\n\t\t\t\t\t";
		system("pause");
		system("cls");
		instructions(arr);
	}
}

int main()
{
	char arr[ROW][COL];
	Candy_Generator(arr);
	return 0;
}

