CXX = g++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES = play play_2D play_3D 2Dfiles/play_ttt2D 3Dfiles/play_ttt3D

FILES_2D = 2Dfiles/ttt2D.o

FILES_3D = 3Dfiles/ttt3D.o 3Dfiles/functions.o 3Dfiles/gameStatus.o \
	3Dfiles/drawDetection.o 3Dfiles/winDetection.o

FILES = ${FILES_2D} ${FILES_3D}

all: ${BINARIES}

play: play.o
	$(CXX) $(CXXFLAGS) play.o -o $@

play_2D: 2Dfiles/play_2D.o ${FILES_2D}
	$(CXX) $(CXXFLAGS) $^ -o $@
	/bin/rm -f 2Dfiles/*.o

play_3D: 3Dfiles/play_3D.o ${FILES_3D}
	$(CXX) $(CXXFLAGS) $^ -o $@
	/bin/rm -f 3Dfiles/*.o

2Dfiles/play_ttt2D: 2Dfiles/play_ttt2D.o ${FILES_2D}
	$(CXX) $(CXXFLAGS) $^ -o $@

3Dfiles/play_ttt3D: 3Dfiles/play_ttt3D.o ${FILES_3D}
	$(CXX) $(CXXFLAGS) $^ -o $@


clean:
	/bin/rm -f ${BINARIES} *.o
	/bin/rm -f 2Dfiles/*.o 3Dfiles/*.o