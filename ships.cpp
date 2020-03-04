#include <iostream>

using namespace std;
char dispArray[] = { '~','#','O','X' };

class board {
	enum cell {sea = 0, ship = 1, hit = 2, miss = 3};
	unsigned int size;
	int **map;
	unsigned int shipNum;
	unsigned int score;
	unsigned int hitShips;

public:
	board(unsigned int _size, unsigned int _shipNum) {
		size = _size;
		if (_shipNum > size*size)
			_shipNum = size * size;
		shipNum = _shipNum;
		hitShips = 0;
		score = 0;
		// allocate memory for grid
		map = new int*[size];
		for (unsigned int i = 0; i < size; i++)
			map[i] = new int[size];
		for (unsigned int i = 0; i < size; i++)
			for (unsigned int j = 0; j < size; j++)
				map[i][j] = sea;
		// init ships
		initShips();
	}
	~board() {
		for (unsigned int i = 0; i < size; i++)
			delete[] map[i];
		delete[] map;
	}
	void display() {
		// clear screen
		system("cls");
		for (unsigned int i = 0; i < size; i++) {
			for (unsigned int j = 0; j < size; j++)
				cout << dispArray[map[i][j]];
			cout << endl;
		}
	}
private:
	bool placeShip(unsigned int _x, unsigned int _y) {
		if (map[_x][_y] != ship) {
			map[_x][_y] = ship;
			return true;
		}
		else return false;
	}
	void initShips() {
		for (unsigned int i=0; i < size; i++) {
			unsigned int x, y;
			do {
				x = rand() % size;
				y = rand() % size;
			} while (!placeShip(x, y));
		}
	}
};

int main() {
	unsigned int size, shipNum;
	cout << "Input size and ship number: ";
	cin >> size >> shipNum;

	board b(size, shipNum);
	b.display();
	cin.get();
	return 0;
}