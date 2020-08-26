

void topologySort(){
 int result[SIZE]
 queue<int> q;
 
 for(int i=1; i<=n; i++){
   if(indegree[i] == 0) q.push(i);
  }
  
  // n개의 노드를 방문하면 됨
  for(int i=1; i<=n; i++){
    
    if(q.empty()) { // 모든 노드를 방문하기 전, 큐가 비었다면 사이클 발생
      cout << "Cycle";
      break;
    }
    
    int cur = q.front();
    q.pop();
    result[i] = cur;
    
    for(int j=0; j<graph[cur].size(); j++){
      int nxt = graph[cur][j];
      if(--indegree[nxt] == 0) q.push(nxt);
    }
    
    // 방문 순서대로 출력
    for(int i=1; i<=n; i++){
      cout << result[i] << " ";
    }
}
