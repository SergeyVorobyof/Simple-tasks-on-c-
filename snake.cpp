#include <iostream>
//#include <conio.h>
#include <cstdlib>
//#include <ncurses.h>

using namespace std;

int LEFT = 0;
int RIGHT = 1;
int UP = 2;
int DOWN = 3;
int STOP = 4;
bool GameOver;
int X,Y;
int fruit_x, fruit_y;
int width = 25;
int height = 10;
int status = STOP, score = 0;
char symbol;

void init(){
    GameOver = false;
    fruit_x = rand() % (width - 2) + 1;
    fruit_y = rand() % (height - 3) + 2;
    X = width / 2;
    Y = height / 2;
    status = STOP;
}

void draw(){
    system("clear");
    /*for (int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << endl;
    */
    cout << "Your score is: " << score << endl;
    for (int j = height; j > 0; j--) {
        for (int i = 0; i < width; i++) {
	    if (i == 0 || i == width - 1 || j == 1 || j == height)
	        cout << "#";		
	    //else
	        //cout << " ";

	    else if (i == X && j == Y)
		cout << "S";

	    else if (i == fruit_x && j == fruit_y)
		cout << char(2);
	    else if (i == X && j == Y && i == fruit_x && j == fruit_y)
		cout << "X";
	    else
		cout << " ";
        }
        cout << endl;
    }
}

void input(){
    //char symbol;
    cin >> symbol;
    switch(symbol) {
        case 'a':
            status = LEFT;
	    break;

        case 's':
	    status = DOWN;
	    break;

	case 'd':
	    status = RIGHT;
	    break;

	case 'w':
	    status = UP;
	    break;

	default:
	    status = STOP;
	    break;
    }
    //cout << "end input" << endl;
}

void logic(){
    if (status == LEFT) {

        X--;

    } else if (status == RIGHT) {

	X++;

    } else if (status == UP) {

	Y++;

    } else if (status == DOWN) {

	Y--;

    }

    if (X == fruit_x && Y == fruit_y) {
	fruit_x = rand() % (width - 2) + 1;
	fruit_y = rand() % (height - 3) + 2;
	score += 5;
    }

    if (X == 0 || Y == 1 || Y == height || X == width - 1)
	GameOver = true;

    /*
    switch(status) {
	case LEFT:
	    X--;
	    break;

	case RIGHT:
	    X++;
	    break;

        case UP:
	    Y++;
	    break;

	case DOWN:
	    Y--;
	    break;

	default:
	    break;
    }
    */
}

int main() {
    init();
    while (!GameOver){
        draw();
        input();
        logic();
    }
    cout << "GameOver"<< endl;
    cout << "Your score is: " << score << endl;
    return 0;
}
