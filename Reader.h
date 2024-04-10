#ifndef READER_H
#define READER_H
#include<string>
#include"Book.h"
using namespace std;
class Reader:public::book
{
private:
	char num[30];//�����˺�
	char name[30];//��������
	char sex[30];//man or woman �����Ա�
	char email[30];//�������� 
	char birthday[30];//���߳�������
	char password[30];//��¼������ 
	char phonenumber[30];//���ߵ绰���� 
	int flag;//״̬����  0����δ��������ѻ�  1������δ�� 
public:
	friend void Book::borrowbook();//��Ԫ-���鹦��
	friend void Book::returnbook();//��Ԫ-���鹦�� 
	static int readernum;//������ 
	int getflag();//����flag 
	void getmessage();//���ļ��ж���Ϣ������������ 
	char* getname();//�õ��������� 
	char* getsex();//�õ������Ա�
	char* getemail();//�õ���������
	char* getphonenumber();//�õ����ߵ绰���� 
	char* getbirthday();//�õ���������
	char* getnum();//�õ������˺� 
	char* getpassword();//�õ��������� 
    void setname(char* newname);//���ö������� 
	void setsex(char* newsex);//���ö����Ա�
	void setemail(char* newemail);//���ö�������
	void setphonenumber(char* newphonenumber);//���ö��ߵ绰���� 
	void setbirthday(char* newbirthday);//���ö�������
	void setnum(char* newnum);//���ö����˺� 
	void setpassword(char* newpassword);//���ö������� 
	void addreaders();   //��Ӷ���
    void findreaders();//���Ҷ���,����ԱȨ��
    void editreaders();     //�༭������Ϣ
    void delreaders();  //ɾ������,�����������,��Ҫ��������ɾ��
};
#endif 
