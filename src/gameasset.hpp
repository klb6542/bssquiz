#pragma once
#include <iostream>
#include <vector>

template <typename T>
class GameAsset;

class IGameAsset {
    public:
        virtual ~IGameAsset() = default;
        virtual void Unload() = 0;

};

class AssetManager {
    public:
        static AssetManager& GetInstance() {
            static AssetManager instance;
            return instance;
        }

        template <typename T>
        void AddAsset(GameAsset<T>* gameAsset);

        void UnloadAllAssets();
    private:
        AssetManager() {
            m_gameAssets = new std::vector<IGameAsset*>();
        }

        ~AssetManager() = default;
        std::vector<IGameAsset*>* m_gameAssets;
};

template <typename T>
void AssetManager::AddAsset(GameAsset<T>* gameAsset) {
    m_gameAssets->push_back(gameAsset);
}

template <typename T>
class GameAsset : public IGameAsset {
    public:
      GameAsset(const GameAsset&) = delete;
      GameAsset(GameAsset&&) = delete;
      GameAsset &operator=(const GameAsset&) = delete;
      GameAsset &operator=(GameAsset&&) = delete;

      GameAsset(const T& asset, void(*unload)(T));
      T GetAsset();
    private:
        void Unload();
        T m_asset;
        void(*m_unload)(T);
};

template <typename T>
GameAsset<T>::GameAsset(const T& asset, void(*unload)(T)) : m_asset(asset), m_unload(unload) {
    AssetManager::GetInstance().AddAsset(this);
}

template <typename T>
T GameAsset<T>::GetAsset() {
    return this->m_asset;
}

template <typename T>
void GameAsset<T>::Unload() {
    std::cout << "Unloaded " << typeid(this->m_asset).name() << "\n";
    this->m_unload(this->m_asset);
    delete this;
}

using s_GameAsset = GameAsset<int>;
