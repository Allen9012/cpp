#pragma once
class CopyLimit
{
public:

	CopyLimit(const CopyLimit&) = delete;
	CopyLimit& operator=(const CopyLimit&) = delete;
private:
	//CopyLimit(const CopyLimit&);
	//CopyLimit& operator=(const CopyLimit&);
};