#pragma once
#include "../VECTOR/VectorCustom.h"

template <typename T>
class QueueCustom :public VectorCustom<T>
{
public:
	QueueCustom()
		:_frontCount(0)
	{

	}

	virtual void Pop();
	virtual int GetSIze();
	T GetFront();

private:
	int _frontCount;
};

#include "QueueCustom.hpp"