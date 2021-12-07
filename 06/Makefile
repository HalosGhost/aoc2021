MKDIR ?= mkdir -p --
RM := rm -rf --

CXX ?= g++
CXXFLAGS ?= -g -ggdb -O0 -Wall -Wextra -Wpedantic -std=gnu++20
LDFLAGS :=

.PHONY: all run clean

all: 01 02

01: 01.cxx common.hxx
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

02: 02.cxx common.hxx
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
	
run:
	(for i in $$(find -type f -executable); do echo "$$i:"; ./"$$i"; done)

clean:
	(for i in $$(find -type f -executable); do $(RM) $$i; done)

$(V).SILENT:
