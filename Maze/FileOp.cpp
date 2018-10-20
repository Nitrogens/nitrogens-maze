#include "stdafx.h"
#include "FileOp.h"


FileOp::FileOp()
{

}

LinkedList * FileOp::getRanklist()
{
	//姓名
	string name;
	//得分
	int score;
	//文件流
	fstream file;
	//创建新的链表
	LinkedList * list = new LinkedList();
	RanklistRecord line;
	try
	{
		//打开文件
		file.open("ranklist", ios::in);
		//若打开失败，则抛出异常
		if (file.fail())
			throw FileOpenException(errno);
		//逐行读入
		while (file >> name >> score)
		{
			line.setName(name);
			line.setScore(score);
			//向链表中插入节点
			list->insertNode(line, list->getLast());
		}
		//关闭文件
		file.close();
	}
	catch (FileOpenException err)
	{
		cout << "文件打开失败！错误代码：" << err.getErrorNumber() << endl;
	}

	return list;
}

void FileOp::updateRanklist(RanklistRecord data, LinkedList * list)
{
	//向链表中插入新的节点
	list->insertNode(data, list->search(data));
	list->traverseToFile("ranklist");
}

void FileOp::saveGame(Game *G, Display *D)
{
	try
	{
		//文件流
		fstream file;
		//若打开失败，则抛出异常
		if (file.fail())
			throw FileOpenException(errno);
		//以二进制形式打开文件
		file.open("save", ios::out | ios::binary);
		file.write((char *)G, sizeof(Game));
		file.write((char *)D, sizeof(Display));
		//关闭文件
		file.close();
	}
	catch (FileOpenException err)
	{
		cout << "文件打开失败！错误代码：" << err.getErrorNumber() << endl;
	}
}

void FileOp::readGame(Game *G, Display *D)
{
	try
	{
		//文件流
		fstream file;
		//若打开失败，则抛出异常
		if (file.fail())
			throw FileOpenException(errno);
		//以二进制形式打开文件
		file.open("save", ios::in | ios::binary);
		file.read((char *)G, sizeof(Game));
		file.read((char *)D, sizeof(Display));
		//关闭文件
		file.close();
	}
	catch (FileOpenException err)
	{
		cout << "文件打开失败！错误代码：" << err.getErrorNumber() << endl;
	}
}

FileOp::~FileOp()
{
}
