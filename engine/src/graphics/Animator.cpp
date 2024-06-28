#include "engine/graphics/Animator.hpp"

namespace Engine::Graphics {

void Animator::Play(AnimationClip clip) {
    m_currentClip = clip;
    m_currentFrameIndex = 0;
    m_elapsedTime = 0.0f;
}

void Animator::Update(float deltaTime) {
    const auto& frames = m_currentClip.GetFrames();
    if (frames.empty()) return;

    m_elapsedTime += deltaTime;
    if (m_elapsedTime >= frames[m_currentFrameIndex].durationSeconds) {
        m_elapsedTime = 0.0f;
        m_currentFrameIndex = (m_currentFrameIndex + 1) % frames.size();
    }
}

Frame Animator::GetCurrentFrame() const {
    const auto& frames = m_currentClip.GetFrames();
    if (frames.empty()) return Frame{0, 0, 0, 0, 0.0f};
    return frames[m_currentFrameIndex];
}

}
