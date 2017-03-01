//
//  main.cpp
//  template_digraph
//
//  Created by Nicholas Rogers on 6/20/16.
//  Copyright © 2016 Nicholas Rogers. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

#include "graph.hpp"

int main(int argc, const char * argv[])
{
//    std::unordered_map<int, int*> pointer_map;
//    std::vector<int*> pointer_vec;
//    
//    int *i = new int(7);
//    int *o = new int(11);
//    int *u = new int(13);
//    
//    pointer_map[*i] = i;
//    pointer_map[*o] = o;
//    pointer_map[*u] = u;
//    
//    pointer_vec.push_back(i);
//    pointer_vec.push_back(o);
//    pointer_vec.push_back(u);
//    
//    for (auto e: pointer_vec)
//        std::cout << *e << std::endl;
//    
//    for (auto e: pointer_vec)
//        delete e;
//    
//    delete i;
//    delete o;
//    delete u;
    
    auto *g = new graph<std::string>();
    
    std::string name1("Nick");
    std::string name2("Steve");
    std::string lastName1("Rogers");
    std::string lastName2("Stevens");
    std::string friendsEdge("friends");
    std::string lastNameEdge("lastName");
    
    g->add_vertex(name1);
    g->add_edge(name1, name2, friendsEdge);
    g->add_edge(name2, name1, friendsEdge);
    g->add_edge(name1, lastName1, lastNameEdge);
    g->add_edge(name2, lastName2, lastNameEdge);
    
    auto neighbors = g->neighbors(name2, lastNameEdge);
    
    for (auto e: neighbors)
        std::cout << e << std::endl;
    
    delete g;
    
    return 0;
}
