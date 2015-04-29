// 
//
// IwGame - Cross Platform Multi-purpose Game Engine using the Marmalade SDK
//
// Developed by Matthew Hopwood of Pocketeers Limited - www.pocketeers.co.uk
//
// For updates, tutorials and more details check out my blog at www.drmop.com
//
// This code is provided free of charge and without any warranty whatsoever. The only restriction to its usage is that this header must remain intact and visible in all IwGame engine files.
// If you use this engine in your product, whilst it is not mandatory, a mention of the IwGame engine would be nice or a quick email to let us know where it is being used.
//
//

#include <stdio.h>
#include <stdlib.h>

#include "IwGameString.h" 


//
//
// CIwGameString implementation
//
//


CIwGameString::CIwGameString(const CIwGameString &string)
{
	FindIndex = 0;
	Data = NULL;
	AutoHash = true;
	if (string.c_str() == NULL)
	{
		Length = 0;
		Size = 0;
	}
	else
	{
		int len = (int)strlen(string.c_str());
		allocString(len);
		Length = len;
		strcpy(Data, string.c_str());

		if (AutoHash)
			DataHash = IwHashString(Data);
	}
}

CIwGameString::CIwGameString(const char *pString)
{
	FindIndex = 0;
	Data = NULL;
	AutoHash = true;
	if (pString == NULL)
	{
		Length = 0;
		Size = 0;
	}
	else
	{
		int len = (int)strlen(pString);
		allocString(len);
		Length = len;
		strcpy(Data, pString);

		if (AutoHash)
			DataHash = IwHashString(Data);
	}
}

CIwGameString::CIwGameString(const char *pString, int start, int num_chars)
{
	FindIndex = 0;
	Data = NULL;
	AutoHash = true;
	if (pString == NULL)
	{
		Length = 0;
		Size = 0;
	}
	else
	{
		int len = num_chars;
		allocString(len);
		Length = len;
		memcpy(Data, pString + start, num_chars);
		Data[len] = 0;

		if (AutoHash)
			DataHash = IwHashString(Data);
	}
}

CIwGameString::CIwGameString(int nNum)
{
	FindIndex = 0;
	Data = NULL;
	AutoHash = true;
	char str[32];
	snprintf(str, 32, "%d", nNum);

	int len = (int)strlen(str);
	allocString(len);
	Length = len;

	strcpy(Data, str);

	if (AutoHash)
		DataHash = IwHashString(Data);
}

CIwGameString::CIwGameString(unsigned int nNum)
{
	FindIndex = 0;
	Data = NULL;
	AutoHash = true;
	char str[32];
	snprintf(str, 32, "%u", nNum);

	int len = (int)strlen(str);
	allocString(len);
	Length = len;

	strcpy(Data, str);

	if (AutoHash)
		DataHash = IwHashString(Data);
}

CIwGameString::CIwGameString(float fNum)
{
	FindIndex = 0;
	Data = NULL;
	AutoHash = true;
	char str[32];
	snprintf(str, 32, "%f", fNum);

	int len = (int)strlen(str);
	allocString(len);
	Length = len;

	strcpy(Data, str);

	if (AutoHash)
		DataHash = IwHashString(Data);
}

CIwGameString::CIwGameString(bool value)
{
	FindIndex = 0;
	Data = NULL;
	AutoHash = true;

	int len;
	
	if (value)
		len = 4;
	else
		len = 5;

	allocString(len);
	Length = len;

	if (value)
		strcpy(Data, "true");
	else
		strcpy(Data, "false");

	if (AutoHash)
		DataHash = IwHashString(Data);
}

void CIwGameString::reallocString(int len)
{
	int old_size = Size;
	Size = len + 1;
	if (Size < 16) Size = 16;
	char* data = new char [Size];
	if (Data != NULL)
	{
		memcpy(data, Data, old_size);
		delete Data;
	}
	Data = data;
}
void CIwGameString::allocString(int len)
{
	Size = len + 1;
	if (Size < 16) Size = 16;
	if (Data != NULL)
		delete Data;
	Data = new char[Size];
	Data[0] = 0;
}
void CIwGameString::reset()
{
	Length = 0;
	if (Size > 0 && Data != NULL)
		Data[0] = 0;
}
void CIwGameString::setString(const char *str)
{
	if (str == NULL)
	{
		if (Data != NULL)
			delete Data;
		Data = NULL;
		Size = 0;
		Length = 0;
		return;
	}
	int len = strlen(str);
	allocString(len);
	strcpy(Data, str);
	Length = len;
	if (AutoHash)
		DataHash = IwHashString(Data);
}
void CIwGameString::setString(const char *str, int len)
{
	if (str == NULL)
	{
		if (Data != NULL)
			delete Data;
		Data = NULL;
		Size = 0;
		Length = 0;
		return;
	}
	allocString(len);
	memcpy(Data, str, len);
	Data[len] = 0;
	Length = len;
	if (AutoHash)
		DataHash = IwHashString(Data);
}
CIwGameString CIwGameString::getSubString(int start, int max_chars)
{
	if ((start + max_chars) > Length)
		max_chars -= (start + max_chars) - Length;
	return CIwGameString(Data, start, max_chars);
}
void CIwGameString::setName(char *name)
{
	if (name == NULL)
		return;
	NameHash = IwHashString(name);
}

