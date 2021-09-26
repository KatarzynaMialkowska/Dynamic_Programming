# Dynamic_Programming

Author: Katarzyna Miałkowska

## Contents ##
1) genSquare.cxx,
- Generates an NxM binary rectangle.
The program accepts the parameters of the sides of the binary rectangle in the argument.
<N> <M>

2) maxRect.cxx
  - The program calculates the maximum area of a rectangle consisting of only "1". It also includes a brute force algorithm.

3) genSequence.cxx
- Generates a random sequence of numbers.
The program accepts the maximum sequence size of numbers in the argument.
<max>

4) LDS.cxx
  - The program calculates the length of the longest decreasing subsequence. Includes implementation O (2 ^ n) recursive and iterative O (n ^ 2). 

## Makefile ##

- To compile all programs, execute:
 make all
- To clear the contents of unnecessary files, execute:
 make clean
- To run the maximum area of a rectangle program (maxRect.cxx):
make maxrect
- To run the longest decreasing subsequence program (LDS.cxx):
make lds
