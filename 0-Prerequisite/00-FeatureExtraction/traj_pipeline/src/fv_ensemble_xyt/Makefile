all: extract_fv

extract_fv : extract_fv.o fisher.o gmm.o stat.o simd_math.o
	g++ -Wall -o extract_fv_xyt extract_fv.o fisher.o gmm.o stat.o simd_math.o -Igzstream -Lgzstream -lgzstream -lz -g

extract_fv.o : extract_fv.cc fisher.h gmm.h gzstream/gzstream.h
	g++ -Wall -c extract_fv.cc -g

fisher.o : fisher.cxx fisher.h gmm.h simd_math.h
	g++ -Wall -c fisher.cxx -g

gmm.o : gmm.cxx gmm.h stat.h simd_math.h
	g++ -Wall -c gmm.cxx -g

stat.o : stat.cxx stat.h
	g++ -Wall -c stat.cxx -g

simd_math.o: simd_math.cxx simd_math.h
	g++ -Wall -c simd_math.cxx -g

clean:
	rm *.o extract_fv
