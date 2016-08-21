#pragma once

namespace typeGameData
{
	enum ENUMPCJOB {
		UNKNOWNJOB = 0,
		SWORDMNAN,
		WIZARD,
		ARCHER
	};

	enum ENUMBOSS {
		UNKNOWNBOSS = 0,
		BEHIMOTH,
		LEVIATHAN,
		RADRAGON
	};

	struct SELECTEDDATA {
		int pcJobNum = typeGameData::UNKNOWNJOB;
		int bossNum = typeGameData::UNKNOWNBOSS;
	};

	enum GAMEWINSIZE {
		//임시데이터
		winHeight = 640,
		winWidth = 380
	};
}