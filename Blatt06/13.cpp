#include "fcpp.hh"

int main(int argc, char *argv[])
{
    int n = 10;
    print(
        ((float(pow(2,n))+float(pow(-2,n)))+float(pow(2,-n)))-(float(pow(2,n))+(float(pow(-2,n))+float(pow(2,-n))))
        );
    return(0);
}