#include "gameasset.hpp"

void AssetManager::UnloadAllAssets() {
    AssetManager& instance = AssetManager::GetInstance();
    std::vector<IGameAsset*>* gameAssets = instance.m_gameAssets;

    for (IGameAsset* iGameAsset : *gameAssets) {
        delete iGameAsset;
    }

    delete gameAssets;
    gameAssets = nullptr;
}
