#pragma once

// Stacks & Queues

	// Stacks

	int stacks_basics_using_array();

	void stack_basics_using_linked_list();

	// Queues

	int queues_basics_using_array();

	int queues_basics_using_linked_list();

		// Queues basic Functions

		void print_queue(int queue[], int queue_size);

		void enqueue(int queue[], int& queue_size, int data);

		void dequeue(int queue[], int& queue_size);

		void peek(int queue[], int queue_size);

		void isEmpty(int queue_size);
