#pragma once

#include "DiscordESDAction.h"

class DeafenOffAction final : public DiscordESDAction {
 public:
  using DiscordESDAction::DiscordESDAction;
  static const std::string ACTION_ID;
  virtual std::string GetActionID() const override { return ACTION_ID; }

  virtual void KeyUp(std::shared_ptr<DiscordClient> client) override {
    client->setIsDeafened(false);
  }

  virtual int GetDesiredState(const DiscordClient::State& state) override {
      return state.isDeafened ? 0 : 1;
  }
};