#pragma once
class FileOpenException
{
	int errorNumber;
public:
	/*
		Function FileOpenException
		构造函数：初始化值

		@param int errorNumber 错误代码

		@return void
	*/
	FileOpenException(int _errorNumber);
	/*
		Function getErrorNumber
		获取错误代码的函数

		@param void

		@return int
	*/
	int getErrorNumber();
	~FileOpenException();
};

