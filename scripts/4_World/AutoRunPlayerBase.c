modded class PlayerBase extends ManBase {
  override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx) {
    if (rpc_type == -77777) {
      Param3<bool, int, int> AutoRunParams;
      if(!ctx.Read(AutoRunParams)) return;

      bool isAutoRun = AutoRunParams.param1;
      int autoRunSpeed = AutoRunParams.param2;
      int autoRunAngle = AutoRunParams.param3;
    
      this.GetInputController().OverrideMovementSpeed(isAutoRun, autoRunSpeed);
      this.GetInputController().OverrideMovementAngle(isAutoRun, autoRunAngle);
    }

    super.OnRPC(sender, rpc_type, ctx);
  }
}