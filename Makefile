TARGET: exe
exe:main.o mylibstatistics.a
	gcc main.o -o exe -L . mylibstatistics.a -lm

mylibstatistics.a:cpu_statistics/cpu_statistics.o
	ar rs mylibstatistics.a cpu_statistics/cpu_statistics.o

cpu_statistics.o:cpu_statistics/cpu_statistics.c
	gcc -c -I cpu_statistics cpu_statistics/cpu_statistics.c -o cpu_statistics/cpu_statistics.o

main.o:main.c
	gcc -c -I cpu_statistics main.c -o main.o

clean:
	rm cpu_statistics/cpu_statistics.o
	rm main.o
	rm mylibstatistics.a
	rm exe
