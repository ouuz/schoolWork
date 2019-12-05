#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
int count = 0;
int n;
int factors[100];
int matrixs[100][100] = {0};


//计算正整数 n 的因子
void factor(){
	cout << n << " 的因数是: " << endl;
	for(int i = 1; i <= n/2; ++i){
		if(n % i == 0){
			factors[count++] = i;
			cout << i << ",";
		}
	}
	factors[count] = n;
	cout << n << endl;
}


//盖住关系
void cover(){
	for(int i = 0; i <= count; ++i){
		for(int j = 0; j <= count; ++j){
			if(factors[j] % factors[i] == 0){
				matrixs[i][j] = 1;
			}
		}
	}
	//开始判断
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
	cout << "盖住集为: {";
	for(int i = 0; i <= count; ++i){
		for(int j = 0; j <= count; ++j){
			if(matrixs[i][j]){
				cout << " <" << factors[i] << "," << factors[j] << ">";
			}
		}
	}
	cout << " }" << endl;
}

//求最大公约数
int gcd(int x, int y){
	int m;
	while(m != 0){
		m = x % y;
		x = y;
		y = m;
	}
	return x;
}

//判断有补格
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
				cout << "这不是补格" << endl;
				return;
			}
		}
	}
	cout << "这是补格" << endl;
	return;
}


int main(){
	cout << "请输入正整数:";
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
