#ifndef EXCEPTIONHANDLER_H
#define EXCEPTIONHANDLER_H

#include <iostream>
using namespace std;

enum ErrorCode
{
	Unknown
};

class ExceptionHandler
{
public:
	// ���� �ڵ�� �޽����� �Է¹޴´�.
	ExceptionHandler(enum ErrorCode nCode, const char* pszMsg);

	enum ErrorCode GetErrorCode() const;
	const char* GetMessage() const;

private:
	enum ErrorCode errorCode;
	char msg[256];
};

#endif // !EXCEPTIONHANDLER_H


