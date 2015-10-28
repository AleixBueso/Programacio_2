#ifndef __P2STRING__
#define __P2STRING__

typedef unsigned int uint;

// · Controlar la seva memória
// · Constructors: Buit, Cópia

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
	bool operator==(const char* string)const;
	bool operator!=(const char* string)const;
	bool operator==(const P2String &string)const;
	bool operator!=(const P2String &string)const;
};
#endif