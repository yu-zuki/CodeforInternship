/*
                ���Ȃ��͍��A�Ƃ���헪�Q�[�����v���C���Ă��܂��B
                �Q�[���̒��ŁA�G���U�����邽�߂ɁA�t�B�[���h�ɔ��e���d�|���܂����B
                �G���t�B�[���h���ɓ������Ƃ���ň�C�ɔ��e��_�΂��A�G�ɍU�������鐡�@�ł��B

                �t�B�[���h�͏c H �s�A�� W �s�̃}�X�ڂƂ��Ă���킳��A�����̃}�X�ڂ̂����̂������ɔ��e���d�|���Ă���܂��B
                i �s�ځAj ��ڂ̔��e����������ƁAi �s�ڑS�̂� j ��ڑS�̂ɔ������L����܂��B

----------------------------------------------
                ���͗�1
                4 4
                #.#.
                ....
                ..#.
                ....

                �o�͗�1
                12
----------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

//�f�[�^�ϐ��錾
int matrix_X, matrix_Y = 0;
vector<vector<int>> matrix;

//char����int�ɕϊ��֐�
int getDate(char _date)
{
    if (_date == '#')    {
        return 1;
    }
    else {
        return 0;
    }
}

//���������֐�
void explosion(vector<vector<int>>& _matrix,int& _counter, const int& _x, const int& _y)
{
    //�J�E���^�[
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
    //�f�[�^�擾
    cin >> matrix_Y >> matrix_X;

    //�̈�m��
    matrix.reserve(matrix_Y);

    for (int y = 0; y < matrix_Y; y++)    {
        //�ꎞ�I�ȕϐ�
        vector<int> temp;   
        char c_temp = 0;
        //�������m��
        temp.reserve(matrix_X);

        for (int x = 0; x < matrix_X; x++)        {
            //�f�[�^�擾�@���e�F�P�@��F�O
            cin >> c_temp;
            temp.emplace_back(getDate(c_temp));
        }
        matrix.emplace_back(temp);
    }

    //�J�E���^�[����
    int iCounter = 0;
    //��������
    for (int y = 0; y < matrix_Y; y++)    {
        for (int x = 0; x < matrix_X; x++) {
            if (matrix[y][x] == 1)           {
                explosion(matrix,iCounter,x,y);
            }
        }
    }

    //�o��
    cout << iCounter;

    return 0;
}