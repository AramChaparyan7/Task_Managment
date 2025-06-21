CXX = g++
CXXFLAGS = -std=c++17 -pthread
LDLIBS = -lgtest -lgtest_main
SRCS = Task.cpp TaskManager.cpp User.cpp main.cpp 
OBJS = $(SRCS:.cpp=.o)

TARGET = Task_Manager

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

