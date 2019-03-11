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

//힙 구현하기
//힙은 루트노드가 전체의 최대값이 되는 트리구조이다.
//자식의 정렬은 고려하지 않는다 즉 좌,우의 대소관계는 따지지 않는다
void push_heap(vector<int>& heap, int newValue);
void pop_heap(vector<int>& heap);
int RunningMedian(int n, RNG rng);

//힙의 일종인 priority_queue를 사용한다
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
	//일단 윈소를 맨 끝에 넣는다
	heap.push_back(newValue);
	int index = heap.size() - 1;
	//부모 노드보다 크면 자리를 바꿔나간다
	while (index > 0 && heap[(index - 1) / 2] < heap[index])
	{
		swap(heap[index], heap[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

void pop_heap(vector<int>& heap)
{
	//마지막 노드를 맨 위로 덮어씌운다
	heap[0] = heap.back();
	heap.pop_back();
	//그후 정렬
	int index = 0;
	while (true)
	{
		int left = index * 2 + 1, right = index * 2 + 2;
		if (left >= heap.size()) {
			break;
		}
		int next = index;
		//다음 왼쪽 원소가 대소관계 만족시
		if (heap[next] < heap[left]) {
			next = left;
		}
		//오른쪽 원소가 대소관계 만족시
		if (right < heap.size() && heap[next] < heap[right]) {
			next = right;
		}
		//끝났을시
		if (next == index) {
			break;
		}
		swap(heap[index], heap[next]);
		index = next;
	}
}
//주어진 배열을 반으로 쪼개서 중간값을 찾아보자
int RunningMedian(int n, RNG rng)
{
	//priority queue의 정렬 기준을 눈여겨 보자
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int result = 0;
	//최대힙에 항상 원소가 먼저 들어간다
	//최대힙의 최대원소는 최소힙의 최소원소보다 작다
	for (int temp = 0; temp < n; temp++) {
		//원소 대입
		if (maxHeap.size() == minHeap.size()) {
			maxHeap.push(rng.next());
		}
		else {
			minHeap.push(rng.next());
		}
		//정렬시킨다
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
