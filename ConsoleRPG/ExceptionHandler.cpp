#include "ExceptionHandler.h"

ExceptionHandler::ExceptionHandler(enum ErrorCode errorCode, const char* pszMsg)
{
	this->errorCode = errorCode;
	strcpy_s(msg, sizeof(msg), pszMsg);
}

enum ErrorCode ExceptionHandler::GetErrorCode() const { return this->errorCode; }

const char* ExceptionHandler::GetMessage() const { return this->msg; }
