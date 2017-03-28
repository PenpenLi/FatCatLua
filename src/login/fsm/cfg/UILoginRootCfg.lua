local registry = {
	stateName = "UILoginRootState";
	resData = {};
	controller = "login.fsm.controller.UILoginRootState";
	entry = true;
	view = "login.mediator.view.LoginLayer",
	push = {
		{eventName="setting";stateName="UISettingState"},
	};
	pop = {
		{eventName="back"}
	}
}
registry.resData.Texture = {
	"gameLog.png"
}
return registry