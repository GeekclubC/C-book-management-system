#include<iostream>
using namespace std;
#include<string.h>
#include"Book.h"
#include<fstream>
#include<iostream>
#include <graphics.h> //ʹ��ege��ͷ�ļ�
#include <ege/sys_edit.h>//����������ͷ�ļ�
Book Books[10000];
int Book::numbers=0;
int j=0;
char* Book::getbookshelf()//���Ҹ������ڵ������������ 
{
	return bookshelf;
}
char Book::getbookarea()//���Ҹ������ڵ�����
{
	return bookarea;
}
int Book::getbooknum()//���Ҹ���ͼ�������
{
	return booknum;
}
char* Book::getbookID()//����ͼ��ı��
{
	return bookID;
}
char* Book::getbookname()//����ͼ������ 
{
	return bookname;
}
char* Book::getbookwriter()//����ͼ������
{
	return bookwriter;
}
double Book::getbookprice()//����ͼ��۸�
{
	return bookprice;
}
void Book::setbookname(char* name) //����ͼ������
{
	strcpy(bookname,name);
}
void Book::setbookID(char* ID)//����ͼ��ı��
{
	strcpy(bookID,ID);
}
void Book::setbookwriter(char* newbookwriter)//����ͼ������
{
	strcpy(bookwriter,newbookwriter);
}
void Book::setprice(double newprice)//����ͼ��۸�
{
	bookprice = newprice;
}
void Book::setbooknum(int newbooknum)//����ͼ������
{
	booknum = newbooknum;
}
void Book::setbookshelf(char* shelf)//����ͼ��������������
{
	strcmp(bookshelf,shelf);
}
void Book::setbookarea(char ch)//����ͼ���������� 
{
	bookarea = ch;
}
void Book::getmessage()//���ļ��ж���Ϣ������������
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
		cout<<"��book.txtʧ��"<<endl;
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
void Book::borrowbook()//���鹦��
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
	PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//������
	putimage(0,0,src3);//����ͼ��src3
	sys_edit editBox;
	xyprintf(290,200,"����������"); 
	xyprintf(290,230,"����������Ҫ�������");
    editBox.create(false);						//������false��ʾ����
    editBox.move(290, 360);						//����λ��
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
			editBox.destroy();//���ٶԻ��� 
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
			xyprintf(290,260,"����ɹ�");
			xyprintf(290,290,"�������Ϣ���£�");
		    xyprintf(290,320,"����ļ۸�Ϊ��%lf",newprice,"Ԫ/ÿ��");
			xyprintf(290,350,"������������Ϊ%c",ch);
			flag++;
			int k=Books[i].getbooknum()-1;
			Books[i].setbooknum(k); 
			}
		}
		if(flag==0&&isOutput)
		xyprintf(290,440,"�����Ѿ������꣬����ʧ��");
			
			}
}
void Book::returnbook()//���鹦�� 
{
	char newbookshelf[10];
	char newbookID[30];
	char ch;
	double newprice;
	char newbookname[30];
	char newbookwriter[30];
	int newbooknum;
	int i,k=0;
	PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//������
	putimage(0,0,src3);//����ͼ��src3
	sys_edit editBox;
	xyprintf(290,200,"���뻹�����"); 
	xyprintf(290,230,"���������뻹��������ƣ�");
    editBox.create(false);						//������false��ʾ����
    editBox.move(290, 360);						//����λ��
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
			editBox.destroy();//���ٶԻ��� 
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
			xyprintf(290,260,"��ʼ����");
			xyprintf(290,290,"�������Ϣ���£�");
			xyprintf(290,320,"������������Ϊ%c",ch);
			xyprintf(290,350,"����ɹ�");
			k++;
		    }
		}
			if(k==0&&isOutput)
			{
				xyprintf(290,440,"���޴��飬���������Ƿ�������ȷ");
			
			}
			
		}
}
void Book::findbook()//���ҹ���--����ͼ����Ϣ 
{
	char newbookshelf[10];
	char newbookID[30];
	char ch;
	double newprice;
	char newbookname[30];
	char newbookwriter[30];
	int newbooknum;
	int i,k=0;
	PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//������
	putimage(0,0,src3);//����ͼ��src3
	sys_edit editBox;
	xyprintf(290,200,"������ҳ���"); 
	xyprintf(290,230,"�����������ѯ���������");
    editBox.create(false);						//������false��ʾ����
    editBox.move(290, 360);						//����λ��
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
			editBox.destroy();//���ٶԻ��� 
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
			xyprintf(290,260,"���ҳɹ�");
			xyprintf(290,290,"�������Ϣ���£�");
		    xyprintf(290,320,"���������Ϊ��%d",newbooknum);
		    xyprintf(290,350,"����ļ۸�Ϊ��%lf",newprice);
			xyprintf(290,380,"������������Ϊ%c",ch);
			xyprintf(290,410,"�������"); 
	        k++; 
			}
		}
		if (k == 0&&isOutput)
	    {
	    	xyprintf(290,260,"���޴��飬���������Ƿ�������ȷ");
	    }
	}
}
void Book::revisebook()//�޸Ĺ���--�޸�ͼ����Ϣ 
{
	int flag=0;
	fstream file;
	file.open("book.txt", ios::out);
	if (file.fail())
	{
		cout << "���ļ�book.txtʧ��" << endl;
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
	PIMAGE src3,src4;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//������
	putimage(0,0,src3);//����ͼ��src3
	sys_edit editBox;
	xyprintf(290,200,"�����޸ĳ���"); 
	xyprintf(290,230,"�����������޸ĵ�������ƣ�");
    editBox.create(false);						//������false��ʾ����
    editBox.move(290, 360);						//����λ��
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
			editBox.destroy();//���ٶԻ��� 
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
	        cleardevice();//������
	        putimage(0,0,src4);//����ͼ��src4
	        sys_edit editBox1;
	        xyprintf(290,200,"����������µı�ţ�");
		    editBox1.create(false);						//������false��ʾ����
            editBox1.move(290, 360);						//����λ��
	        editBox1.size(editTextHeight * 10, 4 * editTextHeight );	//���óߴ磬�߶�һ��Ҫ���ֵĸ߶�һ�㣬��Ϊ�����ı߿�Ҳռһ����С��
	        editBox1.setbgcolor(WHITE);					//���ñ�����ɫ
	        editBox1.setcolor(BLACK);					//����������ɫ
            editBox1.setfont(editTextHeight, 0, "����");	//��������
	        editBox1.setmaxlen(maxLen);					//����������󳤶�
	        //editBox.setreadonly(false);				//Ĭ����������
            editBox1.visible(true);						//ʹ�ɼ�
	       //��ȡ����
	        editBox1.setfocus();
	       //�������뻺����
		   
           int buffLen = 0;
	       for (; is_run(); delay_fps(60)) {
	     	bool isOutput1 = false;

		 //��⵽�س�������ͱ�����
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput1 = true;
			}
		}
		
		//��Ҫ���
		if (isOutput1) {
			 editBox1.gettext(buffSize1,strBuffer1 );
			//��������ȡ������������������Ϊ���ַ���
			editBox1.settext("");
			editBox1.destroy();//���ٶԻ��� 
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
	    	xyprintf(290,260,"���޴��飬���������Ƿ�������ȷ");
	    }
	   file.close();
	   int p=0;
	   if(p==0&&isOutput1)
	   {
	    cout<<"���޸ĵ�ͼ�����ϢΪ��"<<endl;
	    cout<<"���������Ϊ:"<<newbookname<<endl;
	    cout<<"����ı��Ϊ��"<<strBuffer1<<endl;
        cout<<"���������Ϊ��"<<newbookwriter<<endl;
        cout<<"����ļ۸�Ϊ:"<<newprice<<"Ԫ/ÿ��"<<endl;
        cout<<"������������Ϊ"<<ch<<endl;
        p++;
    }
    }
}
}
}
}
void Book::addbook()//��ӹ���--����ͼ����Ϣ 
{
	int w=0; 
	bool isOutput=false;
	fstream file;
	file.open("book.txt",ios::app);
	if (file.fail())
	{
		cout << "���ļ�book.txtʧ��" << endl;
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
	cleardevice();//������
	PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src3
	sys_edit editBox,editBox1,editBox2,editBox3,editBox4,editBox5,editBox6;
	xyprintf(290,200,"������ӳ���"); 
	xyprintf(290,230,"�������������ƣ�");
	i++;
    editBox.create(false);						//������false��ʾ����
    editBox.move(290, 360);						//����λ��
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
    int buffLen = 0;
	for (; is_run(); delay_fps(60)) {

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
			editBox.gettext(buffSize, newbookname);
			//��������ȡ������������������Ϊ���ַ���
			editBox.settext("");
			editBox.destroy();//���ٶԻ��� 
			 w++;
			 Books[i].setbookname(newbookname);
		}
    if(w==1)
    {
    cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src3
    isOutput=false;
	xyprintf(290,230,"���������ı�ţ�");
    editBox1.create(false);						//������false��ʾ����
    editBox1.move(290, 360);						//����λ��
	editBox1.size(editTextHeight * 10, 4 * editTextHeight );	//���óߴ磬�߶�һ��Ҫ���ֵĸ߶�һ�㣬��Ϊ�����ı߿�Ҳռһ����С��
	editBox1.setbgcolor(WHITE);					//���ñ�����ɫ
	editBox1.setcolor(BLACK);					//����������ɫ
    editBox1.setfont(editTextHeight, 0, "����");	//��������
	editBox1.setmaxlen(maxLen);					//����������󳤶�
	//editBox.setreadonly(false);				//Ĭ����������
    editBox1.visible(true);						//ʹ�ɼ�
	//��ȡ����
	editBox1.setfocus();
	//�������뻺����
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
			editBox1.gettext(buffSize, newbookID);
			//��������ȡ������������������Ϊ���ַ���
			editBox1.settext("");
			editBox1.destroy();//���ٶԻ��� 
			Books[i].setbookID(newbookID);
			w++;
		}
		 if(w==2)
    {
	cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"�������������ߣ�");
    editBox2.create(false);						//������false��ʾ����
    editBox2.move(290, 360);						//����λ��
	editBox2.size(editTextHeight * 10, 4 * editTextHeight );	//���óߴ磬�߶�һ��Ҫ���ֵĸ߶�һ�㣬��Ϊ�����ı߿�Ҳռһ����С��
	editBox2.setbgcolor(WHITE);					//���ñ�����ɫ
	editBox2.setcolor(BLACK);					//����������ɫ
    editBox2.setfont(editTextHeight, 0, "����");	//��������
	editBox2.setmaxlen(maxLen);					//����������󳤶�
	//editBox.setreadonly(false);				//Ĭ����������
    editBox2.visible(true);						//ʹ�ɼ�
	//��ȡ����
	editBox2.setfocus();
	//�������뻺����
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
			editBox2.gettext(buffSize, newbookwriter);
			//��������ȡ������������������Ϊ���ַ���
			editBox2.settext("");
			editBox2.destroy();//���ٶԻ��� 
			Books[i].setbookwriter(newbookwriter);
			w++;
		}
		if(w==3)
    {
    cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"���������ļ۸�");
    editBox3.create(false);						//������false��ʾ����
    editBox3.move(290, 360);						//����λ��
	editBox3.size(editTextHeight * 10, 4 * editTextHeight );	//���óߴ磬�߶�һ��Ҫ���ֵĸ߶�һ�㣬��Ϊ�����ı߿�Ҳռһ����С��
	editBox3.setbgcolor(WHITE);					//���ñ�����ɫ
	editBox3.setcolor(BLACK);					//����������ɫ
    editBox3.setfont(editTextHeight, 0, "����");	//��������
	editBox3.setmaxlen(maxLen);					//����������󳤶�
	//editBox.setreadonly(false);				//Ĭ����������
    editBox3.visible(true);						//ʹ�ɼ�
	//��ȡ����
	editBox3.setfocus();
	//�������뻺����
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
			editBox3.gettext(buffSize,strBuffer );
			//��������ȡ������������������Ϊ���ַ���
			editBox3.settext("");
			editBox3.destroy();//���ٶԻ��� 
			sscanf(strBuffer, "%lf", &newprice);
			Books[i].setprice(newprice);
	        w++;
		}
	    if(w==4)
    {
    cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"����������������");
    editBox4.create(false);						//������false��ʾ����
    editBox4.move(290, 360);						//����λ��
	editBox4.size(editTextHeight * 10, 4 * editTextHeight );	//���óߴ磬�߶�һ��Ҫ���ֵĸ߶�һ�㣬��Ϊ�����ı߿�Ҳռһ����С��
	editBox4.setbgcolor(WHITE);					//���ñ�����ɫ
	editBox4.setcolor(BLACK);					//����������ɫ
    editBox4.setfont(editTextHeight, 0, "����");	//��������
	editBox4.setmaxlen(maxLen);					//����������󳤶�
	//editBox.setreadonly(false);				//Ĭ����������
    editBox4.visible(true);						//ʹ�ɼ�
	//��ȡ����
	editBox4.setfocus();
	//�������뻺����
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
			editBox4.gettext(buffSize,strBuffer );
			//��������ȡ������������������Ϊ���ַ���
			editBox4.settext("");
			editBox4.destroy();//���ٶԻ��� 
			sscanf(strBuffer, "%d", &newbooknum);
	        Books[i].setbooknum(newbooknum);
         	w++;
		}
		if(w==5)
    {
	cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"������������������(A,B,C,D����֮һ):");
    editBox5.create(false);						//������false��ʾ����
    editBox5.move(290, 360);						//����λ��
	editBox5.size(editTextHeight * 10, 4 * editTextHeight );	//���óߴ磬�߶�һ��Ҫ���ֵĸ߶�һ�㣬��Ϊ�����ı߿�Ҳռһ����С��
	editBox5.setbgcolor(WHITE);					//���ñ�����ɫ
	editBox5.setcolor(BLACK);					//����������ɫ
    editBox5.setfont(editTextHeight, 0, "����");	//��������
	editBox5.setmaxlen(maxLen);					//����������󳤶�
	//editBox.setreadonly(false);				//Ĭ����������
    editBox5.visible(true);						//ʹ�ɼ�
	//��ȡ����
	editBox5.setfocus();
	//�������뻺����
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
			editBox5.gettext(buffSize,strBuffer );
			//��������ȡ������������������Ϊ���ַ���
			editBox5.settext("");
			editBox5.destroy();//���ٶԻ��� 
			editBox5.gettext(buffSize, strBuffer);
	        sscanf(strBuffer, "%c", &ch);
	        Books[i].setbookarea(ch);
	        w++;
		}
		if(w==6)
    {
	 cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"���������������������");
	xyprintf(290,260,"����һ����λ����ǰ��λ���������������λ��������");
    editBox6.create(false);						//������false��ʾ����
    editBox6.move(290, 360);						//����λ��
	editBox6.size(editTextHeight * 10, 4 * editTextHeight );	//���óߴ磬�߶�һ��Ҫ���ֵĸ߶�һ�㣬��Ϊ�����ı߿�Ҳռһ����С��
	editBox6.setbgcolor(WHITE);					//���ñ�����ɫ
	editBox6.setcolor(BLACK);					//����������ɫ
    editBox6.setfont(editTextHeight, 0, "����");	//��������
	editBox6.setmaxlen(maxLen);					//����������󳤶�
	//editBox.setreadonly(false);				//Ĭ����������
    editBox6.visible(true);						//ʹ�ɼ�
	//��ȡ����
	editBox6.setfocus();
	//�������뻺����
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
			editBox6.gettext(buffSize, newbookshelf);
			//��������ȡ������������������Ϊ���ַ���
			editBox6.settext("");
			editBox6.destroy();//���ٶԻ��� 
			Books[i].setbookshelf(newbookshelf);
			w++;
		}
	if(w==7)
	{
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//������
	putimage(0,0,src3);//����ͼ��src3
	xyprintf(290,260,"������");
	xyprintf(290,290,"����ӵ�ͼ�����ϢΪ��");
	xyprintf(290,320,"���������Ϊ:%s",newbookname);
	xyprintf(290,350,"����ı��Ϊ��%s",newbookID);
	xyprintf(290,380,"���������Ϊ��%s",newbookwriter);
	xyprintf(290,410,"���������Ϊ��%d",newbooknum,"��");
	xyprintf(290,440,"����ļ۸�Ϊ��%lf",newprice,"Ԫ/ÿ��");
	xyprintf(290,470,"������������Ϊ%c",ch);
	xyprintf(290,500,"�������ڵ������������Ϊ%s",newbookshelf);
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
void Book::deletebook()//ɾ������--ɾ��ͼ����Ϣ 
{
	int h=0;
	int flag=0;
	fstream file;
	file.open("book.txt",ios::out);
	if (file.fail())
	{
		cout << "���ļ�book.txtʧ��" << endl;
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
	PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//������
	putimage(0,0,src3);//����ͼ��src3
	sys_edit editBox;
	xyprintf(290,200,"����ɾ������"); 
	xyprintf(290,230,"����������ɾ����������ƣ�");
    editBox.create(false);						//������false��ʾ����
    editBox.move(290, 360);						//����λ��
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
    char strBuffer[30];
    int buffLen = 0;
	for (; is_run(); delay_fps(60)) {
		bool isOutput = false;

		//��⵽�س�������ͱ�����
		while (kbmsg()) {
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up)) {
				isOutput = true;
				editBox.destroy();//���ٶԻ��� 
			}
		}
		
		//��Ҫ���
		if (isOutput) {
			//��ȡ����������ַ���
			editBox.gettext(buffSize, strBuffer);
			//��������ȡ������������������Ϊ���ַ���
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
			xyprintf(290,260,"���ҳɹ�");
			xyprintf(290,290,"��Ҫɾ����ͼ�����Ϣ���£�");
	        xyprintf(290,320,"���������Ϊ:%s",newbookname);
	        xyprintf(290,350,"����ı��Ϊ��%s",newbookID);
		    xyprintf(290,380,"���������Ϊ��%s",newbookwriter);
		    xyprintf(290,410,"���������Ϊ��%d",newbooknum,"��");
		    xyprintf(290,440,"����ļ۸�Ϊ��%lf",newprice);
			xyprintf(290,470,"������������Ϊ%c",ch);
			xyprintf(290,500,"�������ڵ������������Ϊ%s",newbookshelf);
			break;
			}
		}
		    if(h!=0&&isOutput)
		    {
		    	xyprintf(290,530,"ɾ���ɹ�");
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
	
void Book::deletebookshelf()//�������--���ͼ���
{
	fstream file;
	file.open("book.txt",ios::out);
	if (file.fail())
	{
		cout << "���ļ�book.txtʧ��" << endl;
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
	PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//������
	putimage(0,0,src3);//����ͼ��src3
	xyprintf(290,200,"������ճ���"); 
	Books[0].numbers=0;
	Books[0].numbers=0;
	xyprintf(290,230,"���ͼ��ܳɹ�");
	file.close();
}

