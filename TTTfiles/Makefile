CXX = g++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES = evaluate play_2D play_3D 2Dfiles/check_ttt2D 3Dfiles/check_ttt3D \
	4Dtest print4D

FILES_2D = 2Dfiles/ttt2D.o

FILES_3D = 3Dfiles/ttt3D.o 3Dfiles/functions.o 3Dfiles/gameStatus.o \
	3Dfiles/drawDetection.o 3Dfiles/winDetection.o

FILES_4D = 4Dfiles/functions.o 4Dfiles/utility.o 4Dfiles/gameStatus.o \
	4Dfiles/winDetection.o 4Dfiles/testFuncs4D.o

FILES = ${FILES_2D} ${FILES_3D}

all: ${BINARIES}

evaluate: evaluate.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) evaluate.o -o $@
	/bin/rm -f evaluate.o

play_2D: 2Dfiles/play_2D.o ${FILES_2D}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	/bin/rm -f 2Dfiles/*.o

play_3D: 3Dfiles/play_3D.o ${FILES_3D}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	/bin/rm -f 3Dfiles/*.o

2Dfiles/check_ttt2D: 2Dfiles/check_ttt2D.o ${FILES_2D}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	/bin/rm -f 2Dfiles/*.o

3Dfiles/check_ttt3D: 3Dfiles/check_ttt3D.o ${FILES_3D}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	/bin/rm -f 3Dfiles/*.o

4Dtest: 4Dfiles/printoutTest.o ${FILES_4D}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	/bin/rm -f 4Dfiles/*.o

print4D: 4Dfiles/play_4D.o ${FILES_4D}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	/bin/rm -f 4Dfiles/*.o

clean:
	/bin/rm -f ${BINARIES} *.o
	/bin/rm -f 2Dfiles/*.o 3Dfiles/*.o 4Dfiles/*.o