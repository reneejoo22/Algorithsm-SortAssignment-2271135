#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define DATA_NUM	50
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))	//x,y ���� ��ȯ
int n;


void menu()
{
	printf("\n-sorting menu-\n");
	printf("s(��������)\ni(��������)\nb(��������)\nl(������)\nh(��������)\nm(�պ�����)\nq(������)\nt(������)\nr(�������)\nx(����)");
	printf("\n---------------\n");
}

void smenu()
{
	printf("\n-sorting order-\n");
	printf("1(��������)\n2(��������)");
	printf("\n---------------\n");
}

void printList(int list[], int n) {

	for (int q = 0; q < n; q++) //���ĵ� �� ������� ���
		printf("%d ", list[q]);
	printf("\n");
}

void selection_sort(int list[], int n) {	//�������� ��������

	int i, j, least, temp;	//���ŵǴ� �ʱ� ��ġ, ���ŵǴ� �ּ� ã�� ��ġ, �ּ��� ��ġ, ����

	
	for (i = 0; i < n - 1; i++) {	//�ʱ� �ڸ� �����ϰ� ã��
		least = i;	//i�� �ʱ� �ڸ� ����
		for (j = i + 1; j < n; j++)	//�ʱ� �ڸ� ���ϰ� �ּڰ� Ž��
			if (list[j] < list[least])least = j;	// �ʱ⺸�� ���� �� ã���� �ش� �� ��ġ ����
		SWAP(list[i], list[least], temp);	//�ٲٱ�
	
		printList(list, n);
	}
	printf("\n");
}

void selection_sort2(int list[], int n) {	//�������� ��������

	int i, j, least, temp;	//���ŵǴ� �ʱ� ��ġ, ���ŵǴ� �ִ� ã�� ��ġ, �ִ��� ��ġ, ����

	for (i = 0; i < n - 1; i++) {	//�ʱ� �ڸ� �����ϰ� ã��
		least = i;	//i�� �ʱ� �ڸ� ����
		for (j = i + 1; j < n; j++)	//�ʱ� �ڸ� ���ϰ� �ִ� Ž��
			if (list[j] > list[least])least = j;	// �ʱ⺸�� ū �� ã���� �ش� �� ��ġ ����
		SWAP(list[i], list[least], temp);	//�ٲٱ�

		printList(list, n);
	}
	printf("\n");
}

void insert_sort(int list[], int n, char choice) {	//��������

	int i, j, key;	//unsorted ���� ���� ��ġ, sorted ���� ���� ��ġ, sorted

	int num = 0;

	for (i = 1; i < n; i++) {	//unsorted ������ ���� �ʱⰪ
		key = list[i];	//key�� ����

		if (choice == '1') {
			for (j = i - 1; j >= 0 && list[j] > key; j--)	//sorted ������ �ʱⰪ, Ű���� �� ������
				list[j + 1] = list[j];	//sorted �ʱⰪ�� ���������� �Űܰ�
			list[j + 1] = key;	//�ƴҽ� �� �ڸ��� �״�� ����
		}
		else if (choice == '2') {
			for (j = i - 1; j >= 0 && list[j] < key; j--)	//sorted ������ �ʱⰪ, Ű���� �� Ŭ��
				list[j + 1] = list[j];	//sorted �ʱⰪ�� ���������� �Űܰ�
			list[j + 1] = key;	//�ƴҽ� �� �ڸ��� �״�� ����
		}
		printList(list, n);
	}
	printf("\n");

}

void bubble_sort(int list[], int n, char choice) {	//�������� 

	int i, j, temp;	//���ŵǴ� �ʱ� ��ġ, ���ŵǴ� �ּ� ã�� ��ġ, �ּ��� ��ġ, ����

	int num = 0;

	if (choice == '1') {
		for (i = n - 1; i > 0; i--) {
			for (j = 0; j < i; j++)
				if (list[j] > list[j + 1]) {	//j+1�� �� ������
					SWAP(list[j], list[j + 1], temp);

					printList(list, n);
				}
		}
		printf("\n");
	}

	if (choice == '2') {
		for (i = n - 1; i > 0; i--) {
			for (j = 0; j < i; j++)
				if (list[j] < list[j + 1]) {	//j+1�� �� Ŭ��
					SWAP(list[j], list[j + 1], temp);

					printList(list, n);
				}
		}
		printf("\n");
	}
}

