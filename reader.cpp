#include<cstring>
#include<fstream>
#include<iostream>
#include<string.h>
#include <graphics.h> //ʹ��ege��ͷ�ļ�
#include <ege/sys_edit.h>//����������ͷ�ļ�
using namespace std; 
#include"Reader.h"
int Reader::readernum=0; 
Reader readers[1000];
int Reader::getflag()//�õ�flag 
{
	return flag;
}
char* Reader::getname()//�õ���������
{
	return name;
} 
char* Reader::getsex()//�õ������Ա�
{
	return sex;
}
char* Reader::getemail()//�õ���������
{
	return email;
}
char* Reader::getphonenumber()//�õ����ߵ绰����
{
	return phonenumber;
}
char* Reader::getbirthday()//�õ���������
{
	return birthday;
}
char* Reader::getnum()//�õ������˺�
{
	return num; 
 } 
char* Reader::getpassword()//�õ��������� 
{
	return password;
}
void Reader::setname(char* newname)//���ö������� 
{
	strcpy(name,newname);
}
void Reader::setsex(char* newsex)//���ö����Ա�
{
	strcpy(sex,newsex);
}
void Reader::setemail(char* newemail)//���ö�������
{
	strcpy(email,newemail);
}
void Reader::setphonenumber(char* newphonenumber)//���ö��ߵ绰��
{
	strcpy(phonenumber,newphonenumber); 
}
void Reader::setbirthday(char* newbirthday)//���ö�������
{
	strcpy(birthday,newbirthday);
}
void Reader::setnum(char* newnum)//�����˺�
{
	strcpy(num,newnum);
}
void Reader::setpassword(char* newpassword)//���ö�������
{
	strcpy(password,newpassword);
 }
