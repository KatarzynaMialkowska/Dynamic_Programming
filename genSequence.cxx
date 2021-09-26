#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>
#include <sstream>
#include <stdlib.h>     /* exit, EXIT_FAILURE */



int main(int argc, char *argv[]) {
    int n, max;
    if(argc==3){
        for (int i = 1; i <= 2; i++) {
            if (!isdigit(*argv[i])) {
                 std::cout << "ARGUMENTY MUSZA BYC LICZBA\n";
                exit(EXIT_FAILURE);
            }
        }

       std::istringstream iss1( argv[1] );
       if (iss1 >> n){}
        std::istringstream iss2( argv[2] );
       if (iss2 >> max){}

    }else{

        std::cout << "ZLA LICZBA ARGUMENTOW\nliczba losowan<n> maksymalny zakres<max>\n";
        exit (EXIT_FAILURE);

    }
    std::uniform_int_distribution<int> dist1 ( 0, max ); //klasa szablonowa
    std::mt19937 gen ( time ( NULL ) ); //generator pseudolosowy Mersenne Twister 32bit
    
    
    for( int i = 0; i < n; i++ ) {
         std::cout << dist1(gen) << "\n";
    }
 
    return 0;
} 