void inc_insertion_sort(int list[], int first, int last, int gap) {	//��������

	int i, j, key;

	//int num = 0;  //�޴� ���� �� ������ ���� ���� �� �� ����

	for (i = first + gap; i <= last; i = i + gap) {	//���丷 �� ������
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j = j - gap)	// Ű���� �� ������
			list[j + gap] = list[j];	//sorted �ʱⰪ�� ���������� �Űܰ�
		list[j + gap] = key;	//�ƴҽ� �� �ڸ��� �״�� ����

		//printf("====cycle %d====\n", ++num);
		for (int q = 0; q < n; q++)	//���ĵ� �� ������� ���
			printf("%d ", list[q]);
		printf("\n");
	}
	//printf("\n");
}



void inc_insertion_sort2(int list[], int first, int last, int gap) {	//��������

	int i, j, key;

	for (i = first + gap; i <= last; i = i + gap) {	//���丷 �� ������
		key = list[i];
		for (j = i - gap; j >= first && list[j] < key; j = j - gap)	// Ű���� �� Ŭ��
			list[j + gap] = list[j];	//sorted �ʱⰪ�� ���������� �Űܰ�
		list[j + gap] = key;	//�ƴҽ� �� �ڸ��� �״�� ����

		for (int q = 0; q < n; q++)	//���ĵ� �� ������� ���
			printf("%d ", list[q]);
		printf("\n");
	}

}

void shell_sort(int list[], int n) {

	int i, gap;

	for (gap = n / 2; gap > 0; gap = gap / 2) {	//���丷 �� �� ��� ������ߵ�
		if ((gap % 2) == 0) gap++;	//�������� 0�̸� +1 �ؼ� ����
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}

}

void shell_sort2(int list[], int n) {

	int i, gap;

	for (gap = n / 2; gap > 0; gap = gap / 2) {	//���丷 �� �� ��� ������ߵ�
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort2(list, i, n - 1, gap);
	}
}

// ���⼭���� �������� �ڵ�//////////////////////////
#define MAX_ELEMENT 200
typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


// ���� �Լ�
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
// �ʱ�ȭ �Լ�
void init(HeapType* h)
{
	h->heap_size = 0;
}
// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
// ���� �Լ�
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}

void insert_min_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}


// ���� �Լ�
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵�

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(element a[], int n, char choice)
{
	int i;
	HeapType* h;

	h = create();
	init(h);

	if (choice == '1') {
		for (i = 0; i < n; i++) {
			insert_max_heap(h, a[i]);
		}

		for (i = (n - 1); i >= 0; i--) {
			a[i] = delete_max_heap(h);
		}
	}

	else {
		for (i = 0; i < n; i++) {
			insert_min_heap(h, a[i]);
		}
		for (i = (n - 1); i >= 0; i--) {
			a[i] = delete_min_heap(h);
		}
	}


	free(h);
}
// ��������� �������� �ڵ�//////////////////////////

//���⼭���� �պ�����_�̰� ��������////////////////
void merge(int list[], int left, int mid, int right, int num_data, int cycle) {
	
	int* sorted = (int*)malloc(sizeof(int) * num_data);

	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left; // left --- mid     mid+1 --- right

	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
	}

	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	for (l = left; l <= right; l++)
		list[l] = sorted[l];

	printList(list, num_data);

	free(sorted);
}

//�̰� ��������
void merge2(int list[], int left, int mid, int right, int num_data, int cycle) {
	int* sorted = (int*)malloc(sizeof(int) * num_data);

	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left; // left --- mid     mid+1 --- right

	while (i <= mid && j <= right) {
		if (list[i] >= list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
	}

	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	for (l = left; l <= right; l++)
		list[l] = sorted[l];

	printList(list, num_data);

	free(sorted);
}



void merge_sort(int list[], int left, int right, int num_data, int* cycle, char choice) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		merge_sort(list, left, mid, num_data, cycle, choice);
		merge_sort(list, mid + 1, right, num_data, cycle, choice);

		if (choice == '1') {
			//printf("merge(left_%d, mid_%d)\n\n", left, mid);
			merge(list, left, mid, right, num_data, ++(*cycle));

		}
		else {
			merge2(list, left, mid, right, num_data, ++(*cycle));
		}
	}
}

