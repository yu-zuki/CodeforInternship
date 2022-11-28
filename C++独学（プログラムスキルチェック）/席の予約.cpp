/*
		あなたは、映画館の席の予約をしようとしています。

		座席は、縦の位置を表す p と横の位置を表す q の (p, q) で指定でき、最も左上の席が (0, 0) となっています。
		映画館には、最も見やすい席が 1 席存在し、最も映画を見やすい席とのマンハッタン距離が小さいほど、映画を見やすくなっています。

		マンハッタン距離とは、ある 2 点 (p, q)、(s, t) に対して、|p - s| + |q - t| で与えられる距離を表します。

		あなたは、できるだけ映画を見やすい席を予約しようと思っています。
		最も見やすい席とすでに予約されている席の情報が与えられるので、まだ予約されていない席の中で、最も映画を見やすい席を求めてください。

		↓
		入力される値
		入力は以下のフォーマットで与えられます。

		N H W P Q
		p_1 q_1
		p_2 q_2
		...
		p_N q_N
		・1 行目にすでに予約されている座席の数 N、映画館の座席の縦の数 H、映画館の座席の横の数 W、最も見やすい席の p 座標、q 座標を表す P, Q がそれぞれ半角スペース区切りで与えられます。
		・続く N 行のうちの i 行目 (1 ≦ i ≦ N) には、それぞれ i 番目の予約されている座席の p 座標、q 座標を表す整数 p_i, q_i がこの順で半角スペース区切りで与えられます。
		・入力は合計で N + 1 行となり、入力値最終行の末尾に改行が 1 つ入ります。

		↓
		期待する出力
		まだ予約されていない席の中で、最も映画を見やすい席を以下の形式ですべて出力してください。
		a_1 b_1
		a_2 b_2
		...
		a_K b_K
		・まだ予約されていない席の中で、最も映画を見やすい席の数 K に対し、期待する出力は K 行からなります。
		・i 行目 (1 ≦ i ≦ K) にはそれぞれ i 番目の最も映画を見やすい空席の p 座標、q 座標を表す a_i, b_i をこの順で半角スペース区切りで出力して下さい。
		・すべて整数で出力してください。
		・出力最終行の末尾に改行を入れ、余計な文字、空行を含んではいけません。

----------------------------------
			9 4 5 2 3
			1 0
			1 2
			1 3
			1 4
			2 2
			2 3
			2 4
			3 3
			3 4

			出力例1
			0 3
			2 1
			3 2
----------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct s_ManInfo {
    int iNum;
    int x;
    int y;
};

int main(void) {
    int Reser, H, W, BestX, BestY; //N予約されてる席数   
   //値を代入
    cin >> Reser >> H >> W >> BestY >> BestX;

    //Matrix作成
    vector<vector<int> > Matrix;
    Matrix.resize(H);
    for (int i = 0; i < Matrix.size(); i++) {
        Matrix[i].resize(W);
    }

    //予約された席数を入力
    for (int i = 0; i < Reser; i++) {
        int ReserX, ReserY;
        cin >> ReserY >> ReserX;           //入力
        Matrix[ReserY][ReserX] = 9;
    }
    //代入
    for (int y = 0; y < Matrix.size(); y++) {
        for (int x = 0; x < Matrix[y].size(); x++) {
            if (Matrix[y][x] == 0) {
                int Manhattan = 0;
                (y - BestY) > 0 ? Manhattan += (y - BestY) : Manhattan += (y - BestY) * -1;
                (x - BestX) > 0 ? Manhattan += (x - BestX) : Manhattan += (x - BestX) * -1;

                Matrix[y][x] = Manhattan;
            }
        }
    }
    //記録
    vector<s_ManInfo> vMInfo;
    vMInfo.push_back({ 999,0,0 });
    for (int y = 0; y < Matrix.size(); y++) {
        for (int x = 0; x < Matrix[y].size(); x++) {
            if (Matrix[y][x] > vMInfo[0].iNum) {
            }
            else if (Matrix[y][x] == vMInfo[0].iNum) {
                vMInfo.push_back({ Matrix[y][x] ,x,y });
            }
            else if (Matrix[y][x] < vMInfo[0].iNum) {
                vMInfo.clear();
                vMInfo.push_back({ Matrix[y][x] ,x,y });
            }
        }
    }
    //出力
    for (int i = 0; i < vMInfo.size(); i++) {
        cout << vMInfo[i].y << " " << vMInfo[i].x << endl;
    }
    return 0;
}