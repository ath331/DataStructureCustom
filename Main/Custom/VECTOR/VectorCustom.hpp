#include <cstring>

template <typename T>
void VectorCustom<T>::Push(T num)
{
	if (_curSize >= _maxSize)
	{
		int newMaxSize = _maxSize + (_maxSize / 2);
		T* tempArr = new T[newMaxSize];
		memcpy(tempArr, _arr, sizeof(_arr) * _maxSize);
		_DeleteMem();
		_arr = tempArr;
		_maxSize = newMaxSize;
	}

	_arr[_curSize] = num;
	_curSize++;
}

template <typename T>
int VectorCustom<T>::GetSIze()
{
	return _curSize;
}

template <typename T>
int VectorCustom<T>::GetCapacity()
{
	return _maxSize;
}

template <typename T>
void VectorCustom<T>::Pop()
{
	_curSize--;
}
