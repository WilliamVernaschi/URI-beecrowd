#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector <vector <string>> grafo;
queue <string> inqueue;
int dist[65];
bool visited[65];

int c2i(string &s){ // code to integer
  return (s[0] - 'a' + (8 - (s[1] - '0'))*8);
}

vector <string> all_possibs(string &cod){
  char dx[8] = {1, -1, 1, -1, 2, -2, 2, -2};
  char dy[8] = {2, 2, -2, -2, 1, 1, -1, -1};

  vector <string> x;

  for(int i = 0; i < 8; i++){
    if((int)cod[0] + dx[i] >= 'a' && (int)cod[0] + dx[i] <= 'h' &&
        (int)cod[1] + dy[i] >= '1' && (int)cod[1] + dy[i] <= '8'){

      string str = "";
      str += cod[0]+dx[i];
      str += cod[1]+dy[i];

      x.push_back(str);
    }
  }

  return x;

}


int bfs(string from, string to){
  if(from == to) return 0;

  inqueue.push(from);
  dist[c2i(from)] = 0;
  int out=-1;

  while(!inqueue.empty()){
    string processing = inqueue.front(); inqueue.pop();
    for(string neighbour : grafo[c2i(processing)]){
      if(visited[c2i(neighbour)]) continue;
      visited[c2i(neighbour)] = true;
      inqueue.push(neighbour);
      dist[c2i(neighbour)] = dist[c2i(processing)] + 1;
      if(neighbour == to)
        out = dist[c2i(neighbour)];
    }
  }
  return out;
}

int main(){

  grafo.resize(64);

  for(char i = '8'; i > '0'; i--){
    for(char c = 'a'; c <= 'h'; c++){
      string place = "";
      place += c;
      place += i;
      //cout << place << " = " << c2i(place) << endl;
      for(string x : all_possibs(place)){
        grafo[c2i(place)].push_back(x);
        grafo[c2i(x)].push_back(place);
      }
    }
  }

  string from, to;
  while(cin >> from >> to){
    cout << "To get from " << from << " to " << to << " takes " << bfs(from, to) << " knight moves." << endl;

    memset(visited, false, 65*sizeof(bool));
    memset(dist, 0, 65*sizeof(int));
  }
  

  return 0;
}
