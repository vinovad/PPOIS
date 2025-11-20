#ifndef PAGECOUNT_H
#define PAGECOUNT_H
class PageCount {
private:
    int number_pages;         
    int illustrations_count;   
    int chapters_count; 

public:
    PageCount(int pages);
    PageCount();
    int get_number_pages();
    void set_number_pages(int n);
};


#endif
