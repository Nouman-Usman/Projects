#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <fstream>

#define SCREEN_WIDTH 110
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WIDTH 10
#define GAP_SIZE level
#define PIPE_DIF 45

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int level = 7;
int num = 10;
int pipePos[3];
int gapPos[3];
int pipeFlag[3];
char box1 = 234;
char box2 = 219;
char box3 = 208;
char box4 = 170;
char box5 = 158;
char hunter[3][6] = {' ', ' ', ' ', ' ', ' ', ' ',
                     '\1', box2, box2, box2, box4, box5,
                     ' ', ' ', ' ', ' ', ' ', ' '};
char bird[2][6] = {'|', '-', '-', '0', '\\', ' ',
                   '|', '_', '_', '_', ' ', '>'};
int birdPos = 6;
int score = 0;
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void setcursor(bool visible, DWORD size)
{
    if (size == 0)
        size = 20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}
void drawBorder()
{

    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        gotoxy(i, 0);
        cout << "#";
        gotoxy(i, SCREEN_HEIGHT);
        cout << "#";
    }

    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        gotoxy(0, i);
        cout << "#";
        gotoxy(SCREEN_WIDTH, i);
        cout << "##";
    }
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        gotoxy(WIN_WIDTH, i);
        cout << "|";
    }
}
void genPipe(int ind)
{
    gapPos[ind] = 3 + rand() % 14;
}
void drawHunter()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << hunter[i][j];
        }
    }
}

void drawPipe(int ind)
{
    if (pipeFlag[ind] == true)
    {
        for (int i = 0; i < gapPos[ind]; i++)
        {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1);
            cout << "***";
        }
        for (int i = gapPos[ind] + GAP_SIZE; i < SCREEN_HEIGHT - 1; i++)
        {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1);
            cout << "***";
        }
    }
}
void print_hunter(int ind)
{
    if (pipeFlag[ind] == true)
    {
        gotoxy(WIN_WIDTH - pipePos[ind], gapPos[ind] + 2);
        drawHunter();
    }
}
void eraseHunter(int ind)
{
    if (pipeFlag[ind] == true)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                gotoxy(WIN_WIDTH - pipePos[ind] + j, gapPos[ind] + 2 + i);
                cout << "       ";
            }
        }
    }
}
void erasePipe(int ind)
{
    if (pipeFlag[ind] == true)
    {
        for (int i = 0; i < gapPos[ind]; i++)
        {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1);
            cout << "   ";
        }
        for (int i = gapPos[ind] + GAP_SIZE; i < SCREEN_HEIGHT - 1; i++)
        {
            gotoxy(WIN_WIDTH - pipePos[ind], i + 1);
            cout << "   ";
        }
    }
}

void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ">>>>" << endl;
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "    ";
}
void updateScore()
{
    gotoxy(WIN_WIDTH + 11, 5);
    cout << "Score : " << score << endl;
    fstream newFile;
    string line;
    newFile.open("score.txt", ios::in);
    gotoxy(WIN_WIDTH + 12, 10);
    while (!newFile.eof())
    {
        getline(newFile, line);
        cout << "Previous score is: " << line;
    }
    newFile.close();
}
void moveBullet(int ind)
{
    for (int x = birdPos; x < WIN_WIDTH - 3; x++)
    {
        printBullet(x, birdPos);
        char next = getCharAtxy(x + 4, birdPos);
        if (next == '\1')
        {
            score = score + 2;
            updateScore();
            Beep(1000,250);
        }
        Sleep(10);
        eraseBullet(x, birdPos);
    }
}
void drawBird()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            gotoxy(j + 2, i + birdPos);
            cout << bird[i][j];
        }
    }
}
void eraseBird()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            gotoxy(j + 2, i + birdPos);
            cout << " ";
        }
    }
}

int collision()
{
    if (pipePos[0] >= 61)
    {
        if (birdPos < gapPos[0] || birdPos > gapPos[0] + GAP_SIZE || birdPos <= gapPos[0] + 1)
        {
            return 1;
        }
    }
    return 0;
}
void gameover()
{
    system("cls");
    cout << endl;
    Beep(1000, 250);
    string line;
    fstream newFile;
    newFile.open("score.txt", ios::out);
    newFile<<score;
    newFile.close();
    newFile.open("game.txt", ios::in);
    while (!newFile.eof())
    {
        getline(newFile, line);
        cout << line << endl;
    }
    newFile.close();
    cout << endl;
    cout << "\t\tPress any key to go back to menu.";
    getch();
}

