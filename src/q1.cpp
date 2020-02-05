#include <iostream>

typedef unsigned char byte;

int cmp ( const void * a , const void * b )
{

    int *a_cast = (int *) a;
    int *b_cast = (int *) b;
    std::cout << "a " << *a_cast << "b "  << *b_cast << "\n";
    if(*a_cast < *b_cast)
    {
        return -1;
    }else if(*a_cast == *b_cast)
    {
        return 0;
    }

    return 1;

}
void sort_bubble_2 ( const void * first , const void * last , size_t size , int (*cmp)(const void *, const void *))
{
    byte *first_cast = (byte *) first;
    byte *last_cast = (byte *) last;
    byte aux;
    int count{0};
    while(first_cast != last_cast)
    {
        count++;
        first_cast++;
    }
    for(int j(0); j < count; j++)
    {
        first_cast--;
    }
    count /= size;
    last_cast -= size;
    std::cout << "count" << count << "\n";

    while(first_cast != last_cast){
            for(int i{0}; i < count; i++){
            if( cmp( first_cast , first_cast+(size*i) ) == 1)
            {
                aux = *(first_cast+(size*i));
                *(first_cast+(size*i)) = *first_cast;
                *first_cast =  aux;

            }
        }
        count--;
        first_cast += size;
    }

}
void printer(const int *first, const int *last)
{
    std::cout << "A = { ";

    while(first != last)
    {
        std::cout << *first << " ";
        first++;
    }
    std::cout << "}" << std::endl;
}

int main ( void )
{
    int A[] = {1 , 4, 2 , 3, 5 ,7 ,10 ,9 ,8, 6};
    printer(std::begin(A), std::end(A));
    sort_bubble_2(std::begin(A), std::end(A), sizeof(A[0]), *cmp);

    printer(std::begin(A), std::end(A));
    return 0;
}