void CIwGameString::setAutoHash(bool enable)
{
	AutoHash = enable;
	if (enable)
	{
		if (Data != NULL)
			DataHash = IwHashString(Data);
	}
	else
	{
		DataHash = 0;
	}
}

int CIwGameString::GetAsInt() const
{
	return atoi(Data);
}

float CIwGameString::GetAsFloat() const
{
	return (float)atof(Data);
}

bool CIwGameString::GetAsBool() const
{
	return (Compare("true", 4) || Compare("1", 1));
}

void CIwGameString::Copy(const char* pString, int start, int count)
{
	if (Data == NULL)
	{
		allocString(count);
	}
	else
	{
		if (count >= Size)
			reallocString(count);
	}

	memcpy(Data, pString + start, count);
	Length = count;
	Data[count] = 0;

	if (AutoHash)
		DataHash = IwHashString(Data);
}

void CIwGameString::Copy(const char* pString)
{
	Copy(pString, 0, (int)strlen(pString));
}

void CIwGameString::Copy(CIwGameString& string)
{
	Copy((char *)string.c_str(), 0, string.GetLength());
}

char CIwGameString::operator[]	(int nIndex)
{
	if (nIndex < 0 || nIndex > GetLength())
		return 0;

	return *(Data + nIndex);
}

CIwGameString& CIwGameString::operator= (const CIwGameString &op)
{
	Length = op.GetLength();

	if (Data == NULL)
	{
		allocString(Length);
	}
	else
	{
		if (Length >= Size)
			reallocString(Length);
	}
	if (op.c_str() == NULL)
	{
		Data[0] = 0;
		return *this;
	}
	strcpy(Data, op.c_str());
	DataHash = op.getHash();

	return *this;
}

CIwGameString& CIwGameString::operator=	(const char *op)
{
	Length = (int)strlen(op);

	if (Data == NULL)
	{
		allocString(Length);
	}
	else
	{
		if (Length >= Size)
			reallocString(Length);
	}

	if (op == NULL)
	{
		Data[0] = 0;
		return *this;
	}
	strcpy(Data, op);

	if (AutoHash)
		DataHash = IwHashString(Data);

	return *this;
}

CIwGameString& CIwGameString::operator+= (const CIwGameString &op)
{
	int len1 = GetLength();
	int	len2 = op.GetLength();

	if (Data == NULL)
	{
		allocString(len1 + len2);
		strcpy(Data, op.c_str());
	}
	else
	{
		if ((len1 + len2) >= Size)
			reallocString(len1 + len2);

		memcpy(Data + len1, op.c_str(), len2);
		Data[len1 + len2] = 0;
	}
	Length = len1 + len2;

	if (AutoHash)
		DataHash = IwHashString(Data);

	return *this;
}

CIwGameString& CIwGameString::operator+= (const char *op)
{
	if (op == NULL)
		return *this;

	int len1 = GetLength();
	int	len2 = (int)strlen(op);

	if (Data == NULL)
	{
		allocString(len1 + len2);
		strcpy(Data, op);
	}
	else
	{
		if ((len1 + len2) >= Size)
			reallocString(len1 + len2);

		memcpy(Data + len1, op, len2);
		Data[len1 + len2] = 0;
	}
	Length = len1 + len2;

	if (AutoHash)
		DataHash = IwHashString(Data);
	
	return *this;
}

CIwGameString& CIwGameString::operator=	(int nNum)
{
	char str[32];
	snprintf(str, 32, "%d", nNum);

	int len = (int)strlen(str);

	if (len >= Size)
		reallocString(len);

	strcpy(Data, str);
	Length = len;

	if (AutoHash)
		DataHash = IwHashString(Data);
	
	return *this;
}

CIwGameString& CIwGameString::operator+=	(int nNum)
{
	char str[32];
	snprintf(str, 32, "%d", nNum);

	int len1 = GetLength();
	int	len2 = (int)strlen(str);

	if (Data == NULL)
	{
		allocString(len1 + len2);
		strcpy(Data, str);
	}
	else
	{
		if ((len1 + len2) >= Size)
			reallocString(len1 + len2);

		memcpy(Data + len1, str, len2);
		Data[len1 + len2] = 0;
	}

	Length = len1 + len2;

	if (AutoHash)
		DataHash = IwHashString(Data);
	
	return *this;
}


