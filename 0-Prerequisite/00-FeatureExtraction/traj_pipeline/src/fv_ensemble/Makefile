all: extract_fv

extract_fv : extract_fv.o fisher.o gmm.o stat.o simd_math.o
	g++ -O3 -Wall -o extract_fv extract_fv.o fisher.o gmm.o stat.o simd_math.o -Igzstream -Lgzstream -lgzstream -lz

extract_fv.o : extract_fv.cc fisher.h gmm.h gzstream/gzstream.h
	g++ -O3 -Wall -c extract_fv.cc

fisher.o : fisher.cxx fisher.h gmm.h simd_math.h
	g++ -O3 -Wall -c fisher.cxx

gmm.o : gmm.cxx gmm.h stat.h simd_math.h
	g++ -O3 -Wall -c gmm.cxx

stat.o : stat.cxx stat.h
	g++ -O3 -Wall -c stat.cxx

simd_math.o: simd_math.cxx simd_math.h
	g++ -O3 -Wall -c simd_math.cxx

clean:
	rm *.o extract_fv
