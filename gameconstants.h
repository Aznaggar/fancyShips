#pragma once

namespace game
{
  enum class state
  {
    ENTRY,
    SHIPS_LIST_CONFIG,
    DEPLOYMENT,
    WAITING_FOR_BATTLE,
    IDLE,
    BATTLE,
    END
  };
  namespace message
  {
    const std::string INVALID_OPTION = "Invalid option chosen. ";
    const std::string INVALID_INPUT = "Invalid input given. ";

    const std::string DEPLOYMENT_CHOICE = "Manual / automatic deployment?(m/a): ";
    const std::string SHIPS_LIST_TYPE_ADDITION = "Max number of ";
  }
  namespace options
  {
    namespace deployment
    {
      const char MANUAL = 'm';
      const char AUTOMATIC = 'a';
    }
    const char DEPLOY_SHIP = 'd';
    const char RESIZE_BOARD = 'r';
    const char START_BATTLE = 's';
    const char QUIT = 'q';
  }
  namespace screen
  {
    namespace clear
    {
      const std::string COMMAND = "\033[2J\033[0;0H";
      const bool ENABLED = true;
      const bool DISABLED = false;
    }
  }
}
