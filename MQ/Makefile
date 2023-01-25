all: calculator user

calculator: calculator.o array_list.o message_queue.o calculator_model.o
	gcc -o calculator calculator.o array_list.o message_queue.o calculator_model.o

user: user.o message_queue.o
	gcc -o user user.o message_queue.o

calculator.o: calculator.c calculator_model.h array_list.h message_queue.h 
	gcc -c calculator.c

user.o: user.c message_queue.h 
	gcc -c user.c

calculator_model.o: calculator_model.c array_list.h
	gcc -c calculator_model.c

array_list.o: array_list.c 
	gcc -c array_list.c

message_queue.o: message_queue.c
	gcc -c message_queue.c