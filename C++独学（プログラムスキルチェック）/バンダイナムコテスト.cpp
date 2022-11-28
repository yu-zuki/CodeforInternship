#include <iostream>
#include <string>
#include <vector>

using namespace std;

// データに不備(仕様に当てはまらない)があった時のエラー文字列
static constexpr char const* ERROR_DATA = "DataError!";

// 計算した結果、32bit符号付き整数の値の範囲を超えた時のエラー文字列
static constexpr char const* ERROR_OVERFLOW = "Overflow!";

// 割り算が発生する時に、除数が 0 だった時のエラー文字列
static constexpr char const* ERROR_DIV_BY_ZERO = "DivBy0!";

// 割り算が発生する時に、除数、被除数のどちらか、あるいは両方が負の数だった時のエラー文字列
static constexpr char const* ERROR_NEG_DIV = "NegDiv!";
enum Order
{
    ADD = 1,
    SUB,
    MULT,
    DIV,
    MOD,
    ROL,
    ROR
};

void Process(unsigned int& _num,const int _processNum, const Order _order)
{
    try
    {
		switch (_order)
		{
		case ADD:
			if (_num + _processNum > INT_MAX) {
                throw ERROR_OVERFLOW;
			}
			_num += _processNum;
			break;
		case SUB:
            if ((_num - _processNum < INT_MIN)) {
                throw ERROR_OVERFLOW;
            }
			_num -= _processNum;
			break;
		case MULT:
			_num *= _processNum;
			break;
		case DIV:
            if (_num == 0)            {
                throw ERROR_DIV_BY_ZERO;
            }
            if (_num < 0 || _processNum < 0)           {
                throw ERROR_NEG_DIV;
            }
			_num /= _processNum;
			break;
		case MOD:
            _num %= _processNum;
			break;
		case ROL:
			_num = _lrotr(_num, _processNum);
			break;
		case ROR:
			_num = _lrotl(_num, _processNum);
			break;
		}
    }
    catch (string _s) {
        throw ERROR_OVERFLOW;
    }
}

int Binding(int& _index, int _count, vector<uint8_t>& _datastr)
{
    int tmp_data = 0;
    int tmp_Max = _index;

    for (int i = _index; i < tmp_Max + _count; i++)
    {
        tmp_data <<= 8;
        tmp_data |= _datastr[i];

        _index++;
    }

    return tmp_data;
}

uint8_t GetLeftNum(uint8_t _variable)
{
    uint8_t tmp = _variable >> 4;

    return tmp;
}
uint8_t GetRightNum(uint8_t _variable)
{
    uint8_t tmp = (uint8_t) _variable << 4;
    tmp >>= 4;

    return tmp;
}

/*
 * 標準入力からスペース区切りで16進数の文字列(00 - FF)が複数入力されます。
 * 例)   00 01 02 03 03 71 FC 42 00 08 24 06 00 02 05
 * ルールに従ってその入力データを処理して、最終的に得られた数値を10進数、
 * あるいはエラー文字列を標準出力に出力するプログラムを作りなさい。
 */
int main()
{
    unsigned int initNum = 0;
    uint16_t count = 0;

    vector<uint8_t> data;
    string tmp = "a";
    
	//データ入力
	while (cin >> tmp) {
        uint8_t tmpInt = 0;
        tmpInt  = stoul(tmp, 0, 16);
		data.emplace_back(tmpInt);

	}

    int tmp_index = 0;
    //データの結合
    initNum = Binding(tmp_index, 4, data);

    count = data[4];
    if (count > 127)
    {
        cout << ERROR_DATA;
        return 1;
    }

    int index = 5;
    for (int i = 0; i < count; i++)
    {
        int tmp_iNum = 0;
        int tmp_IntOrder = GetLeftNum(data[index]);

        if ( (tmp_IntOrder > 7) || (tmp_IntOrder <= 0))        {
            throw ERROR_DATA;
        }

        Order tmp_Order = (Order)tmp_IntOrder;
        uint8_t tmp_count = GetRightNum(data[index]);
        index++;

		if (tmp_count == 1) {
            tmp_iNum = (int8_t)data[index];
			index++;
		}
        else {
            tmp_iNum = Binding(index, tmp_count, data);
        }

        try       {
            Process(initNum, tmp_iNum, tmp_Order);
        }       
        catch (string _s) {
            cout << _s;
            return 1;
        }
    }

    cout << (int)initNum;
}
