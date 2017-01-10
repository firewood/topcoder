.PHONY: default

default: in_qa

in_qa: qa
	./qa < in_qa | diff out_qa -

qa: QR_A.cpp
	g++ -g -std=c++14 $< -o $@

