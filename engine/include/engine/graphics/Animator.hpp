#pragma once
#include <vector>
#include <string>

namespace Engine::Graphics {

struct Frame {
    int u, v, width, height;
    float durationSeconds;
};

class AnimationClip {
public:
    AnimationClip(const std::string& name) : m_name(name) {}
    void AddFrame(Frame f) { m_frames.push_back(f); }

    const std::vector<Frame>& GetFrames() const { return m_frames; }
    const std::string& GetName() const { return m_name; }

private:
    std::string m_name;
    std::vector<Frame> m_frames;
};

class Animator {
public:
    void Play(AnimationClip clip);
    void Update(float deltaTime);
    Frame GetCurrentFrame() const;

private:
    AnimationClip m_currentClip = AnimationClip("empty");
    size_t m_currentFrameIndex = 0;
    float m_elapsedTime = 0.0f;
};

}