bool CIwGameString::operator==	(const CIwGameString &op)
{
	if (Data == NULL)
		return false;

	if (AutoHash && op.isAutohash())
	{
		if (DataHash == op.getHash())
			return true;
	}
	else
	{
		if (strcmp(op.c_str(), Data) == 0)
			return true;
	}
	return false;
}

bool CIwGameString::operator==	(unsigned int hash)
{
	if (Data == NULL)
		return false;

	if (!AutoHash)
		DataHash = CalculateHash(Data);

	if (DataHash == hash)
		return true;

	return false;
}

bool CIwGameString::operator==	(const char *op)
{
	if (Data == NULL)
		return false;

	if (strcmp(op, Data) == 0)
		return true;

	return false;
}

bool CIwGameString::Compare(const char* pString, int len) const
{
	return memcmp(Data, pString, len) == 0;
}

bool CIwGameString::Compare(int start, const char* pString, int len) const
{
	return memcmp(Data + start, pString, len) == 0;
}

unsigned int	CIwGameString::CalculateHash(const char* pString)
{
	if (pString == NULL)
		return 0;
		
	return IwHashString(pString);
}

void CIwGameString::Replace(char chr, char with)
{
	char*	str = Data;

	for (int t = 0; t < Length; t++)
	{
		if (*str == chr)
		{
			*str = with;
		}
		str++;
	}
}

bool CIwGameString::ContainsSpecialCharacters() const
{
	// Check for chance of special char
	bool	found = false;
	char*	str = Data;

	for (int t = 0; t < Length; t++)
	{
		char c = *str++;
		if (c == '&')
		{
			return true;
		}
	}

	return false;
}

int CIwGameString::Contains(char c) const
{
	char*	str = Data;

	for (int t = 0; t < Length; t++)
	{
		if (*str++ == c)
			return t;
	}

	return -1;
}

void CIwGameString::ReplaceHTMLCodes()
{
	if (!ContainsSpecialCharacters())
		return;

	char* str = Data;
	char* nstr = str;

	// Replace all instances of special tags with ascii codes
	int len = Length;
	for (int t = 0; t < len; t++)
	{
		char c = *str++;
		if (c == '&')
		{
			if (t < len - 3)
			{
				if (*str == 'l' && *(str + 1) == 't' && *(str + 2) == ';')
				{
					*nstr++ = '<';
					str += 3;  t += 3;
				}
				else
				if (*str == 'g' && *(str + 1) == 't' && *(str + 2) == ';')
				{
					*nstr++ = '>';
					str += 3;  t += 3;
				}
				else
				if (t < len - 4)
				{
					if (*str == 'a' && *(str + 1) == 'm' && *(str + 2) == 'p' && *(str + 3) == ';')
					{
						*nstr++ = '&';
						str += 4;  t += 4;
					}
					else
					if (t < len - 4)
					{
						if (*str == 'q' && *(str + 1) == 'u' && *(str + 2) == 'o' && *(str + 3) == 't' && *(str + 4) == ';')
						{
							*nstr++ = '"';
							str += 5;  t += 5;
						}
						else
						if (*str == 'a' && *(str + 1) == 'p' && *(str + 2) == 'o' && *(str + 3) == 's' && *(str + 4) == ';')
						{
							*nstr++ = '\'';
							str += 5;  t += 5;
						}
						else
							*nstr++ = c;
					}
					else
						*nstr++ = c;
				}
				else
					*nstr++ = c;
			}
			else
				*nstr++ = c;
		}
		else
			*nstr++ = c;
	}
	*nstr = 0;
	
	Length = (int)nstr - (int)Data;
	
	if (AutoHash)
		DataHash = IwHashString(Data);
}

void CIwGameString::URLEncode(const char* str)
{
	int slen = strlen(str);
	char* new_data = new char [slen * 2];

	char hexstr[4];
	int len = 0;
	for (int t = 0; t < slen; t++)
	{
		unsigned int c = (unsigned int)*str++;
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c < '9') || c == '$' || c == '-' || c == '_' || c == '.' || c == '!' || c == '*' || c == '\'' || c == '(' || c == ')')
		{
			*(new_data + len) = c; len++;
		}
		else
		{
			snprintf(hexstr, 4, "%x", c);
			*(new_data + len) = '%'; len++;
			if (c < 16)
			{
				*(new_data + len) = '0'; len++;
				*(new_data + len) = hexstr[0]; len++;
			}
			else
			{
				*(new_data + len) = hexstr[0]; len++;
				*(new_data + len) = hexstr[1]; len++;
			}
		}
	}
	*(new_data + len) = 0;

	delete Data;
	Data = new_data;
	Size = Length * 2;
	Length = len;
}


