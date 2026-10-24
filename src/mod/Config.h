#pragma once

#include <string>
#include <string_view>

#include <pl/Config.hpp>

namespace clange_me {

struct ModConfig {
    int version = 1;
    bool enabled = true;
    bool syncDoors = true;
    bool syncTrapdoors = true;
    bool syncFenceGates = true;
};

nlohmann::json makeDefaultConfigJson();
nlohmann::json makeConfigSchemaJson();

} // namespace clange_me

template <> struct pl::config::Schema<clange_me::ModConfig> {
    static constexpr std::string_view title = "Double Door Sync Config";
    static constexpr std::string_view description = "Configure block synchronization.";

    static constexpr FieldSchema field(std::string_view name) {
        if (name == "version")
            return {.title = "Version", .readOnly = true};
        if (name == "enabled")
            return {.title = "Enabled", .description = "Enable or disable the plugin."};
        if (name == "syncDoors")
            return {.title = "Double Doors", .description = "Synchronize paired doors."};
        if (name == "syncTrapdoors")
            return {.title = "Double Trapdoors", .description = "Synchronize paired trapdoors."};
        if (name == "syncFenceGates")
            return {.title = "Double Fence Gates", .description = "Synchronize paired fence gates."};
        return {};
    }
};
