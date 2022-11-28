/*
情報の通信を行う上で、圧縮は必要不可欠な技術です。 生のデータをそのまま通信に用いると非常に多くの時間がかかる場合でも、そのデータの特徴を活かした適切な圧縮を行うことによりデータサイズを大幅に削減し、高速に通信を行うことができます。


例えば次のような特徴を持ったデータを考えます。


・データは文字列で表され、文字数は最大で 2^60 と非常に長い文字列の可能性があります。
・データに含まれる文字は英小文字('a' - 'z') の26種類のみからなります。
・データには規則性があり、同様の文字列の繰り返しの組み合わせで表現可能です。

このような特徴を活かした圧縮方法はいろいろ考えられますが、ここでは次のような書式に従う圧縮方法を考えてみます。


2(2u2lt4d)3(rb)pa
これは繰り返し回数を数字によって表現した書式です。 数字(文字列) という書式は文字列を数字の回数だけ繰り返すことを表します。 ただし、数字が1 のときは数字は省略され、丸括弧の中の文字列の長さが1のときは丸括弧も省略されます。 上記の例はこのルールに従って書かれています。


この例を展開すると次の文字列になります。


uulltdddduulltddddrbrbrbpa

------------------------------------------------------------
入力例1
abcdefg10h12(ij2(3k))l9mnop4(3(2(6(qq)r)s5tu)7v5w)x15(yz)

出力例1
a 1
b 1
c 1
d 1
e 1
f 1
g 1
h 10
i 12
j 12
k 72
l 1
m 9
n 1
o 1
p 1
q 288
r 24
s 12
t 60
u 12
v 28
w 20
x 1
y 15
z 15

------------------------------------------------------------
*/

#include <iostream>
#include <stack>
#include <algorithm> 
#include <string>

using namespace std;

int main() {

	string s;
	cin >> s;
	int len = s.size();
	stack<char> st;
	for (int j = 0; j < len; j++) {
		//数字の場合
		if (s.at(j) >= '0' && s.at(j) <= '9') {
			st.push(s.at(j));
		}
		//左括弧の場合
		else if (s.at(j) == '(') {
			st.push(s.at(j));
		}
		//文字の場合
		else if (s.at(j) >= 'a' && s.at(j) <= 'z') {
			string str = "";
			while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
				str.push_back(st.top());
				st.pop();				
			}
			if (str == "")			{
				str = "1";
			}
			//int型に変換
			reverse(str.begin(), str.end());
			int num = atoi(str.c_str());
			for (int k = 0; k < num; k++) {
				st.push(s.at(j));
			}
		}
		//右括弧の場合
		else {
			string str = "";
			while (st.top() != '(') {
				str += st.top();
				st.pop();
			}
			st.pop();
			string str_b = "";
			while (!st.empty() && (st.top() >= '0' && st.top() <= '9')) {
				str_b.push_back(st.top());
				st.pop();
			}
			if (str == "") {
				str = "1";
			}
			//int型に変換
			reverse(str_b.begin(), str_b.end());
			int num = atoi(str_b.c_str());
			for (int k = 0; k < num; k++) {
				for (int kk = 0; kk < str.length(); kk++) {
					st.push(str.at(kk));
				}
			}
		}
	}

	//出力
	int iCnt[123] = {0};
	while (!st.empty()) {
		iCnt[st.top()]++;
		st.pop();
	}
	for (int i = 97; i < 123; i++)	{		
		cout <<(char)i << " " << iCnt[i] << endl;
	}
	
	return 0;
}
