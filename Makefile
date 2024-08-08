# Srcs := $(wildcard *.c)
# Exes := $(patsubst %.c, %, $(Srcs))

# Srcs := $(wildcard *.cc)
# Exes := $(patsubst %.cc, %, $(Srcs))

# CC := gcc
# CC := g++ -std=c++17
# CFLAGS := -Wall -g -llog4cpp -lredis++ -lhiredis -lpthread -lmysqlclient -lasbl_base -labsl_string -lboost_system
#SRCS = $(wildcard src/*.cpp) $(wildcard abseil-cpp/absl/**/*.cc)

# .PHONY: Out clean rebuild

# Out: $(Exes)

# %: %.c %.cc %.cpp
	# $(CC) $< -o $@ $(CFLAGS)

# clean:
	$(RM) $(Exes) 
# rebuild: clean Out
#
# Compiler and flags
CC = gcc
CXX = g++ -std=c++17
CFLAGS = -Wall -g 
CXXFLAGS = -Wall -g -std=c++17  -Iinclude -Idata/keanu/ym_cpp/cpp_project/ymlocal/comm2/mm3rd/abseil-cpp -Idata/keanu/ym_cpp/cpp_project/ymlocal/comm2/mm3rd/boost -Idata/keanu/ym_cpp/cpp_project/ymlocal/comm2/mm3rd/curl/include
LDFLAGS = -Lmm3rd/boost/lib -Lmm3rd/curl/lib -lboost_system -lcurl -labsl_base -labsl_strings -lpthread -lmysqlclient

# Source files
C_SRCS = $(wildcard src/*.c)
CXX_SRCS = $(wildcard src/*.cc) $(wildcard src/*.cpp) $(wildcard mm3rd/abseil-cpp/absl/**/*.cc) $(wildcard mm3rd/boost/**/*.cpp) $(wildcard mm3rd/curl/**/*.cpp)
OBJS = $(C_SRCS:.c=.o) $(CXX_SRCS:.cpp=.o) $(CXX_SRCS:.cc=.o)

# Executable
#TARGET = my_program  # 你需要定义这个变量
C_EXES = $(C_SRCS:.c=)
CXX_EXES = $(CXX_SRCS:.cpp=) $(CXX_SRCS:.cc=)
EXES = $(C_EXES) $(CXX_EXES)

# Rules
.PHONY: all clean rebuild

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
