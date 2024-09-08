#include "engine/scripting/ScriptEngine.hpp"
#include "engine/core/Logger.hpp"

namespace Engine::Scripting {

void ScriptEngine::SetVariable(const std::string& name, float value) {
    m_variables[name] = value;
}

float ScriptEngine::GetVariable(const std::string& name) {
    auto it = m_variables.find(name);
    return (it != m_variables.end()) ? it->second : 0.0f;
}

void ScriptEngine::Execute(const std::string& scriptCode) {
    Core::Logger::Info("Executing Script code: " + scriptCode);
}

}
