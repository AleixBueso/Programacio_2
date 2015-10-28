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
	P2String(const P2String &string);
	P2String(char* string);
	P2String(const uint new_capacity);
	~P2String();
	char* GetString();
	uint GetCapacity();
	bool operator==(const P2String &string)const;
	bool operator!=(P2String &string)const;
};
#endif