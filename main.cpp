#include<iostream>
using namespace std;
#include<string.h>
#include"Book.h"
#include"Reader.h"
#include<fstream>
#include<iostream>
#include <cstdlib>      //system() ��
#include <graphics.h> //ʹ��ege��ͷ�ļ�
#include <ege/sys_edit.h>//����������ͷ�ļ�
void bookmenu();
void readermenu();
void test() {
	Reader b;
   	b.getmessage();//��reader.txt�е����ݵ����������readers[1000]�� 
	Book a;
	a.getmessage();//��book.txt�е����ֵ����������Books[10000]��
	int n,m;
	initgraph(958, 1920);		//��������
	PIMAGE src1;//����ͼ����� 
	src1 = newimage();//����ͼ�����
	getimage(src1, "1.jpg");//���ļ��ж�ȡͼƬ
	putimage(0, 0, src1);//�ڴ����ϻ���ͼƬ���൱��������ı���ͼ
	setfont(26, 0, "����");//�������壬26���ָߣ� 0ָ�����ֿ�����ָ��Զ������� ����������
	setbkmode(TRANSPARENT);//����ǽ����ֵı���ɫ���ó�͸��������һ���ֺ������ɫ��
	setcolor(BLACK);//���������������ɫ
	for(; is_run(); delay_fps(60)) //is_run()�жϴ����Ƿ���ڣ�delay_fps(60) �������ȶ�֡�ʲ�ˢ�´��� ��һ����ѭ��60��
	{	
 
		mouse_msg msg = {0};	//�������������ҳ�ʼ��
		while(mousemsg()) 
		{  //����mousemsg()�ж���û�������Ϣ
			msg = getmouse();
		} //��������Ϣ
		if((msg.x > 425 && msg.x < 520) && (msg.y > 135 && msg.y < 180) && msg.is_left() && msg.is_down()) 
		{   
			a.borrowbook();//���麯��
		} 
		else if((msg.x > 420 && msg.x < 520) && (msg.y > 240 && msg.y < 280) && msg.is_left() && msg.is_down())
		 {
 
			a.returnbook();//���麯��
		}
		else if((msg.x > 310 && msg.x < 635) && (msg.y > 350 && msg.y < 400) && msg.is_left() && msg.is_down()) 
		{
			
			bookmenu();//ͼ�������
		}
	     else if((msg.x > 310 && msg.x < 625) && (msg.y > 460 && msg.y < 500) && msg.is_left() && msg.is_down())
		  {
		
		   readermenu();//���߹�����
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
	cleardevice();//������
	putimage(0,0,src2);//����ͼ��src2
    for(; is_run(); delay_fps(60)) //is_run()�жϴ����Ƿ���ڣ�delay_fps(60) �������ȶ�֡�ʲ�ˢ�´��� ��һ����ѭ��60��
	{	
        
		mouse_msg msg = {0};	//�������������ҳ�ʼ��
		while(mousemsg()) 
		{  //����mousemsg()�ж���û�������Ϣ
			msg = getmouse();
		} //��������Ϣ
		if((msg.x > 280 && msg.x < 435) && (msg.y > 250 && msg.y < 290) && msg.is_left() && msg.is_down()) 
		{   //����ԱȨ��
		    src3 = newimage();
	        getimage(src3, "3.jpg");
	        cleardevice();//������
	        putimage(0,0,src3);//����ͼ��src3
		     sys_edit editBox;
		     xyprintf(290,240,"����Ա�˺�Ϊ��123456789"); 
        	editBox.create(false);						//������false��ʾ����
        	editBox.move(290, 410);						//����λ��
        	int editTextHeight = 16;
	        editBox.size(editTextHeight * 10, 4 * editTextHeight );	//���óߴ磬�߶�һ��Ҫ���ֵĸ߶�һ�㣬��Ϊ�����ı߿�Ҳռһ����С��
	        editBox.setbgcolor(WHITE);					//���ñ�����ɫ
	        editBox.setcolor(BLACK);					//����������ɫ
        	editBox.setfont(editTextHeight, 0, "����");	//��������
	        int maxLen = 60;
	       editBox.setmaxlen(maxLen);					//����������󳤶�
	       //editBox.setreadonly(false);				//Ĭ����������
           editBox.visible(true);						//ʹ�ɼ�
	       //��ȡ����
	       editBox.setfocus();
	      //�������뻺����
	      const int buffSize = 100;
          char strBuffer[100]={"0"};
          int buffLen = 0;
	    for (; is_run(); delay_fps(60)) {
		   bool isOutput = false;

		//��⵽�س�������ͱ�����
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
			}
		}
		
		//��Ҫ���
		if (isOutput) {
			//��ȡ����������ַ���
			editBox.gettext(buffSize, strBuffer);
			//��������ȡ������������������Ϊ���ַ���
			editBox.settext("");
		}
            if(strcmp(strBuffer,"123456")==0)
             {
             	    editBox.destroy();//���ٶԻ��� 
            		src4 = newimage();
	                getimage(src4, "4.jpg");
	                cleardevice();//������
	                putimage(0,0,src4);//����ͼ��src4
	                for(; is_run(); delay_fps(60)) //is_run()�жϴ����Ƿ���ڣ�delay_fps(60) �������ȶ�֡�ʲ�ˢ�´��� ��һ����ѭ��60��
	                {	
 
		                mouse_msg msg = {0};	//�������������ҳ�ʼ��
		                while(mousemsg()) 
		                {  //����mousemsg()�ж���û�������Ϣ
		                    	msg = getmouse();
		                } //��������Ϣ
		                if((msg.x > 340 && msg.x < 490) && (msg.y > 135 && msg.y < 170) && msg.is_left() && msg.is_down()) 
		                {   
		                    k.addbook();//���ͼ�� 
	                    } 
		                else if((msg.x > 660 && msg.x < 815) && (msg.y > 135&& msg.y < 170) && msg.is_left() && msg.is_down())
		                {
			               k.deletebook();//ɾ��ͼ�� 
		                }
		                else if((msg.x > 340 && msg.x < 490) && (msg.y > 240 && msg.y < 275) && msg.is_left() && msg.is_down()) 
		                {
			               k.findbook();//����ͼ�� 
		                }
	                    else if((msg.x > 665 && msg.x < 815) && (msg.y > 250 && msg.y < 275) && msg.is_left() && msg.is_down())
		                {
		                   k.revisebook();//�޸�ͼ�� 
	                    }
                        else if((msg.x > 335 && msg.x < 490) && (msg.y > 340 && msg.y < 370) && msg.is_left() && msg.is_down()) 
	                  	{
			               k.deletebookshelf();//���ͼ�� 
		                }
		                else if((msg.x > 665 && msg.x < 850) && (msg.y > 350 && msg.y < 380) && msg.is_left() && msg.is_down()) 
	                  	{
			              bookmenu();//������һ�� 
		                }
	                    else if((msg.x > 340 && msg.x < 500) && (msg.y > 445 && msg.y < 470) && msg.is_left() && msg.is_down()) 
	                  	{
			               exit(0);//�˳�ϵͳ 
		                }
					}
				}
		
			else if(strcmp(strBuffer,"123456")!=0&&isOutput)
			{
				xyprintf(280,500,"������������"); 
			}
		}
	}
		else if((msg.x > 750 && msg.x < 850)&& (msg.y > 250 && msg.y < 300) && msg.is_left() && msg.is_down())
		{
			//���߷��� 
			src5 = newimage();
	        getimage(src5, "5.jpg");
	        cleardevice();//������
	        putimage(0,0,src5);//����ͼ��src5
	      for(; is_run(); delay_fps(60)) //is_run()�жϴ����Ƿ���ڣ�delay_fps(60) �������ȶ�֡�ʲ�ˢ�´��� ��һ����ѭ��60��
	      {	
		    mouse_msg msg = {0};	//�������������ҳ�ʼ��
		    while(mousemsg()) 
		    {  //����mousemsg()�ж���û�������Ϣ
			   msg = getmouse();
		    } //��������Ϣ
		    if((msg.x > 350 && msg.x < 500) && (msg.y > 145 && msg.y < 170) && msg.is_left() && msg.is_down()) 
		    {   
      		  k.findbook();//����ͼ�� 
		    } 
		    else if((msg.x > 680 && msg.x < 870) && (msg.y > 150 && msg.y < 170) && msg.is_left() && msg.is_down()) 
		    {
			 bookmenu();//������һ�� 
		    }
	        else if((msg.x > 350 && msg.x < 500) && (msg.y > 270 && msg.y < 300) && msg.is_left() && msg.is_down())
		    {
		     exit(0);//�˳�ϵͳ 
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
	cleardevice();//������
	putimage(0,0,src2);//����ͼ��src2
    for(; is_run(); delay_fps(60)) //is_run()�жϴ����Ƿ���ڣ�delay_fps(60) �������ȶ�֡�ʲ�ˢ�´��� ��һ����ѭ��60��
	{	
        
		mouse_msg msg = {0};	//�������������ҳ�ʼ��
		while(mousemsg()) 
		{  //����mousemsg()�ж���û�������Ϣ
			msg = getmouse();
		} //��������Ϣ
		if((msg.x > 280 && msg.x < 435) && (msg.y > 250 && msg.y < 290) && msg.is_left() && msg.is_down()) 
		{   //����ԱȨ��
		    src3 = newimage();
	        getimage(src3, "3.jpg");
	        cleardevice();//������
	        putimage(0,0,src3);//����ͼ��src3
		     sys_edit editBox;
		     xyprintf(290,240,"����Ա�˺�Ϊ��123456789"); 
        	editBox.create(false);						//������false��ʾ����
        	editBox.move(290, 410);						//����λ��
        	int editTextHeight = 16;
	        editBox.size(editTextHeight * 10, 4 * editTextHeight );	//���óߴ磬�߶�һ��Ҫ���ֵĸ߶�һ�㣬��Ϊ�����ı߿�Ҳռһ����С��
	        editBox.setbgcolor(WHITE);					//���ñ�����ɫ
	        editBox.setcolor(BLACK);					//����������ɫ
        	editBox.setfont(editTextHeight, 0, "����");	//��������
	        int maxLen = 60;
	       editBox.setmaxlen(maxLen);					//����������󳤶�
	       //editBox.setreadonly(false);				//Ĭ����������
           editBox.visible(true);						//ʹ�ɼ�
	       //��ȡ����
	       editBox.setfocus();
	      //�������뻺����
	      const int buffSize = 100;
          char strBuffer[100]={"0"};
          int buffLen = 0;
	    for (; is_run(); delay_fps(60)) {
		   bool isOutput = false;

		//��⵽�س�������ͱ�����
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
			}
		}
		
		//��Ҫ���
		if (isOutput) {
			//��ȡ����������ַ���
			editBox.gettext(buffSize, strBuffer);
			//��������ȡ������������������Ϊ���ַ���
			editBox.settext("");
		}
            if(strcmp(strBuffer,"123456")==0)
             {
             	    editBox.destroy();//���ٶԻ��� 
            		src4 = newimage();
	                getimage(src4, "6.jpg");
	                cleardevice();//������
	                putimage(0,0,src4);//����ͼ��src4
	                for(; is_run(); delay_fps(60)) //is_run()�жϴ����Ƿ���ڣ�delay_fps(60) �������ȶ�֡�ʲ�ˢ�´��� ��һ����ѭ��60��
	                {	
 
		                mouse_msg msg = {0};	//�������������ҳ�ʼ��
		                while(mousemsg()) 
		                {  //����mousemsg()�ж���û�������Ϣ
		                    	msg = getmouse();
		                } //��������Ϣ
		                if((msg.x > 340 && msg.x < 490) && (msg.y > 125 && msg.y < 160) && msg.is_left() && msg.is_down()) 
		                {   
		                   b.addreaders();//��Ӷ��� 
	                    } 
		                else if((msg.x > 715 && msg.x < 865) && (msg.y > 130&& msg.y < 155) && msg.is_left() && msg.is_down())
		                {
			               b.delreaders();//ɾ������ 
		                }
		                else if((msg.x > 335 && msg.x < 480) && (msg.y > 240 && msg.y < 270) && msg.is_left() && msg.is_down()) 
		                {
			               b.findreaders();//���Ҷ��� 
		                }
	                    else if((msg.x > 715 && msg.x < 865) && (msg.y > 250 && msg.y < 280) && msg.is_left() && msg.is_down())
		                {
		                   b.editreaders();//�޸Ķ��� 
	                    }
		                else if((msg.x > 340 && msg.x < 530) && (msg.y > 350 && msg.y < 370) && msg.is_left() && msg.is_down()) 
	                  	{
			              readermenu();//������һ�� 
		                }
	                    else if((msg.x > 720 && msg.x < 875) && (msg.y > 350 && msg.y < 380) && msg.is_left() && msg.is_down()) 
	                  	{
			               exit(0);//�˳�ϵͳ 
		                }
					}
				}
		
			else if(strcmp(strBuffer,"123456")!=0&&isOutput)
			{
				xyprintf(280,500,"������������"); 
			}
		}
	}
		else if((msg.x > 750 && msg.x < 850)&& (msg.y > 250 && msg.y < 300) && msg.is_left() && msg.is_down())
		{
			//���߷��� 
			src5 = newimage();
	        getimage(src5, "7.jpg");
	        cleardevice();//������
	        putimage(0,0,src5);//����ͼ��src5
	      for(; is_run(); delay_fps(60)) //is_run()�жϴ����Ƿ���ڣ�delay_fps(60) �������ȶ�֡�ʲ�ˢ�´��� ��һ����ѭ��60��
	      {	
		    mouse_msg msg = {0};	//�������������ҳ�ʼ��
		    while(mousemsg()) 
		    {  //����mousemsg()�ж���û�������Ϣ
			   msg = getmouse();
		    } //��������Ϣ
		    if((msg.x > 340 && msg.x < 480) && (msg.y > 120 && msg.y < 155) && msg.is_left() && msg.is_down()) 
		    {   
      		  b.findreaders();//���Ҷ��� 
		    } 
		    else if((msg.x > 720 && msg.x < 910) && (msg.y > 130 && msg.y < 160) && msg.is_left() && msg.is_down()) 
		    {
			 readermenu();//������һ�� 
		    }
	        else if((msg.x > 340 && msg.x < 490) && (msg.y > 240 && msg.y < 280) && msg.is_left() && msg.is_down())
		    {
		     exit(0);//�˳�ϵͳ 
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