//���⼭���� �պ�����////////////////////////////////

//���⼭���� �� ����, ���̺귯�� ������/////////////////////
int compare(const void* x, const void* y) {
	return (*(int*)x - *(int*)y); // ��������
}
int compare2(const void* x, const void* y) {
	return (*(int*)y - *(int*)x); // ��������
}

int partition(int list[], int left, int right, int n) {    //����

	int pivot, temp;
	int low, high;
	//int num_data = right + 1;

	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		do
			low++;
		while (list[low] < pivot);  //low�� �� ���� ��� Ž�� ��� ����

		do
			high--;
		while (list[high] > pivot); //high�� �� ū ��� Ž�� ��� ����

		if (low < high) {
			SWAP(list[low], list[high], temp);   //���Ϲ��� ���ҽ� ���� �� �ٲ�

			printList(list, n);
		}

	} while (low < high);   //���� �����ϸ� Ž�� ����

	SWAP(list[left], list[high], temp);

	printList(list, n);

	return high;
}

int partition2(int list[], int left, int right, int n) {   //����

	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		do
			low++;
		while (list[low] > pivot);  //low�� �� ���� ��� Ž�� ��� ����

		do
			high--;
		while (list[high] < pivot); //high�� �� ū ��� Ž�� ��� ����

		if (low < high) {
			SWAP(list[low], list[high], temp);   //���Ϲ��� ���ҽ� ���� �� �ٲ�

			printList(list, n);
		}
	} while (low < high);   //���� �����ϸ� Ž�� ����

	SWAP(list[left], list[high], temp);
	printList(list, n);

	return high;
}


void quick_sort(int list[], int left, int right, int n, char choice) {

	if (left < right) {
		if (choice == '1') {
			int q = partition(list, left, right, n);
			quick_sort(list, left, q - 1,n, choice);  //���ʸ� ��������
			quick_sort(list, q + 1, right,n, choice); //���ʸ� ��������
		}
		else {
			int q = partition2(list, left, right, n);
			quick_sort(list, left, q - 1, n, choice);  //���ʸ� ��������
			quick_sort(list, q + 1, right,n, choice); //���ʸ� ��������

		}
	}
}

//���⼭���� �� ����, ���̺귯�� ������/////////////////////

//���⼭���� ��� ���� ///////////////////////////////////

#define MAX_QUEUE_SIZE 100
typedef int elementt;
typedef struct { // ť Ÿ��
	elementt  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(QueueType* q, elementt item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
elementt dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void print_list(int list[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
}

void radix_sort(int list[], int n, int DIGITS, int* cycle) {
	int i, b, d, factor = 1;
	QueueType queues[10];

	for (b = 0; b < 10; b++)
		init_queue(&queues[b]);

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)
			enqueue(&queues[(list[i] / factor) % 10], list[i]);

		for (b = i = 0; b < 10; b++)
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);

		(*cycle)++;
		printf("Cycle %d: ", *cycle);
		print_list(list, n);

		factor *= 10;
	}
}

void radix_sort2(int list[], int n, int DIGITS, int* cycle) {
	int i, b, d, factor = 1;
	int num = n;
	QueueType queues[10];

	for (b = 0; b < 10; b++)
		init_queue(&queues[b]);

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)
			enqueue(&queues[(list[i] / factor) % 10], list[i]);

		for (b = i = 0; b < 10; b++)
			while (!is_empty(&queues[b]))
				list[n - 1 - i++] = dequeue(&queues[b]);

		(*cycle)++;
		printf("Cycle %d: ", *cycle);
		print_list(list, num);

		factor *= 10;
	}
}


//������� ��� ���� ////////////////////////////////////

