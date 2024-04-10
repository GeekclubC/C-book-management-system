#ifndef BOOK_H
#define BOOK_H
using namespace std;

class Book
{
	private:
		int booknum;//书的数量
		char bookname[30];//书的名称
		char bookID[30];//书的编号
		char bookwriter[30];//书的作者
		double bookprice;//书的价格 
		char bookarea;//书所在的区域，A,B,C,D其中之一 
		char bookshelf[10];/*书所在的书架数和排数，用4位数表示，例如：
		0411代表该书在4号书架，从上往下数第11排;*/

	public:
		static int numbers;//记录书的种数
		void getmessage();//从文件中读信息到对象数组中
		void borrowbook();//借书功能
		void returnbook();//还书功能 
		void findbook();//查找功能--查找图书信息 
		void revisebook();//修改功能--修改图书信息 
		void addbook();//添加功能--增加图书信息 
		void deletebook();//删除功能--删除图书信息 
		void deletebookshelf();//清除功能--清空图书架 
		char* getbookshelf();//查找该书所在的书架数和排数 
		char getbookarea();//查找该书所在的区域 
		int getbooknum();//查找该种图书的数量
		char* getbookID();//查找图书的编号
		char* getbookname(); //查找图书名称 
		char* getbookwriter();//查找图书作者
		double getbookprice();//查找图书价格
		void setbookname(char* name);//设置图书名称
		void setbookID(char* ID) ;//设置图书的编号
		void setbookwriter(char* newbookwriter) ;//设置图书作者
		void setprice(double newprice);//设置图书价格
		void setbooknum(int newbooknum);//设置图书数量
		void setbookshelf(char* shelf);//设置图书的书架数和排数
		void setbookarea(char ch);//设置图书所在区域 
};
#endif
