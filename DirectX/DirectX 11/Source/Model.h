#pragma once

#include "stdafx.h"
#include "Object.h"
#include <filesystem>

class Model final : public Object
{
public:
	[[nodiscard]] bool Initialize(struct ID3D11Device* device,
		const std::filesystem::path& moelPath, const std::filesystem::path texturePaths[2]);

	void ReadyToRender(struct ID3D11DeviceContext* context);
	void Release() noexcept;

	class TextureArray* GetTextures() const noexcept { return textures; }
	UINT GetVertexCount() const noexcept { return vertexCount; }
	UINT GetIndexCount() const noexcept { return indexCount; }

private:
	bool InitBuffer(ID3D11Device* device);
	bool LoadModel(const std::filesystem::path& path);
	bool LoadTextures(ID3D11Device* device, const std::filesystem::path paths[2]);

private:
	struct ID3D11Buffer* vertexBuffer = nullptr;
	ID3D11Buffer* indexBuffer = nullptr;

	struct ModelType* model = nullptr;
	TextureArray* textures = nullptr;
	
	UINT vertexCount = 0u, indexCount = 0u;
};
