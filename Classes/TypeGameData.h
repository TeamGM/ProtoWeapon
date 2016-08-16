#pragma once

namespace typeGameData
{
	enum ENUMPCJOB {
		UNKNOWNJOB = 0,
		WARRIOR,
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
}