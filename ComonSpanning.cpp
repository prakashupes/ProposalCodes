
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/two_graphs_common_spanning_trees.hpp>
#include <exception>
#include <vector>
#include<iostream>



using namespace std;

typedef
boost::adjacency_list
  <
    boost::vecS,         // OutEdgeList
    boost::vecS,         // VertexList
    boost::undirectedS,  // Directed
    boost::no_property,  // VertexProperties
    boost::no_property,  // EdgeProperties
    boost::no_property,  // GraphProperties
    boost::listS         // EdgeList
  >
Graph
;

typedef
boost::graph_traits<Graph>::vertex_descriptor
vertex_descriptor;

typedef
boost::graph_traits<Graph>::edge_descriptor
edge_descriptor;

typedef
boost::graph_traits<Graph>::vertex_iterator
vertex_iterator;

typedef
boost::graph_traits<Graph>::edge_iterator
edge_iterator;


int main(int argc, char **argv)
{
  Graph iG, vG;
  vector< edge_descriptor > iG_o;
  vector< edge_descriptor > vG_o;
/*
  iG_o.push_back(boost::add_edge(0, 3, iG).first);
  iG_o.push_back(boost::add_edge(0, 1, iG).first);
  iG_o.push_back(boost::add_edge(1, 2, iG).first);
  iG_o.push_back(boost::add_edge(2, 3, iG).first);
  iG_o.push_back(boost::add_edge(3, 4, iG).first);

   
  vG_o.push_back(boost::add_edge(0, 3, vG).first);
  vG_o.push_back(boost::add_edge(0, 1, vG).first);
  vG_o.push_back(boost::add_edge(1, 2, vG).first);
  vG_o.push_back(boost::add_edge(2, 3, vG).first);
  vG_o.push_back(boost::add_edge(2, 4, vG).first);

*/
iG_o.push_back(boost::add_edge(0, 1, iG).first);

vG_o.push_back(boost::add_edge(0, 0, vG).first);
vG_o.push_back(boost::add_edge(0, 1, vG).first);
  cout<<"Iterate over iG_o"<<endl;
  
  for(edge_descriptor i: iG_o)
  {
  	cout<<i<<" ";
  }
  cout<<endl;
  cout<<"Iterate over iG_o"<<endl;
  for(auto i: vG_o)
  {
  	cout<<i<<" ";
  }
  vector<bool> inL(iG_o.size(), false);

  std::vector< std::vector<bool> > coll;
  boost::tree_collector<
      std::vector< std::vector<bool> >,
      std::vector<bool>
    > tree_collector(coll);
  boost::two_graphs_common_spanning_trees
    (
      iG,
      
      vG,
     
      tree_collector,
      inL
    );
/*
//Try these one bye one
boost::two_graphs_common_spanning_trees
    (
      vG,
      
      vG,
     
      tree_collector,
      inL
    );


boost::two_graphs_common_spanning_trees
    (
      iG,
      
      iG,
     
      tree_collector,
      inL
    );

*/

  cout<<"\nReading trees"<<endl;
  for(auto i: coll)
  {
  	for(auto j: i)
  	{
  		cout<<j<<" ";
  	}
  	cout<<endl;
  
  }


  return 0;
}
