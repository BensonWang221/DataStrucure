SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))

out: $(OBJECTS)
	g++ $^ -o $@ -Iinclude -std=c++11 -g

%.o: %.cpp
	g++ $^ -c -o $@ -Iinclude -std=c++11 -g

.PHONY: clean
clean:
	-rm out *.o