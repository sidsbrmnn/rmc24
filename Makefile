UNAME := $(shell uname -s)

CXX = g++-14
CXXFLAGS = -g -O2 -std=gnu++23
ifeq ($(UNAME), Linux)
  CXXFLAGS += -static
endif

LDLIBS = -lpthread
ifeq ($(UNAME), Linux)
  LDLIBS += -lrt
endif

SRC = $(wildcard *.cpp)
BIN = $(SRC:.cpp=)

all: $(BIN)

clean:
	$(RM) $(BIN)
	$(RM) -r $(SRC:.cpp=.dSYM)

.PHONY: all clean
