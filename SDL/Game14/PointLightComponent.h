#pragma once

#include "Component.h"
#include "Math.h"

class PointLightComponent : public Component {
public:
	PointLightComponent(Actor* inOwner);
	~PointLightComponent();

	void Draw(class Shader* shader, class Mesh* mesh);

	inline Vector3 GetDiffuseColor() const { return diffuseColor; }
	inline void SetDiffuseColor(const Vector3& inDiffuseColor) { diffuseColor = inDiffuseColor; }
	
	inline float GetInnerRadius() const { return innerRadius; }
	inline void SetInnerRadius(const float inInnerRadius) { innerRadius = inInnerRadius; }
	
	inline float GetOuterRadius() const { return outerRadius; }
	inline void SetOuterRadius(const float inOuterRadius) { outerRadius = inOuterRadius; }

	TypeId GetType() const override { return TypeId::TPointLightComponent; }

	void LoadProperties(const rapidjson::Value& inObj) override;
	void SaveProperties(rapidjson::Document::AllocatorType& alloc,
		rapidjson::Value& inObj) const override;

private:
	Vector3 diffuseColor;
	float innerRadius;
	float outerRadius;
};