#include <iostream>
#include<string>
#include<windows.h>
#include<cmath>
using namespace std;
int width = 2;
int height = 2;
int plygrid[2]{ 2,2 }; // height, length
int mapgrid[2]{ 21, 60 };
int yVelocity = 0;
int positionDiff = 0;
bool grounded = false;
int dir = true; // true = right, false left

void gravity() {
	Sleep(10);
	if (grounded == false) {
		plygrid[0] += positionDiff;
		positionDiff += 1;
	}
}

void border() {
	for (int x = 0; x < mapgrid[0]; x++) {

		cout << "\n";
		for (int i = 0; i < mapgrid[1]; i++) {
			cout << " ";
			if (x == plygrid[0] && i == plygrid[1]) {
				cout << "0";
				i = i + 1;
			}
		}
		cout << "#";
	}
	cout << "\n";
	for (int i = 0; i < mapgrid[1]; i++) {
		cout << "#";
	}

	cout << "\n" << "\n" << plygrid[0] << "," << plygrid[1];
	cout << "\n" << yVelocity;

	if (plygrid[1] > mapgrid[1] - 1) {
		plygrid[1] = 1;
	}
	if (plygrid[0] > mapgrid[0] - 1)
	{
		plygrid[0] -= 1;
		grounded = true;
	}
	else if (plygrid[0] < mapgrid[0] - 1) {
		grounded = false;
	}
	if (plygrid[1] < -1 /* || plygrid[0] < -1*/) {
		plygrid[1] = 60;
	}
	Sleep(40);
	system("CLS");

}

int main()
{
	while (true) {
		border();
		gravity();
		if (GetKeyState('D') & 0x8000)
		{
			plygrid[1] = plygrid[1] + 1;
			dir = true;
		}
		if (GetKeyState('A') & 0x8000)
		{
			plygrid[1] = plygrid[1] - 1;
		}
		if (GetKeyState('W') & 0x8000)
		{
			if (grounded == true) {
				grounded = false;
				positionDiff = -3;
			}
		}
	}
	return 0;
}
