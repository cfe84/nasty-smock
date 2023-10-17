CXX = g++
CPPFLAGS  = -g -Wall -Werror
LDFLAGS = -g
LDLIBS = 

TARGET = nasty-smock
OUT = out
SRC = src
ALL = $(patsubst $(SRC)/%,%,$(patsubst %.cpp,%.o,$(wildcard $(SRC)/*.cpp)))
ALL_WITH_PATH=$(patsubst %,$(OUT)/% ,$(ALL))
ALL_EXC_MAIN=$(patsubst $(OUT)/main.o%,,$(ALL_WITH_PATH))

TEST = test
ALL_TESTS = $(patsubst $(TEST)/%,%,$(patsubst %.cpp,%.o,$(wildcard $(TEST)/*.cpp)))

VPATH=$(SRC)

all: $(TARGET)

$(TARGET): $(ALL)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(ALL_WITH_PATH) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -o $(OUT)/$(patsubst $(SRC)/%,%,$@) -c $<

clean:
	$(RM) $(TARGET)
	$(RM) out/*.o
	$(RM) out/tests

test: $(ALL)
	$(CXX) -g test/*.test.cpp $(ALL_EXC_MAIN) -l UnitTest++ -o out/tests && out/tests