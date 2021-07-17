#include <iostream>
#include <random>
#include <algorithm>
#include <windows.h>
//#include <locale>

#define CHECK_DOT(X,Z) (((X) >= 0) && ((X) < (Z)))
#define POINT_ITEM(a,r,c) (*((*((a) + (r))) + (c)))

//C++11 <random>
std::random_device rd;
std::mt19937 mt(rd());
//std::uniform_int_distribution<int> dist(0, *p_interval);

enum PLAYER { HUMAN='X', AI='O', EMPTY='_' };
typedef struct {
	int szX;
	int szY;
	PLAYER **map;
	int toWin;
} Field;
char getVal(PLAYER **array, const int row, const int col) {
	return POINT_ITEM(array, row, col);
}
void setVal(PLAYER **array, const int row, const int col, PLAYER value) {
	POINT_ITEM(array, row, col) = value;
}

void Request (Field &field) {
    char Answer;
    while (!Answer)
    {
        std::cout << "Do you want to change the size of the field or leave it as default (y/n) ";
        std::cin >> Answer;
    }
    switch (Answer)
    {
        case('y'):
            std::cout << "Enter the size of the field ";
            std::cin >> field.szX;
            field.szY = field.szX;
            std::cout << "Enter the size to win ";
            std::cin >> field.toWin;
            break;
        case('n'):
            field.toWin = 5;
            field.szX = 7;
            field.szY = 7;
            break;


    }

}
void init(Field &field) {
	//field.toWin = 5;
	//field.szX = 7;
	//field.szY = 7;
	Request(field);
	field.map = (PLAYER **) calloc(field.szX, sizeof(PLAYER *));
	for (int y = 0; y < field.szY; y++) {
		*(field.map + y) = (PLAYER *) calloc(field.szX, sizeof(PLAYER));
		for (int x = 0; x < field.szX; x++) {
			setVal(field.map, y, x, EMPTY);
		}
	}
}
void print(Field &field) {
	//#include <windows.h>
	std::system("cls");
//	std::system("clear");
    for (int i = 1; i <= field.szX; i++) {
        std::cout << "-" << i;
    }
    std::cout << "-\n";
	//std::cout << "-1-2-3-4-5-6-7-\n";
	for (int y = 0; y < field.szY; y++) {
		std::cout << (y + 1);
		for (int x = 0; x < field.szX; x++) {
			std::cout << getVal(field.map, y, x) << "|";
		}
		std::cout << std::endl;
	}
}
bool isEmpty(Field &field, int x, int y) {
	return getVal(field.map, y, x) == EMPTY;
}
bool isValid(Field &field, int x, int y) {
	return CHECK_DOT(x, field.szX) && CHECK_DOT(y, field.szY);
}
void humanTurn(Field &field) {
	int x;
	int y;
	bool isError = false;
	do {
		if (isError)
			std::cout << "your coordinates were entered wrong!, field size is..." << std::endl;
        std::cout << std::endl;
		std::cout << "Enter the X and Y stroke coordinates separated by a space>>" << std::endl;
		// <regex>
		std::cin >> x;
		std::cin.ignore(1);
		std::cin >> y;
		// scanf("%d %d", &x, &y);
		// todo check if numbers are entered
		x--; y--;
		isError = true;
	} while (!isValid(field, x, y) || !isEmpty(field, x, y));
	setVal(field.map, y, x, HUMAN);
}
bool isDraw(Field &field) {
	for (int y = 0; y < field.szY; y++)
		for (int x = 0; x < field.szX; x++)
			if (isEmpty(field, x, y))
				return false;
	return true;
}
bool checkLine(Field &field, int y, int x, int vx, int vy, int len, PLAYER c) {
	const int endX = x + (len - 1) * vx;
	const int endY = y + (len - 1) * vy;
	if (!isValid(field, endX, endY))
		return false;
	for (int i = 0; i < len; i++) {
		if (getVal(field.map, (y + i * vy), (x + i * vx)) != c)
			return false;
	}
	return true;
}
bool checkWin(Field &field, PLAYER c) {
	for (int y = 0; y < field.szY; y++) {
		for (int x = 0; x < field.szX; x++) {
			if (getVal(field.map, y, x) == EMPTY)
				continue;
			if (checkLine(field, y, x, 1, 0, field.toWin, c)) return true;
			if (checkLine(field, y, x, 1, 1, field.toWin, c)) return true;
			if (checkLine(field, y, x, 0, 1, field.toWin, c)) return true;
			if (checkLine(field, y, x, 1, -1, field.toWin, c)) return true;
		}
	}
	return false;
}
// ai turn
bool aiWinCheck(Field &field) {
	for (int y = 0; y < field.szY; y++) {
		for (int x = 0; x < field.szX; x++) {
			if (isEmpty(field, x, y)) {
				setVal(field.map, y, x, AI);
				if (checkWin(field, AI))
					return true;
				setVal(field.map, y, x, EMPTY);
			}
		}
	}
	return false;
}

bool humWinCheck(Field &field) {
	for (int y = 0; y < field.szY; y++) {
		for (int x = 0; x < field.szX; x++) {
			if (isEmpty(field, x, y)) {
				setVal(field.map, y, x, HUMAN);
				if (checkWin(field, HUMAN)) {
					setVal(field.map, y, x, AI);
					return true;
				}
				setVal(field.map, y, x, EMPTY);
			}
		}
	}
	return false;
}


void aiTurn(Field &field) {
    std::uniform_int_distribution<int> dist(0, field.szX - 1);
	if (aiWinCheck(field)) return;
	if (humWinCheck(field)) return;
	int x;
	int y;
	do {
		x = dist(mt);
		y = dist(mt);
	} while (!isEmpty(field, x, y));
	setVal(field.map, y, x, AI);
}

bool gameCheck(Field &field, PLAYER dot, const std::string &winString) {
	print(field);
	if (checkWin(field, dot)) {
		std::cout << winString << std::endl;
		return true;
	}
	if (isDraw(field)) {
		std::cout << "Draw!" << std::endl;
		return true;
	}
	return false;
}

int main(int argc, char** argv) { // 1TBS
	// game cycle + new game
	//setlocale(LC_ALL, "Russian");
	//setlocale (LC_ALL, ".866");
	//SetConsoleCP(1251);
  //  SetConsoleOutputCP(1251);



	Field field;
	while (true) {
		init(field);
		print(field);
		while (true) {
			humanTurn(field);
			if (gameCheck(field, HUMAN, "Human win")) break;
			aiTurn(field);
			if (gameCheck(field, AI, "Computer win")) break;
		}
		std::string answer;
		std::cout << "Play again? ";
		std::cin >> answer;
		// <regex>
		//		if (strcasecmp(answer, "y") != 0);
		transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
		if (answer.find('y') != 0) break;
	}

	// todo stats
    return 0;
}