emulate8080 : clean
	gcc -g -O0 main.c -o emulate8080

clean : 
	rm emulate8080
