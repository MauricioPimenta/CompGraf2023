Target = trabalhocg
Compiler = g++
Debugger = -g
CompOpt = -Wall -Werror

BaseFile = jogo.cpp
Classes = Classes/*.cpp Classes/*.h

Files = $(BaseFile) $(Classes)

OpenGLibs = -lGL -lGLU -lglut
Libs = -lm

# g++ jogo.cpp -o trabalhocg Classes/rect.h Classes/rect.cpp Classes/circle.h Classes/circle.cpp -lGL -lGLU -lglut -lm
all: $(BaseFile) $(Classes)
	$(Compiler) $(BaseFile) -o $(Target) $(Classes) $(OpenGLibs) $(Libs)

debug: $(BaseFile) $(Classes)
	$(Compiler) $(Debugger) $(BaseFile) -o $(Target) $(Classes) $(OpenGLibs) $(Libs)