#include "binary_tree_sort.h"

namespace sortlib {
	template void binary_tree_sort(std::vector<int>::iterator, std::vector<int>::iterator, std::less<>);
	template void binary_tree_sort(std::vector<long>::iterator, std::vector<long>::iterator, std::less<>);
	template void binary_tree_sort(std::vector<unsigned>::iterator, std::vector<unsigned>::iterator, std::less<>);
	template void binary_tree_sort(std::vector<double>::iterator, std::vector<double>::iterator, std::less<>);
	template void binary_tree_sort(std::vector<std::string>::iterator, std::vector<std::string>::iterator, std::less<>);
	template void binary_tree_sort(int*, int*, std::less<>);
	template void binary_tree_sort(long*, long*, std::less<>);
	template void binary_tree_sort(double*, double*, std::less<>);

} 