void main(int argc, char* argv[])
{

	FILE* fp;
	int num_data;
	int* data;
	int i, j;
	char cmd, str[64], order_cmd;
	int cycle = 1;

	while (1) {
		if (argc == 2) {
			fp = fopen(argv[1], "r");
			fscanf(fp, "%d", &num_data);
			data = (int*)malloc(sizeof(int) * num_data);
			for (i = 0; i < num_data; i++)
				fscanf(fp, "%d", &data[i]);
			fclose(fp);
		}
		else {
			printf("Enter the number to be sorted in line by line(at most 50 lines)\n");
			data = (int*)malloc(sizeof(int) * DATA_NUM);
			num_data = 0;
			do {
				gets_s(str, 64);
				if (str == NULL || strcmp(str, "=") == 0) break;
				else data[num_data++] = atoi(str);
			} while (str != NULL);
		}
		printf("Input data:\n");		// unsorted data
		for (i = 0; i < num_data; i++)
			printf("%d ", data[i]);
		printf("\n");

		menu();
		cmd = getchar();
		getchar();		// ����Ű ����
		if (cmd == 'x') {
			printf("Exit...\n");
			return;
		}
		smenu();
		order_cmd = getchar();
		getchar();		// ����Ű ����

		switch (cmd) {
		case 's':
			printf("selection sort with %s order", (order_cmd == '1' ? "����" : "����"));
			printf("\n");
			(order_cmd == '1') ? selection_sort(data, num_data) : selection_sort2(data, num_data);
			break;

		case 'i':
			printf("Insertion sort with %s order", (order_cmd == '1' ? "����" : "����"));
			printf("\n");
			insert_sort(data, num_data, order_cmd);
			break;

		case 'b':
			printf("Bubble sort with %s order", (order_cmd == '1' ? "����" : "����"));
			printf("\n");
			bubble_sort(data, num_data, order_cmd);
			break;

		case 'l':
			printf("Shell sort with %s order", (order_cmd == '1' ? "����" : "����"));
			printf("\n");
			n = num_data;
			(order_cmd == '1') ? shell_sort(data, num_data) : shell_sort2(data, num_data);
			break;

		case 'h':
			printf("Heap sort with %s order", (order_cmd == '1' ? "����" : "����"));
			printf("\n");
			heap_sort(data, num_data, order_cmd);
			element list[DATA_NUM] = { '\0' };

			for (int i = 0; i < num_data; i++) {
				list[i].key = data[i];
			}

			heap_sort(list, num_data, order_cmd);
			for (int i = 0; i < num_data; i++) { 
				printf("%d ", list[i].key);
			}
			printf("\n");

			break;

		case 'm':
			printf("Merge sort with %s order", (order_cmd == '1' ? "����" : "����"));
			printf("\n");
			merge_sort(data, 0, num_data - 1, num_data, &cycle, order_cmd);
			break;

		case 'q':
			//#define stay num_data//���� ��� �ٲ� �ȵǾ����� ���� ������� ������ �� ���
			printf("Quick sort with %s order", (order_cmd == '1' ? "����" : "����"));
			printf("\n");
			quick_sort(data, 0, num_data - 1, num_data, order_cmd);
			//printList(data, num_data);
			break;

		case 't':
			printf("[Library Functions] Quick sort with %s order", (order_cmd == '1' ? "����" : "����"));

			if (order_cmd == '1') {
				qsort(data, num_data, sizeof(int), compare);
			}
			else qsort(data, num_data, sizeof(int), compare2);

			printList(data, n);
			break;

		case 'r':
			printf("Radix sort with %s order", (order_cmd == '1' ? "����" : "����"));
			printf("\n");

			int digit = 0; int cyclee = 0;
			printf("�ڸ����� �Է��ϼ��� -> ");
			if (scanf("%d", &digit) == 0) { printf("�Է��� ����� �ȵǾ����ϴ�"); };

			(order_cmd == '1') ? radix_sort(data, num_data, digit, &cyclee) : radix_sort2(data, num_data, digit, &cyclee);
			
			break;
		}

		printf("\nOutput data:\n");		// sorted data
		for (i = 0; i < num_data; i++)
			printf("%d ", data[i]);
		printf("\n");
	}
}