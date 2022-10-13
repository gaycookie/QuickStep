modded class MissionGameplay {
	bool autoRunState;

	override void OnUpdate(float timeslice) {
		super.OnUpdate(timeslice);

		Input input = GetGame().GetInput();
		if (GetGame().GetUIManager().GetMenu() == NULL) {

			if (input.LocalPress("QSEnableAutoRun")) {
				autoRunState = !autoRunState;

				if (!autoRunState) stopAutoRun();
				else startAutoRun(3);
				return
			}

			if (input.LocalPress("QSEnableAutoWalk")) {
				autoRunState = !autoRunState;

				if (!autoRunState) stopAutoRun();
				else startAutoRun(1);
				return
			}

			if (input.LocalPress("QSEnableAutoJog")) {
				autoRunState = !autoRunState;

				if (!autoRunState) stopAutoRun();
				else startAutoRun(2);
				return
			}

			if (input.LocalPress("UAMoveForward") || input.LocalPress("UAMoveBack") || input.LocalPress("UAMoveLeft") || input.LocalPress("UAMoveRight")) {
				if (autoRunState == true) {
					autoRunState = false;
					stopAutoRun();
				}
			}
		}
	}

	void startAutoRun(int speed) {
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		player.GetInputController().OverrideMovementSpeed(true, speed);
		player.GetInputController().OverrideMovementAngle(true, 1);

		if (GetGame().IsMultiplayer()) {
			auto params = new Param2<bool, int>(autoRunState, speed);
			GetGame().RPCSingleParam(player, -77777, params, true);
		}
	}

	void stopAutoRun() {
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		player.GetInputController().OverrideMovementSpeed(false, 0);
		player.GetInputController().OverrideMovementAngle(false, 0);

		if (GetGame().IsMultiplayer()) {
			auto params = new Param2<bool, int>(autoRunState, 0);
			GetGame().RPCSingleParam(player, -77777, params, true);
		}
	}
}