void instructions()
{

    system("cls");
    fstream newFile;
    string line;
    newFile.open("instruction.txt", ios::in);
    while (!newFile.eof())
    {
        getline(newFile, line);
        cout << line << endl;
    }
    cout << "\n Press spacebar to make bird fly";
    cout << "\n\nPress any key to go back to menu";
    getch();
}

void play()
{

    birdPos = 7;
    score = 0;
    pipeFlag[0] = 1;
    pipeFlag[1] = 0;
    pipePos[0] = pipePos[1] = 4;

    system("cls");
    drawBorder();
    genPipe(0);
    updateScore();

    gotoxy(WIN_WIDTH + 7, 2);
    cout << "ASSASSION BIRD";
    gotoxy(WIN_WIDTH + 10, 4);
    cout << "----------";
    gotoxy(WIN_WIDTH + 10, 6);
    cout << "----------";
    gotoxy(WIN_WIDTH + 22, 12);
    cout << "Control ";
    gotoxy(WIN_WIDTH + 22, 13);
    cout << "-------- ";
    gotoxy(WIN_WIDTH + 18, 14);
    cout << " Spacebar = jump";

    gotoxy(20, 11);
    cout << "Press Any Key To Start";
    getch();
    gotoxy(20, 11);
    cout << "                      ";

    while (1)
    {
        if (kbhit())
        {
            char ch = getch();
            if (ch == 32)
            {
                if (birdPos > 3)
                    birdPos = birdPos - 3;
            }
            if (ch == 27)
            {
                break;
            }
        }
        drawBird();

        print_hunter(0);
        drawPipe(0);
        drawPipe(1);
        if (collision() == 1)
        {
            gameover();
            return;
        }
        Sleep(100);
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveBullet(0);
        }
        eraseBird();
        erasePipe(0);
        erasePipe(1);
        eraseHunter(0);
        birdPos = birdPos + 1;
        if (birdPos > SCREEN_HEIGHT - 2)
        {
            gameover();
            return;
        }

        if (pipeFlag[0] == 1)
            pipePos[0] += 2;

        if (pipeFlag[1] == 1)
            pipePos[1] += 2;

        if (pipePos[0] >= 40 && pipePos[0] < 42)
        {
            pipeFlag[1] = 1;
            pipePos[1] = 4;
            genPipe(1);
        }
        if (pipePos[0] > 68)
        {
            score++;
            updateScore();
            pipeFlag[1] = 0;
            pipePos[0] = pipePos[1];
            gapPos[0] = gapPos[1];
        }
    }
}
int chnageColor(int number)
{
    cout << endl;
    cout << "Enter a number in between zero to 255 : ";
    cin >> number;
    if (number <= 255)
    {
        num = number;
    }
    else
    {
        cout << "Invalid number" << endl;
        cout << "Press any key to continue ";
        getch();
    }
    return num;
}
void header(int num)
{
    fstream newFile;
    string line;
    newFile.open("Flappy header.txt", ios::in);
    gotoxy(10, 2);
    system("cls");
    while (!newFile.eof())
    {
        getline(newFile, line);
        SetConsoleTextAttribute(hConsole, num);
        cout << line << endl;
    }
    newFile.close();
}
void changeLevel(char num)
{
    if (num == '1')
    {
        level = 7;
    }
    else if (num == '2')
    {
        level = 5;
    }
    if (num == '3')
    {
        level = 3;
    }
}
int main()
{
    setcursor(0, 0);
    srand((unsigned)time(NULL));
    system("cls");
    while (1)
    {
        ShowConsoleCursor(false);
        header(num);
        gotoxy(10, 12);
        cout << "1. Start Game";
        gotoxy(10, 14);
        cout << "2.  Levels";
        gotoxy(10, 16);
        cout << "3. Instructions";
        gotoxy(10, 18);
        cout << "4. Change Color";
        gotoxy(10, 20);
        cout << "5. Quit";
        gotoxy(10, 22);
        cout << "Select option: ";
        char op = getche();
        if (op == '1')
            play();
        else if (op == '2')
        {
            system("cls");
            gotoxy(15, 12);
            cout << " 1. Easy ";
            gotoxy(15, 14);
            cout << " 2. Medium ";
            gotoxy(15, 16);
            cout << " 3. Hard";
            gotoxy(15, 18);
            cout << " Select any option: ";
            char num = getche();
            changeLevel(num);
        }
        else if (op == '3')
            instructions();
        else if (op == '4')
        {
            system("cls");
            chnageColor(num);
            header(num);
        }
        else if (op == '5')
        {
            cout << endl;
            cout << "Press any key to exit the game ";
            getch();
            return 0;
        }
    }
    return 0;
}