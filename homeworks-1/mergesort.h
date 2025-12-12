#pragma once
#include <vector>

void merge(std::vector<int>& , int , int , int , bool (*)(int, int));
void merge_sort(std::vector<int>& , int , int , bool (*)(int, int));