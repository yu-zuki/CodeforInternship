/*
                あなたは今、とある戦略ゲームをプレイしています。
                ゲームの中で、敵を攻撃するために、フィールドに爆弾を仕掛けました。
                敵がフィールド内に入ったところで一気に爆弾を点火し、敵に攻撃をする寸法です。

                フィールドは縦 H 行、横 W 行のマス目としてあらわされ、これらのマス目のうちのいくつかに爆弾が仕掛けてあります。
                i 行目、j 列目の爆弾が爆発すると、i 行目全体と j 列目全体に爆風が広がります。

----------------------------------------------
                入力例1
                4 4
                #.#.
                ....
                ..#.
                ....

                出力例1
                12
----------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

//データ変数宣言
int matrix_X, matrix_Y = 0;
vector<vector<int>> matrix;

//charからintに変換関数
int getDate(char _date)
{
    if (_date == '#')    {
        return 1;
    }
    else {
        return 0;
    }
}

//爆発処理関数
void explosion(vector<vector<int>>& _matrix,int& _counter, const int& _x, const int& _y)
{
    //カウンター
    _counter++;
    for (int x = 0; x < matrix_X; x++)    {
        if (_matrix[_y][x] == 0) {
            _matrix[_y][x] = 2;
             _counter++;
        }
    }
    for (int y = 0; y < matrix_Y; y++) {
        if (_matrix[y][_x] == 0) {
            _matrix[y][_x] = 2;
             _counter++;
        }
    }
}

int main(void) {
    //データ取得
    cin >> matrix_Y >> matrix_X;

    //領域確保
    matrix.reserve(matrix_Y);

    for (int y = 0; y < matrix_Y; y++)    {
        //一時的な変数
        vector<int> temp;   
        char c_temp = 0;
        //メモリ確保
        temp.reserve(matrix_X);

        for (int x = 0; x < matrix_X; x++)        {
            //データ取得　爆弾：１　空：０
            cin >> c_temp;
            temp.emplace_back(getDate(c_temp));
        }
        matrix.emplace_back(temp);
    }

    //カウンター処理
    int iCounter = 0;
    //爆発処理
    for (int y = 0; y < matrix_Y; y++)    {
        for (int x = 0; x < matrix_X; x++) {
            if (matrix[y][x] == 1)           {
                explosion(matrix,iCounter,x,y);
            }
        }
    }

    //出力
    cout << iCounter;

    return 0;
}