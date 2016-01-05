.PHONY: default

default: in_a in_b

in_a: a
	./a < in_a

in_b: b
	./b < in_b

a: a.cpp
	g++ $< -o $@

b: b.cpp
	g++ $< -o $@

