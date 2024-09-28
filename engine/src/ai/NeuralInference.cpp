#include "engine/ai/NeuralInference.hpp"

namespace Engine::AI {

NeuralInferenceRuntime::NeuralInferenceRuntime(size_t inputSize, size_t outputSize) {
    m_weights.resize(outputSize, std::vector<float>(inputSize, 0.5f));
}

std::vector<float> NeuralInferenceRuntime::Predict(const std::vector<float>& input) {
    std::vector<float> output(m_weights.size(), 0.0f);
    for (size_t i = 0; i < m_weights.size(); ++i) {
        for (size_t j = 0; j < input.size(); ++j) {
            output[i] += m_weights[i][j] * input[j];
        }
    }
    return output;
}

}
