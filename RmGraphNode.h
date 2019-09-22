#pragma once

#include <vector>
#include <string>

#include "RMGen.h"


/*****************************************************
 ****************** Default Graph node ***************
 *****************************************************/

class RmGraphNode
{
public:
	explicit RmGraphNode(const std::string& newName);
	~RmGraphNode();

	bool hasFlag(const std::string& flag) const;
	void addFlag(std::string&& newFlag);

	/**
	 * @return Vec3bool with mirroring capabilities.
	 */
	auto getMirroring() const;


	auto& getChildren();

private:
	/**
	 * The name of the current object
	 */
	std::string m_objectName;

	/**
	 * If true, this node should excavate his siblings, otherwise it should be additive
	 */
	bool m_subtract;

	/**
	 * Smoothing factor
	 */
	Scalar m_smooth;

	/**
	 * Save if the elements should be mirrored along the X, Y or Z
	 * as [x:bool, y:bool, z:bool]
	 */
	Vec3bool m_mirroring;

	std::vector<std::string> m_flags;
	std::vector<RmGraphNode*> m_children;
};

/*****************************************************
 ****************** Default Graph node ***************
 *****************************************************/

enum class ShapeType : char
{
	Sphere = 0,	//Vec3+f
	Ellipse,	//Vec3+Vec3
	Stick,		//Vec3+f+Vec3+f

};

struct ShapeData
{
	ShapeType m_type;
	union
	{
		struct Sphere
		{
			Vec3 m_pos;
			Scalar m_rad;
		};
		struct Ellipse
		{
			Vec3 m_pos;
			Vec3 m_size;
		};
		struct Stick
		{
			Vec3 m_posA;
			Scalar m_radA;
			Vec3 m_posB;
			Scalar m_radB;
		};
	};
};

class RmGraphLeaf: public RmGraphNode
{
public:
	RmGraphLeaf();
	~RmGraphLeaf();

	

};