void CIwGameString::URLDecode()
{
	if (Data == NULL)
		return;

	int len = 0;
	char* new_data = new char [Length];
	char* str = Data;

	for (int t = 0; t < Length; t++)
	{
		unsigned int c = (unsigned int)*str++;
		if (c == '$')
		{
			int h1 = GetValueFromHexDigit(*str++);
			int h2 = GetValueFromHexDigit(*str++);
			*(new_data + len) = (h1 << 4) | h2;
		}
		else
		{
			*(new_data + len) = c;
		}
		len++;
	}
	*(new_data + len) = 0;

	delete Data;
	Data = new_data;
	Size = Length;
	Length = len;
}

bool CIwGameString::SplitFilename(CIwGameString& filename, CIwGameString& ext)
{
	int index = 0;
	
	// Find the dot
	for (int t = GetLength() - 1; t != 0; t--)
	{
		if (*(Data + t) == '.')
		{
			index = t;
			break;
		}
	}
	if (index == 0) return false;
	
	filename.Copy(Data, 0, index);
	ext.Copy(Data, index + 1, GetLength() - index - 1);
	
	return true;
}

bool CIwGameString::GetFilenameExt(CIwGameString& ext)
{
	int index = 0;
	
	// Find the dot
	for (int t = GetLength() - 1; t != 0; t--)
	{
		if (*(Data + t) == '.')
		{
			index = t;
			break;
		}
	}
	if (index == 0) return false;
	
	ext.Copy(Data, index + 1, GetLength() - index - 1);
	
	return true;
}

void CIwGameString::ToUpper()
{
	char* pData = Data;
	for (int t = 0; t < Length; t++)
	{
		char c = *pData;
		if (IsLower(c))
		{
			c += 'A' - 'a';
			*pData++ = c;
		}
		else
			pData++;
	}
}

void CIwGameString::ToLower()
{
	char* pData = Data;
	for (int t = 0; t < Length; t++)
	{
		char c = *pData;
		if (IsUpper(c))
		{
			c += 'a' - 'A';
			*pData++ = c;
		}
		else
			pData++;
	}
}

int	CIwGameString::FindNext(const char* string, int len)
{
	int		count = Length - FindIndex;
	char*	str = Data + FindIndex;
	if (count <= 0)
		return -1;
	
	// Find first character
	char fc = *string;
	while (count != 0)
	{
		char c = *str++;
		if (c == fc)
		{
			// if number of chars left in this string is less than the length of the test string then it cant match
			if (count < len)
				return -1;

			// Check the rest of the string
			char*	str1 = str;
			char*	str2 = (char*)string + 1;
			int		count2 = len - 1;
			bool	mismatch = false;

			while (count2-- != 0)
			{
				if (*str1++ != *str2++)
				{
					mismatch = true;
					break;
				}
			}
			
			// A match was found
			if (!mismatch)
				return FindIndex;
		}
		FindIndex++;
		count--;
	}

	return -1;
}

int	CIwGameString::Find(const char* string)
{
	FindIndex = 0;
	int index = FindNext(string);
	FindIndex = 0;
	return index;
}

int	CIwGameString::FindNext(const char* string)
{
	return FindNext(string, strlen(string));
}

void CIwGameString::FindReset()
{
	FindIndex = 0;
}

int CIwGameString::StepFindIndex(int amount)
{
	FindIndex += amount;
	if (FindIndex < 0)
		FindIndex = 0;
	else
	if (FindIndex >= Length)
		FindIndex = Length - 1;

	return FindIndex;
}

int CIwGameString::GetNextMarkedString(char start_mark, char end_mark, int &offset)
{
	int		count = Length - FindIndex;
	char*	str = Data + FindIndex;
	if (count <= 0)
		return -1;
	
	offset = -1;

	while (count-- != 0)
	{
		char c = *str++;
		if (offset < 0)
		{
			// Find start marker
			if (c == start_mark)
				offset = FindIndex + 1;
		}
		else
		{
			// Find end marker
			if (c == end_mark)
				return FindIndex - offset;
		}

		FindIndex++;
	}

	return -1;
}

int CIwGameString::GetNextMarkedStringAfterString(const char* search_string, char start_mark, char end_mark, CIwGameString& out_string)
{
	int pos = FindNext(search_string);
	if (pos >= 0)
	{
		// Get the text label
		int offset;
		StepFindIndex(strlen(search_string));
		int len = GetNextMarkedString(start_mark, end_mark, offset);
		if (len > 0)
		{
			out_string.setString(getString() + offset, len);
			return pos;
		}
		
		return -1;
	}

	return -1;
}
