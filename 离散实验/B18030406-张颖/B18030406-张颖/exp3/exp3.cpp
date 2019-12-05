#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
int count = 0;
int n;
int factors[100];
int matrixs[100][100] = {0};


//���������� n ������
void factor(){
	cout << n << " ��������: " << endl;
	for(int i = 1; i <= n/2; ++i){
		if(n % i == 0){
			factors[count++] = i;
			cout << i << ",";
		}
	}
	factors[count] = n;
	cout << n << endl;
}


//��ס��ϵ
void cover(){
	for(int i = 0; i <= count; ++i){
		for(int j = 0; j <= count; ++j){
			if(factors[j] % factors[i] == 0){
				matrixs[i][j] = 1;
			}
		}
	}
	//��ʼ�ж�
	for(int i = 0; i <= count; ++i){
		for(int j = 0; j <= count; ++j){
			for(int k = 0; k <= count; ++k){
				matrixs[k][k] = 0;
				if(matrixs[i][j] && matrixs[j][k]){
					matrixs[i][k] = 0;
				}
			}
		}
	}
	cout << "��ס��Ϊ: {";
	for(int i = 0; i <= count; ++i){
		for(int j = 0; j <= count; ++j){
			if(matrixs[i][j]){
				cout << " <" << factors[i] << "," << factors[j] << ">";
			}
		}
	}
	cout << " }" << endl;
}

//�����Լ��
int gcd(int x, int y){
	int m;
	while(m != 0){
		m = x % y;
		x = y;
		y = m;
	}
	return x;
}

//�ж��в���
void complemented_lattice(){
	bool flag;
	int Gcd, Lcm;
	for(int i = 1; i < count; i++)
	{
		flag = false;
		for(int j = 1; j < count; j++)
		{
			if(i == j)
				continue;
			Gcd = gcd(factors[i], factors[j]);
            Lcm = factors[i] / Gcd * factors[j];
			if(Gcd == factors[0] && Lcm == factors[count])
			{
				flag = true;
				break;
			}
			if(!flag)
			{
				cout << "�ⲻ�ǲ���" << endl;
				return;
			}
		}
	}
	cout << "���ǲ���" << endl;
	return;
}


int main(){
	cout << "������������:";
	cin >> n;
	cout << endl;
	factor();
	cout << endl;
	cover();
	cout << endl;
	complemented_lattice();
	cout << endl;
	return 0;
}
