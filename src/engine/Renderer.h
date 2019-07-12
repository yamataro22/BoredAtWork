#pragma once

#include "GameInformer.hpp"
#include "Renderable.hpp"
#include "Shader.hpp"

#include <list>
#include <memory>
#include <string>

class Renderer : public GameInformer
{
public:
    explicit Renderer();
    ~Renderer();

    void defineObject(const Renderable& object) override;

    void render();

private:
    unsigned m_vertexArrayObjectID;

    std::list<const Renderable&> m_objectList;
    std::unique_ptr<Shader> m_shader;

    bool initGLEW();
    bool initDevIL();
};
