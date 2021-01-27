/*
4.20
假设iter的类型vector<string>::iterator,下列是否合法？
（1）*iter++  √ 
（2）(*iter)++ × ：(*iter)为string, string没有递增操作 
（3）*iter.empty() × : 解引用的优先解低于点运算符，iter.empty()不合法，因为vector没有empty()操作 
（4） iter -> empty() √ 
（5） ++*iter × ：*iter为string, string没有递增操作 
（6）iter++.empty() √ 
*/ 

/*
4.37
用命名的强制类型转换改写下列旧式的转换语句
int i; 
double d;
const string *ps;
char *pc;
void *pv;

(1)pv = (void*) ps   : pv = static_cast<void*>(const_cast<string*>(ps)); 
(2)i = int(*pc) : i = static_cast<int>(*pc)
(3)pv = &d : pv = static_cast<void*>(&d)
(4)pc = (char*)pv : pc = static_cast<char*>(pv) 
*/
