#include <ostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

class Edge{
    private:
    int src;
    int dest;
    int weight;
    public:
    int get_weight() const{
        return weight;
    }
    int get_src() const{
        return src;
    }
    int get_dest() const{
        return dest;
    }
    Edge(int s, int d, int w)
    :src(s), dest(d), weight(w){}
    Edge reverse(){
        return Edge(dest, src, weight);
    }
    void print(std::ostream& out){
        out<<"["<<src<<"-"<<dest<<"] "<<"("<<weight<<")"<<std::endl;
    }
};
class Vertex{
    private:
    int id;
    std::vector<Edge> edges;
    public:
    Vertex(int i = 0)
    :id(i){}
    void add_edge(const Edge& e){
        edges.push_back (e);
    }
    void change_id(int i){
        id = i;
    }
    std::vector<Edge>& get_edges(){
        return edges;
    }
    void print(std::ostream& out){
        for(unsigned int i = 0; i<edges.size(); i++){
            edges[i].print(out);
        }
    }
};
class Graph{
    private:
    Vertex* verticies;
    int num_vertex;
    int num_edge = 0;
    std::vector<Edge> edges;
    public:
    int get_num_edge() const{
        return num_edge;
    }
    int get_num_vertex() const{
        return num_vertex;
    }
    Vertex* get_verticies() const{
        return verticies;
    }
    std::vector<Edge> get_edges() const{
        return edges;
    }
    Graph(std::string file_name){
        std::ifstream inp;
        inp.open(file_name);
        std::string temp = "";
        std::getline(inp, temp);
        num_vertex = std::stoi(temp);
        verticies = new Vertex[num_vertex];
        for(int i = 0; i<num_vertex; i++){
            verticies[i] = Vertex(i);
        }
        int count = 0;
        std::string wrd = "";
        std::string temp1 = "";
        std::string temp2 = "";
        std::string temp3 = "";
        while(std::getline(inp,temp)){
            for(unsigned int i = 0; i<temp.length(); i++){
                    if(temp[i]== ' '){
                        if(count==0){
                            temp1 = wrd;
                            wrd = "";
                        }
                        else if(count ==1){
                            temp2 = wrd;
                            wrd = "";
                        }
                        count++;
                    }
                    else
                        wrd+=temp[i]; 
            }
            temp3 = wrd;
            wrd = "";  
            num_edge++;
            count = 0;
            verticies[std::stoi(temp1)].add_edge(Edge(std::stoi(temp1), std::stoi(temp2), std::stoi(temp3)));
            edges.push_back(Edge(std::stoi(temp1), std::stoi(temp2), std::stoi(temp3)));
        }
    }
    void add_edge(int src, int dest, int w){
        verticies[src].add_edge(Edge(src, dest, w));
    }
    void print(std::ostream& out){
        for(int i = 0; i<num_vertex; i++)
            verticies[i].print(out);
    }
    ~Graph(){
        delete[] verticies;
    }
};
