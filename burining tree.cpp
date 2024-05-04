class Solution {
  public:
  Node* mapAndFind(Node* root,map<Node*,Node*> &nodeToParent,int target){
      queue<Node*>q;
      q.push(root);
        nodeToParent[root] = NULL;
       Node* ans = NULL;
       while(!q.empty()){
            Node* f = q.front();
            q.pop();
          if(f->data == target){
                ans = f;
            }
            if(f->left){
                nodeToParent[f->left] = f;
                q.push(f->left);
            }
            if(f->right){
                nodeToParent[f->right] = f;
                q.push(f->right);
            }
        }
        return ans;
  }
    int solve(Node* root,map<Node*,Node*> &nodeToParent){
        int ans = 0;
        map<Node*,bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root] = 1;
        while(!q.empty()){
            bool flag = 0;
            int size = q.size();
            for(int i=0;i<size;i++){
            Node* front = q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
        } 
          if(front->right && !visited[front->right]){
        flag = 1;
         q.push(front->right);
      visited[front->right] = 1;
      } 
        if(nodeToParent[front] && !visited[nodeToParent[front]]){
       flag = 1;
        q.push(nodeToParent[front]);
       visited[nodeToParent[front]] = 1;
    }
     } 
        if(flag == 1){
           ans++;
             }
          } 
     return ans;
    }
      int minTime(Node* root, int target) 
   {
    map<Node*,Node*> nodeToParent;
    Node* findedNode = mapAndFind(root,nodeToParent,target);
    int ans = solve(findedNode,nodeToParent);
       return ans;
   }
};