modded class PlayerBase extends ManBase {
  override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx) {
    if (rpc_type == -77777) {
      Param2<bool, int> AutoRunParams;
      if(!ctx.Read(AutoRunParams)) return;

      bool RunInServer = AutoRunParams.param1;
      int AutoRunSpeed = AutoRunParams.param2;
    
      ServerAutoRun(RunInServer, AutoRunSpeed);
    }

    super.OnRPC(sender, rpc_type, ctx);
  }

  void ServerAutoRun(bool RunInServer, int speed) {
    if (RunInServer) {
      this.GetInputController().OverrideMovementSpeed(true, speed);
      this.GetInputController().OverrideMovementAngle(true, 1);
    } else {
      this.GetInputController().OverrideMovementSpeed(false, 0);
      this.GetInputController().OverrideMovementAngle(false, 0);
    }
  }
}