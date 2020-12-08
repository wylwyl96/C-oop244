
#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_
#include "Collection.h"
#include <iostream>
#include <cstring>
namespace sdds {
	/*template <typename T>
	bool search(T* arr, int noOf, const char* name, Collection<T>& object);*/

	template<typename T>
	bool search(T* arr, int noOf, const char* name, Collection<T>& object)
	{
		bool found = false;
		for (int i = 0; i < noOf; i++)
		{
			if (arr[i]==name)
			{
				found = true;
				object.add(arr[i]);
			}
		}
		return found;
	}

}
#endif // !SDDS_STUDENT_H_

