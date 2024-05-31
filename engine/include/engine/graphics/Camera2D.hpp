#pragma once

namespace Engine::Graphics {

class Camera2D {
public:
    Camera2D(float width, float height) : m_width(width), m_height(height) {}

    void SetPosition(float x, float y) { m_posX = x; m_posY = y; }
    void SetZoom(float zoom) { m_zoom = zoom; }

    float GetX() const { return m_posX; }
    float GetY() const { return m_posY; }
    float GetZoom() const { return m_zoom; }

private:
    float m_posX = 0.0f;
    float m_posY = 0.0f;
    float m_zoom = 1.0f;
    float m_width, m_height;
};

}
