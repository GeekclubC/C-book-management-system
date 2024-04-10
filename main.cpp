#include<iostream>
using namespace std;
#include<string.h>
#include"Book.h"
#include"Reader.h"
#include<fstream>
#include<iostream>
#include <cstdlib>      //system() 库
#include <graphics.h> //使用ege的头文件
#include <ege/sys_edit.h>//输入框所需的头文件
void bookmenu();
void readermenu();
void test() {
	Reader b;
   	b.getmessage();//将reader.txt中的数据导入对象数组readers[1000]中 
	Book a;
	a.getmessage();//将book.txt中的数字导入对象数组Books[10000]中
	int n,m;
	initgraph(958, 1920);		//创建窗口
	PIMAGE src1;//定义图像对像 
	src1 = newimage();//创建图像对象
	getimage(src1, "1.jpg");//从文件中读取图片
	putimage(0, 0, src1);//在窗口上绘制图片，相当于贴上你的背景图
	setfont(26, 0, "宋体");//设置字体，26是字高， 0指的是字宽根据字高自动调整， 宋体是字体
	setbkmode(TRANSPARENT);//这个是将文字的背景色设置成透明，否则一个字后面会有色块
	setcolor(BLACK);//这个是设置字体颜色
	for(; is_run(); delay_fps(60)) //is_run()判断窗口是否存在，delay_fps(60) 作用是稳定帧率并刷新窗口 ，一秒钟循环60次
	{	
 
		mouse_msg msg = {0};	//定义鼠标变量并且初始化
		while(mousemsg()) 
		{  //利用mousemsg()判断有没有鼠标消息
			msg = getmouse();
		} //获得鼠标消息
		if((msg.x > 425 && msg.x < 520) && (msg.y > 135 && msg.y < 180) && msg.is_left() && msg.is_down()) 
		{   
			a.borrowbook();//借书函数
		} 
		else if((msg.x > 420 && msg.x < 520) && (msg.y > 240 && msg.y < 280) && msg.is_left() && msg.is_down())
		 {
 
			a.returnbook();//还书函数
		}
		else if((msg.x > 310 && msg.x < 635) && (msg.y > 350 && msg.y < 400) && msg.is_left() && msg.is_down()) 
		{
			
			bookmenu();//图书管理函数
		}
	     else if((msg.x > 310 && msg.x < 625) && (msg.y > 460 && msg.y < 500) && msg.is_left() && msg.is_down())
		  {
		
		   readermenu();//读者管理函数
	    }
         else if((msg.x > 370 && msg.x < 590 ) && (msg.y > 575 && msg.y < 620) && msg.is_left() && msg.is_down()) 
		{
			
			break;
		}

	}
}
void bookmenu()
{
	const int i=30;
	char ID[30];
	char password[30]; 
	char ch;
	Book k;
	int a;
	PIMAGE src2,src3,src4,src5;
	src2 = newimage();
	getimage(src2, "2.jpg");
	cleardevice();//先清屏
	putimage(0,0,src2);//背景图是src2
    for(; is_run(); delay_fps(60)) //is_run()判断窗口是否存在，delay_fps(60) 作用是稳定帧率并刷新窗口 ，一秒钟循环60次
	{	
        
		mouse_msg msg = {0};	//定义鼠标变量并且初始化
		while(mousemsg()) 
		{  //利用mousemsg()判断有没有鼠标消息
			msg = getmouse();
		} //获得鼠标消息
		if((msg.x > 280 && msg.x < 435) && (msg.y > 250 && msg.y < 290) && msg.is_left() && msg.is_down()) 
		{   //管理员权限
		    src3 = newimage();
	        getimage(src3, "3.jpg");
	        cleardevice();//先清屏
	        putimage(0,0,src3);//背景图是src3
		     sys_edit editBox;
		     xyprintf(290,240,"管理员账号为：123456789"); 
        	editBox.create(false);						//创建，false表示单行
        	editBox.move(290, 410);						//设置位置
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
		}
            if(strcmp(strBuffer,"123456")==0)
             {
             	    editBox.destroy();//销毁对话框 
            		src4 = newimage();
	                getimage(src4, "4.jpg");
	                cleardevice();//先清屏
	                putimage(0,0,src4);//背景图是src4
	                for(; is_run(); delay_fps(60)) //is_run()判断窗口是否存在，delay_fps(60) 作用是稳定帧率并刷新窗口 ，一秒钟循环60次
	                {	
 
		                mouse_msg msg = {0};	//定义鼠标变量并且初始化
		                while(mousemsg()) 
		                {  //利用mousemsg()判断有没有鼠标消息
		                    	msg = getmouse();
		                } //获得鼠标消息
		                if((msg.x > 340 && msg.x < 490) && (msg.y > 135 && msg.y < 170) && msg.is_left() && msg.is_down()) 
		                {   
		                    k.addbook();//添加图书 
	                    } 
		                else if((msg.x > 660 && msg.x < 815) && (msg.y > 135&& msg.y < 170) && msg.is_left() && msg.is_down())
		                {
			               k.deletebook();//删除图书 
		                }
		                else if((msg.x > 340 && msg.x < 490) && (msg.y > 240 && msg.y < 275) && msg.is_left() && msg.is_down()) 
		                {
			               k.findbook();//查找图书 
		                }
	                    else if((msg.x > 665 && msg.x < 815) && (msg.y > 250 && msg.y < 275) && msg.is_left() && msg.is_down())
		                {
		                   k.revisebook();//修改图书 
	                    }
                        else if((msg.x > 335 && msg.x < 490) && (msg.y > 340 && msg.y < 370) && msg.is_left() && msg.is_down()) 
	                  	{
			               k.deletebookshelf();//清空图书 
		                }
		                else if((msg.x > 665 && msg.x < 850) && (msg.y > 350 && msg.y < 380) && msg.is_left() && msg.is_down()) 
	                  	{
			              bookmenu();//返回上一步 
		                }
	                    else if((msg.x > 340 && msg.x < 500) && (msg.y > 445 && msg.y < 470) && msg.is_left() && msg.is_down()) 
	                  	{
			               exit(0);//退出系统 
		                }
					}
				}
		
			else if(strcmp(strBuffer,"123456")!=0&&isOutput)
			{
				xyprintf(280,500,"输入的密码错误！"); 
			}
		}
	}
		else if((msg.x > 750 && msg.x < 850)&& (msg.y > 250 && msg.y < 300) && msg.is_left() && msg.is_down())
		{
			//读者访问 
			src5 = newimage();
	        getimage(src5, "5.jpg");
	        cleardevice();//先清屏
	        putimage(0,0,src5);//背景图是src5
	      for(; is_run(); delay_fps(60)) //is_run()判断窗口是否存在，delay_fps(60) 作用是稳定帧率并刷新窗口 ，一秒钟循环60次
	      {	
		    mouse_msg msg = {0};	//定义鼠标变量并且初始化
		    while(mousemsg()) 
		    {  //利用mousemsg()判断有没有鼠标消息
			   msg = getmouse();
		    } //获得鼠标消息
		    if((msg.x > 350 && msg.x < 500) && (msg.y > 145 && msg.y < 170) && msg.is_left() && msg.is_down()) 
		    {   
      		  k.findbook();//查找图书 
		    } 
		    else if((msg.x > 680 && msg.x < 870) && (msg.y > 150 && msg.y < 170) && msg.is_left() && msg.is_down()) 
		    {
			 bookmenu();//返回上一步 
		    }
	        else if((msg.x > 350 && msg.x < 500) && (msg.y > 270 && msg.y < 300) && msg.is_left() && msg.is_down())
		    {
		     exit(0);//退出系统 
	        }
		  }
	   }
    }
}
void readermenu()
{
	Reader b;
	const int i=30;
	char ID[30];
	char password[30]; 
	char ch;
	int a;
	PIMAGE src2,src3,src4,src5;
	src2 = newimage();
	getimage(src2, "2.jpg");
	cleardevice();//先清屏
	putimage(0,0,src2);//背景图是src2
    for(; is_run(); delay_fps(60)) //is_run()判断窗口是否存在，delay_fps(60) 作用是稳定帧率并刷新窗口 ，一秒钟循环60次
	{	
        
		mouse_msg msg = {0};	//定义鼠标变量并且初始化
		while(mousemsg()) 
		{  //利用mousemsg()判断有没有鼠标消息
			msg = getmouse();
		} //获得鼠标消息
		if((msg.x > 280 && msg.x < 435) && (msg.y > 250 && msg.y < 290) && msg.is_left() && msg.is_down()) 
		{   //管理员权限
		    src3 = newimage();
	        getimage(src3, "3.jpg");
	        cleardevice();//先清屏
	        putimage(0,0,src3);//背景图是src3
		     sys_edit editBox;
		     xyprintf(290,240,"管理员账号为：123456789"); 
        	editBox.create(false);						//创建，false表示单行
        	editBox.move(290, 410);						//设置位置
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
		}
            if(strcmp(strBuffer,"123456")==0)
             {
             	    editBox.destroy();//销毁对话框 
            		src4 = newimage();
	                getimage(src4, "6.jpg");
	                cleardevice();//先清屏
	                putimage(0,0,src4);//背景图是src4
	                for(; is_run(); delay_fps(60)) //is_run()判断窗口是否存在，delay_fps(60) 作用是稳定帧率并刷新窗口 ，一秒钟循环60次
	                {	
 
		                mouse_msg msg = {0};	//定义鼠标变量并且初始化
		                while(mousemsg()) 
		                {  //利用mousemsg()判断有没有鼠标消息
		                    	msg = getmouse();
		                } //获得鼠标消息
		                if((msg.x > 340 && msg.x < 490) && (msg.y > 125 && msg.y < 160) && msg.is_left() && msg.is_down()) 
		                {   
		                   b.addreaders();//添加读者 
	                    } 
		                else if((msg.x > 715 && msg.x < 865) && (msg.y > 130&& msg.y < 155) && msg.is_left() && msg.is_down())
		                {
			               b.delreaders();//删除读者 
		                }
		                else if((msg.x > 335 && msg.x < 480) && (msg.y > 240 && msg.y < 270) && msg.is_left() && msg.is_down()) 
		                {
			               b.findreaders();//查找读者 
		                }
	                    else if((msg.x > 715 && msg.x < 865) && (msg.y > 250 && msg.y < 280) && msg.is_left() && msg.is_down())
		                {
		                   b.editreaders();//修改读者 
	                    }
		                else if((msg.x > 340 && msg.x < 530) && (msg.y > 350 && msg.y < 370) && msg.is_left() && msg.is_down()) 
	                  	{
			              readermenu();//返回上一步 
		                }
	                    else if((msg.x > 720 && msg.x < 875) && (msg.y > 350 && msg.y < 380) && msg.is_left() && msg.is_down()) 
	                  	{
			               exit(0);//退出系统 
		                }
					}
				}
		
			else if(strcmp(strBuffer,"123456")!=0&&isOutput)
			{
				xyprintf(280,500,"输入的密码错误！"); 
			}
		}
	}
		else if((msg.x > 750 && msg.x < 850)&& (msg.y > 250 && msg.y < 300) && msg.is_left() && msg.is_down())
		{
			//读者访问 
			src5 = newimage();
	        getimage(src5, "7.jpg");
	        cleardevice();//先清屏
	        putimage(0,0,src5);//背景图是src5
	      for(; is_run(); delay_fps(60)) //is_run()判断窗口是否存在，delay_fps(60) 作用是稳定帧率并刷新窗口 ，一秒钟循环60次
	      {	
		    mouse_msg msg = {0};	//定义鼠标变量并且初始化
		    while(mousemsg()) 
		    {  //利用mousemsg()判断有没有鼠标消息
			   msg = getmouse();
		    } //获得鼠标消息
		    if((msg.x > 340 && msg.x < 480) && (msg.y > 120 && msg.y < 155) && msg.is_left() && msg.is_down()) 
		    {   
      		  b.findreaders();//查找读者 
		    } 
		    else if((msg.x > 720 && msg.x < 910) && (msg.y > 130 && msg.y < 160) && msg.is_left() && msg.is_down()) 
		    {
			 readermenu();//返回上一步 
		    }
	        else if((msg.x > 340 && msg.x < 490) && (msg.y > 240 && msg.y < 280) && msg.is_left() && msg.is_down())
		    {
		     exit(0);//退出系统 
	        }
		  }
	   }
    }
}
int main()
{ 
	test();
	return 0;
}
