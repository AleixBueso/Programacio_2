#ifndef __P2STRING__
#define __P2STRING__

typedef unsigned int uint;

// � Controlar la seva mem�ria
// � Constructors: Buit, C�pia

class P2String
{
	char* str;
	uint capacity;

public:
	P2String();
	P2String(const P2String &string);
	P2String(const char* string);
	P2String(uint new_capacity);
	~P2String();

	const char* GetString()const;
	const uint GetCapacity()const;
	const uint GetLength(const char* string);
	P2String operator=(const P2String &string);
	P2String operator+=(const char* string);
	bool operator==(const char* string)const;
	bool operator!=(const char* string)const;
	bool operator==(const P2String &string)const;
	bool operator!=(const P2String &string)const;

};
#endif