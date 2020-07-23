#pragma once
template <typename T>
void QueueCustom<T>::Pop()
{
	_frontCount++;
}

template <typename T>
T QueueCustom<T>::GetFront()
{
	return VectorCustom<T>::_arr[_frontCount];
}

template <typename T>
int QueueCustom<T>::GetSIze()
{
	return QueueCustom<T>::GetSIze() - _frontCount;
}
