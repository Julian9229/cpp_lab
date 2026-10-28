#include "list_node.h"

ListNode::ListNode()
    : data(), next(nullptr) {}

ListNode::ListNode(const Television& value)
    : data(value), next(nullptr) {}

ListNode::~ListNode() {}
