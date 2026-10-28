#ifndef TELEVISION_NODE_H
#define TELEVISION_NODE_H

#include "television.h"
#include <memory>

class TelevisionNode {
public:
    Television data;
    std::shared_ptr<TelevisionNode> next;
    std::weak_ptr<TelevisionNode> prev;

    TelevisionNode(double diagonal, const std::string& resolution, bool smart);
    ~TelevisionNode();

    void display() const;
};

#endif
