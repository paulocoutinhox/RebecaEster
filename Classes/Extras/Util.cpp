#include "Util.h"

USING_NS_CC;

void Util::autoHeightForWidth(Node *node, float width)
{
    auto nodeRatio = node->getContentSize().width / node->getContentSize().height;
    auto nodeWidth = width;
    auto nodeHeight = nodeWidth / nodeRatio;
    
    node->setContentSize(Size(nodeWidth, nodeHeight));
}
