#include "mod/MyMod.h"

#include <filesystem>

#include <pl/Mod.hpp>

namespace clange_me {

ClangeMeMod &ClangeMeMod::instance() {
    static ClangeMeMod instance;
    return instance;
}

ClangeMeMod::ClangeMeMod() : mSelf(*ll::mod::NativeMod::current()) {}

bool ClangeMeMod::load() {
    auto &self = getSelf();
    self.getLogger().debug("Loading Double Door Sync...");

    std::error_code ec;
    std::filesystem::create_directories(self.getDataDir(), ec);
    if (ec) {
        self.getLogger().error(
            "Failed to create data directory: {}", ec.message()
        );
        return false;
    }

    std::filesystem::create_directories(self.getConfigDir(), ec);
    if (ec) {
        self.getLogger().error(
            "Failed to create config directory: {}", ec.message()
        );
        return false;
    }

    mConfigFile.emplace();
    if (!mConfigFile->load()) {
        self.getLogger().warn("Failed to load config");
        return false;
    }

    mConfig = mConfigFile->value();

    self.getLogger().info("Double Door Sync loaded");
    return true;
}

bool ClangeMeMod::enable() {
    auto &self = getSelf();
    self.getLogger().debug("Enabling Double Door Sync...");

    if (!mConfig.enabled) {
        self.getLogger().info("Double Door Sync is disabled in config");
        return true;
    }

    self.getLogger().info(
        "Options: doors={}, trapdoors={}, fence_gates={}",
        mConfig.syncDoors,
        mConfig.syncTrapdoors,
        mConfig.syncFenceGates
    );

    // Block interaction synchronization will be implemented here.
    return true;
}

bool ClangeMeMod::disable() {
    getSelf().getLogger().debug("Disabling Double Door Sync...");
    return true;
}

bool ClangeMeMod::unload() {
    getSelf().getLogger().debug("Unloading Double Door Sync...");
    mConfigFile.reset();
    return true;
}

} // namespace clange_me
