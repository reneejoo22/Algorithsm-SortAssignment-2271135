#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define DATA_NUM	50
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))	//x,y 값을 교환
int n;


void menu()
{
	printf("\n-sorting menu-\n");
	printf("s(선택정렬)\ni(삽입정렬)\nb(버블정렬)\nl(쉘정렬)\nh(히프정렬)\nm(합병정렬)\nq(퀵정렬)\nt(퀵정렬)\nr(기수정렬)\nx(종료)");
	printf("\n---------------\n");
}

void smenu()
{
	printf("\n-sorting order-\n");
	printf("1(오름차순)\n2(내림차순)");
	printf("\n---------------\n");
}

void printList(int list[], int n) {

	for (int q = 0; q < n; q++) //정렬된 것 순서대로 출력
		printf("%d ", list[q]);
	printf("\n");
}

void selection_sort(int list[], int n) {	//선택정렬 오름차순

	int i, j, least, temp;	//갱신되는 초기 위치, 갱신되는 최소 찾는 위치, 최소의 위치, 저장

	
	for (i = 0; i < n - 1; i++) {	//초기 자리 제외하고 찾기
		least = i;	//i에 초기 자리 저장
		for (j = i + 1; j < n; j++)	//초기 자리 제하고 최솟값 탐색
			if (list[j] < list[least])least = j;	// 초기보다 작은 값 찾으면 해당 값 위치 저장
		SWAP(list[i], list[least], temp);	//바꾸기
	
		printList(list, n);
	}
	printf("\n");
}

void selection_sort2(int list[], int n) {	//선택정렬 내림차순

	int i, j, least, temp;	//갱신되는 초기 위치, 갱신되는 최대 찾는 위치, 최대의 위치, 저장

	for (i = 0; i < n - 1; i++) {	//초기 자리 제외하고 찾기
		least = i;	//i에 초기 자리 저장
		for (j = i + 1; j < n; j++)	//초기 자리 제하고 최댓값 탐색
			if (list[j] > list[least])least = j;	// 초기보다 큰 값 찾으면 해당 값 위치 저장
		SWAP(list[i], list[least], temp);	//바꾸기

		printList(list, n);
	}
	printf("\n");
}

void insert_sort(int list[], int n, char choice) {	//삽입정렬

	int i, j, key;	//unsorted 영역 내의 위치, sorted 영역 내의 위치, sorted

	int num = 0;

	for (i = 1; i < n; i++) {	//unsorted 영역의 가장 초기값
		key = list[i];	//key에 저장

		if (choice == '1') {
			for (j = i - 1; j >= 0 && list[j] > key; j--)	//sorted 영역의 초기값, 키값이 더 작을시
				list[j + 1] = list[j];	//sorted 초기값이 오른쪽으로 옮겨감
			list[j + 1] = key;	//아닐시 그 자리에 그대로 있음
		}
		else if (choice == '2') {
			for (j = i - 1; j >= 0 && list[j] < key; j--)	//sorted 영역의 초기값, 키값이 더 클시
				list[j + 1] = list[j];	//sorted 초기값이 오른쪽으로 옮겨감
			list[j + 1] = key;	//아닐시 그 자리에 그대로 있음
		}
		printList(list, n);
	}
	printf("\n");

}

void bubble_sort(int list[], int n, char choice) {	//버블정렬 

	int i, j, temp;	//갱신되는 초기 위치, 갱신되는 최소 찾는 위치, 최소의 위치, 저장

	int num = 0;

	if (choice == '1') {
		for (i = n - 1; i > 0; i--) {
			for (j = 0; j < i; j++)
				if (list[j] > list[j + 1]) {	//j+1이 더 작을시
					SWAP(list[j], list[j + 1], temp);

					printList(list, n);
				}
		}
		printf("\n");
	}

	if (choice == '2') {
		for (i = n - 1; i > 0; i--) {
			for (j = 0; j < i; j++)
				if (list[j] < list[j + 1]) {	//j+1이 더 클시
					SWAP(list[j], list[j + 1], temp);

					printList(list, n);
				}
		}
		printf("\n");
	}
}

