# Heap Algorithm

## What is Heap?

 - **Heap**: 완전 이진 트리의 일종으로 부모 노드와 자식 노드간 대소 관계가 항상 성립하는 자료구조
 - **Max Heap**: 부모 노드가 자식 노드 보다 항상 큰 구조
 - **Min Heap**: 자식 노드가 부모 노드 보다 항상 큰 구조
 
 
## Implement

 - ** Priority Queue** 사용
 - priority_queue<int, vector<int>, less<int> > pq; // max heap
 - priority_queue<int, vector<int>, greater<int> > pq; // min heap
 
 ``` c++
  priority_queue<int, vector<int>, less<int> > max_pq;
  priority_queue<int, vector<int>, greater<int> > min_pq;
  
  max_pq.push(4);  min_pq.push(4);
  max_pq.push(2);  min_pq.push(2);
  max_pq.push(3);  min_pq.push(3);
  max_pq.push(5);  min_pq.push(5);
  
  // print top of heap
  cout << max_pq.top() << "\n";
  cout << min_pq.top() << "\n";
  
  // print all element of heap
  while(!max_pq.empty()){  // or min_pq
    cout << max_pq.top() << "\n";
    max_pq.pop();
  }
```
