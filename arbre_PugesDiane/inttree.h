#ifndef INTTREE_H
#define INTTREE_H

#include <vector>

// Node of a tree containing an integer at each node
class IntTree {
    // Node information
    int data;
    // Sequence of sons (empty if none)
    std::vector<IntTree*> sons;
public:
    // Create a node with given information
    IntTree(int d){
        data=d;
        sons.erase(sons.begin(),sons.end());
    };
    // Destruct a node and all its descendants
    ~IntTree(){
        data=0;
        sons.erase(sons.begin(),sons.end());
    };
    // Return information of this node
    int getData(){
        return data;
    };
    // Set information of this node
    void setData(int d){
        data=d;
    };
    // Return the number of sons of this node
    int nbSons(){
        return sons.size();
    };
    // Return the son at position pos, if any (considering left-most son is at position 0)
    IntTree* getSon(int pos){
        return sons[pos];
    };
    // Replace the exisiting son at position pos with newSon (left-most son at position 0)
    void setSon(int pos, IntTree* newSon){
        sons[pos] = newSon;
    };
    // Add newSon as supplementary right-most son of this node
    void addAsLastSon(IntTree* newSon){
        sons.push_back(newSon);
    };
    // Remove right-most son of this node
    void removeLastSon(){
        sons.pop_back();
    };
};


#endif // INTTREE_H
