#include<iostream>
using namespace std;
#include<string.h>
#include"Book.h"
#include<fstream>
#include<iostream>
#include <graphics.h> //使用ege的头文件
#include <ege/sys_edit.h>//输入框所需的头文件
Book Books[10000];
int Book::numbers=0;
int j=0;
char* Book::getbookshelf()//查找该书所在的书架数和排数 
{
	return bookshelf;
}
char Book::getbookarea()//查找该书所在的区域
{
	return bookarea;
}
int Book::getbooknum()//查找该种图书的数量
{
	return booknum;
}
char* Book::getbookID()//查找图书的编号
{
	return bookID;
}
char* Book::getbookname()//查找图书名称 
{
	return bookname;
}
char* Book::getbookwriter()//查找图书作者
{
	return bookwriter;
}
double Book::getbookprice()//查找图书价格
{
	return bookprice;
}
void Book::setbookname(char* name) //设置图书名称
{
	strcpy(bookname,name);
}
void Book::setbookID(char* ID)//设置图书的编号
{
	strcpy(bookID,ID);
}
void Book::setbookwriter(char* newbookwriter)//设置图书作者
{
	strcpy(bookwriter,newbookwriter);
}
void Book::setprice(double newprice)//设置图书价格
{
	bookprice = newprice;
}
void Book::setbooknum(int newbooknum)//设置图书数量
{
	booknum = newbooknum;
}
void Book::setbookshelf(char* shelf)//设置图书的书架数和排数
{
	strcmp(bookshelf,shelf);
}
void Book::setbookarea(char ch)//设置图书所在区域 
{
	bookarea = ch;
}
void Book::getmessage()//从文件中读信息到对象数组中
{
	char newbookshelf[10];
	char newbookID[30];
	char ch;
	double newprice;
	char bookname1[30];
	char newbookwriter[30];
	int newbooknum;
	int i=-1;
	fstream file;
	file.open("book.txt",ios::in);
	if(file.fail())
	{
		cout<<"打开book.txt失败"<<endl;
		exit(0); 
	}
	while(!file.eof())
	{
		if(file.fail())
		   break;
		i++;
		file>> bookname1;
		file>> newbookID;
		file>> newbookwriter>> newbooknum;
		file>> newprice>> ch>> newbookshelf;
		Books[i].setbookname(bookname1);
		Books[i].setbookID(newbookID);
		Books[i].setbookwriter(newbookwriter);
		Books[i].setprice(newprice);
		Books[i].setbooknum(newbooknum);
		Books[i].setbookarea(ch);
		Books[i].setbookshelf(newbookshelf);
	}
	numbers=i;
	file.close();
}
void Book::borrowbook()//借书功能
{
	int flag=0;
	char newbookshelf[10];
	char newbookID[30];
	char ch;
	double newprice;
	char newbookname[30];
	char newbookwriter[30];
	int newbooknum;
	int i;
	PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//先清屏
	putimage(0,0,src3);//背景图是src3
	sys_edit editBox;
	xyprintf(290,200,"进入借书程序"); 
	xyprintf(290,230,"请输入您想要借的书名");
    editBox.create(false);						//创建，false表示单行
    editBox.move(290, 360);						//设置位置
    int editTextHeight = 16;
	editBox.size(editTextHeight * 10, 4 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	editBox.setbgcolor(WHITE);					//设置背景颜色
	editBox.setcolor(BLACK);					//设置文字颜色
    editBox.setfont(editTextHeight, 0, "楷体");	//设置字体
	int maxLen = 60;
	editBox.setmaxlen(maxLen);					//设置输入最大长度
	//editBox.setreadonly(false);				//默认允许输入
    editBox.visible(true);						//使可见
	//获取焦点
	editBox.setfocus();
	//创建输入缓存区
	const int buffSize = 100;
    char strBuffer[100]={"0"};
    int buffLen = 0;
	for (; is_run(); delay_fps(60)) {
		bool isOutput = false;

		//检测到回车键弹起就标记输出
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
			}
		}
		
		//需要输出
		if (isOutput) {
			//获取输入框内容字符串
			editBox.gettext(buffSize, strBuffer);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox.settext("");
			editBox.destroy();//销毁对话框 
		}
     
	for (i = 1; i <= Books[0].numbers; i++)
	    {
	     	if (strcmp(Books[i].getbookname(),strBuffer)==0)
		    {
		    strcmp(newbookname,Books[i].getbookname());
			strcmp(newbookID,Books[i].getbookID());
			strcmp(newbookwriter,Books[i].getbookwriter());
			newbooknum=Books[i].getbooknum();
			newprice=Books[i].getbookprice();
			ch=Books[i].getbookarea();
			strcmp(newbookshelf,Books[i].getbookshelf());
			xyprintf(290,260,"借书成功");
			xyprintf(290,290,"该书的信息如下：");
		    xyprintf(290,320,"该书的价格为：%lf",newprice,"元/每本");
			xyprintf(290,350,"该书所在区域为%c",ch);
			flag++;
			int k=Books[i].getbooknum()-1;
			Books[i].setbooknum(k); 
			}
		}
		if(flag==0&&isOutput)
		xyprintf(290,440,"该书已经被借完，借书失败");
			
			}
}
void Book::returnbook()//还书功能 
{
	char newbookshelf[10];
	char newbookID[30];
	char ch;
	double newprice;
	char newbookname[30];
	char newbookwriter[30];
	int newbooknum;
	int i,k=0;
	PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//先清屏
	putimage(0,0,src3);//背景图是src3
	sys_edit editBox;
	xyprintf(290,200,"进入还书程序"); 
	xyprintf(290,230,"请输入您想还的书的名称：");
    editBox.create(false);						//创建，false表示单行
    editBox.move(290, 360);						//设置位置
    int editTextHeight = 16;
	editBox.size(editTextHeight * 10, 4 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	editBox.setbgcolor(WHITE);					//设置背景颜色
	editBox.setcolor(BLACK);					//设置文字颜色
    editBox.setfont(editTextHeight, 0, "楷体");	//设置字体
	int maxLen = 60;
	editBox.setmaxlen(maxLen);					//设置输入最大长度
	//editBox.setreadonly(false);				//默认允许输入
    editBox.visible(true);						//使可见
	//获取焦点
	editBox.setfocus();
	//创建输入缓存区
	const int buffSize = 100;
    char strBuffer[100]={"0"};
    int buffLen = 0;
	for (; is_run(); delay_fps(60)) {
		bool isOutput = false;

		//检测到回车键弹起就标记输出
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
			}
		}
		
		//需要输出
		if (isOutput) {
			//获取输入框内容字符串
			editBox.gettext(buffSize, strBuffer);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox.settext("");
			editBox.destroy();//销毁对话框 
		}
     
	for (i = 1; i <= Books[0].numbers; i++)
	    {
	     	if (strcmp(Books[i].getbookname(),strBuffer)==0)
		    {
		    strcmp(newbookname,Books[i].getbookname());
			strcmp(newbookID,Books[i].getbookID());
			strcmp(newbookwriter,Books[i].getbookwriter());
			newbooknum=Books[i].getbooknum();
			newprice=Books[i].getbookprice();
			ch=Books[i].getbookarea();
			strcmp(newbookshelf,Books[i].getbookshelf());
			Books[i].setbooknum(newbooknum+1);
			xyprintf(290,260,"开始还书");
			xyprintf(290,290,"该书的信息如下：");
			xyprintf(290,320,"该书所在区域为%c",ch);
			xyprintf(290,350,"还书成功");
			k++;
		    }
		}
			if(k==0&&isOutput)
			{
				xyprintf(290,440,"查无此书，请检查书名是否输入正确");
			
			}
			
		}
}
void Book::findbook()//查找功能--查找图书信息 
{
	char newbookshelf[10];
	char newbookID[30];
	char ch;
	double newprice;
	char newbookname[30];
	char newbookwriter[30];
	int newbooknum;
	int i,k=0;
	PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//先清屏
	putimage(0,0,src3);//背景图是src3
	sys_edit editBox;
	xyprintf(290,200,"进入查找程序"); 
	xyprintf(290,230,"请输入您想查询的书的名称");
    editBox.create(false);						//创建，false表示单行
    editBox.move(290, 360);						//设置位置
    int editTextHeight = 16;
	editBox.size(editTextHeight * 10, 4 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	editBox.setbgcolor(WHITE);					//设置背景颜色
	editBox.setcolor(BLACK);					//设置文字颜色
    editBox.setfont(editTextHeight, 0, "楷体");	//设置字体
	int maxLen = 60;
	editBox.setmaxlen(maxLen);					//设置输入最大长度
	//editBox.setreadonly(false);				//默认允许输入
    editBox.visible(true);						//使可见
	//获取焦点
	editBox.setfocus();
	//创建输入缓存区
	const int buffSize = 100;
    char strBuffer[100]={"0"};
    int buffLen = 0;
	for (; is_run(); delay_fps(60)) {
		bool isOutput = false;

		//检测到回车键弹起就标记输出
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
			}
		}
		
		//需要输出
		if (isOutput) {
			//获取输入框内容字符串
			editBox.gettext(buffSize, strBuffer);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox.settext("");
			editBox.destroy();//销毁对话框 
		}
     
	for (i = 1; i <= Books[0].numbers; i++)
	    {
	     	if (strcmp(Books[i].getbookname(),strBuffer)==0)
		    {
		    strcmp(newbookname,Books[i].getbookname());
			strcmp(newbookID,Books[i].getbookID());
			strcmp(newbookwriter,Books[i].getbookwriter());
			newbooknum=Books[i].getbooknum();
			newprice=Books[i].getbookprice();
			ch=Books[i].getbookarea();
			strcmp(newbookshelf,Books[i].getbookshelf());
			xyprintf(290,260,"查找成功");
			xyprintf(290,290,"该书的信息如下：");
		    xyprintf(290,320,"该书的数量为：%d",newbooknum);
		    xyprintf(290,350,"该书的价格为：%lf",newprice);
			xyprintf(290,380,"该书所在区域为%c",ch);
			xyprintf(290,410,"查找完毕"); 
	        k++; 
			}
		}
		if (k == 0&&isOutput)
	    {
	    	xyprintf(290,260,"查无此书，请检查书名是否输入正确");
	    }
	}
}
void Book::revisebook()//修改功能--修改图书信息 
{
	int flag=0;
	fstream file;
	file.open("book.txt", ios::out);
	if (file.fail())
	{
		cout << "打开文件book.txt失败" << endl;
		exit(0);
	}
	bool isOutput1 = false;
	int k = 0;
	char newbookshelf[10];
	char newbookID[30];
	char ch;
	double newprice;
	char newbookname[30];
	char newbookwriter[30];
	int newbooknum;
	int i;
	const int buffSize1 = 100;
    char strBuffer1[30];
	PIMAGE src3,src4;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//先清屏
	putimage(0,0,src3);//背景图是src3
	sys_edit editBox;
	xyprintf(290,200,"进入修改程序"); 
	xyprintf(290,230,"请输入您想修改的书的名称：");
    editBox.create(false);						//创建，false表示单行
    editBox.move(290, 360);						//设置位置
    int editTextHeight = 16;
	editBox.size(editTextHeight * 10, 4 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	editBox.setbgcolor(WHITE);					//设置背景颜色
	editBox.setcolor(BLACK);					//设置文字颜色
    editBox.setfont(editTextHeight, 0, "楷体");	//设置字体
	int maxLen = 60;
	editBox.setmaxlen(maxLen);					//设置输入最大长度
	//editBox.setreadonly(false);				//默认允许输入
    editBox.visible(true);						//使可见
	//获取焦点
	editBox.setfocus();
	//创建输入缓存区
	const int buffSize = 100;
    char strBuffer[100]={"0"};
    int buffLen = 0;
	for (; is_run(); delay_fps(60)) {
		bool isOutput = false;

		//检测到回车键弹起就标记输出
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
			}
		}
		
		//需要输出
		if (isOutput) {
			//获取输入框内容字符串
			editBox.gettext(buffSize, strBuffer);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox.settext("");
			editBox.destroy();//销毁对话框 
		}
     
	for (i = 0; i <= Books[0].numbers; i++)
	    {
	     	if (strcmp(Books[i].getbookname(),strBuffer)==0)
		    {
		    	flag=i;
		    strcpy(newbookname,Books[i].getbookname());
			strcpy(newbookID,Books[i].getbookID());
			strcpy(newbookwriter,Books[i].getbookwriter());
			//newbooknum=Books[i].getbooknum();
			newprice=Books[i].getbookprice();
			ch=Books[i].getbookarea();
			strcpy(newbookshelf,Books[i].getbookshelf());
			src4 = newimage();
	        getimage(src4, "book.jpg");
	        cleardevice();//先清屏
	        putimage(0,0,src4);//背景图是src4
	        sys_edit editBox1;
	        xyprintf(290,200,"请输入该书新的编号：");
		    editBox1.create(false);						//创建，false表示单行
            editBox1.move(290, 360);						//设置位置
	        editBox1.size(editTextHeight * 10, 4 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	        editBox1.setbgcolor(WHITE);					//设置背景颜色
	        editBox1.setcolor(BLACK);					//设置文字颜色
            editBox1.setfont(editTextHeight, 0, "楷体");	//设置字体
	        editBox1.setmaxlen(maxLen);					//设置输入最大长度
	        //editBox.setreadonly(false);				//默认允许输入
            editBox1.visible(true);						//使可见
	       //获取焦点
	        editBox1.setfocus();
	       //创建输入缓存区
		   
           int buffLen = 0;
	       for (; is_run(); delay_fps(60)) {
	     	bool isOutput1 = false;

		 //检测到回车键弹起就标记输出
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput1 = true;
			}
		}
		
		//需要输出
		if (isOutput1) {
			 editBox1.gettext(buffSize1,strBuffer1 );
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox1.settext("");
			editBox1.destroy();//销毁对话框 
	        Books[i].setbookID(strBuffer1); 
		}
		for (int i = 0; i < Books[0].numbers;i++)
	        {
	        strcpy(newbookname,Books[i].getbookname());
			strcpy(newbookID,Books[i].getbookID());
			strcpy(newbookwriter,Books[i].getbookwriter());
			newprice=Books[i].getbookprice();
			ch=Books[i].getbookarea();
			strcpy(newbookshelf,Books[i].getbookshelf());
			newbooknum=Books[i].getbooknum();
			file<< newbookname<<endl
	         << newbookID<<endl<< newbookwriter<<endl
	         << newbooknum<<endl<< newprice<<endl
	         << ch<<endl<< newbookshelf<<endl;
			}
			k++;
		if (k == 0&&isOutput1)
	    {
	    	xyprintf(290,260,"查无此书，请检查书名是否输入正确");
	    }
	   file.close();
	   int p=0;
	   if(p==0&&isOutput1)
	   {
	    cout<<"新修改的图书的信息为："<<endl;
	    cout<<"该书的名称为:"<<newbookname<<endl;
	    cout<<"该书的编号为："<<strBuffer1<<endl;
        cout<<"该书的作者为："<<newbookwriter<<endl;
        cout<<"该书的价格为:"<<newprice<<"元/每本"<<endl;
        cout<<"该书所在区域为"<<ch<<endl;
        p++;
    }
    }
}
}
}
}
void Book::addbook()//添加功能--增加图书信息 
{
	int w=0; 
	bool isOutput=false;
	fstream file;
	file.open("book.txt",ios::app);
	if (file.fail())
	{
		cout << "打开文件book.txt失败" << endl;
		exit(0);
	}
	char newbookshelf[10];
	char newbookID[30]={"0"};
	char ch;
	double newprice;
	char newbookname[30]={"0"};
	char newbookwriter[30]={"0"};
	char strBuffer[30]={"0"};
	int newbooknum;
	int i,k=0;
	i=numbers;
	cleardevice();//先清屏
	PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src3
	sys_edit editBox,editBox1,editBox2,editBox3,editBox4,editBox5,editBox6;
	xyprintf(290,200,"进入添加程序"); 
	xyprintf(290,230,"请输入该书的名称：");
	i++;
    editBox.create(false);						//创建，false表示单行
    editBox.move(290, 360);						//设置位置
    int editTextHeight = 16;
	editBox.size(editTextHeight * 10, 4 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	editBox.setbgcolor(WHITE);					//设置背景颜色
	editBox.setcolor(BLACK);					//设置文字颜色
    editBox.setfont(editTextHeight, 0, "楷体");	//设置字体
	int maxLen = 60;
	editBox.setmaxlen(maxLen);					//设置输入最大长度
	//editBox.setreadonly(false);				//默认允许输入
    editBox.visible(true);						//使可见
	//获取焦点
	editBox.setfocus();
	//创建输入缓存区
	const int buffSize = 100;
    int buffLen = 0;
	for (; is_run(); delay_fps(60)) {

		//检测到回车键弹起就标记输出
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
			}
		}
		
		//需要输出
		if (isOutput) {
			//获取输入框内容字符串
			editBox.gettext(buffSize, newbookname);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox.settext("");
			editBox.destroy();//销毁对话框 
			 w++;
			 Books[i].setbookname(newbookname);
		}
    if(w==1)
    {
    cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src3
    isOutput=false;
	xyprintf(290,230,"请输入该书的编号：");
    editBox1.create(false);						//创建，false表示单行
    editBox1.move(290, 360);						//设置位置
	editBox1.size(editTextHeight * 10, 4 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	editBox1.setbgcolor(WHITE);					//设置背景颜色
	editBox1.setcolor(BLACK);					//设置文字颜色
    editBox1.setfont(editTextHeight, 0, "楷体");	//设置字体
	editBox1.setmaxlen(maxLen);					//设置输入最大长度
	//editBox.setreadonly(false);				//默认允许输入
    editBox1.visible(true);						//使可见
	//获取焦点
	editBox1.setfocus();
	//创建输入缓存区
	for (; is_run(); delay_fps(60)) {
		bool isOutput = false;

		//检测到回车键弹起就标记输出
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
			}
		}
		
		//需要输出
		if (isOutput) {
			//获取输入框内容字符串
			editBox1.gettext(buffSize, newbookID);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox1.settext("");
			editBox1.destroy();//销毁对话框 
			Books[i].setbookID(newbookID);
			w++;
		}
		 if(w==2)
    {
	cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该书的作者：");
    editBox2.create(false);						//创建，false表示单行
    editBox2.move(290, 360);						//设置位置
	editBox2.size(editTextHeight * 10, 4 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	editBox2.setbgcolor(WHITE);					//设置背景颜色
	editBox2.setcolor(BLACK);					//设置文字颜色
    editBox2.setfont(editTextHeight, 0, "楷体");	//设置字体
	editBox2.setmaxlen(maxLen);					//设置输入最大长度
	//editBox.setreadonly(false);				//默认允许输入
    editBox2.visible(true);						//使可见
	//获取焦点
	editBox2.setfocus();
	//创建输入缓存区
	for (; is_run(); delay_fps(60)) {
		bool isOutput = false;

		//检测到回车键弹起就标记输出
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
			}
		}
		
		//需要输出
		if (isOutput) {
			//获取输入框内容字符串
			editBox2.gettext(buffSize, newbookwriter);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox2.settext("");
			editBox2.destroy();//销毁对话框 
			Books[i].setbookwriter(newbookwriter);
			w++;
		}
		if(w==3)
    {
    cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该书的价格：");
    editBox3.create(false);						//创建，false表示单行
    editBox3.move(290, 360);						//设置位置
	editBox3.size(editTextHeight * 10, 4 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	editBox3.setbgcolor(WHITE);					//设置背景颜色
	editBox3.setcolor(BLACK);					//设置文字颜色
    editBox3.setfont(editTextHeight, 0, "楷体");	//设置字体
	editBox3.setmaxlen(maxLen);					//设置输入最大长度
	//editBox.setreadonly(false);				//默认允许输入
    editBox3.visible(true);						//使可见
	//获取焦点
	editBox3.setfocus();
	//创建输入缓存区
	for (; is_run(); delay_fps(60)) {
		bool isOutput = false;

		//检测到回车键弹起就标记输出
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
			}
		}
		
		//需要输出
		if (isOutput) {
			//获取输入框内容字符串
			editBox3.gettext(buffSize,strBuffer );
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox3.settext("");
			editBox3.destroy();//销毁对话框 
			sscanf(strBuffer, "%lf", &newprice);
			Books[i].setprice(newprice);
	        w++;
		}
	    if(w==4)
    {
    cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该书的数量：");
    editBox4.create(false);						//创建，false表示单行
    editBox4.move(290, 360);						//设置位置
	editBox4.size(editTextHeight * 10, 4 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	editBox4.setbgcolor(WHITE);					//设置背景颜色
	editBox4.setcolor(BLACK);					//设置文字颜色
    editBox4.setfont(editTextHeight, 0, "楷体");	//设置字体
	editBox4.setmaxlen(maxLen);					//设置输入最大长度
	//editBox.setreadonly(false);				//默认允许输入
    editBox4.visible(true);						//使可见
	//获取焦点
	editBox4.setfocus();
	//创建输入缓存区
	for (; is_run(); delay_fps(60)) {
		bool isOutput = false;

		//检测到回车键弹起就标记输出
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
			}
		}
		
		//需要输出
		if (isOutput) {
			//获取输入框内容字符串
			editBox4.gettext(buffSize,strBuffer );
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox4.settext("");
			editBox4.destroy();//销毁对话框 
			sscanf(strBuffer, "%d", &newbooknum);
	        Books[i].setbooknum(newbooknum);
         	w++;
		}
		if(w==5)
    {
	cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该书的所在区域(A,B,C,D其中之一):");
    editBox5.create(false);						//创建，false表示单行
    editBox5.move(290, 360);						//设置位置
	editBox5.size(editTextHeight * 10, 4 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	editBox5.setbgcolor(WHITE);					//设置背景颜色
	editBox5.setcolor(BLACK);					//设置文字颜色
    editBox5.setfont(editTextHeight, 0, "楷体");	//设置字体
	editBox5.setmaxlen(maxLen);					//设置输入最大长度
	//editBox.setreadonly(false);				//默认允许输入
    editBox5.visible(true);						//使可见
	//获取焦点
	editBox5.setfocus();
	//创建输入缓存区
	for (; is_run(); delay_fps(60)) {
		bool isOutput = false;

		//检测到回车键弹起就标记输出
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
			}
		}
		
		//需要输出
		if (isOutput) {
			//获取输入框内容字符串
			editBox5.gettext(buffSize,strBuffer );
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox5.settext("");
			editBox5.destroy();//销毁对话框 
			editBox5.gettext(buffSize, strBuffer);
	        sscanf(strBuffer, "%c", &ch);
	        Books[i].setbookarea(ch);
	        w++;
		}
		if(w==6)
    {
	 cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该书的书架数和排数");
	xyprintf(290,260,"输入一个四位数，前两位代表书架数，后两位代表排数");
    editBox6.create(false);						//创建，false表示单行
    editBox6.move(290, 360);						//设置位置
	editBox6.size(editTextHeight * 10, 4 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	editBox6.setbgcolor(WHITE);					//设置背景颜色
	editBox6.setcolor(BLACK);					//设置文字颜色
    editBox6.setfont(editTextHeight, 0, "楷体");	//设置字体
	editBox6.setmaxlen(maxLen);					//设置输入最大长度
	//editBox.setreadonly(false);				//默认允许输入
    editBox6.visible(true);						//使可见
	//获取焦点
	editBox6.setfocus();
	//创建输入缓存区
	for (; is_run(); delay_fps(60)) {
		bool isOutput = false;

		//检测到回车键弹起就标记输出
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
			}
		}
		
		//需要输出
		if (isOutput) {
			//获取输入框内容字符串
			editBox6.gettext(buffSize, newbookshelf);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox6.settext("");
			editBox6.destroy();//销毁对话框 
			Books[i].setbookshelf(newbookshelf);
			w++;
		}
	if(w==7)
	{
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//先清屏
	putimage(0,0,src3);//背景图是src3
	xyprintf(290,260,"添加完成");
	xyprintf(290,290,"新添加的图书的信息为：");
	xyprintf(290,320,"该书的名称为:%s",newbookname);
	xyprintf(290,350,"该书的编号为：%s",newbookID);
	xyprintf(290,380,"该书的作者为：%s",newbookwriter);
	xyprintf(290,410,"该书的数量为：%d",newbooknum,"本");
	xyprintf(290,440,"该书的价格为：%lf",newprice,"元/每本");
	xyprintf(290,470,"该书所在区域为%c",ch);
	xyprintf(290,500,"该书所在的书架数和排数为%s",newbookshelf);
	file<< newbookname<<endl
	<< newbookID<<endl<< newbookwriter<<endl
	<< newbooknum<<endl<< newprice<<endl
	<< ch<<endl<< newbookshelf<<endl;
	w++;
	file.close(); 
	   }
	   }
     }
    }
  }
 }
}
}
}
}
}
}
}
}
}
void Book::deletebook()//删除功能--删除图书信息 
{
	int h=0;
	int flag=0;
	fstream file;
	file.open("book.txt",ios::out);
	if (file.fail())
	{
		cout << "打开文件book.txt失败" << endl;
		exit(0);
	}
	char newbookshelf[10];
	char newbookID[30];
	char ch;
	double newprice;
	char newbookname[30];
	char newbookwriter[30];
	int newbooknum;
	int i,k=0;
	PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//先清屏
	putimage(0,0,src3);//背景图是src3
	sys_edit editBox;
	xyprintf(290,200,"进入删除程序"); 
	xyprintf(290,230,"请输入您想删除的书的名称：");
    editBox.create(false);						//创建，false表示单行
    editBox.move(290, 360);						//设置位置
    int editTextHeight = 16;
	editBox.size(editTextHeight * 10, 4 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	editBox.setbgcolor(WHITE);					//设置背景颜色
	editBox.setcolor(BLACK);					//设置文字颜色
    editBox.setfont(editTextHeight, 0, "楷体");	//设置字体
	int maxLen = 60;
	editBox.setmaxlen(maxLen);					//设置输入最大长度
	//editBox.setreadonly(false);				//默认允许输入
    editBox.visible(true);						//使可见
	//获取焦点
	editBox.setfocus();
	//创建输入缓存区
	const int buffSize = 100;
    char strBuffer[30];
    int buffLen = 0;
	for (; is_run(); delay_fps(60)) {
		bool isOutput = false;

		//检测到回车键弹起就标记输出
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
				editBox.destroy();//销毁对话框 
			}
		}
		
		//需要输出
		if (isOutput) {
			//获取输入框内容字符串
			editBox.gettext(buffSize, strBuffer);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox.settext("");
		}
     
	for (i = 1; i <= Books[0].numbers; i++)
	    {
	     	if (strcmp(Books[i].getbookname(),strBuffer)==0)
		    {
		    h++;
		    flag=i;
		    strcpy(newbookname,Books[i].getbookname());
			strcpy(newbookID,Books[i].getbookID());
			strcpy(newbookwriter,Books[i].getbookwriter());
			newbooknum=Books[i].getbooknum();
			newprice=Books[i].getbookprice();
			ch=Books[i].getbookarea();
			strcpy(newbookshelf,Books[i].getbookshelf());
			xyprintf(290,260,"查找成功");
			xyprintf(290,290,"您要删除的图书的信息如下：");
	        xyprintf(290,320,"该书的名称为:%s",newbookname);
	        xyprintf(290,350,"该书的编号为：%s",newbookID);
		    xyprintf(290,380,"该书的作者为：%s",newbookwriter);
		    xyprintf(290,410,"该书的数量为：%d",newbooknum,"本");
		    xyprintf(290,440,"该书的价格为：%lf",newprice);
			xyprintf(290,470,"该书所在区域为%c",ch);
			xyprintf(290,500,"该书所在的书架数和排数为%s",newbookshelf);
			break;
			}
		}
		    if(h!=0&&isOutput)
		    {
		    	xyprintf(290,530,"删除成功");
			}
		        for (int i = 1; i < Books[0].numbers; i++)
		        {
		        if(i==flag)
				   continue;
		        strcpy(newbookname,Books[i].getbookname());
		        strcpy(newbookID,Books[i].getbookID());
	         	strcpy(newbookwriter,Books[i].getbookwriter());
	        	newbooknum=Books[i].getbooknum();
		        newprice=Books[i].getbookprice();
	        	ch=Books[i].getbookarea();
	        	strcpy(newbookshelf,Books[i].getbookshelf());
	        	file<< newbookname<<endl
	            << newbookID<<endl<< newbookwriter<<endl
	            << newbooknum<<endl<< newprice<<endl
	            << ch<<endl<< newbookshelf<<endl;
	            }
	            Books[0].numbers--;
				file.close();
	    }
}
	
void Book::deletebookshelf()//清除功能--清空图书架
{
	fstream file;
	file.open("book.txt",ios::out);
	if (file.fail())
	{
		cout << "打开文件book.txt失败" << endl;
		exit(0);
	}
	char newbookshelf[10];
	char newbookID[30];
	char ch;
	double newprice;
	char newbookname[30];
	char newbookwriter[30];
	int newbooknum;
	int i,k=0;
	PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//先清屏
	putimage(0,0,src3);//背景图是src3
	xyprintf(290,200,"进入清空程序"); 
	Books[0].numbers=0;
	Books[0].numbers=0;
	xyprintf(290,230,"清空图书架成功");
	file.close();
}

