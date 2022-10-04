#include <iostream>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

typedef pair<int,int> pii;

char room[1001][1001];
int dist[1001][1001];
int n, m; 
const int INF=123456789;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int bfs(vector <pii> sources){
  queue <pii> q;

  for(pii p : sources){
    q.push(p);
    dist[p.first][p.second] = 1;
  }

  while(!q.empty()){
    pii curr=q.front();
    q.pop();
    //cout << curr.first << " " << curr.second << endl;

    for(int i = 0; i < 4; i++){
      int new_row = curr.first + dx[i];
      int new_col = curr.second + dy[i];
      if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m){
        char neighb = room[new_row][new_col];
        //cout << neighb << endl;
        pii n; n.first = new_row; n.second = new_col;

        if(neighb == 'E') return dist[curr.first][curr.second]+1;
      
        else if(neighb == '.' && !dist[n.first][n.second]){
          dist[n.first][n.second] = dist[curr.first][curr.second]+1;
          q.push(n);
        }
      }
    }
  }
  return INF;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    cin >> n >> m;
    pii start, end, fire;
    vector <pii> fires;
    vector <pii> person;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> room[i][j];
        if(room[i][j] == 'F'){
          fire.first = i; fire.second = j;
          fires.push_back(fire);
        }
        else if(room[i][j] == 'S'){
          start.first = i; start.second = j;
          person.push_back(start);
        }
        else if(room[i][j] == 'E'){
          end.first = i; end.second = j;
        }
      }
    }

    int pers_dis = bfs(person);
    memset(dist, 0, 1001*1001*sizeof(int));
    int fire_dis = bfs(fires);
    memset(dist, 0, 1001*1001*sizeof(int));
    //cout << pers_dis << " " << fire_dis << endl;
    
    cout << (pers_dis < fire_dis ? 'Y' : 'N') << endl;
  }


}
