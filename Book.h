#ifndef BOOK_H
#define BOOK_H
using namespace std;

class Book
{
	private:
		int booknum;//�������
		char bookname[30];//�������
		char bookID[30];//��ı��
		char bookwriter[30];//�������
		double bookprice;//��ļ۸� 
		char bookarea;//�����ڵ�����A,B,C,D����֮һ 
		char bookshelf[10];/*�����ڵ����������������4λ����ʾ�����磺
		0411���������4����ܣ�������������11��;*/

	public:
		static int numbers;//��¼�������
		void getmessage();//���ļ��ж���Ϣ������������
		void borrowbook();//���鹦��
		void returnbook();//���鹦�� 
		void findbook();//���ҹ���--����ͼ����Ϣ 
		void revisebook();//�޸Ĺ���--�޸�ͼ����Ϣ 
		void addbook();//��ӹ���--����ͼ����Ϣ 
		void deletebook();//ɾ������--ɾ��ͼ����Ϣ 
		void deletebookshelf();//�������--���ͼ��� 
		char* getbookshelf();//���Ҹ������ڵ������������ 
		char getbookarea();//���Ҹ������ڵ����� 
		int getbooknum();//���Ҹ���ͼ�������
		char* getbookID();//����ͼ��ı��
		char* getbookname(); //����ͼ������ 
		char* getbookwriter();//����ͼ������
		double getbookprice();//����ͼ��۸�
		void setbookname(char* name);//����ͼ������
		void setbookID(char* ID) ;//����ͼ��ı��
		void setbookwriter(char* newbookwriter) ;//����ͼ������
		void setprice(double newprice);//����ͼ��۸�
		void setbooknum(int newbooknum);//����ͼ������
		void setbookshelf(char* shelf);//����ͼ��������������
		void setbookarea(char ch);//����ͼ���������� 
};
#endif
