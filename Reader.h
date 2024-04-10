#ifndef READER_H
#define READER_H
#include<string>
#include"Book.h"
using namespace std;
class Reader:public::book
{
private:
	char num[30];//读者账号
	char name[30];//读者姓名
	char sex[30];//man or woman 读者性别
	char email[30];//读者邮箱 
	char birthday[30];//读者出生日期
	char password[30];//登录的密码 
	char phonenumber[30];//读者电话号码 
	int flag;//状态变量  0代表未借书或书已还  1代表书未还 
public:
	friend void Book::borrowbook();//友元-借书功能
	friend void Book::returnbook();//友元-还书功能 
	static int readernum;//读者数 
	int getflag();//返回flag 
	void getmessage();//从文件中读信息到对象数组中 
	char* getname();//得到读者姓名 
	char* getsex();//得到读者性别
	char* getemail();//得到读者邮箱
	char* getphonenumber();//得到读者电话号码 
	char* getbirthday();//得到读者生日
	char* getnum();//得到读者账号 
	char* getpassword();//得到读者密码 
    void setname(char* newname);//设置读者姓名 
	void setsex(char* newsex);//设置读者性别
	void setemail(char* newemail);//设置读者邮箱
	void setphonenumber(char* newphonenumber);//设置读者电话号码 
	void setbirthday(char* newbirthday);//设置读者生日
	void setnum(char* newnum);//设置读者账号 
	void setpassword(char* newpassword);//设置读者密码 
	void addreaders();   //添加读者
    void findreaders();//查找读者,管理员权限
    void editreaders();     //编辑读者信息
    void delreaders();  //删除读者,读者如果借书,需要还书后才能删除
};
#endif 
