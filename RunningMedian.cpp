#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct RNG
{
	int seed, a, b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
	int next() {
		int result = seed;
		seed = ((seed*(long long)a) + b) % 20090711;
		return result;
	}
};

//�� �����ϱ�
//���� ��Ʈ��尡 ��ü�� �ִ밪�� �Ǵ� Ʈ�������̴�.
//�ڽ��� ������ ������� �ʴ´� �� ��,���� ��Ұ���� ������ �ʴ´�
void push_heap(vector<int>& heap, int newValue);
void pop_heap(vector<int>& heap);
int RunningMedian(int n, RNG rng);

//���� ������ priority_queue�� ����Ѵ�
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		int arraySize, a_seed, b_seed;
		cin >> arraySize;
		cin >> a_seed;
		cin >> b_seed;
		RNG rngTemp(a_seed, b_seed);
		cout << RunningMedian(arraySize, rngTemp) << endl;
	}
	return 0;
}

void push_heap(vector<int>& heap, int newValue)
{
	//�ϴ� ���Ҹ� �� ���� �ִ´�
	heap.push_back(newValue);
	int index = heap.size() - 1;
	//�θ� ��庸�� ũ�� �ڸ��� �ٲ㳪����
	while (index > 0 && heap[(index - 1) / 2] < heap[index])
	{
		swap(heap[index], heap[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

void pop_heap(vector<int>& heap)
{
	//������ ��带 �� ���� ������
	heap[0] = heap.back();
	heap.pop_back();
	//���� ����
	int index = 0;
	while (true)
	{
		int left = index * 2 + 1, right = index * 2 + 2;
		if (left >= heap.size()) {
			break;
		}
		int next = index;
		//���� ���� ���Ұ� ��Ұ��� ������
		if (heap[next] < heap[left]) {
			next = left;
		}
		//������ ���Ұ� ��Ұ��� ������
		if (right < heap.size() && heap[next] < heap[right]) {
			next = right;
		}
		//��������
		if (next == index) {
			break;
		}
		swap(heap[index], heap[next]);
		index = next;
	}
}
//�־��� �迭�� ������ �ɰ��� �߰����� ã�ƺ���
int RunningMedian(int n, RNG rng)
{
	//priority queue�� ���� ������ ������ ����
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int result = 0;
	//�ִ����� �׻� ���Ұ� ���� ����
	//�ִ����� �ִ���Ҵ� �ּ����� �ּҿ��Һ��� �۴�
	for (int temp = 0; temp < n; temp++) {
		//���� ����
		if (maxHeap.size() == minHeap.size()) {
			maxHeap.push(rng.next());
		}
		else {
			minHeap.push(rng.next());
		}
		//���Ľ�Ų��
		if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
			int mintemp = minHeap.top(), maxtemp = maxHeap.top();
			minHeap.pop();
			maxHeap.pop();
			minHeap.push(maxtemp);
			maxHeap.push(mintemp);
		}
		result = (result + maxHeap.top()) % 20090711;
	}

	return result;
}
