
struct q_elem_s
{
	char* name;
	int priority;
	struct q_elem_s *next;
};

struct PrioQueue
{
	int size;
	q_elem *root;
};

PrioQueue* pqueue_new()
{
	//TODO
	struct PrioQueue *new_pqueue;
	new_pqueue = (struct PrioQueue*)malloc(sizeof(struct PrioQueue));
	new_pqueue->size = 0;
	new_pqueue->root = NULL;
	return new_pqueue;
}

q_elem* q_elem_new(int priority, char* name)
{
	//TODO
	struct q_elem_s *q_element;
	q_element = (struct q_elem_s*)malloc(sizeof(struct q_elem_s));
	q_element->priority = priority;
	q_element->name = name;
	q_element->next = NULL;
	return q_element;
}

void pqueue_free(PrioQueue *queue)
{
	struct q_elem_s *tmp = queue->root;
	if(tmp==NULL)
	{
		free(queue);
		return;
	}
	struct q_elem_s *cur = tmp;
	while (tmp != NULL) {
		cur = tmp;
		tmp = tmp->next;
		free(cur);
	}
	free(queue);
	//TODO
}

char* pqueue_offer(PrioQueue *queue, q_elem* newElem)
{
	//TODO
		
	if (newElem == NULL)
		return NULL;
	
	if (queue->root == NULL)
	{
		queue->root = newElem;
		queue->size = queue->size + 1;
		return newElem->name;
	}

	struct q_elem_s *tmp_1, *tmp_2;
	
	tmp_1 = queue->root;
	tmp_2 = queue->root->next;

	queue->size = queue->size + 1;

	if (tmp_1->priority < newElem->priority)
	{
		queue->root = newElem;
		newElem->next = tmp_1;
		return newElem->name;
	}

	while (tmp_2 != NULL)
	{
		if (tmp_2->priority < newElem->priority)
		{
			tmp_1->next = newElem;
			newElem->next = tmp_2;
			return newElem->name;
		}
		tmp_1 = tmp_2;
		tmp_2 = tmp_2->next;
	}

	tmp_2 = newElem;
	tmp_1->next = tmp_2;
	return newElem->name;

}

char* pqueue_peek(PrioQueue *queue)
{
	//TODO
	if (queue->size == 0)
		return NULL;
	else
		return queue->root->name;
}

char* pqueue_poll(PrioQueue *queue)
{
	//TODO
	if (queue->size == 0)
		return NULL;
	else
	{
		queue->size = queue->size - 1;
		struct q_elem_s *tmp;
		tmp = queue->root;
		char *c = tmp->name;
		queue->root = tmp->next;
		free(tmp);
		return c;
	}
}

int pqueue_size(PrioQueue *queue)
{
	//TODO
	return queue->size;
}

void pqueue_print(PrioQueue *queue)
{
	if (queue->size == 0)
		return;

	struct q_elem_s *tmp = queue->root;
	while (tmp!=NULL)
	{
		printf("(%d,%c)", tmp->priority, *tmp->name);
		tmp = tmp->next;
	}
	//TODO
}

