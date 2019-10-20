#pragma once

#include "Component.h"
#include <SDL/SDL.h>
#include "Texture.h"

class SpriteComponent : public Component {
public:
	SpriteComponent(class Actor* inOwner, int inDrawOrder = 100);
	~SpriteComponent();

	virtual void Draw(class Shader* shader);
	virtual void SetTexture(class Texture* inTexture);

	inline int GetDrawOrder() const { return drawOrder; }
	inline int GetTextureWidth() const { return width; }
	inline int GetTextureHeight() const { return height; }

	inline bool GetVisible() const { return visible; }
	inline void SetVisible(const bool inVisible) { visible = inVisible; }

	TypeId GetType() const override { return TypeId::TSpriteComponent; }

	void LoadProperties(const rapidjson::Value& inObj) override;
	void SaveProperties(rapidjson::Document::AllocatorType& alloc,
		rapidjson::Value& inObj) const override;

protected:
	Texture* texture;

	int drawOrder;
	int width;
	int height;

	bool visible;
};
