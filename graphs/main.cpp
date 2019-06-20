#include <iostream>
#include "classes.hpp"
#include <queue>
#include <vector>
#include <climits>
#include <string>

void dijkstras ( Graph & g, int src, int * dist, int * prv){
    PriorityQueue PQ(g.get_num_vertex());
    Vertex* vs = g.get_verticies();
    for(int i = src; i <g.get_num_vertex(); i++){
        dist[vs[i].get_id()] = INT_MAX;
        prv[vs[i].get_id()] = -1;
        PQ.enqueue(Ent(vs[i].get_id(), i)); 
    }
    Ent temp;
    dist[src] = 0;
    std::vector<std::vector<int>> recall(g.get_num_vertex());
    while(!PQ.isEmpty()){
        Vertex u = PQ.dequeue().id;
        std::vector<Edge> es = g.get_out_going_edges(u);
        Vertex v;
        for(unsigned int i = 0; i<es.size(); i++){
            v = es[i].get_dest();
            if(v.get_id()>=src&&dist[v.get_id()]>dist[u.get_id()]+es[i].get_weight()){
                dist[v.get_id()] = dist[u.get_id()] + es[i].get_weight();
                prv[v.get_id()] = u.get_id();
                recall[v.get_id()].push_back(es[i].get_src());
            } 
        }  
        std::cout<<u.get_id()<<'[';
        for(unsigned int j = 0; j<recall[u.get_id()].size(); j++){
            if(j==0){
                std::cout<<src<<'-';
            }
            else
                std::cout<<recall[u.get_id()][j]<<'-';
        }
        std::cout<<u.get_id()<<"]("<<dist[u.get_id()]<<')'<<std::endl;
    }
}


int main(int argc, char** argv){
    if(argc >3)
        return 0;
    Graph g = Graph(argv[2]);
    std::string stemp = argv[1];
    int temp3 = std::stoi(stemp);
    int* temp = new int[g.get_num_vertex()];
    int * temp2 = new int[g.get_num_edge()];
    dijkstras(g, temp3, temp, temp2);
    delete[] temp;
    delete[] temp2;
    return 0;
}
