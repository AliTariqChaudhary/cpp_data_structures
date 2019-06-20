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
    Edge(int s=0, int d=0, int w=0)
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
    int get_id(){
        return id;
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
    std::vector<Edge> get_out_going_edges(Vertex v){
        std::vector<Edge> answer;
        for(unsigned int i = 0; i<edges.size();i++){
            if(edges[i].get_src() == v.get_id())
                answer.push_back(edges[i]);
        }
        return answer;
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

struct Ent{
  int id;
  int weight;
  Ent(int i=0, int w=0)
  :id(i), weight(w){}
};
class PriorityQueue{
    private:
    Ent * buf;
    int capacity;
    int size;
    public:
    PriorityQueue(int cap)
    :capacity(cap){
        buf = new Ent[cap];
        size = 0;
    }
    void sift_up(int toMove){
        if( parent(toMove) != -1 && buf[parent(toMove)].weight > buf[toMove].weight){
            swap(toMove, parent(toMove));
            sift_up(toMove);
        }
    }
    void swapDown(){
        for(int i = 0; i <size-1; i++){
            swap(i,i+1);
        }
    }
    void swap(int one, int two){
        Ent temp = buf[one];
        buf[one] = buf[two];
        buf[two] = temp;
    }
    void enqueue(Ent toAdd){
        buf[size] = toAdd;
        size++;
        sift_up(size-1);

    }
    int peek(){
        return buf[0].id;
    }
    Ent dequeue(){
        Ent temp = buf[0];
        buf[0] = buf[size-1];
        size--;
        swapDown();
        return temp;
    }
    int leftChild(int i){
        return 2*i+1;
    }
    int rightChild(int i){
        return 2*i +2;
    }
    int parent(int i){
        if(i == 0)
            return -1;
        else
            return (i-1)/2;
    }
    void print(){
        for(int i = 0; i <size; i++){
            std::cout<<buf[i].id<<"  "<<buf[i].weight<<std::endl;
        }
    }
    bool isEmpty(){
        return size ==0;
    }
    ~PriorityQueue(){
        delete[] buf;
    }
};
