#include "RmGraphNode.h"

#include <algorithm>


RmGraphNode::RmGraphNode(const std::string& newName):
m_objectName(newName),
m_smooth(0.0),
m_mirroring{ false, false, false },
m_flags{},
m_children{}
{
}

RmGraphNode::~RmGraphNode() = default;

bool RmGraphNode::hasFlag(const std::string& flag) const
{
	return m_flags.end() != std::find(m_flags.begin(), m_flags.end(), flag);
}

void RmGraphNode::addFlag(std::string&& newFlag)
{
	if (!hasFlag(newFlag))
		m_flags.push_back(newFlag);
}

auto RmGraphNode::getMirroring() const
{
	return m_mirroring;
}

auto& RmGraphNode::getChildren()
{
	return m_children;
}
