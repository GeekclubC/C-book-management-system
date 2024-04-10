#include<cstring>
#include<fstream>
#include<iostream>
#include<string.h>
#include <graphics.h> //使用ege的头文件
#include <ege/sys_edit.h>//输入框所需的头文件
using namespace std; 
#include"Reader.h"
int Reader::readernum=0; 
Reader readers[1000];
int Reader::getflag()//得到flag 
{
	return flag;
}
char* Reader::getname()//得到读者姓名
{
	return name;
} 
char* Reader::getsex()//得到读者性别
{
	return sex;
}
char* Reader::getemail()//得到读者邮箱
{
	return email;
}
char* Reader::getphonenumber()//得到读者电话号码
{
	return phonenumber;
}
char* Reader::getbirthday()//得到读者生日
{
	return birthday;
}
char* Reader::getnum()//得到读者账号
{
	return num; 
 } 
char* Reader::getpassword()//得到读者密码 
{
	return password;
}
void Reader::setname(char* newname)//设置读者姓名 
{
	strcpy(name,newname);
}
void Reader::setsex(char* newsex)//设置读者性别
{
	strcpy(sex,newsex);
}
void Reader::setemail(char* newemail)//设置读者邮箱
{
	strcpy(email,newemail);
}
void Reader::setphonenumber(char* newphonenumber)//设置读者电话号
{
	strcpy(phonenumber,newphonenumber); 
}
void Reader::setbirthday(char* newbirthday)//设置读者生日
{
	strcpy(birthday,newbirthday);
}
void Reader::setnum(char* newnum)//读者账号
{
	strcpy(num,newnum);
}
void Reader::setpassword(char* newpassword)//设置读者密码
{
	strcpy(password,newpassword);
 }
