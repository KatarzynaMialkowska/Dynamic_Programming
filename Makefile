
.SUFFIXES: .cxx .o .x .hxx .c .cpp

NAME1 = GenRectangle
NAME2 = maxRect
NAME3 = genSequence
NAME4 = LDS


CXX1 = $(NAME1).cxx
CXX2 = $(NAME2).cxx
CXX3 = $(NAME3).cxx
CXX4 = $(NAME4).cxx


EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x
EXEC4 = $(NAME4).x

CO=g++
FLAGS= -std=c++11


.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4)



$(EXEC1): 
	$(CO) -o $@ $(CXX1) $(FLAGS)

$(EXEC2): 
	$(CO) -o $@ $(CXX2) $(FLAGS)
	
$(EXEC3): 
	$(CO) -o $@ $(CXX3) $(FLAGS)
	
$(EXEC4): 
	$(CO) -o $@ $(CXX4) $(FLAGS)



.PHONY: maxrect
maxrect: all
	@echo "*The maximum area of a rectangle*\n"
	@./$(EXEC1) 30 20 > file3.txt
	@./$(EXEC2) < file3.txt

.PHONY: lds
lds: all
	@echo "*Longest Decreasing Subsequence*\n"
	@./$(EXEC3) 50 100 > file.txt
	@./$(EXEC4) < file.txt



.PHONY: clean
clean:                                                     
	rm -f *.o  *~ *.a *.so *.dat *.x *.txt core core* a.out; rm -rf ${LIB_DIR}
