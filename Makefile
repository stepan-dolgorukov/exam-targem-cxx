compiler_cxx := g++

flags_compiler_cxx :=\
--std=c++11\
-Wall\
-ggdb

sort_strings:\
sort_strings.o\
string.o
	${compiler_cxx} ${flags_compiler_cxx} ${^} -o ${@}

sort_strings.o:\
sort_strings.cc
	${compiler_cxx} ${flags_compiler_cxx} -c ${<}

string.o:\
string.cc\
string.hh
	${compiler_cxx} ${flags_compiler_cxx} -c ${<}