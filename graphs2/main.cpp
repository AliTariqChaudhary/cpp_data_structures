#include <iostream>
#include "classes.hpp"
#include <queue>

struct SetNode{
    SetNode* parent;
    int id;
    int rank;
    int size;
    SetNode()
    :parent(this), id(0), rank(0), size(0){}
};

struct DisjoinedSet{
    int count;
    SetNode* nodes;
    DisjoinedSet(int cnt)
    :count(cnt), nodes(new SetNode[cnt]){}
    void Make(int id){
        SetNode &n = nodes[id];
        n.parent = & n;
        n.rank = 0;
        n.size = 1;
    }
    SetNode* Find(SetNode* sn){
        if(sn->parent != sn)
            sn->parent = Find(sn->parent);
        return sn->parent;
    }
    SetNode* Find(int id){
        SetNode &n = nodes[id];
        return Find(&n);
    }
    void Union(int id1, int id2){
        SetNode* root1 = Find(id1);
        SetNode* root2 = Find(id2);
        if(root1 == root2)
            return;
        if(root1->size < root2->size)
            std::swap(root1, root2);
        root2->parent = root1;
        root1->size += root2->size;
    }
    ~DisjoinedSet(){
        delete[] nodes;
    }
};

void kruskals(const Graph& g){
    int weight = 0;
    int count = 0;
    DisjoinedSet ds  = DisjoinedSet(g.get_num_vertex());
    std::vector<Edge> answer;
    std::vector<Edge> edges = g.get_edges();
    std::sort(edges.begin(), edges.end(), [](Edge e1, Edge e2){
        return e1.get_weight() < e2.get_weight();
    });
    for(int i =0; i<g.get_num_vertex(); i++){
        ds.Make(i);
    }
    for(int i = 0; i<g.get_num_edge(); i++){
        if(ds.Find(edges[i].get_src()) != ds.Find(edges[i].get_dest())){
            answer.push_back(edges[i]);
            ds.Union(edges[i].get_src(),edges[i].get_dest());
            count ++;
            weight+=edges[i].get_weight();
        }
    } 
    std::cout<<weight<<std::endl;
    for(int i = 0; i<count; i++){
        answer[i].print(std::cout);
    }

}

int main(int argc, char** argv){
    if(argc >2)
        return 0;
    Graph g = Graph(argv[1]);
    kruskals(g);
    return 0;
}
