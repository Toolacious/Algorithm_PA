# CC and CFLAGS are varilables
CC = g++
CFLAGS = -c
CPPFLAGS = -std=c++11 
AR = ar
ARFLAGS = rcv
# -c option ask g++ to compile the source files, but do not link.
# -g option is for debugging version
# -O2 option is for optimized version
DBGFLAGS = -g #-D_DEBUG_ON_
OPTFLAGS = -O2

all     : bin/mps
	@echo -n ""

# optimized version
bin/mps  : maxPlanarSubset_opt.o main_opt.o 
			$(CC) $(OPTFLAGS) $(CPPFLAGS)maxPlanarSubset_opt.o main_opt.o -o bin/mps
main_opt.o              : src/main.cpp
			$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@
maxPlanarSubset_opt.o : src/maxPlanarSubset.cpp src/maxPlanarSubset.h
			$(CC) $(CFLAGS) $(OPTFLAGS) $(CPPFLAGS) $< -o $@

# DEBUG Version
dbg : bin/NTU_sort_dbg
	@echo -n ""

bin/NTU_sort_dbg        : maxPlanarSubset_opt.o main_opt.o
			$(CC) $(DBGFLAGS) $(CPPFLAGS) maxPlanarSubset_opt.o main_opt.o -o bin/mps_dbg
main_dbg.o              : src/main.cpp 
			$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@
sort_tool_dbg.o : src/maxPlanarSubset.cpp src/maxPlanarSubset.h
			$(CC) $(CFLAGS) $(DBGFLAGS) $(CPPFLAGS) $< -o $@

# clean all the .o and executable files
clean:
			rm -rf *.o bin/*