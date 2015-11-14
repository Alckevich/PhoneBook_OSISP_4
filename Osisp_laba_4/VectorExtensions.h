#pragma once

#ifndef V_E
#define V_E

#include "Entry.h"
#include <vector>
#include <algorithm>



class VectorExtensions
{
public:
	template <typename T>
	static void GetIntersection(std::vector<T> first, std::vector<T> second, std::function<bool (T*, T*)> predicate, std::vector<T>* result);
	template <typename T>
	static void GetIntersectionOfMany(std::vector<std::vector<T>> vectors, std::function<bool (T*, T*)> predicate, std::vector<T>* result);
	
	~VectorExtensions();
private:
	VectorExtensions();
};


template <typename T>
void VectorExtensions::GetIntersection(std::vector<T> first, std::vector<T> second, std::function<bool(T*, T*)> predicate, std::vector<T>* result){
	result->clear();
	for (int i = 0; i < first.size(); i++){
		for (int j = 0; j < second.size(); j++){
			if (predicate(&first[i], &second[j])){
				result->push_back(second[j]);
				second.erase(second.begin() + j);
			}
		}
	}
}

template <typename T>
void VectorExtensions::GetIntersectionOfMany(std::vector<std::vector<T>> vectors, std::function<bool(T*, T*)> predicate, std::vector<T>* result){
	result->clear();

	if (vectors.empty()){
		return;
	}

	*result = std::vector<T>(vectors[0]);

	std::vector<T> intesect;
	for (int i = 1; i < vectors.size(); i++){
		VectorExtensions::GetIntersection(*result, vectors[i], predicate, result);
	}
}

#endif