void inc_insertion_sort(int list[], int first, int last, int gap) {	//내림차순

	int i, j, key;

	//int num = 0;  //받는 간격 값 때문에 수가 누적 될 수 없음

	for (i = first + gap; i <= last; i = i + gap) {	//반토막 낸 내에서
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j = j - gap)	// 키값이 더 작을시
			list[j + gap] = list[j];	//sorted 초기값이 오른쪽으로 옮겨감
		list[j + gap] = key;	//아닐시 그 자리에 그대로 있음

		//printf("====cycle %d====\n", ++num);
		for (int q = 0; q < n; q++)	//정렬된 것 순서대로 출력
			printf("%d ", list[q]);
		printf("\n");
	}
	//printf("\n");
}



void inc_insertion_sort2(int list[], int first, int last, int gap) {	//오름차순

	int i, j, key;

	for (i = first + gap; i <= last; i = i + gap) {	//반토막 낸 내에서
		key = list[i];
		for (j = i - gap; j >= first && list[j] < key; j = j - gap)	// 키값이 더 클시
			list[j + gap] = list[j];	//sorted 초기값이 오른쪽으로 옮겨감
		list[j + gap] = key;	//아닐시 그 자리에 그대로 있음

		for (int q = 0; q < n; q++)	//정렬된 것 순서대로 출력
			printf("%d ", list[q]);
		printf("\n");
	}

}

void shell_sort(int list[], int n) {

	int i, gap;

	for (gap = n / 2; gap > 0; gap = gap / 2) {	//반토막 낸 값 계속 보내줘야됨
		if ((gap % 2) == 0) gap++;	//나머지가 0이면 +1 해서 보냄
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}

}

void shell_sort2(int list[], int n) {

	int i, gap;

	for (gap = n / 2; gap > 0; gap = gap / 2) {	//반토막 낸 값 계속 보내줘야됨
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort2(list, i, n - 1, gap);
	}
}

// 여기서부터 히프정렬 코드//////////////////////////
#define MAX_ELEMENT 200
typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}
// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}

void insert_min_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}


// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// 한 단계 아래로 이동

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
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// 한 단계 아래로 이동
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
// 여기까지가 히프정렬 코드//////////////////////////

//여기서부터 합병정렬_이건 오름차순////////////////
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

//이건 내림차순
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

//여기서까지 합병정렬////////////////////////////////

//여기서부터 퀵 정렬, 라이브러리 퀵정렬/////////////////////
int compare(const void* x, const void* y) {
	return (*(int*)x - *(int*)y); // 오름차순
}
int compare2(const void* x, const void* y) {
	return (*(int*)y - *(int*)x); // 내림차순
}

int partition(int list[], int left, int right, int n) {    //오름

	int pivot, temp;
	int low, high;
	//int num_data = right + 1;

	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		do
			low++;
		while (list[low] < pivot);  //low가 더 작은 경우 탐색 계속 진행

		do
			high--;
		while (list[high] > pivot); //high가 더 큰 경우 탐색 계속 진행

		if (low < high) {
			SWAP(list[low], list[high], temp);   //와일문에 반할시 둘의 값 바꿈

			printList(list, n);
		}

	} while (low < high);   //둘이 교차하면 탐색 멈춤

	SWAP(list[left], list[high], temp);

	printList(list, n);

	return high;
}

int partition2(int list[], int left, int right, int n) {   //내림

	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		do
			low++;
		while (list[low] > pivot);  //low가 더 작은 경우 탐색 계속 진행

		do
			high--;
		while (list[high] < pivot); //high가 더 큰 경우 탐색 계속 진행

		if (low < high) {
			SWAP(list[low], list[high], temp);   //와일문에 반할시 둘의 값 바꿈

			printList(list, n);
		}
	} while (low < high);   //둘이 교차하면 탐색 멈춤

	SWAP(list[left], list[high], temp);
	printList(list, n);

	return high;
}


