#include "../../include/Localisation/LocalisationManager.h"
#include <fstream>
#include <sstream>


LocalisationManager& LocalisationManager::GetInstance() {
    static LocalisationManager instance;
    return instance;
}

bool LocalisationManager::LoadLanguage(const std::string& langCode, const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) return false;
    std::unordered_map<std::string, std::string> langMap;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        size_t eqPos = line.find('=');
        if (eqPos == std::string::npos) continue;
        std::string key = line.substr(0, eqPos);
        std::string value = line.substr(eqPos + 1);
        langMap[key] = value;
    }
    languages[langCode] = std::move(langMap);
    return true;
}

const std::string& LocalisationManager::GetString(const std::string& key) const {
    static std::string empty;
    auto langIt = languages.find(currentLanguage);
    if (langIt != languages.end()) {
        auto strIt = langIt->second.find(key);
        if (strIt != langIt->second.end()) {
            return strIt->second;
        }
    }
    return empty;
}

void LocalisationManager::SetCurrentLanguage(const std::string& langCode) {
    currentLanguage = langCode;
}
