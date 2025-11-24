CC=g++ #Compiler
Flags=-std=c++20 #compiler flags specified to change complile properties
Target=DataAnalysisExecutable
Objects=AnalyseData.o CustomFunctions.o

#make final executable from intermidiate objects (which get auto made by lower rules if they don't exist)
${Target}:${Objects}
	${CC} ${Flags} ${Objects} -o ${Target}
	@make clean #removes intermidiate objects

#Make each of the intermidiate objects
AnalyseData.o:AnalyseData.cxx
	${CC} ${Flags} -c AnalyseData.cxx 

#Make each of the intermidiate objects
CustomFunctions.o:CustomFunctions.cxx
	${CC} ${Flags} -c CustomFunctions.cxx 

clean: #Remove intermidiate object files
	@rm -f *.o *~

#Delete final target
cleantarget: #Remove intermidiate object files
	@rm -f ${Target}
