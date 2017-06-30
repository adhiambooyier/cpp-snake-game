


# include <Windows.h>
# include <conio.h>
# include <iostream>
using namespace std;
bool gameOver;
const int WIDTH = 20;
const int HEIGHT = 20;
int x, y, fruitX, fruitY, score;
enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void Setup(){
	gameOver = false;
	dir = STOP;
	x = WIDTH / 2;
	y = HEIGHT / 2;
	fruitX = rand() % WIDTH;
	fruitY = rand() % HEIGHT;
	score = 0;
}
void Draw(){
	system("cls");// to clear
		for (int i = 0; i < WIDTH+2; i++){
			cout << "#";
		}
	cout << endl;
	for (int i = 0; i < HEIGHT; i++){
		for (int j = 0; j < WIDTH; j++){
			if (j == 0){
				cout << "#";
			}
			if (i == y && j == x){
				cout << "O";
			}
			else if (i == fruitY && j == fruitX){
				cout << "F";
			}
			else
				cout << " ";
			if (j == WIDTH - 1){
				cout << "#";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < WIDTH + 2; i++){
		cout << "#";
	}
	cout << endl;

}

void Input(){
	if (_kbhit()){
		switch (_getch()){
		case 'a':
			dir = LEFT;
			break;
		case 'l':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 'm':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}

}
void Logic(){
	switch (dir){
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
}

int main(){
	Setup();
	while (!gameOver){
		Draw();
		Input();
		Logic();
		Sleep(1000);
	}
	return 0;
}