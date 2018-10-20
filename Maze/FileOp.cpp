#include "stdafx.h"
#include "FileOp.h"


FileOp::FileOp()
{

}

LinkedList * FileOp::getRanklist()
{
	//����
	string name;
	//�÷�
	int score;
	//�ļ���
	fstream file;
	//�����µ�����
	LinkedList * list = new LinkedList();
	RanklistRecord line;
	try
	{
		//���ļ�
		file.open("ranklist", ios::in);
		//����ʧ�ܣ����׳��쳣
		if (file.fail())
			throw FileOpenException(errno);
		//���ж���
		while (file >> name >> score)
		{
			line.setName(name);
			line.setScore(score);
			//�������в���ڵ�
			list->insertNode(line, list->getLast());
		}
		//�ر��ļ�
		file.close();
	}
	catch (FileOpenException err)
	{
		cout << "�ļ���ʧ�ܣ�������룺" << err.getErrorNumber() << endl;
	}

	return list;
}

void FileOp::updateRanklist(RanklistRecord data, LinkedList * list)
{
	//�������в����µĽڵ�
	list->insertNode(data, list->search(data));
	list->traverseToFile("ranklist");
}

void FileOp::saveGame(Game *G, Display *D)
{
	try
	{
		//�ļ���
		fstream file;
		//����ʧ�ܣ����׳��쳣
		if (file.fail())
			throw FileOpenException(errno);
		//�Զ�������ʽ���ļ�
		file.open("save", ios::out | ios::binary);
		file.write((char *)G, sizeof(Game));
		file.write((char *)D, sizeof(Display));
		//�ر��ļ�
		file.close();
	}
	catch (FileOpenException err)
	{
		cout << "�ļ���ʧ�ܣ�������룺" << err.getErrorNumber() << endl;
	}
}

void FileOp::readGame(Game *G, Display *D)
{
	try
	{
		//�ļ���
		fstream file;
		//����ʧ�ܣ����׳��쳣
		if (file.fail())
			throw FileOpenException(errno);
		//�Զ�������ʽ���ļ�
		file.open("save", ios::in | ios::binary);
		file.read((char *)G, sizeof(Game));
		file.read((char *)D, sizeof(Display));
		//�ر��ļ�
		file.close();
	}
	catch (FileOpenException err)
	{
		cout << "�ļ���ʧ�ܣ�������룺" << err.getErrorNumber() << endl;
	}
}

FileOp::~FileOp()
{
}
