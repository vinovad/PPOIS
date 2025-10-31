#include "msd_radix_sort.h"

namespace sortlib {
    template void msd_radix_sort(std::vector<int>::iterator, std::vector<int>::iterator);
    template void msd_radix_sort(std::vector<long>::iterator, std::vector<long>::iterator);
    template void msd_radix_sort(std::vector<long long>::iterator, std::vector<long long>::iterator);
    template void msd_radix_sort(std::vector<unsigned>::iterator, std::vector<unsigned>::iterator);
    template void msd_radix_sort(std::vector<unsigned long>::iterator, std::vector<unsigned long>::iterator);
    template void msd_radix_sort(std::vector<unsigned long long>::iterator, std::vector<unsigned long long>::iterator);
    template void msd_radix_sort(std::vector<short>::iterator, std::vector<short>::iterator);
    template void msd_radix_sort(std::vector<unsigned short>::iterator, std::vector<unsigned short>::iterator);
    template void msd_radix_sort(std::vector<signed char>::iterator, std::vector<signed char>::iterator);
    template void msd_radix_sort(std::vector<unsigned char>::iterator, std::vector<unsigned char>::iterator);

    template void msd_radix_sort(int*, int*);
    template void msd_radix_sort(long*, long*);
    template void msd_radix_sort(unsigned*, unsigned*);

    template void msd_radix_sort(std::vector<std::string>::iterator, std::vector<std::string>::iterator);
    template void msd_radix_sort(std::string*, std::string*);

    template void msd_radix_sort(std::vector<int>&);
    template void msd_radix_sort(std::vector<long>&);
    template void msd_radix_sort(std::vector<unsigned>&);
    template void msd_radix_sort(std::vector<std::string>&);


} 
