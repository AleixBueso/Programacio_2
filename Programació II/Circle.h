#ifndef __CIRCLE_H__
#define __CIRCLE_H__

class Circle
{

	float r;

public:
	
	const Circle& operator=(const Circle& c);

	bool operator==(const Circle& c)const;

	bool operator!=(const Circle& c)const;

	const Circle& operator+=(const Circle& c);

	const Circle& operator-=(const Circle& c);

	Circle operator+(const Circle& c)const;

	Circle operator-(const Circle& c)const;

	float GetArea()const;

	//A l'esquerra afecta al Circle&, al mig afecta al argument, 
	//a la dreta afecta als atributs de la classe
};

#endif //__CIRCLE_H__