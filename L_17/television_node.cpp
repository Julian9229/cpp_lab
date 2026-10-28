#include "television_node.h"
#include <iostream>

using namespace std;

TelevisionNode::TelevisionNode(double diagonal, const string& resolution, bool smart)
    : data(diagonal, resolution, smart) {
    cout << "[TelevisionNode] Constructor\n";
}

TelevisionNode::~TelevisionNode() {
    cout << "[TelevisionNode] Destructor\n";
}

void TelevisionNode::display() const {
    data.display();
}
