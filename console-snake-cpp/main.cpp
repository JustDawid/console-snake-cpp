#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

    const int width = 20;
    const int height = 20;

    bool gameOver;
    int x, y;
    int fruitX, fruitY;
    int score;
    int tailX[100], tailY[100];
    int nTail = 0;
    enum eDirection{STOP=0, LEFT, RIGHT, UP, DOWN};
    eDirection dir;

void Setup(){
    gameOver=false;
    dir = STOP;
    x = width/2;
    y = height/2;

    fruitX = rand()%width;
    fruitY = rand()%height;
    score = 0;
}

void Draw(){
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

    for(int i=0; i<width+2; i++)
        cout << "#";
    cout << endl;

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(j==0)
                cout << "#";
            if(i==y && j==x)
                cout << "0";
            else if(i==fruitY && j==fruitX)
                cout << "X";
            else {
                bool printTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        printTail = true;
                        break;
                    }
                }
                if (!printTail) cout << " ";
            }
            if(j==width-1)
                cout << "#";
        }
        cout << endl;
    }
    for(int i=0; i<width+2; i++)
        cout << "#";
    cout << endl;
    cout << "Sterowanie jest za pomoca \"wsad\".\nWybranie \"x\" zakonczy gre.\nOwoce to X a glowa weza to 0" << endl;
    cout << "Gra rozpocznie sie od razu po wybraniu kierunku." << endl;
    cout << "Score: " << score << endl;
}

void Input(){
    if(_kbhit()){
        switch(_getch()){
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic(){

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for(int i=1; i<nTail; i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(dir){
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if(x>=width || x<0 || y>=height || y<0)
        gameOver = true;

    if(x==fruitX && y==fruitY){
        score+=10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }

    for(int i=0; i<nTail; i++){
        if(tailX[i]==x && tailY[i]==y)
            gameOver = true;
    }
}
int main()
{
    srand(time(NULL));
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        Sleep(100);
    }
    cout << "END\n";
    cout << "Final score: " << score;
    return 0;
}

