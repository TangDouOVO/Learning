/*
6.6说明形参和局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式 
*/

#include <iostream>
using namespace std;

double myAdd(double val1, double val2){ //形参 
	double result = val1 + val2; //普通局部变量 
	static unsigned iCnt = 0; //静态局部变量 
	++iCnt;
	cout << "此函数已经累计执行了" << iCnt << "次" << endl;
	return result; 
} 

int main(){
	double num1, num2;
	cout << "请输入两个数:" ;
	while(cin >> num1 >> num2){
		cout << num1 << "与" << num2 << "的求和结果是：" << myAdd(num1, num2) << endl; 
	} 
	return 0;
}


/*
6.25
编写一个main函数，令其接受两个实参，把实参的内容连接成一个string对象并输出 
*/
#include <iostream>
using namespace std;

int main(int argc, char**argv){
	string str;
	for(int i = 0; i < argc; i++){
		str += argv[i];
	}
	cout << str << endl;
	return 0;
}

/*
6.27
编写函数，它的参数是initializer_list<int>类型的对象，函数的功能是计算类别中所有可变的函数 
*/
#include<iostream>
using namespace std;

int iCount(initializer_list<int> il){
	int count = 0;
	for(auto cha : il){
		count += cha;
	}
	return count;
}

int main(){
	cout << iCount({1, 3, 4}) << endl;
	cout << iCount({1, 2}) << endl;
	return 0;
}


/*
6.29
在范围for循环中使用initializer_list对象时，应该将循环控制变量设置成引用类型吗？ 
引用类型的优势主要是可以直接操作所引用的对象以及避免拷贝复杂的类的类型对象和容器对象。因为initializer_list对象的元素。
所以，我们不能通过设定引用类型来更改循环控制变量的内容。只有当initializer_list对象的元素是类类型或容器类型（比如string）时，
才有必要把范围for循环的循环控制变量设为引用类型。 
*/


/*
6.36
编写一个函数声明，使其返回数组的引用并且该数组包含10个string对象。 
string (&func())[10];
*/ 
 
 
/*
6.37
为6.36的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用decltype关键词 
(1)
typedef string arr[10];
arr & func(); 
(2)
auto func() -> string(&)[10];
(3) 
string str[10]
decltype (str) &func();
*/
#include<iostream>
using namespace std;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) & arrPtr(int i){
	return (i%2) ? odd : even; 
} 

int main(){
	decltype(odd) & store = arrPtr(4);
	for(auto cha : store){
		cout << cha << " ";
	}
	return 0;
}


/*
6.44
将函数改写成内联函数 
*/

inline bool solution(const string& x, cosnt string& y){
	return x.size() < y.size();
} 




/*
6.56
编写四个函数，分别对两个int执行加减乘除运算；在vector对象中保存指向这些值的指针，并输出结果 
*/ 

#include <iostream>
#include <vector>
using namespace std;

int func1(int a, int b){
	return a + b;
}

int func2(int a, int b){
	return a - b;
}

int func3(int a, int b){
	return a * b;
}

int func4(int a, int b){
	return a / b;
}

void compute(int a, int b, int (*p)(int, int)){
	cout << p(a, b) << endl;
}
int main(){
	int i = 10, j = 5;
	decltype(func1)*p1 = func1, *p2 = func2, *p3 = func3, *p4 = func4;
	vector<decltype(func1)*> vF = {p1, p2, p3, p4};
	for(auto cha : vF){
		compute(i, j, cha);
	}
	return 0;
} 
