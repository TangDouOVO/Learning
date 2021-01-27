/*
3.2编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词 
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	string line;
	cout << "请输入您的字符串，可以包含空格：" << endl;
	while(getline(cin, line)){
		cout << line << endl;
	}
	return 0;
}


#include <iostream>
#include <string>

using namespace std;

int main(){
	string word;
	cout << "请输入您的单词，不可以包含空格：" << endl;
	while(cin >> word){
		cout << word << endl;
	} 
	
	return 0;
}



/*
提示：标准库string的输入运算符自动忽略字符串开头的空白（包括空格符、换行符、制表符等等），从第一个真正的字符开始读起，直到遇见下一处空白
为止。如果希望在最终的字符串中保留输入时的空白符，应该使用getline函数代替原来的>>运算符，getline从给定的输入流中读取数据，直到遇到换行符
为止，此时换行符也被读取进来，但是并不存储在最后的字符串中。 
*/



/*
3.13下列的vector对象各包含多少元素？
(1)vector<int>v1;    1个0 
(2)vector<int>v2(10); 10个0 
(3)vector<int>v3(10, 42); 10个42 
(4)vector<int>v4{10}; 1个10 
(5)vector<int>v5{10, 42};  10和42各1个 
(6)vector<string>v6{10};  10个空串 
(7)vector<string>v7{10, "hi"};   10个"hi" 
*/ 



/*
3.22将text的第一段全部改成大写形式，然后输出它 
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	vector<string>text;
	string s;
	while(getline(cin, s)){
		text.push_back(s);
	}
	for(auto it = text.begin(); it != text.end(); it++){
		for(auto it2 =  it -> begin(); it2 != it -> end(); it2++){ //此处注意！！！！！！！！！！！！  
			*it2 = toupper(*it2);
		}
		cout << *it << endl;
	}
	return 0;
} 

//it -> mem 等价于(*it).mem!!!!!!!!!! 

/*
3.26
C++中没有定义两个迭代器的加法运算，实际上直接把两个迭代器加起来是没有意义的。与之相反，C++定义了迭代器的减法运算，
两个迭代器相减的结果是他们之间距离，也就是说，将运算符右侧的迭代器向前移动多少个元素后可以得到左侧的迭代器
C++还定义了迭代器与证书的加减法运算，用以控制迭代器在容器中左右移动 
*/ 


//size_t是一种无符号的整型数，它的取值没有负数，在数组中也用不到负数，而它的取值范围是整型数的双倍。 

/*
3.27
假设txt_size是一无参数的函数，它的返回值是int，下列定义是否合法
unsigned buf_size = 1024
(1)int ia[buf_size] ×:buf_size是一个普通的无符号数，不是常量，不能作为数组的维度 
(2)int ia[4*7-14]  √ 
(3)int ia[txt_size()] ×: txt_size()是普通的函数调用，没有被定义成constexpr 
(4)char st[11] = 'fundamental' ×：当使用字符串初始化字符数组时，默认在尾部添加一个空字符'\0' 
*/ 



/*
3.43
打印多维数组 
*/


#include <iostream>
using namespace std;

int main(){
	int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	cout << "利用范围for语句输出多维数组的内容" << endl;
	for(int (&row)[4] : ia){
		for(int & col : row){
			cout << col << " ";
		}
		cout << endl;
	}
	cout << "利用普通for语句和指针输出多维数组的内容" << endl; 
	for(int (*p)[4] = ia; p != ia + 3; p++){
		for(int *q = *p; q != *p + 4; q++){
			cout << *q << " ";
		}
		cout << endl;
	}
	return 0;
} 