void Reader::getmessage()//���ļ��ж���Ϣ������������ 
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
		cout<<"��reader.txtʧ��"<<endl;
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
void Reader::addreaders()//���������˺� 
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
		cout<<"�޷����ļ�reader.txt"<<endl;
		exit(0); 
	}
	readers[0].readernum++;
	i=readers[0].readernum;
	cleardevice();//������
	PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src3
	sys_edit editBox,editBox1,editBox2,editBox3,editBox4,editBox5,editBox6;
	xyprintf(290,200,"������ӳ���"); 
	xyprintf(290,230,"������ö��ߵ�������");
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
			editBox.gettext(buffSize, name1);
			//��������ȡ������������������Ϊ���ַ���
			editBox.settext("");
			editBox.destroy();//���ٶԻ��� 
			 w++;
			 readers[i].setname(name1);
		}
    if(w==1)
    {
    cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src3
    isOutput=false;
	xyprintf(290,230,"������ö��ߵ��Ա�");
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
			editBox1.gettext(buffSize, sex1);
			//��������ȡ������������������Ϊ���ַ���
			editBox1.settext("");
			editBox1.destroy();//���ٶԻ��� 
			readers[i].setsex(sex1);
			w++;
		}
		 if(w==2)
    {
	cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"������ö��ߵ����䣺");
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
			editBox2.gettext(buffSize, email1);
			//��������ȡ������������������Ϊ���ַ���
			editBox2.settext("");
			editBox2.destroy();//���ٶԻ��� 
			readers[i].setemail(email1);
			w++;
		}
	if(w==3)
    {
    cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"������ö��ߵĳ������ڣ�");
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
			editBox3.gettext(buffSize,birthday1);
			//��������ȡ������������������Ϊ���ַ���
			editBox3.settext("");
			editBox3.destroy();//���ٶԻ��� 
			readers[i].setbirthday(birthday1);
	        w++;
		}
	    if(w==4)
    {
    cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"������ö��ߵ��˺ţ�");
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
			editBox4.gettext(buffSize,num1);
			//��������ȡ������������������Ϊ���ַ���
			editBox4.settext("");
			editBox4.destroy();//���ٶԻ��� 
	        readers[i].setnum(num1);
         	w++;
		}
		if(w==5)
    {
	cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"������ö��ߵ�����:");
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
			editBox5.gettext(buffSize,password1);
			//��������ȡ������������������Ϊ���ַ���
			editBox5.settext("");
			editBox5.destroy();//���ٶԻ��� 
	        readers[i].setpassword(password1);
	        w++;
		}
		if(w==6)
    {
	 cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"������ö��ߵĵ绰���룺");
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
			editBox6.gettext(buffSize, newphone);
			//��������ȡ������������������Ϊ���ַ���
			editBox6.settext("");
			editBox6.destroy();//���ٶԻ��� 
			readers[i].setphonenumber(newphone);
			w++;
		}
	if(w==7)
	{
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//������
	putimage(0,0,src3);//����ͼ��src3
	xyprintf(290,260,"������");
	xyprintf(290,290,"����ӵĶ��ߵ���ϢΪ��");
	xyprintf(290,320,"�ö��ߵ�����Ϊ:%s",name1);
	xyprintf(290,350,"�ö��ߵ��Ա�Ϊ��%s",sex1);
	xyprintf(290,380,"�ö��ߵ�����Ϊ��%s",email1);
	xyprintf(290,410,"�ö��ߵĳ�������Ϊ��%s",birthday1);
	xyprintf(290,440,"�ö��ߵ��˺�Ϊ:%s",num1);
	xyprintf(290,470,"�ö��ߵ�����Ϊ��%s",password1);
	xyprintf(290,500,"�ö��ߵĵ绰����Ϊ%s",newphone);
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
void Reader::findreaders()//���Ҷ��ߣ�����ԱȨ�� 
{
	int i=0,k=0;
	char num1[30];
	char newphone[30];
	char name1[30],sex1[30],email1[30];
	char birthday1[30],password1[30];
	PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//������
	putimage(0,0,src3);//����ͼ��src3
	sys_edit editBox;
	xyprintf(290,200,"������ҳ���"); 
	xyprintf(290,230,"��������Ҫ���ҵĶ��ߵ�����");
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
			   xyprintf(290,260,"���ҳɹ�");
			   xyprintf(290,290,"�ö��ߵ���Ϣ���£�");
	           xyprintf(290,320,"�ö��ߵ�����Ϊ:%s",name1);
	           xyprintf(290,350,"�ö��ߵ��Ա�Ϊ��%s",sex1);
		       xyprintf(290,380,"�ö��ߵ�����Ϊ��%s",email1);
		       xyprintf(290,410,"�ö��ߵĳ�������Ϊ��%s",birthday1);
		       xyprintf(290,440,"�ö��ߵ��˺�Ϊ:%s",num1);
			   xyprintf(290,470,"�ö��ߵĵ绰����Ϊ%s",newphone);
			   xyprintf(290,500,"�������"); 
	           k++; 
			}
		}
		if (k == 0&&isOutput)
	    {
	    	xyprintf(290,260,"���޴��ˣ�������������Ƿ�������ȷ");
	    }
	}
}
void Reader::editreaders()//�޸Ķ��߸�����Ϣ
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
		cout<<"�޷����ļ�reader.txt"<<endl;
		exit(0); 
	}
	readers[0].readernum++;
	i=readers[0].readernum;
	cleardevice();//������
	PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src3
	sys_edit editBox,editBox1,editBox2,editBox3,editBox4,editBox5,editBox6,editBox7;
	xyprintf(290,200,"�����޸ĳ���"); 
	xyprintf(290,230,"������Ҫ�޸���Ϣ�Ķ��ߵ�������");
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
			editBox.gettext(buffSize, name1);
			//��������ȡ������������������Ϊ���ַ���
			editBox.settext("");
			editBox.destroy();//���ٶԻ��� 
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
	cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src3
    isOutput=false;
	xyprintf(290,230,"������ö����µ�������");
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
			editBox1.gettext(buffSize, name1);
			//��������ȡ������������������Ϊ���ַ���
			editBox1.settext("");
			editBox1.destroy();//���ٶԻ��� 
			readers[i].setname(name1);
			w++;
		}
		if(w==2)
    {
    cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src3
    isOutput=false;
	xyprintf(290,230,"������ö����µ��Ա�");
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
			editBox1.gettext(buffSize, sex1);
			//��������ȡ������������������Ϊ���ַ���
			editBox1.settext("");
			editBox1.destroy();//���ٶԻ��� 
			readers[i].setsex(sex1);
			w++;
		}
		 if(w==3)
    {
	cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"������ö��ߵ����䣺");
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
			editBox2.gettext(buffSize, email1);
			//��������ȡ������������������Ϊ���ַ���
			editBox2.settext("");
			editBox2.destroy();//���ٶԻ��� 
			readers[i].setemail(email1);
			w++;
		}
		if(w==4)
    {
    cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"������ö��ߵĳ������ڣ�");
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
			editBox3.gettext(buffSize,birthday1);
			//��������ȡ������������������Ϊ���ַ���
			editBox3.settext("");
			editBox3.destroy();//���ٶԻ��� 
			readers[i].setbirthday(birthday1);
	        w++;
		}
	    if(w==5)
    {
    cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"������ö��ߵ��˺ţ�");
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
			editBox4.gettext(buffSize,num1);
			//��������ȡ������������������Ϊ���ַ���
			editBox4.settext("");
			editBox4.destroy();//���ٶԻ��� 
	        readers[i].setnum(num1);
         	w++;
		}
		if(w==6)
    {
	cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"������ö��ߵ�����:");
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
			editBox5.gettext(buffSize,password1);
			//��������ȡ������������������Ϊ���ַ���
			editBox5.settext("");
			editBox5.destroy();//���ٶԻ��� 
	        readers[i].setpassword(password1);
	        w++;
		}
		if(w==7)
    {
	 cleardevice();//������
    PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	putimage(0,0,src3);//����ͼ��src4
	xyprintf(290,230,"������ö��ߵĵ绰���룺");
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
			editBox6.gettext(buffSize, newphone);
			//��������ȡ������������������Ϊ���ַ���
			editBox6.settext("");
			editBox6.destroy();//���ٶԻ��� 
			readers[i].setphonenumber(newphone);
			w++;
		}
	if(w==8)
	{
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//������
	putimage(0,0,src3);//����ͼ��src3
	xyprintf(290,260,"�޸����");
	xyprintf(290,290,"�ö��ߵ�����ϢΪ��");
	xyprintf(290,320,"�ö��ߵ�������Ϊ:%s",name1);
	xyprintf(290,350,"�ö��ߵ����Ա�Ϊ��%s",sex1);
	xyprintf(290,380,"�ö��ߵ�������Ϊ��%s",email1);
	xyprintf(290,410,"�ö��ߵ��³�������Ϊ��%s",birthday1);
	xyprintf(290,440,"�ö��ߵ����˺�Ϊ:%s",num1);
	xyprintf(290,470,"�ö��ߵ�������Ϊ��%s",password1);
	xyprintf(290,500,"�ö��ߵ��µ绰����Ϊ%s",newphone);
	xyprintf(290,530,"�޸����");
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
void Reader::delreaders()  //ɾ������
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
		cout<<"�޷����ļ�reader.txt"<<endl;
		exit(0); 
	}
	PIMAGE src3;//����ͼ�����
	src3 = newimage();
	getimage(src3, "book.jpg");
	cleardevice();//������
	putimage(0,0,src3);//����ͼ��src3
	sys_edit editBox;
	xyprintf(290,200,"����ɾ������"); 
	xyprintf(290,230,"����������ɾ���Ķ��ߵ�������");
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
			   xyprintf(290,260,"���ҳɹ�");
			   xyprintf(290,290,"��Ҫɾ���Ķ��ߵ���Ϣ���£�");
	           xyprintf(290,320,"�ö��ߵ�����Ϊ:%s",name1);
	           xyprintf(290,350,"�ö��ߵ��Ա�Ϊ��%s",sex1);
		       xyprintf(290,380,"�ö��ߵ�����Ϊ��%s",email1);
		       xyprintf(290,410,"�ö��ߵĳ�������Ϊ��%s",birthday1);
		       xyprintf(290,440,"�ö��ߵ��˺�Ϊ:%s",num1);
			   xyprintf(290,470,"�ö��ߵ�����Ϊ��%s",password1);
			   xyprintf(290,500,"�ö��ߵĵ绰����Ϊ%s",newphone);
			   xyprintf(290,530,"�������"); 
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
	             xyprintf(290,530,"ɾ���ɹ�"); 
				file.close();
	    }
}

