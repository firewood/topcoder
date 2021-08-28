.PHONY: default test

ifeq ($(OS),Windows_NT)

default: test

test: Release/Problem_A.exe
	Release\\Problem_A.exe < in.txt > out.txt



Release/Problem_A.exe: main.cpp
	cl /O2 /Ot /Oi /GS /Gd /GL /Gy /std:c++17 /D _CONSOLE /D NDEBUG /D _USE_MATH_DEFINES $< /Fe:Release/Problem_A.exe

endif
