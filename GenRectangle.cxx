#include <sstream>
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <iostream>
#include <ctime>
#include <cstdlib>



 
int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n, m;

    if(argc==3){
        for (int i = 1; i < 3; i++) {
            if (!isdigit(*argv[i])) {
                 std::cout << "ARGUMENTY MUSZA BYC LICZBA\n";
                exit(EXIT_FAILURE);
            }
        }
        std::istringstream iss1( argv[1] );
        if (iss1 >> n){}
        std::istringstream iss2( argv[2] );
        if (iss2 >> m){}
    }else{
        std::cout << "ZLA LICZBA ARGUMENTOW\n<N> <M>\n";
        exit (EXIT_FAILURE);

    } 
    std::cout<<n<<" "<<m<<'\n';

    for(int i = 0; i<n; i++){
         for(int j = 0; j<m; j++){
             std::cout << rand() % 2;
        }std::cout<<'\n';
    }
    return 0;   
}