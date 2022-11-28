/*
		気づくとあなたは知らない空間に閉じ込められていました。
		この空間は縦 H マス横 W マスのグリッドになっています。
		あなたはこのグリッドの外に出ることで、この空間から脱出しようとしています。

		ただし、この空間のいくつかのマスには巨大な柱が立っており、あなたはこの柱を通り抜けることが出来ません。
		あなたの仕事は、柱にぶつかることなくグリッドの外に出ることが可能か判定することです。

----------------------------------------------
		入力例1
		7 6
		######
		#....#
		#.##.#
		#.#S.#
		#.####
		#.....
		######

		出力例1
		YES
---------------------------------------------
* 
*/

#include <iostream>
#include <vector>

using namespace std;

int X;
int Y;
int PosX;
int PosY;
vector< vector<int> > i_array;
vector <int> i_Barr;

bool Decision();
bool Check(int PosY, int PosX);

int main(void) {

	//データを記録
	std::cin >> Y >> X;

	for (int y = 0; y < Y; y++) {
		string str;
		cin >> str;
		for (int x = 0; x < X; x++) {
			if (str[x] == '#') {
				i_Barr.push_back(1);
			}
			else if (str[x] == '.') {
				i_Barr.push_back(2);
			}
			else if (str[x] == 'S') {
				i_Barr.push_back(0);
				PosX = x;
				PosY = y;
			}
		}
		i_array.push_back(i_Barr);
		i_Barr.clear();
	}


	if (Decision()) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}

//チェック
bool Check(int PosY, int PosX)
{
	if (PosX >= X) {
		return false;
	}
	else if (PosX < 0) {
		return false;
	}
	else if (PosY >= Y) {
		return false;
	}
	else if (PosY < 0) {
		return false;
	}
	return true;
}

//各方向のチェック
bool Decision()
{
	while (true) {
		//右
		if (Check(PosY, PosX + 1) && Check(PosY + 1, PosX) && Check(PosY, PosX - 1) && Check(PosY - 1, PosX)) {
			if (i_array[PosY][PosX + 1] != 1) {
				i_array[PosY][PosX] = 1;
				PosX += 1;
			}
			else if (i_array[PosY + 1][PosX] != 1) {
				i_array[PosY][PosX] = 1;
				PosY += 1;
			}
			//左
			else if (i_array[PosY][PosX - 1] != 1) {
				i_array[PosY][PosX] = 1;
				PosX -= 1;
			}
			//上
			else if (i_array[PosY - 1][PosX] != 1) {
				i_array[PosY][PosX] = 1;
				PosY -= 1;
			}
			else {				
					return false;
			}
		}
		else {
			return true;
		}
	}

}