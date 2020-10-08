analyzer: main.o functions.o
	g++ $(GFLAGS) -o analyzer main.o functions.o -pthread
	
main.o: main.cpp functions.hpp 
	g++ $(GFLAGS) -c main.cpp -pthread
	
functions.o: functions.cpp functions.hpp
	g++ $(GFLAGS) -c functions.cpp -pthread
	
clean: 
	rm -f *.o analyzer
