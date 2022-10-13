class CfgPatches {
  class QuickStep {
    requiredAddons[] = { };
  };
};

class CfgMods {
  class QuickStep {
    type = "mod";
    name = "QuickStep";
    version = "0.2";
    hidePicture = 1;
    inputs = "QuickStep\data\inputs.xml";
    author = "GayCookie";
    authorID = "76561198120564384";
    credits = "GayCookie";
    dependencies[] = { "World", "Mission" };

    class defs {
      class worldScriptModule {
        value = "";
        files[] = { "QuickStep/scripts/4_World" };
      };
      class missionScriptModule {
        value = "";
        files[] = { "QuickStep/scripts/5_Mission" };
      };
    };
  };
};