void Reader::getmessage()//从文件中读信息到对象数组中 
{
    int i=-1;
	char num1[30];
	char newphone[30];
	char name1[30],sex1[30],email1[30];
	char birthday1[30],password1[30];
	fstream file;
	file.open("readers.txt",ios::in);
	if(file.fail())
	{
		cout<<"打开reader.txt失败"<<endl;
		exit(0); 
	}
	while(!file.eof())
	{
		if(file.fail())
		   break;
		i++;
		file>>name1>>sex1
		>>email1>>birthday1
		>>num1>>password>>newphone;
	    readers[i].setname(name1);
	    readers[i].setsex(sex1);
	    readers[i].setemail(email1);
	    readers[i].setphonenumber(newphone);
	    readers[i].setbirthday(birthday1);
	    readers[i].setnum(num1);
	    readers[i].setpassword(password1);
	}
	readers[0].readernum=i;
	file.close();
}
void Reader::addreaders()//创建读者账号 
{
    bool isOutput=false; 
	int i=0,w=0;
	char num1[30];
	char newphone[30];
	char name1[30],sex1[30],email1[30];
	char birthday1[30],password1[30];
	fstream file;
	file.open("readers.txt",ios::app);
	if(file.fail())
	{
		cout<<"无法打开文件reader.txt"<<endl;
		exit(0); 
	}
	readers[0].readernum++;
	i=readers[0].readernum;
	cleardevice();//先清屏
	PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src3
	sys_edit editBox,editBox1,editBox2,editBox3,editBox4,editBox5,editBox6;
	xyprintf(290,200,"进入添加程序"); 
	xyprintf(290,230,"请输入该读者的姓名：");
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
			editBox.gettext(buffSize, name1);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox.settext("");
			editBox.destroy();//销毁对话框 
			 w++;
			 readers[i].setname(name1);
		}
    if(w==1)
    {
    cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src3
    isOutput=false;
	xyprintf(290,230,"请输入该读者的性别：");
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
			editBox1.gettext(buffSize, sex1);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox1.settext("");
			editBox1.destroy();//销毁对话框 
			readers[i].setsex(sex1);
			w++;
		}
		 if(w==2)
    {
	cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该读者的邮箱：");
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
			editBox2.gettext(buffSize, email1);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox2.settext("");
			editBox2.destroy();//销毁对话框 
			readers[i].setemail(email1);
			w++;
		}
	if(w==3)
    {
    cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该读者的出生日期：");
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
			editBox3.gettext(buffSize,birthday1);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox3.settext("");
			editBox3.destroy();//销毁对话框 
			readers[i].setbirthday(birthday1);
	        w++;
		}
	    if(w==4)
    {
    cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该读者的账号：");
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
			editBox4.gettext(buffSize,num1);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox4.settext("");
			editBox4.destroy();//销毁对话框 
	        readers[i].setnum(num1);
         	w++;
		}
		if(w==5)
    {
	cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该读者的密码:");
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
			editBox5.gettext(buffSize,password1);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox5.settext("");
			editBox5.destroy();//销毁对话框 
	        readers[i].setpassword(password1);
	        w++;
		}
		if(w==6)
    {
	 cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该读者的电话号码：");
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
			editBox6.gettext(buffSize, newphone);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox6.settext("");
			editBox6.destroy();//销毁对话框 
			readers[i].setphonenumber(newphone);
			w++;
		}
	if(w==7)
	{
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//先清屏
	putimage(0,0,src3);//背景图是src3
	xyprintf(290,260,"添加完成");
	xyprintf(290,290,"新添加的读者的信息为：");
	xyprintf(290,320,"该读者的名字为:%s",name1);
	xyprintf(290,350,"该读者的性别为：%s",sex1);
	xyprintf(290,380,"该读者的邮箱为：%s",email1);
	xyprintf(290,410,"该读者的出生日期为：%s",birthday1);
	xyprintf(290,440,"该读者的账号为:%s",num1);
	xyprintf(290,470,"该读者的密码为：%s",password1);
	xyprintf(290,500,"该读者的电话号码为%s",newphone);
	file<<name1<<endl<<sex1<<endl;
	file<<email1<<endl<<birthday1<<endl;
	file<<num1<<endl;
	file<<password1<<endl<<newphone;
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
void Reader::findreaders()//查找读者，管理员权限 
{
	int i=0,k=0;
	char num1[30];
	char newphone[30];
	char name1[30],sex1[30],email1[30];
	char birthday1[30],password1[30];
	PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//先清屏
	putimage(0,0,src3);//背景图是src3
	sys_edit editBox;
	xyprintf(290,200,"进入查找程序"); 
	xyprintf(290,230,"请输入您要查找的读者的姓名");
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
     
	for (i = 0; i <= readers[0].readernum; i++)
	    {
	     	if (strcmp(readers[i].getname(),strBuffer)==0)
		    {
		       strcpy(name1,readers[i].getname());
               strcpy(sex1,readers[i].getsex());
               strcpy(email1,readers[i].getemail());
               strcpy(newphone,readers[i].getphonenumber()); 
			   strcpy(birthday1,readers[i].getbirthday());
			   strcpy(num1,readers[i].getnum()); 
			   xyprintf(290,260,"查找成功");
			   xyprintf(290,290,"该读者的信息如下：");
	           xyprintf(290,320,"该读者的名字为:%s",name1);
	           xyprintf(290,350,"该读者的性别为：%s",sex1);
		       xyprintf(290,380,"该读者的邮箱为：%s",email1);
		       xyprintf(290,410,"该读者的出生日期为：%s",birthday1);
		       xyprintf(290,440,"该读者的账号为:%s",num1);
			   xyprintf(290,470,"该读者的电话号码为%s",newphone);
			   xyprintf(290,500,"查找完毕"); 
	           k++; 
			}
		}
		if (k == 0&&isOutput)
	    {
	    	xyprintf(290,260,"查无此人，请检查读者姓名是否输入正确");
	    }
	}
}
void Reader::editreaders()//修改读者个人信息
{
	int flag=0;
	bool isOutput=false; 
	int i=0,w=0;
	char num1[30];
	char newphone[30];
	char name1[30],sex1[30],email1[30];
	char birthday1[30],password1[30];
	fstream file;
	file.open("readers.txt",ios::out);
	if(file.fail())
	{
		cout<<"无法打开文件reader.txt"<<endl;
		exit(0); 
	}
	readers[0].readernum++;
	i=readers[0].readernum;
	cleardevice();//先清屏
	PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src3
	sys_edit editBox,editBox1,editBox2,editBox3,editBox4,editBox5,editBox6,editBox7;
	xyprintf(290,200,"进入修改程序"); 
	xyprintf(290,230,"请输入要修改信息的读者的姓名：");
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
			editBox.gettext(buffSize, name1);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox.settext("");
			editBox.destroy();//销毁对话框 
			 w++;
			 //readers[i].setname(name1);
		}
