#pragma once
class FileOpenException
{
	int errorNumber;
public:
	/*
		Function FileOpenException
		���캯������ʼ��ֵ

		@param int errorNumber �������

		@return void
	*/
	FileOpenException(int _errorNumber);
	/*
		Function getErrorNumber
		��ȡ�������ĺ���

		@param void

		@return int
	*/
	int getErrorNumber();
	~FileOpenException();
};

