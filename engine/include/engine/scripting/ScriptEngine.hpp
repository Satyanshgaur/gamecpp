#pragma once
#include <string>
#include <unordered_map>

namespace Engine::Scripting {

class ScriptEngine {
public:
    void SetVariable(const std::string& name, float value);
    float GetVariable(const std::string& name);
    void Execute(const std::string& scriptCode);

private:
    std::unordered_map<std::string, float> m_variables;
};

}
