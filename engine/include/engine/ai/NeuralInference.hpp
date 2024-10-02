#pragma once
#include <vector>

namespace Engine::AI {

class NeuralInferenceRuntime {
public:
    NeuralInferenceRuntime(size_t inputSize, size_t outputSize);

    std::vector<float> Predict(const std::vector<float>& input);

private:
    std::vector<std::vector<float>> m_weights;
};

}
