#pragma once

template <typename T>
T StackCustom<T>::GetTop()
{
	int sizeIndex = VectorCustom<T>::GetSIze() - 1;

	return VectorCustom<T>::_arr[sizeIndex];
}