void quick_sort(int list[], int left, int right, int n, char choice) {

	if (left < right) {
		if (choice == '1') {
			int q = partition(list, left, right, n);
			quick_sort(list, left, q - 1,n, choice);  //왼쪽만 정렬진행
			quick_sort(list, q + 1, right,n, choice); //른쪽만 정렬진행
		}
		else {
			int q = partition2(list, left, right, n);
			quick_sort(list, left, q - 1, n, choice);  //왼쪽만 정렬진행
			quick_sort(list, q + 1, right,n, choice); //른쪽만 정렬진행

		}
	}
}

//여기서까지 퀵 정렬, 라이브러리 퀵정렬/////////////////////

//여기서부터 기수 정렬 ///////////////////////////////////

#define MAX_QUEUE_SIZE 100
typedef int elementt;
typedef struct { // 큐 타입
	elementt  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType* q, elementt item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
elementt dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
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


//여기까지 기수 정렬 ////////////////////////////////////

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
		getchar();		// 엔터키 제거
		if (cmd == 'x') {
			printf("Exit...\n");
			return;
		}
		smenu();
		order_cmd = getchar();
		getchar();		// 엔터키 제거

		switch (cmd) {
		case 's':
			printf("selection sort with %s order", (order_cmd == '1' ? "오름" : "내림"));
			printf("\n");
			(order_cmd == '1') ? selection_sort(data, num_data) : selection_sort2(data, num_data);
			break;

		case 'i':
			printf("Insertion sort with %s order", (order_cmd == '1' ? "오름" : "내림"));
			printf("\n");
			insert_sort(data, num_data, order_cmd);
			break;

		case 'b':
			printf("Bubble sort with %s order", (order_cmd == '1' ? "오름" : "내림"));
			printf("\n");
			bubble_sort(data, num_data, order_cmd);
			break;

		case 'l':
			printf("Shell sort with %s order", (order_cmd == '1' ? "오름" : "내림"));
			printf("\n");
			n = num_data;
			(order_cmd == '1') ? shell_sort(data, num_data) : shell_sort2(data, num_data);
			break;

		case 'h':
			printf("Heap sort with %s order", (order_cmd == '1' ? "오름" : "내림"));
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
			printf("Merge sort with %s order", (order_cmd == '1' ? "오름" : "내림"));
			printf("\n");
			merge_sort(data, 0, num_data - 1, num_data, &cycle, order_cmd);
			break;

		case 'q':
			//#define stay num_data//값이 계속 바뀌어서 안되었던것 동적 멤버변수 보내는 것 고려
			printf("Quick sort with %s order", (order_cmd == '1' ? "오름" : "내림"));
			printf("\n");
			quick_sort(data, 0, num_data - 1, num_data, order_cmd);
			//printList(data, num_data);
			break;

		case 't':
			printf("[Library Functions] Quick sort with %s order", (order_cmd == '1' ? "오름" : "내림"));

			if (order_cmd == '1') {
				qsort(data, num_data, sizeof(int), compare);
			}
			else qsort(data, num_data, sizeof(int), compare2);

			printList(data, n);
			break;

		case 'r':
			printf("Radix sort with %s order", (order_cmd == '1' ? "오름" : "내림"));
			printf("\n");

			int digit = 0; int cyclee = 0;
			printf("자릿수를 입력하세요 -> ");
			if (scanf("%d", &digit) == 0) { printf("입력이 제대로 안되었습니다"); };

			(order_cmd == '1') ? radix_sort(data, num_data, digit, &cyclee) : radix_sort2(data, num_data, digit, &cyclee);
			
			break;
		}

		printf("\nOutput data:\n");		// sorted data
		for (i = 0; i < num_data; i++)
			printf("%d ", data[i]);
		printf("\n");
	}
}