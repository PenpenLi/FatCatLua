local HallUICfg = {}
HallUICfg.giftData = {
		{id = 5001,zh = "box0_cn",en="box0_en"},
		{id = 5002,zh = "box1_cn",en="box1_en"},
		{id = 5003,zh = "box2_cn",en="box2_en"},
	}
function HallUICfg.getGiftBagData(id)
	for _,v in pairs(HallUICfg.giftData) do
		if v.id == id then
			return v
		end
	end
	return nil
end
return HallUICfg