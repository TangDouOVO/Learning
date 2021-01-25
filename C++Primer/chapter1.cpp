/*
练习1.16 
编写程序，从cin读取一组数，输出其和 
*/
#include<iostream>

int main(){
	int sum = 0, val = 0;
	std::cout << "请输入一些数， 按ctrl+z表示结束" << std::endl;
	for(; std::cin >> val;){//注意写法 while(std::cin >> val){sum+=val};
		sum += val;
	}
	std::cout << "读入的数之和为：" << sum << std::endl;
	return 0; 
}  

