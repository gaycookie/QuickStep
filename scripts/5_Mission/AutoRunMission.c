modded class MissionGameplay {
  bool autoRunState;

  override void OnUpdate(float timeslice) {
    super.OnUpdate(timeslice);

    if (GetGame().GetUIManager().GetMenu() == NULL) {
      Input input = GetGame().GetInput();
      PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

      if (input.LocalPress("QSEnableAutoRun")) {
        autoRunState = !autoRunState;

        if (autoRunState) updateMovement(player, 3, 1);
        else updateMovement(player, 0, 0);
        return
      }

      if (input.LocalPress("QSEnableAutoWalk")) {
        autoRunState = !autoRunState;

        if (autoRunState) updateMovement(player, 1, 1);
        else updateMovement(player, 0, 0);
        return
      }

      if (input.LocalPress("QSEnableAutoJog")) {
        autoRunState = !autoRunState;

        if (autoRunState) updateMovement(player, 2, 1);
        else updateMovement(player, 0, 0);
        return
      }

      if (input.LocalPress("UAMoveForward") || input.LocalPress("UAMoveBack") || input.LocalPress("UAMoveLeft") || input.LocalPress("UAMoveRight")) {
        if (autoRunState) {
          autoRunState = false;
          updateMovement(player, 0, 0)
        }
      }
    }
  }

  void updateMovement(PlayerBase player, int speed, int angle) {
    player.GetInputController().OverrideMovementSpeed(autoRunState, speed);
    player.GetInputController().OverrideMovementAngle(autoRunState, angle);

    if (GetGame().IsMultiplayer()) {
      auto params = new Param3<bool, int, int>(autoRunState, speed, angle);
      GetGame().RPCSingleParam(player, -77777, params, true);
    }
  }
}