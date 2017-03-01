//
//  dgraph.hpp
//  template_digraph
//
//  Created by Nicholas Rogers on 6/20/16.
//  Copyright © 2016 Nicholas Rogers. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cassert>

template <class T>
class graph
{
public:
    
    graph()
    {
        _pointer_vec = std::vector<T*>();
        _vertices_pointer_map = std::unordered_map<T, T*>();
        _edge_data = std::unordered_map<std::string, std::unordered_map<T*, std::unordered_set<T*>>>();
    }
    
    ~graph()
    {
        for (auto e: _pointer_vec)
            delete e;
    }
    
    void add_vertex(T & target)
    {
        T *newData = new T(target);
        _pointer_vec.push_back(newData);
        _vertices_pointer_map[target] = newData;
    }
    
    void add_edge(T & a, T & b, std::string & type)
    {
        if (_vertices_pointer_map.find(a) == _vertices_pointer_map.end())
            add_vertex(a);
        if (_vertices_pointer_map.find(b) == _vertices_pointer_map.end())
            add_vertex(b);
        
        T *pointerA = _vertices_pointer_map[a];
        T *pointerB = _vertices_pointer_map[b];
        
//        std::cout << "Created " << type << " edge: " << a << " ( " << pointerA << " ) " << "-> " << b << " ( " << pointerB << " ) " << std::endl;
        
        _edge_data[type][pointerA].insert(pointerB);
    }
    
    std::unordered_set<T> neighbors(T & target, std::string edgeType = "") const
    {
        assert(_vertices_pointer_map.find(target) != _vertices_pointer_map.end());
        
        std::unordered_set<T> neighborValues;
        T *targetPointer = _vertices_pointer_map.at(target);
        
        if (edgeType.empty()) // Find all neighbors for all edges
        {
            for (auto const & edge_types: _edge_data)
            {
                std::unordered_map<T*, std::unordered_set<T*>> edges = edge_types.second;
                if (edges.find(targetPointer) != edges.end())
                {
                    for (auto const & vertices : edges[targetPointer])
                    {
                        neighborValues.insert(*vertices);
                    }
                }
            }
        }
        else // Find neighbors for specified edges
        {
            if (_edge_data.find(edgeType) == _edge_data.end()) { return neighborValues; }
            
            std::unordered_map<T*, std::unordered_set<T*>> specified_edge = _edge_data.at(edgeType);
            
            std::cout << specified_edge.size() << std::endl;
            
            for (auto const & e: specified_edge)
            {
                std::cout << *e.first << std::endl;
            }
            
//            for (auto const & edge_types: _edge_data)
//            {
//                std::unordered_map<T*, std::unordered_set<T*>> edges = edge_types.second;
//                if (edges.find(targetPointer) != edges.end())
//                {
//                    for (auto const & vertices : edges[targetPointer])
//                    {
//                        neighborValues.insert(*vertices);
//                    }
//                }
//            }
        }
        
        return neighborValues;
    }
    
private:
    
    std::vector<T*>                                                                     _pointer_vec;
    std::unordered_map<T, T*>                                                           _vertices_pointer_map;
    std::unordered_map<std::string, std::unordered_map<T*, std::unordered_set<T*>>>     _edge_data;
    
};

#endif /* dgraph_hpp */
