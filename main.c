#include "PrioQueue.h"
#include <stdio.h>


int main()
{
	//hab ein bisschen geändert um alle funktionen zu prüfen (@Ilja)
        //pqueue_free() nicht gecheckt weil kein valgrind habe (@Ilja)
	PrioQueue *queue = pqueue_new();

	pqueue_offer(queue, q_elem_new(3, "1"));
	pqueue_offer(queue, q_elem_new(5, "2"));
	printf("root is %c\n", *pqueue_peek(queue));
	pqueue_offer(queue,q_elem_new(2, "3"));
	pqueue_offer(queue, q_elem_new(6, "4"));
	printf("size is %d\n", pqueue_size(queue));
	printf("root is %c\n", *pqueue_poll(queue));
	printf("size is %d\n", pqueue_size(queue));
	printf("root is %c\n", *pqueue_peek(queue));
	pqueue_offer(queue, q_elem_new(8, "3"));
	pqueue_offer(queue, q_elem_new(4, "4"));
	pqueue_offer(queue, q_elem_new(2, "3"));
	printf("root is %c\n", *pqueue_peek(queue));
	pqueue_offer(queue, q_elem_new(4, "4"));
	pqueue_print(queue);
	printf("\n");
	printf("size is %d\n", pqueue_size(queue));
	// should print: (5,2)(4,4)(4,4)(4,4)(3,1)(2,3)(2,3)(2,3)

	pqueue_free(queue);
	// use: valgrind ./PrioQueue
	// to check if your free function works correctly 
	system("pause");
	return 0;
}
