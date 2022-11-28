/*
		���Ȃ��́A�f��ق̐Ȃ̗\������悤�Ƃ��Ă��܂��B

		���Ȃ́A�c�̈ʒu��\�� p �Ɖ��̈ʒu��\�� q �� (p, q) �Ŏw��ł��A�ł�����̐Ȃ� (0, 0) �ƂȂ��Ă��܂��B
		�f��قɂ́A�ł����₷���Ȃ� 1 �ȑ��݂��A�ł��f������₷���ȂƂ̃}���n�b�^���������������قǁA�f������₷���Ȃ��Ă��܂��B

		�}���n�b�^�������Ƃ́A���� 2 �_ (p, q)�A(s, t) �ɑ΂��āA|p - s| + |q - t| �ŗ^�����鋗����\���܂��B

		���Ȃ��́A�ł��邾���f������₷���Ȃ�\�񂵂悤�Ǝv���Ă��܂��B
		�ł����₷���ȂƂ��łɗ\�񂳂�Ă���Ȃ̏�񂪗^������̂ŁA�܂��\�񂳂�Ă��Ȃ��Ȃ̒��ŁA�ł��f������₷���Ȃ����߂Ă��������B

		��
		���͂����l
		���͈͂ȉ��̃t�H�[�}�b�g�ŗ^�����܂��B

		N H W P Q
		p_1 q_1
		p_2 q_2
		...
		p_N q_N
		�E1 �s�ڂɂ��łɗ\�񂳂�Ă�����Ȃ̐� N�A�f��ق̍��Ȃ̏c�̐� H�A�f��ق̍��Ȃ̉��̐� W�A�ł����₷���Ȃ� p ���W�Aq ���W��\�� P, Q �����ꂼ�ꔼ�p�X�y�[�X��؂�ŗ^�����܂��B
		�E���� N �s�̂����� i �s�� (1 �� i �� N) �ɂ́A���ꂼ�� i �Ԗڂ̗\�񂳂�Ă�����Ȃ� p ���W�Aq ���W��\������ p_i, q_i �����̏��Ŕ��p�X�y�[�X��؂�ŗ^�����܂��B
		�E���͍͂��v�� N + 1 �s�ƂȂ�A���͒l�ŏI�s�̖����ɉ��s�� 1 ����܂��B

		��
		���҂���o��
		�܂��\�񂳂�Ă��Ȃ��Ȃ̒��ŁA�ł��f������₷���Ȃ��ȉ��̌`���ł��ׂďo�͂��Ă��������B
		a_1 b_1
		a_2 b_2
		...
		a_K b_K
		�E�܂��\�񂳂�Ă��Ȃ��Ȃ̒��ŁA�ł��f������₷���Ȃ̐� K �ɑ΂��A���҂���o�͂� K �s����Ȃ�܂��B
		�Ei �s�� (1 �� i �� K) �ɂ͂��ꂼ�� i �Ԗڂ̍ł��f������₷����Ȃ� p ���W�Aq ���W��\�� a_i, b_i �����̏��Ŕ��p�X�y�[�X��؂�ŏo�͂��ĉ������B
		�E���ׂĐ����ŏo�͂��Ă��������B
		�E�o�͍ŏI�s�̖����ɉ��s�����A�]�v�ȕ����A��s���܂�ł͂����܂���B

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

			�o�͗�1
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
    int Reser, H, W, BestX, BestY; //N�\�񂳂�Ă�Ȑ�   
   //�l����
    cin >> Reser >> H >> W >> BestY >> BestX;

    //Matrix�쐬
    vector<vector<int> > Matrix;
    Matrix.resize(H);
    for (int i = 0; i < Matrix.size(); i++) {
        Matrix[i].resize(W);
    }

    //�\�񂳂ꂽ�Ȑ������
    for (int i = 0; i < Reser; i++) {
        int ReserX, ReserY;
        cin >> ReserY >> ReserX;           //����
        Matrix[ReserY][ReserX] = 9;
    }
    //���
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
    //�L�^
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
    //�o��
    for (int i = 0; i < vMInfo.size(); i++) {
        cout << vMInfo[i].y << " " << vMInfo[i].x << endl;
    }
    return 0;
}