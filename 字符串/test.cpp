#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include<sstream>
//#include <tr1/unordered_map>
using namespace std;
//建立转换映射 
map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map; //保存转换规则
	string key; //要转换的单词
	string value; //替换后的内容
				  //读取第一个单词存入key中，行中剩余内容存入value
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1) //检查是否有转换规则
			trans_map[key] = value.substr(1); //跳过前导空格
		else
			throw runtime_error("no rule for " + key);
	return trans_map;
}

//生成转换文本
const string & transform(const string &s, const map<string, string> &m)
{
	//实际的转换工作；此部分是程序的核心
	auto map_it = m.find(s);
	//如果单词在转换规则map中
	if (map_it != m.end()) //cend改为end 
		return map_it->second; //使用替换语句
	else
		return s; //否则返回原string 
}


/*单词转换程序*/
void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file); //保存转换规则
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);  //读取每个单词
		string word;
		bool firstword = true;      //控制是否打印空格 
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " ";      //在单词间打印一个空格
								  //transform 返回它的第一个参数或其他转换之后的形式
			cout << transform(word, trans_map); //打印输出 
		}
		cout << endl;  //完成一行的转换 
	}
}

int main()
{
	ifstream file1("map_file.txt"); //转换的规则 
	ifstream file2("data_input.txt"); //输入的文件 
	word_transform(file1, file2);
	return 0;
}