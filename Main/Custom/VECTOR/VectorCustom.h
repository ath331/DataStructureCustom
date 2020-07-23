#pragma once
const static int START_SIZE = 5;

template <typename T>
class VectorCustom
{
public:
	VectorCustom()
		:_curSize(0), _maxSize(START_SIZE)
	{
		_arr = new T[START_SIZE];
	}

	virtual ~VectorCustom()
	{
		_DeleteMem();
	}

	void Push(T num);
	virtual void Pop();
	virtual int GetSIze();
	int GetCapacity();

	T operator[] (const int index) const
	{
		if (index >= _curSize)
			return nullptr;
		else
			return _arr[index];
	}
protected:
	T* _arr;
private:
	int _curSize;
	int _maxSize;

	void _DeleteMem()
	{
		delete[] _arr;
	}
};
#include "VectorCustom.hpp"