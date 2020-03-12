#pragma once
class FieldObject
{
public:
	FieldObject(void){}
	~FieldObject(void);

	//virtual void drawFieldObject() = 0;

	virtual void draw2d() = 0;
};

