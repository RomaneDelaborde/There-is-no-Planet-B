CC=g++
CCFLAGS= -Wall -std=c++11 `pkg-config gtkmm-3.0 --cflags --libs` -g
LIBFLAGS= 
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
TST_DIR=tests/
TST= $(wildcard $(TST_DIR)/*.cc)
OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cc=.o)
EXEC= planetB


all: $(EXEC)

testcase : 
	cd $(TST_DIR) ;  make

$(EXEC): $(OBJ)
	$(CC) $(LIBFLAGS) $^ -o $@ `pkg-config gtkmm-3.0 --cflags --libs`

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

clean:
	rm -f $(OBJ) $(EXEC)
cleantest:
	cd $(TST_DIR) ; make clean
distclean : clean cleantest

