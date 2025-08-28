#ifndef PROJECT2A_LOCALISATION_MANAGER_H
#define PROJECT2A_LOCALISATION_MANAGER_H

#include <string>
#include <unordered_map>

class LocalisationManager {
public:
    static LocalisationManager& GetInstance();
    bool LoadLanguage(const std::string& langCode, const std::string& filePath);
    const std::string& GetString(const std::string& key) const;
    void SetCurrentLanguage(const std::string& langCode);

private:
    LocalisationManager() = default;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> languages;
    std::string currentLanguage;
};

#endif