for (i = 0; i < readers[0].readernum; i++)
	{
	if (strcmp(readers[i].getname(),name1)==0)
		{
			flag=i;
		if(w==1)
	{
	cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src3
    isOutput=false;
	xyprintf(290,230,"请输入该读者新的姓名：");
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
			editBox1.gettext(buffSize, name1);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox1.settext("");
			editBox1.destroy();//销毁对话框 
			readers[i].setname(name1);
			w++;
		}
		if(w==2)
    {
    cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src3
    isOutput=false;
	xyprintf(290,230,"请输入该读者新的性别：");
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
			editBox1.gettext(buffSize, sex1);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox1.settext("");
			editBox1.destroy();//销毁对话框 
			readers[i].setsex(sex1);
			w++;
		}
		 if(w==3)
    {
	cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该读者的邮箱：");
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
			editBox2.gettext(buffSize, email1);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox2.settext("");
			editBox2.destroy();//销毁对话框 
			readers[i].setemail(email1);
			w++;
		}
		if(w==4)
    {
    cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该读者的出生日期：");
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
			editBox3.gettext(buffSize,birthday1);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox3.settext("");
			editBox3.destroy();//销毁对话框 
			readers[i].setbirthday(birthday1);
	        w++;
		}
	    if(w==5)
    {
    cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该读者的账号：");
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
			editBox4.gettext(buffSize,num1);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox4.settext("");
			editBox4.destroy();//销毁对话框 
	        readers[i].setnum(num1);
         	w++;
		}
		if(w==6)
    {
	cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该读者的密码:");
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
			editBox5.gettext(buffSize,password1);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox5.settext("");
			editBox5.destroy();//销毁对话框 
	        readers[i].setpassword(password1);
	        w++;
		}
		if(w==7)
    {
	 cleardevice();//先清屏
    PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//背景图是src4
	xyprintf(290,230,"请输入该读者的电话号码：");
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
			editBox6.gettext(buffSize, newphone);
			//如果你想获取后清空输入框，设置内容为空字符串
			editBox6.settext("");
			editBox6.destroy();//销毁对话框 
			readers[i].setphonenumber(newphone);
			w++;
		}
	if(w==8)
	{
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//先清屏
	putimage(0,0,src3);//背景图是src3
	xyprintf(290,260,"修改完成");
	xyprintf(290,290,"该读者的新信息为：");
	xyprintf(290,320,"该读者的新名字为:%s",name1);
	xyprintf(290,350,"该读者的新性别为：%s",sex1);
	xyprintf(290,380,"该读者的新邮箱为：%s",email1);
	xyprintf(290,410,"该读者的新出生日期为：%s",birthday1);
	xyprintf(290,440,"该读者的新账号为:%s",num1);
	xyprintf(290,470,"该读者的新密码为：%s",password1);
	xyprintf(290,500,"该读者的新电话号码为%s",newphone);
	xyprintf(290,530,"修改完成");
	for (int i = 0; i < readers[0].readernum; i++)
		{
			if(i==flag)
			{
				file<<name1<<endl<<sex1<<endl;
	         	file<<email1<<endl<<birthday1<<endl;
		        file<<num1<<endl;
		        file<<password1<<endl<<newphone;
			}
			else
			{
		    strcpy(name1,readers[i].getname());
            strcpy(sex1,readers[i].getsex());
            strcpy(email1,readers[i].getemail());
            strcpy(newphone,readers[i].getphonenumber()); 
		    strcpy(birthday1,readers[i].getbirthday());
		    strcpy(num1,readers[i].getnum()); 
	        strcpy(password1,readers[i].getpassword());
		    file<<name1<<endl<<sex1<<endl;
		    file<<email1<<endl<<newphone<<endl;
		    file<<birthday1<<endl<<num1<<endl;
		    file<<password<<endl;
		    }
	    }
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
}
}
}
}
void Reader::delreaders()  //删除读者
{
	int flag=0;
	int i=0,k=0;
	char num1[30];
	char newphone[30];
	char name1[30],sex1[30],email1[30];
	char birthday1[30],password1[30];
	fstream file; 
	file.open("readers.txt",ios::out);
	if(file.fail())
	{
		cout<<"无法打开文件reader.txt"<<endl;
		exit(0); 
	}
	PIMAGE src3;//定义图像对象
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//先清屏
	putimage(0,0,src3);//背景图是src3
	sys_edit editBox;
	xyprintf(290,200,"进入删除程序"); 
	xyprintf(290,230,"请输入您想删除的读者的姓名：");
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
     
	for (i = 0; i < readers[0].readernum; i++)
	    {
	     	if (strcmp(readers[i].getname(),strBuffer)==0)
		    {
		    	flag=i;
		       strcpy(name1,readers[i].getname());
               strcpy(sex1,readers[i].getsex());
               strcpy(email1,readers[i].getemail());
               strcpy(newphone,readers[i].getphonenumber()); 
			   strcpy(birthday1,readers[i].getbirthday());
			   strcpy(num1,readers[i].getnum()); 
	           strcpy(password1,readers[i].getpassword());
			   xyprintf(290,260,"查找成功");
			   xyprintf(290,290,"您要删除的读者的信息如下：");
	           xyprintf(290,320,"该读者的名字为:%s",name1);
	           xyprintf(290,350,"该读者的性别为：%s",sex1);
		       xyprintf(290,380,"该读者的邮箱为：%s",email1);
		       xyprintf(290,410,"该读者的出生日期为：%s",birthday1);
		       xyprintf(290,440,"该读者的账号为:%s",num1);
			   xyprintf(290,470,"该读者的密码为：%s",password1);
			   xyprintf(290,500,"该读者的电话号码为%s",newphone);
			   xyprintf(290,530,"查找完毕"); 
				break;
			}
		}
		        for (int j = 0; j < readers[0].readernum; j++)
		        {
		        	if(flag==i)
		        	  continue;
		        strcpy(name1,readers[i].getname());
                strcpy(sex1,readers[i].getsex());
                strcpy(email1,readers[i].getemail());
                strcpy(newphone,readers[i].getphonenumber()); 
			    strcpy(birthday1,readers[i].getbirthday());
			    strcpy(num1,readers[i].getnum()); 
	            strcpy(password1,readers[i].getpassword());
				file<<name1<<endl<<sex1<<endl;
				file<<email1<<endl<<newphone<<endl;
				file<<birthday1<<endl<<num1<<endl;
				file<<password<<endl;
			}
	             xyprintf(290,530,"删除成功"); 
				file.close();
	    }
}

